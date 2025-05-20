//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void sync_files(FILE *file1, FILE *file2) {
    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    int bytes_read1, bytes_read2;

    // Read from file1
    while ((bytes_read1 = fread(buffer1, sizeof(char), BUFFER_SIZE, file1))!= 0) {
        // Write to file2
        bytes_read2 = fwrite(buffer1, sizeof(char), bytes_read1, file2);
        if (bytes_read2!= bytes_read1) {
            fprintf(stderr, "Error: Failed to write to file2\n");
            exit(1);
        }
    }

    // Read from file2
    while ((bytes_read2 = fread(buffer2, sizeof(char), BUFFER_SIZE, file2))!= 0) {
        // Seek back in file1
        fseek(file1, -bytes_read2, SEEK_END);
        // Write to file1
        bytes_read1 = fwrite(buffer2, sizeof(char), bytes_read2, file1);
        if (bytes_read1!= bytes_read2) {
            fprintf(stderr, "Error: Failed to write to file1\n");
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    FILE *file1 = fopen(argv[1], "r+");
    FILE *file2 = fopen(argv[2], "r+");

    if (file1 == NULL || file2 == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        exit(1);
    }

    sync_files(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}