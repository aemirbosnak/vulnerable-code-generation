//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// File header magic numbers
#define FAT12_MAGIC 0xAA55
#define FAT16_MAGIC 0x55AA
#define FAT32_MAGIC 0x6EB176EF

// FAT entry types
#define FAT_ENTRY_FREE 0x0000
#define FAT_ENTRY_LAST 0xFFFF
#define FAT_ENTRY_BAD 0xFFF7

// Sector size
#define SECTOR_SIZE 512

// Number of sectors per cluster
#define CLUSTER_SIZE 8

// Maximum number of clusters in a FAT12 file system
#define FAT12_MAX_CLUSTERS 4085

// Maximum number of clusters in a FAT16 file system
#define FAT16_MAX_CLUSTERS 65535

// Maximum number of clusters in a FAT32 file system
#define FAT32_MAX_CLUSTERS 0xFFFFFFFF

// Data structure to represent a FAT entry
typedef struct fat_entry {
    uint16_t value;
} fat_entry;

// Data structure to represent a FAT sector
typedef struct fat_sector {
    fat_entry entries[SECTOR_SIZE / sizeof(fat_entry)];
} fat_sector;

// Data structure to represent a FAT file system
typedef struct fat_filesystem {
    uint32_t magic;
    uint16_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t number_of_fats;
    uint16_t root_directory_sector;
    uint16_t total_sectors;
    uint16_t max_clusters;
    fat_sector *fat_sectors;
} fat_filesystem;

// Function to read a sector from a file
int read_sector(FILE *file, uint32_t sector, void *buffer) {
    fseek(file, sector * SECTOR_SIZE, SEEK_SET);
    return fread(buffer, SECTOR_SIZE, 1, file);
}

// Function to read the FAT sector from a file system
int read_fat_sector(fat_filesystem *fs, uint32_t sector, fat_sector *fat_sector) {
    return read_sector(fs->fat_sectors, sector, fat_sector);
}

// Function to get the FAT entry for a cluster
fat_entry get_fat_entry(fat_filesystem *fs, uint32_t cluster) {
    uint32_t sector = cluster / (SECTOR_SIZE / sizeof(fat_entry));
    uint32_t offset = cluster % (SECTOR_SIZE / sizeof(fat_entry));
    fat_sector fat_sector;
    read_fat_sector(fs, sector, &fat_sector);
    return fat_sector.entries[offset];
}

// Function to follow a FAT chain
int follow_fat_chain(fat_filesystem *fs, uint32_t cluster, uint8_t *data) {
    while (cluster != FAT_ENTRY_LAST) {
        fat_entry fat_entry = get_fat_entry(fs, cluster);
        switch (fat_entry.value) {
            case FAT_ENTRY_FREE:
                return 0;
            case FAT_ENTRY_BAD:
                return 0;
            default:
                read_sector(fs->fat_sectors, cluster * fs->sectors_per_cluster, data);
                data += SECTOR_SIZE;
                cluster = fat_entry.value;
        }
    }
    return 1;
}

// Function to recover data from a FAT file system
int recover_data(fat_filesystem *fs, FILE *output) {
    uint32_t cluster = 2;  // Start at the root directory
    uint8_t data[SECTOR_SIZE];
    while (cluster != FAT_ENTRY_LAST) {
        if (follow_fat_chain(fs, cluster, data)) {
            fwrite(data, SECTOR_SIZE, 1, output);
        }
        cluster++;
    }
    return 1;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        return 1;
    }

    // Read the boot sector
    uint8_t boot_sector[SECTOR_SIZE];
    read_sector(input, 0, boot_sector);

    // Check the magic number
    uint32_t magic = *(uint32_t *)boot_sector;
    if (magic != FAT12_MAGIC && magic != FAT16_MAGIC && magic != FAT32_MAGIC) {
        fprintf(stderr, "Error: Invalid FAT file system\n");
        return 1;
    }

    // Create a FAT file system object
    fat_filesystem fs;
    fs.magic = magic;
    fs.sectors_per_cluster = boot_sector[13];
    fs.reserved_sectors = *(uint16_t *)&boot_sector[14];
    fs.number_of_fats = boot_sector[16];
    fs.root_directory_sector = *(uint16_t *)&boot_sector[18];
    fs.total_sectors = *(uint16_t *)&boot_sector[19];

    // Calculate the maximum number of clusters
    switch (magic) {
        case FAT12_MAGIC:
            fs.max_clusters = FAT12_MAX_CLUSTERS;
            break;
        case FAT16_MAGIC:
            fs.max_clusters = FAT16_MAX_CLUSTERS;
            break;
        case FAT32_MAGIC:
            fs.max_clusters = FAT32_MAX_CLUSTERS;
            break;
    }

    // Allocate memory for the FAT sectors
    fs.fat_sectors = malloc(fs.number_of_fats * fs.total_sectors * sizeof(fat_sector));
    if (fs.fat_sectors == NULL) {
        fprintf(stderr, "Error allocating memory for FAT sectors\n");
        return 1;
    }

    // Read the FAT sectors
    for (uint32_t i = 0; i < fs.number_of_fats; i++) {
        for (uint32_t j = 0; j < fs.total_sectors; j++) {
            read_fat_sector(&fs, j, &fs.fat_sectors[i * fs.total_sectors + j]);
        }
    }

    // Recover data from the FAT file system
    recover_data(&fs, output);

    // Free memory
    free(fs.fat_sectors);

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}