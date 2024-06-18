#
# Copyright (C) 2024 Wind River Systems, Inc.
#


COMPATIBLE_MACHINE:amd-zynqmp = "amd-zynqmp"

TARGET_SUPPORTED_KTYPES:amd-zynqmp = "standard preempt-rt"

KERNEL_DTC_FLAGS:append:amd-zynqmp = " -@"
