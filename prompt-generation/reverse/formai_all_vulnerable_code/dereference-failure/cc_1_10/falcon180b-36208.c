//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to compare two files and synchronize them
void synchronize_files(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];

    // Read first line from both files
    fgets(line1, MAX_LINE_LENGTH, file1);
    fgets(line2, MAX_LINE_LENGTH, file2);

    // Compare lines until end of file is reached
    while (strcmp(line1, line2)!= 0) {
        // If line1 is longer, write it to file2
        if (strlen(line1) > strlen(line2)) {
            fputs(line1, file2);
        }
        // If line2 is longer, write it to file1
        else {
            fputs(line2, file1);
        }

        // Read next line from both files
        fgets(line1, MAX_LINE_LENGTH, file1);
        fgets(line2, MAX_LINE_LENGTH, file2);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <file1> <file2> <output>\n", argv[0]);
        return 1;
    }

    // Open input files
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Create output file
    FILE *output = fopen(argv[3], "w");

    if (output == NULL) {
        printf("Error creating output file.\n");
        return 1;
    }

    // Synchronize files and write result to output file
    synchronize_files(file1, file2);

    // Close files
    fclose(file1);
    fclose(file2);
    fclose(output);

    return 0;
}