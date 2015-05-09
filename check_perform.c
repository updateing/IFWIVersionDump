/*
 * Copyright 2014 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include "fw_version_check.h"

static void dump_fw_versions(struct firmware_versions *v)
{
    fprintf(stdout, "Image FW versions:\n");
    fprintf(stdout, "	   ifwi: %04X.%04X\n", v->ifwi.major, v->ifwi.minor);
    fprintf(stdout, "---- components ----\n");
    fprintf(stdout, "	    scu: %04X.%04X\n", v->scu.major, v->scu.minor);
    fprintf(stdout, "      hooks/oem: %04X.%04X\n", v->valhooks.major, v->valhooks.minor);
    fprintf(stdout, "	   ia32: %04X.%04X\n", v->ia32.major, v->ia32.minor);
    fprintf(stdout, "	 chaabi: %04X.%04X\n", v->chaabi.major, v->chaabi.minor);
    fprintf(stdout, "	    mIA: %04X.%04X\n", v->mia.major, v->mia.minor);
}

int check_ifwi_file(void *data, size_t size)
{
	struct firmware_versions img_fw_rev;

	if (get_image_fw_rev(data, size, &img_fw_rev)) {
		fprintf(stderr, "Couldn't extract FW version data from image\n");
		return -1;
	}

	dump_fw_versions(&img_fw_rev);

	return 1;
}
