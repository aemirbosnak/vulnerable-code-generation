//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_SIZE 1024

// Function to compare two files
int compare_files(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "rb");
    FILE* f2 = fopen(file2, "rb");

    if (f1 == NULL || f2 == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }

    char buffer1[1024], buffer2[1024];
    int bytes_read1, bytes_read2;

    while ((bytes_read1 = fread(buffer1, sizeof(char), sizeof(buffer1), f1)) > 0 &&
           (bytes_read2 = fread(buffer2, sizeof(char), sizeof(buffer2), f2)) > 0) {

        int cmp = memcmp(buffer1, buffer2, bytes_read1 < bytes_read2? bytes_read1 : bytes_read2);

        if (cmp!= 0) {
            fprintf(stderr, "Files are different.\n");
            exit(1);
        }
    }

    if (ferror(f1)!= 0 || ferror(f2)!= 0) {
        fprintf(stderr, "Error: Could not read file.\n");
        exit(1);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    char path1[MAX_PATH_SIZE], path2[MAX_PATH_SIZE];

    strcpy(path1, argv[1]);
    strcpy(path2, argv[2]);

    compare_files(path1, path2);

    return 0;
}