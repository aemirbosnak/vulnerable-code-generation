//FormAI DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECTOR_SIZE 512

typedef struct {
    char* filename;
    unsigned int start_sector;
    unsigned int size;
} File;

void print_help() {
    printf("Usage: data_recovery <disk image file>\n");
}

void print_file(File* file) {
    printf("%s - starts at sector %d, size %d bytes\n", file->filename, file->start_sector, file->size);
}

void save_file(char* filename, char* data, unsigned int size) {
    FILE* file = fopen(filename, "wb");
    fwrite(data, 1, size, file);
    fclose(file);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        print_help();
        return 1;
    }

    char* image_filename = argv[1];
    FILE* image_file = fopen(image_filename, "rb");

    if (!image_file) {
        printf("Error: Could not open image file '%s'\n", image_filename);
        return 1;
    }

    fseek(image_file, 0, SEEK_END);
    unsigned int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    char* image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);

    fclose(image_file);

    unsigned int num_sectors = image_size / SECTOR_SIZE;
    unsigned char* sector_map = calloc(num_sectors, sizeof(unsigned char));

    // Search for files
    unsigned int i, j, k;
    unsigned int bytes_read = 0;
    unsigned int files_found = 0;
    File* files = malloc(sizeof(File) * num_sectors);

    for (i = 0; i < num_sectors; i++) {
        if (sector_map[i] == 1) {
            continue;
        }

        // Check if sector starts with file header
        if (image_data[i * SECTOR_SIZE] == 'F') {
            // Read filename
            unsigned int filename_length = 0;
            char* filename = malloc(256);
            for (j = 0; j < 255; j++) {
                char c = image_data[i * SECTOR_SIZE + 1 + j];

                if (c == 0) {
                    filename[j] = '\0';
                    break;
                }

                filename[j] = c;
                filename_length++;
            }

            // Read file size
            unsigned int file_size = (unsigned int)*((unsigned int*)(image_data + i * SECTOR_SIZE + filename_length + 2));

            // Check if file fits within image
            if (i + 1 + (file_size + SECTOR_SIZE - 1) / SECTOR_SIZE > num_sectors) {
                free(filename);
                continue;
            }

            // Mark sectors as used
            for (j = i; j < i + 1 + (file_size + SECTOR_SIZE - 1) / SECTOR_SIZE; j++) {
                sector_map[j] = 1;
            }

            // Store file data
            char* file_data = malloc(file_size);
            memcpy(file_data, image_data + i * SECTOR_SIZE + filename_length + 6, file_size);

            // Add file to list
            files[files_found].filename = filename;
            files[files_found].start_sector = i;
            files[files_found].size = file_size;

            files_found++;
        }
    }

    if (files_found == 0) {
        printf("No files found :(\n");
        return 0;
    }

    // Print found files
    printf("Found %d files:\n", files_found);
    for (i = 0; i < files_found; i++) {
        print_file(&files[i]);
    }

    // Prompt user to save files
    char input[256];
    for (i = 0; i < files_found; i++) {
        printf("Save %s? (y/n) ", files[i].filename);
        fgets(input, 256, stdin);

        if (input[0] == 'y' || input[0] == 'Y') {
            printf("Saving %s...\n", files[i].filename);
            char* file_data = malloc(files[i].size);
            for (j = 0; j < files[i].size; j++) {
                file_data[j] = image_data[files[i].start_sector * SECTOR_SIZE + j];
            }

            save_file(files[i].filename, file_data, files[i].size);
            free(file_data);
        }
    }

    // Cleanup
    free(files);
    free(sector_map);
    free(image_data);

    return 0;
}