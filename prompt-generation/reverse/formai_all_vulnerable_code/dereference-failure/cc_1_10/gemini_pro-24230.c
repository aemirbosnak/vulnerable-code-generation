//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store file metadata
typedef struct FileMetadata {
    char filename[256];
    int size;
    int start_sector;
} FileMetadata;

// Structure to store the disk image
typedef struct DiskImage {
    unsigned char *data;
    int num_sectors;
    int sector_size;
} DiskImage;

// Function to read the disk image
DiskImage *read_disk_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening disk image");
        return NULL;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the disk image
    DiskImage *disk_image = malloc(sizeof(DiskImage));
    disk_image->data = malloc(file_size);

    // Read the disk image into memory
    fread(disk_image->data, file_size, 1, fp);

    // Get the number of sectors and sector size
    disk_image->num_sectors = file_size / 512;
    disk_image->sector_size = 512;

    fclose(fp);

    return disk_image;
}

// Function to free the disk image
void free_disk_image(DiskImage *disk_image) {
    free(disk_image->data);
    free(disk_image);
}

// Function to find the files in the disk image
int find_files(DiskImage *disk_image, FileMetadata **files) {
    // Initialize the number of files to 0
    int num_files = 0;

    // Iterate over the sectors in the disk image
    for (int i = 0; i < disk_image->num_sectors; i++) {
        // Check if the sector is the start of a file
        if (disk_image->data[i * disk_image->sector_size] == 0xE5) {
            // Get the filename
            char filename[256];
            memcpy(filename, &disk_image->data[i * disk_image->sector_size + 1], 11);

            // Get the file size
            int size = *(int *)&disk_image->data[i * disk_image->sector_size + 26];

            // Get the start sector
            int start_sector = *(int *)&disk_image->data[i * disk_image->sector_size + 22];

            // Add the file to the list of files
            files[num_files] = malloc(sizeof(FileMetadata));
            strcpy(files[num_files]->filename, filename);
            files[num_files]->size = size;
            files[num_files]->start_sector = start_sector;

            num_files++;
        }
    }

    return num_files;
}

// Function to recover a file from the disk image
int recover_file(DiskImage *disk_image, FileMetadata *file, const char *output_filename) {
    // Open the output file
    FILE *fp = fopen(output_filename, "wb");
    if (fp == NULL) {
        perror("Error opening output file");
        return -1;
    }

    // Write the file data to the output file
    fwrite(&disk_image->data[file->start_sector * disk_image->sector_size], file->size, 1, fp);

    fclose(fp);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        printf("Usage: %s <disk image> <output file>\n", argv[0]);
        return -1;
    }

    // Read the disk image
    DiskImage *disk_image = read_disk_image(argv[1]);
    if (disk_image == NULL) {
        return -1;
    }

    // Find the files in the disk image
    FileMetadata *files[100];
    int num_files = find_files(disk_image, files);

    // Recover the first file
    recover_file(disk_image, files[0], argv[2]);

    // Free the files
    for (int i = 0; i < num_files; i++) {
        free(files[i]);
    }

    // Free the disk image
    free_disk_image(disk_image);

    return 0;
}