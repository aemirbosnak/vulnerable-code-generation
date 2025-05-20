//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: systematic
// C File Synchronizer - Compares and Synchronizes Two Files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_LINE_SIZE 256
#define BUFFER_SIZE 1024

// Function Prototypes
void display_usage(char *program_name);
int compare_files(FILE *file1, FILE *file2);
void synchronize_files(FILE *file1, FILE *file2);

// Main Function
int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Open the two files
    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        perror("Error opening file 1");
        return EXIT_FAILURE;
    }

    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        perror("Error opening file 2");
        return EXIT_FAILURE;
    }

    // Compare the two files
    int result = compare_files(file1, file2);

    if (result == 0) {
        printf("Files are identical.\n");
    } else if (result == 1) {
        printf("Files differ.\n");
        synchronize_files(file1, file2);
    } else {
        printf("Error comparing files.\n");
        return EXIT_FAILURE;
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    return EXIT_SUCCESS;
}

// Display usage information
void display_usage(char *program_name) {
    printf("Usage: %s file1 file2\n", program_name);
}

// Compare two files and return 0 if they are identical, 1 if they differ, and -1 if an error occurs
int compare_files(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_SIZE], line2[MAX_LINE_SIZE];

    while (fgets(line1, MAX_LINE_SIZE, file1) != NULL && fgets(line2, MAX_LINE_SIZE, file2) != NULL) {
        if (strcmp(line1, line2) != 0) {
            return 1;
        }
    }

    // If one of the files has more lines than the other, they are different
    if (fgets(line1, MAX_LINE_SIZE, file1) != NULL || fgets(line2, MAX_LINE_SIZE, file2) != NULL) {
        return 1;
    }

    return 0;
}

// Synchronize two files by copying the contents of file1 to file2
void synchronize_files(FILE *file1, FILE *file2) {
    char buffer[BUFFER_SIZE];
    int num_read;

    rewind(file1);

    while ((num_read = fread(buffer, 1, BUFFER_SIZE, file1)) > 0) {
        fwrite(buffer, 1, num_read, file2);
    }

    printf("Files synchronized.\n");
}