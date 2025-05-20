//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define FILE_HEADER_SIZE 512
#define FILE_FOOTER_SIZE 512

// Function to read data from a file
void read_data(FILE *file, char *buffer, int size) {
    if (fread(buffer, size, 1, file)!= 1) {
        printf("Error reading data from file\n");
        exit(1);
    }
}

// Function to write data to a file
void write_data(FILE *file, char *buffer, int size) {
    if (fwrite(buffer, size, 1, file)!= 1) {
        printf("Error writing data to file\n");
        exit(1);
    }
}

// Function to recover data from a corrupted file
void recover_data(char *filename) {
    FILE *file;
    char header[FILE_HEADER_SIZE];
    char footer[FILE_FOOTER_SIZE];
    char buffer[MAX_FILE_SIZE];
    int size;

    // Open the file for reading
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        exit(1);
    }

    // Read the header
    read_data(file, header, FILE_HEADER_SIZE);

    // Read the footer
    fseek(file, -FILE_FOOTER_SIZE, SEEK_END);
    read_data(file, footer, FILE_FOOTER_SIZE);

    // Check if the file is corrupted
    if (memcmp(header, footer, FILE_FOOTER_SIZE)!= 0) {
        printf("File is corrupted\n");
        exit(1);
    }

    // Create a new file for writing
    char *output_filename = malloc(strlen(filename) + 5);
    strcpy(output_filename, filename);
    strcat(output_filename, "_recovered.txt");
    file = fopen(output_filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        exit(1);
    }

    // Read data from the original file and write it to the new file
    while ((size = fread(buffer, 1, MAX_FILE_SIZE, file)) > 0) {
        write_data(file, buffer, size);
    }

    // Close the files
    fclose(file);
    fclose(file);

    printf("Data recovery successful\n");
}

int main() {
    char filename[100];
    printf("Enter the name of the corrupted file: ");
    scanf("%s", filename);
    recover_data(filename);
    return 0;
}