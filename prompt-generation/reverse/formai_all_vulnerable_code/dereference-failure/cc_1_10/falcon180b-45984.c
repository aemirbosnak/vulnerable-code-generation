//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to compare two files for synchronization
int compareFiles(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int lineCount = 0;

    // Read first line from file1
    fgets(line1, MAX_LINE_LENGTH, file1);
    while (fgets(line2, MAX_LINE_LENGTH, file2)!= NULL) {
        // Compare lines from both files
        if (strcmp(line1, line2)!= 0) {
            printf("Files are not synchronized at line %d\n", lineCount + 1);
            return 1;
        }
        lineCount++;
        // Read next line from file2
        fgets(line2, MAX_LINE_LENGTH, file2);
    }

    // Check if file1 has more lines than file2
    if (fgets(line1, MAX_LINE_LENGTH, file1)!= NULL) {
        printf("Files are not synchronized at line %d\n", lineCount + 1);
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int result = compareFiles(file1, file2);

    fclose(file1);
    fclose(file2);

    return result;
}