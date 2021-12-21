# Bare metal demo
Basic demo written on i386 32bit AT&T assembler and bare metal C

![preview](https://github.com/dikovmaxim/basicbaremetaldemo/blob/main/image.png)

Install dependencies (Debian-like distros)
```bash
apt install binutils gcc qemu qemu-kvm
```

Basic commands to compile 512 bytes binary
```bash
#Convert code to object file
gcc -c -g -Os -ffunction-sections -march=i686 -Wall demo.c -o demo.o

#Linking files
ld -static -Tlinker.ld -nostdlib --nmagic -o demo.elf demo.o

#Finishing up the compilation
objcopy -O binary demo.elf boot.bin
```

Automatic build
```bash
chmod +x build.sh
./build.sh
```

Preview the result
```bash
qemu-system-x86_64 boot.bin
```
