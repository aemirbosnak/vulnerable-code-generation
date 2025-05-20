//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

// Function to read the contents of a file
void read_file(char *filename, char *buffer) {
    FILE *file;
    long file_size;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("File size exceeds maximum limit of %d bytes.\n", MAX_FILE_SIZE);
        exit(1);
    }

    fread(buffer, file_size, 1, file);
    fclose(file);
}

// Function to write the recovered data to a new file
void write_file(char *filename, char *buffer) {
    FILE *file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error creating file: %s\n", filename);
        exit(1);
    }

    fwrite(buffer, strlen(buffer), 1, file);
    fclose(file);
}

// Function to recover data from a corrupted file
void recover_data(char *filename) {
    char buffer[MAX_FILE_SIZE];
    int i, j;

    read_file(filename, buffer);

    // Remove any trailing whitespace
    for (i = strlen(buffer) - 1; i >= 0 && isspace(buffer[i]); i--) {
        buffer[i] = '\0';
    }

    // Remove any leading whitespace
    for (i = 0; i < strlen(buffer) && isspace(buffer[i]); i++);

    // Remove any consecutive whitespace characters
    for (i = 0, j = 0; i < strlen(buffer); i++) {
        if (!isspace(buffer[i])) {
            buffer[j++] = buffer[i];
        }
    }
    buffer[j] = '\0';

    // Write the recovered data to a new file
    write_file("recovered_data.txt", buffer);
}

int main() {
    char filename[100];

    printf("Enter the name of the corrupted file: ");
    scanf("%s", filename);

    recover_data(filename);

    printf("Data recovery completed! Check the recovered_data.txt file.\n");

    return 0;
}