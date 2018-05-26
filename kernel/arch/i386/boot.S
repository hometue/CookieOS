# Declare constants used for creating a multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM



# Reserve a stack for the initial thread.
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

.section .idt

idt_descr:
	.word 256*8-1
	.long $IDT

.section .gdt

gdt_descr:
	.word 256*8-1 #Its x*8-1, for x = number of entries
	.long _gdt
_gdt:   .quad 0x0000000000000000 #Null pointer.
	.quad 0x00CF9A000000FFFF #Kernel space code
	.quad 0x00CF92000000FFFF #Kernel space data
	.fill 253,8,0 #Blank space for nothing at all
	
# The kernel entry point.
.section .text
.global _start
.type _start, @function
_start:
	movl $stack_top, %esp
	lgdt (gdt_descr)
	ljmp $0x08, $reload_CS
.code32
reload_CS:
	
	# Initialize the core kernel before running the global constructors.
	call kernel_early

	# Call the global constructors.
	call _init

	# Set up IDT
	lea (interuptHandler), %eax
	pushl %eax
	movl $0, %ebx
	movw %ax, %bx
	pushl %ebx
	shrl $16, %eax
	pushl %eax
	call idt_setup
	addl $0x10, %esp
	# lidt (idt_descr)
	# Transfer control to the main kernel.
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
	hlt
.Lhang:
	jmp .Lhang
.size _start, . - _start

.global interuptHandler
.type interuptHandler, @function
interuptHandler:
	pusha
	call kernel_int
	popa
	iret
