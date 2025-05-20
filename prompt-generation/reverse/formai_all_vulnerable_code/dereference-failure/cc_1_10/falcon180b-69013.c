//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to recover

typedef struct {
    char magic[2];
    int version;
    int file_size;
    char file_name[256];
    char file_data[MAX_FILE_SIZE];
} FileHeader;

// Function to read a file header
FileHeader* read_header(FILE* file) {
    FileHeader* header = malloc(sizeof(FileHeader));
    fread(header, sizeof(FileHeader), 1, file);
    return header;
}

// Function to recover a file
void recover_file(FILE* input, FILE* output, FileHeader* header) {
    int file_size = header->file_size;
    char* file_data = malloc(file_size);
    fread(file_data, file_size, 1, input);
    fprintf(output, "Recovered file: %s\n", header->file_name);
    fprintf(output, "File size: %d bytes\n", file_size);
    fprintf(output, "File data:\n");
    for (int i = 0; i < file_size; i++) {
        fprintf(output, "%c", file_data[i]);
    }
    fprintf(output, "\n");
    free(file_data);
}

// Function to recover all files in a directory
void recover_files(char* directory) {
    FILE* input = fopen(directory, "rb");
    if (!input) {
        printf("Error opening directory: %s\n", directory);
        exit(1);
    }
    while (1) {
        FileHeader* header = read_header(input);
        if (!header) {
            break;
        }
        FILE* output = fopen(header->file_name, "wb");
        if (!output) {
            printf("Error creating file: %s\n", header->file_name);
            free(header);
            continue;
        }
        recover_file(input, output, header);
        fclose(output);
        free(header);
    }
    fclose(input);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    recover_files(argv[1]);
    return 0;
}