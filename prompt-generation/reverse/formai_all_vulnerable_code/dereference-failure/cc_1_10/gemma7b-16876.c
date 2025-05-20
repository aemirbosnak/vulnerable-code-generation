//Gemma-7B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    char filename[] = "my_file.txt";
    FILE *fp;

    // Open file in read-write mode
    fp = fopen(filename, "r+w");

    // Check if file is opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for file content
    char *file_content = malloc(MAX_SIZE);

    // Read file content
    int read_size = fread(file_content, MAX_SIZE, 1, fp);

    // Check if file content was read successfully
    if (read_size != 1) {
        perror("Error reading file");
        exit(1);
    }

    // Print file content
    printf("File content: \n");
    printf("%s", file_content);

    // Modify file content
    file_content[0] = 'H';

    // Write modified file content
    int write_size = fwrite(file_content, MAX_SIZE, 1, fp);

    // Check if file content was written successfully
    if (write_size != 1) {
        perror("Error writing file");
        exit(1);
    }

    // Close file
    fclose(fp);

    // Free memory
    free(file_content);

    return 0;
}