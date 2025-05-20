//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    char magic[2];
    short int num_files;
    short int block_count;
    short int root_dir_offset;
    short int sector_size;
    short int sectors_per_cluster;
} boot_sector;

typedef struct {
    char filename[8];
    char extension[3];
    unsigned char attributes;
    short int create_time;
    short int create_date;
    short int access_date;
    unsigned int first_cluster_high;
    unsigned int first_cluster_low;
    unsigned int file_size;
} directory_entry;

typedef struct {
    unsigned char *data;
    int size;
} file;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Open the image file
    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", strerror(errno));
        return 1;
    }

    // Read the boot sector
    boot_sector boot_sector;
    fseek(image_file, 0, SEEK_SET);
    fread(&boot_sector, sizeof(boot_sector), 1, image_file);

    // Check the magic number
    if (boot_sector.magic[0] != 0xEB || boot_sector.magic[1] != 0x3C) {
        fprintf(stderr, "Error: Invalid magic number in boot sector\n");
        fclose(image_file);
        return 1;
    }

    // Get the root directory offset
    int root_dir_offset = boot_sector.root_dir_offset * boot_sector.sector_size;

    // Read the root directory
    directory_entry *root_directory = malloc(sizeof(directory_entry) * boot_sector.num_files);
    fseek(image_file, root_dir_offset, SEEK_SET);
    fread(root_directory, sizeof(directory_entry), boot_sector.num_files, image_file);

    // Process the root directory entries
    for (int i = 0; i < boot_sector.num_files; i++) {
        // Skip deleted files
        if (root_directory[i].filename[0] == 0xE5) {
            continue;
        }

        // Get the file name
        char file_name[12];
        strncpy(file_name, root_directory[i].filename, 8);
        file_name[8] = '.';
        strncpy(file_name + 9, root_directory[i].extension, 3);
        file_name[12] = '\0';

        // Get the file size
        int file_size = root_directory[i].file_size;

        // Get the first cluster of the file
        unsigned int first_cluster = (root_directory[i].first_cluster_high << 16) | root_directory[i].first_cluster_low;

        // Allocate memory for the file data
        file *file_data = malloc(sizeof(file));
        file_data->data = malloc(file_size);
        file_data->size = file_size;

        // Read the file data
        int cluster_offset = first_cluster * boot_sector.sectors_per_cluster * boot_sector.sector_size;
        fseek(image_file, cluster_offset, SEEK_SET);
        fread(file_data->data, file_size, 1, image_file);

        // Write the file to disk
        FILE *output_file = fopen(file_name, "wb");
        if (output_file == NULL) {
            fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
            free(file_data->data);
            free(file_data);
            continue;
        }
        fwrite(file_data->data, file_size, 1, output_file);
        fclose(output_file);

        // Free the memory for the file data
        free(file_data->data);
        free(file_data);
    }

    // Free the memory for the root directory
    free(root_directory);

    // Close the image file
    fclose(image_file);

    return 0;
}