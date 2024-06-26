FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SECURE_BOOT_PATCHES:amd-zynqmp = " \
    file://0001-u-boot-xlnx-force-to-build-dtb-file.patch \
    file://fitImage.cfg \
    file://zcu102-devicetree.cfg \
"

SRC_URI:append:amd-zynqmp = " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', '${SECURE_BOOT_PATCHES}', '', d)}"
