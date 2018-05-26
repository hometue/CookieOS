#include <stdio.h>
 
#include <kernel/tty.h>
#include <kernel/itoa.h>
#include <kernel/idt.h>
struct IDTDescr IDT[256];

void kernel_main(void) {
	printf("Hello, kernel World v2!\n");
}

void kernel_early(void){
	terminal_initialize();
	printf("Help me I am drowning in code\n");
}

void kernel_int(void){
	printf("kernel_int\n");
}

void idt_setup(unsigned int a, unsigned int b, unsigned int c){
	char output[10];
	itoa(a, output, 16);
	printf(output);
	printf("\n");
	itoa(b, output, 16);
	printf(output);
	printf("\n");
	itoa(c, output, 16);
	printf(output);
	printf("\n");
	struct IDTDescr test=(struct IDTDescr){.offset_1=1, .selector=0b0000000000000001, .zero=0, .type_attr=0b1110, .offset_2=2};
	IDT[0]=test;
}