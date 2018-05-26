#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/cookieos.kernel isodir/boot/cookieos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "cookieos" {
	multiboot /boot/cookieos.kernel
}
EOF
grub-mkrescue -o cookieos.iso isodir
