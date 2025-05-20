//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BOOT_SECTOR_SIZE 512
#define NUM_SECTORS_PER_CLUSTER 8
#define NUM_RESERVED_SECTORS 32
#define NUM_FATS 2

typedef struct {
    uint8_t jump_boot[3];
    uint8_t oem_id[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t num_fats;
    uint16_t num_root_dir_entries;
    uint16_t total_logical_sectors;
    uint8_t media_descriptor;
    uint16_t sectors_per_fat;
    uint16_t sectors_per_track;
    uint16_t num_heads;
    uint32_t hidden_sectors;
    uint32_t large_total_logical_sectors;
} boot_sector;

typedef struct {
    uint8_t filename[11];
    uint8_t attributes;
    uint16_t cluster_high;
    uint16_t cluster_low;
    uint32_t file_size;
} directory_entry;

typedef struct {
    boot_sector boot_sector;
    directory_entry directory_entries[512];
} superblock;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "rb+");
    if (fp == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    superblock *superblock = malloc(sizeof(superblock));
    if (superblock == NULL) {
        perror("Error allocating memory for superblock");
        fclose(fp);
        return EXIT_FAILURE;
    }

    fread(superblock, sizeof(superblock), 1, fp);

    // Optimize the boot sector

    superblock->boot_sector.bytes_per_sector = 4096;
    superblock->boot_sector.sectors_per_cluster = 32;
    superblock->boot_sector.num_fats = 1;
    superblock->boot_sector.total_logical_sectors = 1024;
    superblock->boot_sector.media_descriptor = 0xf8;

    // Optimize the directory entries

    for (int i = 0; i < 512; i++) {
        directory_entry *entry = &superblock->directory_entries[i];
        if (entry->attributes == 0x00) {
            continue;
        }

        // Move the file to the root directory

        if (entry->attributes & 0x10) {
            entry->cluster_high = 0;
            entry->cluster_low = i + 2;
        }

        // Pack the filename

        for (int j = 0; j < 11; j++) {
            if (entry->filename[j] == ' ') {
                entry->filename[j] = 0xe5;
            }
        }
    }

    // Write the optimized boot sector and directory entries

    fseek(fp, 0, SEEK_SET);
    fwrite(superblock, sizeof(superblock), 1, fp);

    fclose(fp);

    free(superblock);

    return EXIT_SUCCESS;
}