//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

// Function to read a binary file and store its contents in a buffer
void read_file(char* filename, char* buffer) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum limit of %d bytes\n", MAX_FILE_SIZE);
        fclose(file);
        exit(1);
    }

    fread(buffer, file_size, 1, file);
    fclose(file);
}

// Function to write a buffer to a binary file
void write_file(char* filename, char* buffer) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fwrite(buffer, strlen(buffer), 1, file);
    fclose(file);
}

// Function to recover data from a corrupted file
void recover_data(char* filename) {
    char buffer[MAX_FILE_SIZE];

    // Read the corrupted file into a buffer
    read_file(filename, buffer);

    // Search for the file signature
    char* signature = "Sig";
    char* pos = strstr(buffer, signature);

    // If the signature is not found, the file is not recoverable
    if (pos == NULL) {
        printf("Error: File %s is not recoverable\n", filename);
        return;
    }

    // Calculate the offset of the data from the signature
    int offset = pos - buffer;

    // Extract the data from the buffer
    char* data = &buffer[offset];

    // Write the recovered data to a new file
    char* new_filename = malloc(strlen(filename) + 5);
    strcpy(new_filename, filename);
    strcat(new_filename, "_rec");
    write_file(new_filename, data);

    printf("Data recovered and saved to file %s\n", new_filename);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <corrupted_file> <recovered_file>\n", argv[0]);
        return 1;
    }

    char* corrupted_file = argv[1];
    char* recovered_file = argv[2];

    recover_data(corrupted_file);

    return 0;
}