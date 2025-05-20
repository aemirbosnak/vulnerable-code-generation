//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOOT_SECTOR_SIZE 512
#define KERNEL_IMAGE_SIZE 4096

typedef struct {
    unsigned char jmp[3];
    unsigned char oem_name[8];
    unsigned short bytes_per_sector;
    unsigned char sectors_per_cluster;
    unsigned short reserved_sectors;
    unsigned char num_fats;
    unsigned short num_root_dir_entries;
    unsigned short num_sectors;
    unsigned short media_descriptor_type;
    unsigned short sectors_per_fat;
    unsigned short sectors_per_track;
    unsigned short num_heads;
    unsigned int hidden_sectors;
    unsigned int total_sectors;
    unsigned char drive_number;
    unsigned char current_head;
    unsigned char signature;
    unsigned int volume_id;
    char volume_label[11];
    char file_system_type[8];
} boot_sector;

typedef struct {
    unsigned char filename[8];
    unsigned char extension[3];
    unsigned char attributes;
    unsigned short reserved;
    unsigned short created_time;
    unsigned short created_date;
    unsigned short last_accessed_date;
    unsigned int cluster;
    unsigned int file_size;
} directory_entry;

typedef struct {
    unsigned char status;
    unsigned char fat_entry[3];
} fat_entry;

int main(int argc, char *argv[]) {
    // Check if the input file is provided
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening the input file");
        return EXIT_FAILURE;
    }

    // Read the boot sector
    boot_sector boot_sector;
    fread(&boot_sector, sizeof(boot_sector), 1, input_file);

    // Check if the boot sector is valid
    if (boot_sector.signature != 0xAA55) {
        printf("Error: Invalid boot sector\n");
        return EXIT_FAILURE;
    }

    // Read the directory entries
    directory_entry directory_entries[boot_sector.num_root_dir_entries];
    fread(directory_entries, sizeof(directory_entry), boot_sector.num_root_dir_entries, input_file);

    // Find the cluster of the kernel image
    unsigned int kernel_image_cluster = 0;
    for (int i = 0; i < boot_sector.num_root_dir_entries; i++) {
        if (strcmp(directory_entries[i].filename, "KERNEL.EXE") == 0 && strcmp(directory_entries[i].extension, "COM") == 0) {
            kernel_image_cluster = directory_entries[i].cluster;
            break;
        }
    }

    // Check if the kernel image is found
    if (kernel_image_cluster == 0) {
        printf("Error: Kernel image not found\n");
        return EXIT_FAILURE;
    }

    // Read the kernel image
    unsigned char kernel_image[KERNEL_IMAGE_SIZE];
    fseek(input_file, boot_sector.bytes_per_sector * boot_sector.reserved_sectors + kernel_image_cluster * boot_sector.bytes_per_sector * boot_sector.sectors_per_cluster, SEEK_SET);
    fread(kernel_image, KERNEL_IMAGE_SIZE, 1, input_file);

    // Close the input file
    fclose(input_file);

    // Write the optimized boot sector
    FILE *output_file = fopen("optimized_boot.img", "wb");
    if (output_file == NULL) {
        perror("Error opening the output file");
        return EXIT_FAILURE;
    }

    // Modify the boot sector to load the kernel image directly
    boot_sector.jmp[0] = 0xE9;
    boot_sector.jmp[1] = 0x00;
    boot_sector.jmp[2] = 0x00;
    boot_sector.num_fats = 0;
    boot_sector.num_root_dir_entries = 0;
    boot_sector.num_sectors = boot_sector.sectors_per_track * boot_sector.num_heads * boot_sector.hidden_sectors;
    boot_sector.media_descriptor_type = 0xF8;
    boot_sector.sectors_per_fat = 0;
    boot_sector.sectors_per_track = boot_sector.num_heads * boot_sector.sectors_per_cluster;
    boot_sector.num_heads = 1;
    boot_sector.hidden_sectors = boot_sector.reserved_sectors;
    boot_sector.total_sectors = boot_sector.num_sectors;
    boot_sector.signature = 0xAA55;
    boot_sector.volume_label[0] = '\0';
    boot_sector.file_system_type[0] = '\0';

    // Write the modified boot sector
    fwrite(&boot_sector, sizeof(boot_sector), 1, output_file);

    // Write the kernel image
    fwrite(kernel_image, KERNEL_IMAGE_SIZE, 1, output_file);

    // Close the output file
    fclose(output_file);

    printf("Boot sector optimized successfully!\n");

    return EXIT_SUCCESS;
}