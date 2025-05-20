//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SECTOR_SIZE 512
#define MBR_OFFSET 0x1BE
#define BOOTSTRAP_OFFSET 0x7C00

#define BOOTING_PARTITION_SIG 0xAA55

struct boot_record {
    uint8_t jump_instruction[3];
    char oem_id[8];
    uint16_t sector_size;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t num_fats;
    uint16_t num_root_entries;
    uint16_t num_sectors_small;
    uint8_t media_descriptor_type;
    uint16_t sectors_per_fat;
    uint16_t sectors_per_track;
    uint16_t num_heads;
    uint32_t hidden_sectors;
    uint32_t large_sector_count;
};

struct partition_record {
    uint8_t status;
    uint8_t starting_head;
    uint8_t starting_sector;
    uint8_t starting_cylinder;
    uint8_t system_id;
    uint8_t ending_head;
    uint8_t ending_sector;
    uint8_t ending_cylinder;
    uint32_t starting_sector_lba;
    uint32_t sector_count;
};

struct mbr {
    uint8_t signature[4];
    struct partition_record partitions[4];
};

int main() {
    FILE *mbr_file;
    struct mbr mbr;
    struct boot_record boot_record;
    int i;

    // Open the MBR file
    mbr_file = fopen("mbr.bin", "rb");
    if (mbr_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the MBR
    fread(&mbr, sizeof(mbr), 1, mbr_file);

    // Find the active partition
    for (i = 0; i < 4; i++) {
        if (mbr.partitions[i].status == 0x80) {
            // Found the active partition
            break;
        }
    }

    if (i == 4) {
        // No active partition found
        fprintf(stderr, "No active partition found\n");
        return EXIT_FAILURE;
    }

    // Read the boot record of the active partition
    fseek(mbr_file, mbr.partitions[i].starting_sector_lba * SECTOR_SIZE, SEEK_SET);
    fread(&boot_record, sizeof(boot_record), 1, mbr_file);

    // Check if the boot record is valid
    if (memcmp(boot_record.jump_instruction, "\xEB\x3C\x90", 3) != 0) {
        // Invalid boot record
        fprintf(stderr, "Invalid boot record\n");
        return EXIT_FAILURE;
    }

    // Print the boot record information
    printf("Boot record information:\n");
    printf("  Jump instruction: %02X %02X %02X\n", boot_record.jump_instruction[0], boot_record.jump_instruction[1], boot_record.jump_instruction[2]);
    printf("  OEM ID: %s\n", boot_record.oem_id);
    printf("  Sector size: %d bytes\n", boot_record.sector_size);
    printf("  Sectors per cluster: %d\n", boot_record.sectors_per_cluster);
    printf("  Reserved sectors: %d\n", boot_record.reserved_sectors);
    printf("  Number of FATs: %d\n", boot_record.num_fats);
    printf("  Number of root entries: %d\n", boot_record.num_root_entries);
    printf("  Number of sectors (small): %d\n", boot_record.num_sectors_small);
    printf("  Media descriptor type: %d\n", boot_record.media_descriptor_type);
    printf("  Sectors per FAT: %d\n", boot_record.sectors_per_fat);
    printf("  Sectors per track: %d\n", boot_record.sectors_per_track);
    printf("  Number of heads: %d\n", boot_record.num_heads);
    printf("  Hidden sectors: %d\n", boot_record.hidden_sectors);
    printf("  Large sector count: %d\n", boot_record.large_sector_count);

    // Optimize the boot record
    boot_record.sector_size = 4096;
    boot_record.sectors_per_cluster = 8;
    boot_record.reserved_sectors = 64;
    boot_record.num_fats = 1;
    boot_record.num_root_entries = 512;
    boot_record.media_descriptor_type = 0xF8;
    boot_record.sectors_per_fat = 128;
    boot_record.sectors_per_track = 63;
    boot_record.num_heads = 255;
    boot_record.hidden_sectors = 0;
    boot_record.large_sector_count = 0;

    // Write the optimized boot record to the file
    fseek(mbr_file, mbr.partitions[i].starting_sector_lba * SECTOR_SIZE, SEEK_SET);
    fwrite(&boot_record, sizeof(boot_record), 1, mbr_file);

    // Close the MBR file
    fclose(mbr_file);

    return EXIT_SUCCESS;
}