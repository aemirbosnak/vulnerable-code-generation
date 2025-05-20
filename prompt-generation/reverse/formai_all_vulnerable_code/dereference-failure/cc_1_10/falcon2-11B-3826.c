//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE 10000 // Maximum file size for synchronization

// Function to read a file and return its contents as a character array
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char* buffer = (char*) malloc(FILE_SIZE * sizeof(char));
    fread(buffer, sizeof(char), FILE_SIZE, file);
    fclose(file);

    return buffer;
}

// Function to write a character array to a file
void write_file(const char* filename, const char* contents) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fwrite(contents, sizeof(char), strlen(contents), file);
    fclose(file);
}

// Function to synchronize two files and create a new file with the contents of the first file if it differs from the second file
void synchronize_files(const char* file1, const char* file2, const char* output_file) {
    char* contents1 = read_file(file1);
    char* contents2 = read_file(file2);

    if (!contents1 ||!contents2) {
        fprintf(stderr, "Error reading file\n");
        return;
    }

    if (strcmp(contents1, contents2)) {
        write_file(output_file, contents1);
        printf("New file created with contents from %s\n", file1);
    } else {
        printf("Files are identical\n");
    }

    free(contents1);
    free(contents2);
}

int main() {
    const char* file1 = "input1.txt";
    const char* file2 = "input2.txt";
    const char* output_file = "output.txt";

    synchronize_files(file1, file2, output_file);

    return 0;
}