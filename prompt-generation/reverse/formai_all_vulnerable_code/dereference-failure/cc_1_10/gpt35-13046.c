//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file1, *file2;
    char ch1, ch2;
    int lineNo = 1, colNo = 0, diff = 0;

    // Check if both filenames are passed as arguments
    if (argc != 3) {
        printf("ERROR: Please provide 2 filenames.\n");
        return 1;
    }

    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[2], "r");

    // Check if files were opened successfully
    if (file1 == NULL || file2 == NULL) {
        printf("ERROR: Unable to open files.\n");
        return 1;
    }

    // Check each character in both files and compare
    while ((ch1 = fgetc(file1)) != EOF && (ch2 = fgetc(file2)) != EOF) {
        colNo++;

        if (ch1 != ch2) {
            diff = 1;
            printf("Files are different at line %d, column %d.\n", lineNo, colNo-1);
            printf("File 1: %c\n", ch1);
            printf("File 2: %c\n", ch2);
            break;
        }

        if (ch1 == '\n') {
            lineNo++;
            colNo = 0;
        }
    }

    if (!diff) {
        printf("Files are identical.\n");
    }

    fclose(file1);
    fclose(file2);

    return 0;
}