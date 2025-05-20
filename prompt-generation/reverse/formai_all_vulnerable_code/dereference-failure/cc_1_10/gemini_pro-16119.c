//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECTOR_SIZE 512
#define MBR_OFFSET 0
#define MBR_SIZE 512
#define MBR_SIGNATURE_OFFSET 510
#define MBR_SIGNATURE 0xAA55
#define BOOT_LOADER_OFFSET MBR_OFFSET + MBR_SIZE
#define BOOT_LOADER_SIZE 4096
#define KERNEL_OFFSET BOOT_LOADER_OFFSET + BOOT_LOADER_SIZE
#define KERNEL_SIZE 16384
#define RAMDISK_OFFSET KERNEL_OFFSET + KERNEL_SIZE
#define RAMDISK_SIZE 32768

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <boot_loader> <kernel> <ramdisk> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *boot_loader_file = argv[1];
    char *kernel_file = argv[2];
    char *ramdisk_file = argv[3];
    char *output_image_file = argv[4];

    FILE *boot_loader_fp = fopen(boot_loader_file, "rb");
    if (boot_loader_fp == NULL) {
        perror("fopen: boot_loader_file");
        return EXIT_FAILURE;
    }

    FILE *kernel_fp = fopen(kernel_file, "rb");
    if (kernel_fp == NULL) {
        perror("fopen: kernel_file");
        return EXIT_FAILURE;
    }

    FILE *ramdisk_fp = fopen(ramdisk_file, "rb");
    if (ramdisk_fp == NULL) {
        perror("fopen: ramdisk_file");
        return EXIT_FAILURE;
    }

    FILE *output_image_fp = fopen(output_image_file, "wb");
    if (output_image_fp == NULL) {
        perror("fopen: output_image_file");
        return EXIT_FAILURE;
    }

    // Write MBR
    char mbr[MBR_SIZE] = { 0 };
    mbr[MBR_SIGNATURE_OFFSET] = MBR_SIGNATURE;

    // Write boot loader
    char boot_loader[BOOT_LOADER_SIZE] = { 0 };
    fread(boot_loader, BOOT_LOADER_SIZE, 1, boot_loader_fp);
    fwrite(boot_loader, BOOT_LOADER_SIZE, 1, output_image_fp);

    // Write kernel
    char kernel[KERNEL_SIZE] = { 0 };
    fread(kernel, KERNEL_SIZE, 1, kernel_fp);
    fwrite(kernel, KERNEL_SIZE, 1, output_image_fp);

    // Write ramdisk
    char ramdisk[RAMDISK_SIZE] = { 0 };
    fread(ramdisk, RAMDISK_SIZE, 1, ramdisk_fp);
    fwrite(ramdisk, RAMDISK_SIZE, 1, output_image_fp);

    fclose(boot_loader_fp);
    fclose(kernel_fp);
    fclose(ramdisk_fp);
    fclose(output_image_fp);

    printf("Successfully created boot image: %s\n", output_image_file);
    return EXIT_SUCCESS;
}