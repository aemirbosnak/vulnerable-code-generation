//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to synchronize two files
void synchronize_files(FILE *file1, FILE *file2) {
    char ch1, ch2;

    // Check if either file is empty
    if (feof(file1)) {
        printf("File 1 is empty.\n");
        exit(0);
    }
    if (feof(file2)) {
        printf("File 2 is empty.\n");
        exit(0);
    }

    // Compare characters from both files
    while ((ch1 = fgetc(file1))!= EOF && (ch2 = fgetc(file2))!= EOF) {
        if (ch1!= ch2) {
            printf("Files are not synchronized.\n");
            exit(0);
        }
    }

    // Check if end of file is reached for both files
    if (feof(file1)) {
        printf("Files are synchronized.\n");
    }
    else if (feof(file2)) {
        printf("Files are synchronized.\n");
    }
    else {
        printf("Files are not synchronized.\n");
    }
}

int main() {
    // Open files for reading
    FILE *file1 = fopen("file1.txt", "r");
    FILE *file2 = fopen("file2.txt", "r");

    // Check if files are opened successfully
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files.\n");
        exit(0);
    }

    // Synchronize files
    synchronize_files(file1, file2);

    // Close files
    fclose(file1);
    fclose(file2);

    return 0;
}