//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Constants
#define BOOT_SIZE 512
#define SECTOR_SIZE 512

// Function prototypes
void read_boot_sector(FILE *f, void *buf);
void write_boot_sector(FILE *f, void *buf);
void print_boot_sector_info(void *buf);
void optimize_boot_sector(void *buf);

// Main function
int main(int argc, char **argv)
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <boot sector file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the boot sector file
    FILE *f = fopen(argv[1], "r+b");
    if (f == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Allocate a buffer to store the boot sector
    void *buf = malloc(BOOT_SIZE);
    if (buf == NULL)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the boot sector into the buffer
    read_boot_sector(f, buf);

    // Print the boot sector information
    print_boot_sector_info(buf);

    // Optimize the boot sector
    optimize_boot_sector(buf);

    // Write the optimized boot sector to the file
    write_boot_sector(f, buf);

    // Free the buffer
    free(buf);

    // Close the file
    fclose(f);

    return EXIT_SUCCESS;
}

// Read the boot sector from the file
void read_boot_sector(FILE *f, void *buf)
{
    // Seek to the beginning of the file
    if (fseek(f, 0, SEEK_SET) != 0)
    {
        perror("fseek");
        exit(EXIT_FAILURE);
    }

    // Read the boot sector into the buffer
    if (fread(buf, BOOT_SIZE, 1, f) != 1)
    {
        perror("fread");
        exit(EXIT_FAILURE);
    }
}

// Write the boot sector to the file
void write_boot_sector(FILE *f, void *buf)
{
    // Seek to the beginning of the file
    if (fseek(f, 0, SEEK_SET) != 0)
    {
        perror("fseek");
        exit(EXIT_FAILURE);
    }

    // Write the boot sector to the file
    if (fwrite(buf, BOOT_SIZE, 1, f) != 1)
    {
        perror("fwrite");
        exit(EXIT_FAILURE);
    }
}

// Print the boot sector information
void print_boot_sector_info(void *buf)
{
    // Get the boot sector fields
    uint8_t *jmp_code = buf;
    uint16_t oem_id = *(uint16_t *)(buf + 3);
    uint16_t sector_size = *(uint16_t *)(buf + 11);
    uint16_t sectors_per_cluster = *(uint16_t *)(buf + 13);
    uint16_t reserved_sectors = *(uint16_t *)(buf + 14);
    uint8_t num_fats = *(uint8_t *)(buf + 16);
    uint16_t num_root_dir_entries = *(uint16_t *)(buf + 17);
    uint16_t total_sectors = *(uint16_t *)(buf + 19);
    uint8_t media_descriptor = *(uint8_t *)(buf + 21);
    uint16_t sectors_per_fat = *(uint16_t *)(buf + 22);
    uint16_t sectors_per_track = *(uint16_t *)(buf + 24);
    uint16_t num_heads = *(uint16_t *)(buf + 26);
    uint32_t hidden_sectors = *(uint32_t *)(buf + 28);
    uint32_t large_total_sectors = *(uint32_t *)(buf + 32);

    // Print the boot sector information
    printf("Boot Sector Information:\n");
    printf("------------------------\n");
    printf("JMP Code: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%02x ", jmp_code[i]);
    }
    printf("\n");
    printf("OEM ID: %04x\n", oem_id);
    printf("Sector Size: %u\n", sector_size);
    printf("Sectors per Cluster: %u\n", sectors_per_cluster);
    printf("Reserved Sectors: %u\n", reserved_sectors);
    printf("Number of FATs: %u\n", num_fats);
    printf("Number of Root Directory Entries: %u\n", num_root_dir_entries);
    printf("Total Sectors: %u\n", total_sectors);
    printf("Media Descriptor: %02x\n", media_descriptor);
    printf("Sectors per FAT: %u\n", sectors_per_fat);
    printf("Sectors per Track: %u\n", sectors_per_track);
    printf("Number of Heads: %u\n", num_heads);
    printf("Hidden Sectors: %u\n", hidden_sectors);
    printf("Large Total Sectors: %u\n", large_total_sectors);
}

// Optimize the boot sector
void optimize_boot_sector(void *buf)
{
    // Get the boot sector fields
    uint8_t *jmp_code = buf;
    uint16_t oem_id = *(uint16_t *)(buf + 3);
    uint16_t sector_size = *(uint16_t *)(buf + 11);
    uint16_t sectors_per_cluster = *(uint16_t *)(buf + 13);
    uint16_t reserved_sectors = *(uint16_t *)(buf + 14);
    uint8_t num_fats = *(uint8_t *)(buf + 16);
    uint16_t num_root_dir_entries = *(uint16_t *)(buf + 17);
    uint16_t total_sectors = *(uint16_t *)(buf + 19);
    uint8_t media_descriptor = *(uint8_t *)(buf + 21);
    uint16_t sectors_per_fat = *(uint16_t *)(buf + 22);
    uint16_t sectors_per_track = *(uint16_t *)(buf + 24);
    uint16_t num_heads = *(uint16_t *)(buf + 26);
    uint32_t hidden_sectors = *(uint32_t *)(buf + 28);
    uint32_t large_total_sectors = *(uint32_t *)(buf + 32);

    // Check for FAT32 boot sector
    if (oem_id == 0x4161 && sector_size == 512 && num_fats == 1 && sectors_per_cluster == 0 && reserved_sectors == 0 &&
        media_descriptor == 0xf8 && sectors_per_fat == 0)
    {
        // Set the total sectors field to the large total sectors field
        total_sectors = large_total_sectors;

        // Set the boot sector fields
        *(uint16_t *)(buf + 19) = total_sectors;
        *(uint32_t *)(buf + 32) = 0;
    }
}