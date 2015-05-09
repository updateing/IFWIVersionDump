#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include "check_perform.h"

// From ifwi.zip, all files are in the same size
#define IMG_CONTENT_BUFFER_SIZE 4194468

int main(int argc, char* argv[])
{
    int rc = 0;
    char* img_content;
    long img_size;
    FILE* img_fp;

    img_content = malloc(IMG_CONTENT_BUFFER_SIZE);

    if (argc < 2) {
        fprintf(stderr, "ERROR: At least one parameter suggesting path to IFWI image is required\n");
        rc = EINVAL;
        goto FINAL;
    }

    img_fp = fopen(argv[1], "rb");
    if (img_fp == NULL) {
        fprintf(stderr, "Couldn't read from give file: %s\n", argv[1]);
        rc = EIO;
        goto FINAL;
    }

    fseek(img_fp, 0, SEEK_END);
    img_size = ftell(img_fp);
    if (img_size <= 0) {
        fprintf(stderr, "Couldn't retrive img_size\n");
        rc = EIO;
        goto FINAL;
    }
    fseek(img_fp, 0, SEEK_SET);

    fread(img_content, img_size, 1, img_fp);
    check_ifwi_file(img_content, img_size);

FINAL:
    free(img_content);
    return rc;
}
