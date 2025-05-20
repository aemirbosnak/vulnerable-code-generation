//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1000000

struct file_header {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
};

void read_file_header(FILE *file, struct file_header *header) {
    fread(header, sizeof(struct file_header), 1, file);
}

int main() {
    FILE *file;
    char file_name[MAX_FILE_NAME_LENGTH];
    struct file_header header;

    // Open the file for reading
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the file header
    read_file_header(file, &header);

    // Print the file name and size
    printf("File name: %s\n", header.file_name);
    printf("File size: %d bytes\n", header.file_size);

    // Allocate memory for the file contents
    char *file_contents = (char *)malloc(header.file_size);
    if (file_contents == NULL) {
        printf("Error allocating memory!\n");
        return 2;
    }

    // Read the file contents
    fread(file_contents, header.file_size, 1, file);

    // Close the file
    fclose(file);

    // Open the file for writing
    file = fopen("recovered_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 3;
    }

    // Write the file contents
    fwrite(file_contents, header.file_size, 1, file);

    // Close the file
    fclose(file);

    printf("File recovery successful!\n");

    return 0;
}