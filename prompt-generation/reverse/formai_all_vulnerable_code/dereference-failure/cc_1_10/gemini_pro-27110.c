//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024
#define SECTOR_SIZE 512

typedef struct {
    char filename[256];
    int start_sector;
    int end_sector;
    int size;
} file_entry;

file_entry *files;
int num_files;

void read_fat(FILE *disk_image) {
    char buffer[SECTOR_SIZE];

    fseek(disk_image, 0, SEEK_SET);
    fread(buffer, SECTOR_SIZE, 1, disk_image);

    // Get the number of files
    num_files = (buffer[11] << 8) | buffer[12];

    // Get the starting sector of the root directory
    int root_dir_sector = (buffer[19] << 8) | buffer[20];

    // Allocate memory for the files
    files = malloc(sizeof(file_entry) * num_files);

    // Read the root directory
    fseek(disk_image, root_dir_sector * SECTOR_SIZE, SEEK_SET);
    fread(buffer, SECTOR_SIZE, num_files, disk_image);

    // Parse the root directory
    int i;
    for (i = 0; i < num_files; i++) {
        // Get the filename
        strncpy(files[i].filename, buffer + i * 32, 11);

        // Get the starting sector
        files[i].start_sector = (buffer[i * 32 + 26] << 8) | buffer[i * 32 + 27];

        // Get the end sector
        files[i].end_sector = (buffer[i * 32 + 28] << 8) | buffer[i * 32 + 29];

        // Get the size
        files[i].size = (files[i].end_sector - files[i].start_sector + 1) * SECTOR_SIZE;
    }
}

void write_file(FILE *disk_image, int file_index) {
    char buffer[SECTOR_SIZE];

    // Get the file
    file_entry file = files[file_index];

    // Open the output file
    FILE *output_file = fopen(file.filename, "wb");

    // Seek to the starting sector of the file
    fseek(disk_image, file.start_sector * SECTOR_SIZE, SEEK_SET);

    // Read the file
    int sectors_read = 0;
    while (sectors_read < file.size / SECTOR_SIZE) {
        fread(buffer, SECTOR_SIZE, 1, disk_image);
        fwrite(buffer, SECTOR_SIZE, 1, output_file);
        sectors_read++;
    }

    // Close the output file
    fclose(output_file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <disk image>\n", argv[0]);
        return 1;
    }

    // Open the disk image
    FILE *disk_image = fopen(argv[1], "rb");
    if (disk_image == NULL) {
        printf("Error opening disk image: %s\n", argv[1]);
        return 1;
    }

    // Read the FAT
    read_fat(disk_image);

    // Print the list of files
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].filename, files[i].size);
    }

    // Prompt the user to select a file to recover
    int file_index;
    printf("Enter the index of the file to recover: ");
    scanf("%d", &file_index);

    // Write the file to disk
    write_file(disk_image, file_index);

    // Close the disk image
    fclose(disk_image);

    return 0;
}