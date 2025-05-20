//FormAI DATASET v1.0 Category: File Synchronizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two files
int compareFiles(FILE* file1, FILE* file2) {
    char ch1 = getc(file1);
    char ch2 = getc(file2);

    while (ch1 != EOF && ch2 != EOF) {
        if (ch1 != ch2)
            return 0;

        ch1 = getc(file1);
        ch2 = getc(file2);
    }

    if (ch1 == EOF && ch2 == EOF)
        return 1;
    else
        return 0;
}

// Function to synchronize files
void syncFiles(char* fileName1, char* fileName2) {
    FILE *file1, *file2;

    // Open file1 in read mode and file2 in write mode
    file1 = fopen(fileName1, "r");
    file2 = fopen(fileName2, "w");

    if (file1 == NULL || file2 == NULL) {
        printf("Error in opening files\n");
        exit(EXIT_FAILURE);
    }

    // Read each character from file1 and write it to file2
    char ch = getc(file1);
    while (ch != EOF) {
        putc(ch, file2);
        ch = getc(file1);
    }

    // Close file pointers
    fclose(file1);
    fclose(file2);

    // Check if files are identical
    file1 = fopen(fileName1, "r");
    file2 = fopen(fileName2, "r");

    if (compareFiles(file1, file2))
        printf("Files synchronized\n");
    else
        printf("Files not synchronized\n");

    // Close file pointers
    fclose(file1);
    fclose(file2);
}

// Driver function
int main() {
    char fileName1[100], fileName2[100];

    // Take input file names
    printf("Enter file1 name: ");
    scanf("%s", fileName1);

    printf("Enter file2 name: ");
    scanf("%s", fileName2);

    // Synchronize files
    syncFiles(fileName1, fileName2);

    return 0;
}