# Bare metal demo
Basic demo written on i386 32bit AT&T assembler and bare metal C
```bash
gcc -c -g -Os -ffunction-sections -march=i686 -Wall demo.c -o demo.o
ld -static -Tlinker.ld -nostdlib --nmagic -o demo.elf demo.o
objcopy -O binary demo.elf boot.bin
qemu-system-x86_64 boot.bin 
```
