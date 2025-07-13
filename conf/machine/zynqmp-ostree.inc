OSTREE_BOOTLOADER_INCLUDE ?= ""
OSTREE_SD_UBOOT_WIC1 ?= ""
OSTREE_SD_BOOT_ALIGN ?= "4096"
OSTREE_FDISK_BLM ?= "8192"
OSTREE_FDISK_FSZ ?= "132"
OSTREE_KERNEL ?= "Image"
OSTREE_UBOOT_CMD ?= "booti"
OSTREE_WKS_EFI_SIZE ?= "--size=64M"
INSTAB ?= "1"
DEFAULT_DTB ?= "zynqmp-zcu102-rev1.0.dtb"
OSTREE_NETINST_DEV ?= "/dev/mmcblk0,/dev/sda,/dev/vda"
OSTREE_NETINST_ARGS ?= "${OSTREE_CONSOLE} bl=ufsd rdinit=/install instdev=${OSTREE_NETINST_DEV} instname=wrlinux instbr=\$BRANCH insturl=\$URL instab=${OSTREE_USE_AB} instsf=1 instdate=BUILD_DATE"
OSTREE_COPY_IMAGE_BOOT_FILES = "1"
INITRAMFS_IMAGE ??= ""

# Avoid the definition "devicetree/*.dtbo;devicetree/" of IMAGE_BOOT_FILES in meta-xilinx to
# break do_image_otaimg.
IMAGE_BOOT_FILES = " Image zynqmp-zcu102-rev1.0.dtb boot.scr ${INITRAMFS_IMAGE}-${MACHINE}.${INITRAMFS_FSTYPES};initramfs "
IMAGE_BOOT_FILES:append = "${@bb.utils.contains_any('WRL_ZYNQMP_BOOTBIN_TARGET', 'zcu102', ' boot.bin', '', d)}"

OSTREE_BOOTSCR_PRECMD ?= "\
setenv no_menu yes; \
setenv initrd_addr 0x40000000; \
setenv fdt_addr 0xe0000; \
setenv console ttyPS0; \
setenv baudrate 115200n8; \
"
