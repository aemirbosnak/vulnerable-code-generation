//FormAI DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a file
typedef struct file {
    char name[100];
    int size;
    char content[10000];
} file_t;

// Define a function to read a file
void read_file(FILE *fp, file_t *file) {
    // Get the size of the file
    fseek(fp, 0L, SEEK_END);
    file->size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Read the content of the file
    fread(file->content, sizeof(char), file->size, fp);
    file->content[file->size] = '\0';
}

// Define a function to recover files
void recover_files(char *disk_image_filename) {
    // Open the disk image file
    FILE *disk_image = fopen(disk_image_filename, "rb");

    // Check if the disk image file exists
    if (!disk_image) {
        printf("The disk image file %s does not exist.\n", disk_image_filename);
        exit(1);
    }

    // Read the number of files
    int num_files;
    fread(&num_files, sizeof(int), 1, disk_image);

    // Allocate memory for the files
    file_t *files = malloc(num_files * sizeof(file_t));

    // Read the files
    for (int i = 0; i < num_files; i++) {
        // Read the name of the file
        fread(files[i].name, sizeof(char), 100, disk_image);
        files[i].name[100] = '\0';

        // Read the content of the file
        read_file(disk_image, &files[i]);

        printf("Recovered file %d: %s\n", i+1, files[i].name);
        printf("Size of recovered file %d: %d bytes\n", i+1, files[i].size);
        printf("Content of recovered file %d: %s\n", i+1, files[i].content);
    }

    // Close the disk image file
    fclose(disk_image);

    // Free the memory
    free(files);
}

int main() {
    char *disk_image_filename = "disk_image.bin";
    recover_files(disk_image_filename);
    return 0;
}