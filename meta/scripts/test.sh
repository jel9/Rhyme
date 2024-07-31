#/bin/sh

set -e

rm -rf build/
meson build --cross-file meta/targets/x86_64-llvm.ini
ninja -C build

make -C limine

rm -rf iso_root
mkdir -p iso_root/boot
cp -v build/rhm iso_root/boot/
mkdir -p iso_root/boot/limine
cp -v limine.cfg limine/limine-bios.sys limine/limine-bios-cd.bin limine/limine-uefi-cd.bin iso_root/boot/limine/
mkdir -p iso_root/EFI/BOOT
cp -v limine/BOOTX64.EFI iso_root/EFI/BOOT/
cp -v limine/BOOTIA32.EFI iso_root/EFI/BOOT/
xorriso -as mkisofs -b boot/limine/limine-bios-cd.bin \
  -no-emul-boot -boot-load-size 4 -boot-info-table \
  --efi-boot boot/limine/limine-uefi-cd.bin \
  -efi-boot-part --efi-boot-image --protective-msdos-label \
  iso_root -o rhyme-x86_64.iso
./limine/limine bios-install rhyme-x86_64.iso
rm -rf iso_root

qemu-system-x86_64 -M q35 -m 2G -bios meta/ovmf/64_86.fd -cdrom rhyme-x86_64.iso -boot d
