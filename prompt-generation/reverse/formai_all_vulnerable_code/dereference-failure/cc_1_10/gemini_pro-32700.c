//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint32_t signature;
    uint32_t start_sector;
    uint32_t num_sectors;
} MBR_entry;

typedef struct {
    uint32_t signature;
    uint32_t num_sectors;
    uint32_t start_sector;
    uint32_t first_cluster;
    uint32_t num_fats;
    uint32_t sectors_per_fat;
    uint32_t sectors_per_cluster;
    uint32_t num_reserved_sectors;
    uint8_t num_fat_copies;
    uint8_t root_dir_entries;
    uint16_t total_sectors_small;
    uint8_t media_descriptor_type;
    uint16_t sectors_per_track;
    uint16_t num_heads;
    uint32_t hidden_sectors;
    uint32_t total_sectors_large;
} FAT_boot_sector;

typedef struct {
    uint8_t filename[8];
    uint8_t extension[3];
    uint8_t attributes;
    uint32_t timestamp;
    uint32_t filesize;
    uint16_t start_cluster;
} FAT_directory_entry;

typedef struct {
    uint32_t signature;
    uint32_t num_files;
    uint32_t first_cluster;
    uint32_t next_cluster;
} FAT_cluster;

#define FAT_ENTRY_UNUSED 0x00
#define FAT_ENTRY_EOF 0xFFF
#define FAT_ENTRY_RESERVED 0xFF0
#define FAT_ENTRY_BAD 0xFF7

#define FAT_SECTOR_SIZE 512

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <disk image file>\n", argv[0]);
        return 1;
    }

    FILE *disk_image = fopen(argv[1], "rb");
    if (disk_image == NULL) {
        printf("Error: could not open disk image file '%s'\n", argv[1]);
        return 1;
    }

    MBR_entry mbr;
    fread(&mbr, sizeof(mbr), 1, disk_image);

    if (mbr.signature != 0xAA55) {
        printf("Error: invalid MBR signature\n");
        return 1;
    }

    FAT_boot_sector boot_sector;
    fseek(disk_image, mbr.start_sector * FAT_SECTOR_SIZE, SEEK_SET);
    fread(&boot_sector, sizeof(boot_sector), 1, disk_image);

    if (boot_sector.signature != 0xEB90) {
        printf("Error: invalid FAT boot sector signature\n");
        return 1;
    }

    uint32_t root_dir_start_sector = mbr.start_sector + boot_sector.num_reserved_sectors + boot_sector.num_fats * boot_sector.sectors_per_fat;
    uint32_t root_dir_num_sectors = (boot_sector.root_dir_entries * sizeof(FAT_directory_entry) + FAT_SECTOR_SIZE - 1) / FAT_SECTOR_SIZE;

    FAT_directory_entry *root_dir = malloc(root_dir_num_sectors * FAT_SECTOR_SIZE);
    fseek(disk_image, root_dir_start_sector * FAT_SECTOR_SIZE, SEEK_SET);
    fread(root_dir, root_dir_num_sectors * FAT_SECTOR_SIZE, 1, disk_image);

    for (int i = 0; i < boot_sector.root_dir_entries; i++) {
        FAT_directory_entry *entry = &root_dir[i];

        if (entry->filename[0] == 0x00) {
            continue;
        }

        if (entry->attributes & 0x10) {
            // This is a directory, not a file.
            continue;
        }

        printf("%s.%s (%d bytes)\n", entry->filename, entry->extension, entry->filesize);
    }

    free(root_dir);
    fclose(disk_image);

    return 0;
}