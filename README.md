IFWI Version Dump
=================
  This is tool is meant for checking version of Intel FirmWare Interface(IFWI) images.

###### fw_version_check.* and check_perform.c(recovery_updater.cpp modified) is taken from AOSP fugu device tree.

  *Build*: as simple as `make`

  *Usage*: `ifwi_ver_dump <path_to_ifwi_image>`

  *Example*:
> $ ./ifwi_ver_dump ifwi_ann_a0-mofd_v1-ze551ml.bin

> Image FW versions:

>ifwi: 0094.0171

> ---- components ----

>scu: 00B0.0032

>hooks/oem: 005E.002C

>ia32: 0003.0001

>chaabi: 0058.0501

>mIA: 00B0.3130

