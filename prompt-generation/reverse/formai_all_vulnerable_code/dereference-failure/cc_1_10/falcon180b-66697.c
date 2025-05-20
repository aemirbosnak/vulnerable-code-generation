//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define BUFFER_SIZE 1024

// Function to compare two files
int compare_files(FILE *file1, FILE *file2) {
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int cmp;

    // Read first file
    cmp = fread(buffer1, 1, BUFFER_SIZE, file1);
    if (cmp == 0) {
        printf("Error reading file 1\n");
        return -1;
    }

    // Read second file
    cmp = fread(buffer2, 1, BUFFER_SIZE, file2);
    if (cmp == 0) {
        printf("Error reading file 2\n");
        return -1;
    }

    // Compare buffers
    while (strcmp(buffer1, buffer2) == 0) {
        // Read next buffer from both files
        cmp = fread(buffer1, 1, BUFFER_SIZE, file1);
        if (cmp == 0) {
            printf("Error reading file 1\n");
            return -1;
        }

        cmp = fread(buffer2, 1, BUFFER_SIZE, file2);
        if (cmp == 0) {
            printf("Error reading file 2\n");
            return -1;
        }
    }

    // Files are different
    return 0;
}

// Function to synchronize files
void synchronize_files(FILE *file1, FILE *file2) {
    char buffer[BUFFER_SIZE];
    int cmp;

    // Rewind both files
    rewind(file1);
    rewind(file2);

    // Compare files and synchronize
    while ((cmp = compare_files(file1, file2))!= 0) {
        if (cmp < 0) {
            printf("Error comparing files\n");
            exit(1);
        }

        if (fseek(file1, 0, SEEK_SET)!= 0) {
            printf("Error seeking file 1\n");
            exit(1);
        }

        if (fseek(file2, 0, SEEK_SET)!= 0) {
            printf("Error seeking file 2\n");
            exit(1);
        }

        if (fwrite(buffer, 1, BUFFER_SIZE, file1)!= BUFFER_SIZE) {
            printf("Error writing to file 1\n");
            exit(1);
        }

        if (fwrite(buffer, 1, BUFFER_SIZE, file2)!= BUFFER_SIZE) {
            printf("Error writing to file 2\n");
            exit(1);
        }
    }
}

int main(int argc, char **argv) {
    FILE *file1, *file2;

    // Check if correct number of arguments
    if (argc!= 4) {
        printf("Usage: %s <file1> <file2> <output>\n", argv[0]);
        return 1;
    }

    // Open input files
    file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        printf("Error opening file 1\n");
        return 1;
    }

    file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        printf("Error opening file 2\n");
        return 1;
    }

    // Create output file
    FILE *output = fopen(argv[3], "w");
    if (output == NULL) {
        printf("Error creating output file\n");
        return 1;
    }

    // Synchronize files and write to output
    synchronize_files(file1, file2);

    // Close files
    fclose(file1);
    fclose(file2);
    fclose(output);

    printf("Files synchronized successfully\n");

    return 0;
}