# secure boot related configurations
KERNEL_IMAGETYPES = "fitImage"
UBOOT_SIGN_ENABLE = "1"
IMAGE_INSTALL:append = " kernel-image-fitimage "
IMAGE_BOOT_FILES:append = " fitImage "
UBOOT_SIGN_KEYDIR = "${@bb.utils.contains("FIT_SIGN_ALG", "rsa4096", "${LAYER_PATH_wr-amd-zynqmp}/zynqmp_keys/fitImage-rsa4096-keys", "${LAYER_PATH_wr-amd-zynqmp}/zynqmp_keys/fitImage-rsa2048-keys", d)}"
UBOOT_MKIMAGE_DTCOPTS = "-I dts -O dtb -p 2000"
UBOOT_SIGN_KEYNAME = "dev"
# UBOOT_MACHINE is needed by linux-yocto
UBOOT_MACHINE ?= "xilinx_zynqmp_virt_defconfig"
# Key used to sign kernel and dtb parts in fit image
UBOOT_SIGN_IMG_KEYNAME = "dev_individual"
FIT_SIGN_INDIVIDUAL  = "1"
UBOOT_SUFFIX = "img"
SPL_BINARY ?= "spl/boot.bin"

KERNEL_CLASSES  = "kernel-fitimage"

# Xilinx secure boot feature supports rsa2048 and rsa4096 key type.
# Set FIT_SIGN_ALG as the expected value in local.conf. The default one is rsa2048.
FIT_SIGN_ALG ?= "rsa2048"

# Xilinx secure boot feature supports sha1 and sha256 digest.
# Set FIT_HASH_ALG as the expected value in local.conf. The default one is sha256.
FIT_HASH_ALG ?= "sha256"
