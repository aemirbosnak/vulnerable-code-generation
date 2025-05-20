//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *file_ptr;
    char line[MAX_LINE_LENGTH];
    int line_number;
} file_t;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_name_1> <file_name_2>\n", argv[0]);
        return 1;
    }

    file_t file1, file2;

    // Open the first file
    strcpy(file1.file_name, argv[1]);
    file1.file_ptr = fopen(argv[1], "r");
    if (file1.file_ptr == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // Open the second file
    strcpy(file2.file_name, argv[2]);
    file2.file_ptr = fopen(argv[2], "r");
    if (file2.file_ptr == NULL) {
        printf("Error: could not open file %s\n", argv[2]);
        return 1;
    }

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int line_number = 1;

    // Read the first line from both files
    fgets(line1, MAX_LINE_LENGTH, file1.file_ptr);
    fgets(line2, MAX_LINE_LENGTH, file2.file_ptr);

    // Compare the first lines
    while (strcmp(line1, line2) == 0) {
        // If the lines are the same, read the next line from both files
        fgets(line1, MAX_LINE_LENGTH, file1.file_ptr);
        fgets(line2, MAX_LINE_LENGTH, file2.file_ptr);

        // Increment the line number
        line_number++;
    }

    // If the files are not the same, print the line number and the difference
    if (strcmp(line1, line2)!= 0) {
        printf("Files are not the same\n");
        printf("Line %d:\n", line_number);
        printf("File 1: %s\n", line1);
        printf("File 2: %s\n", line2);
    } else {
        printf("Files are the same\n");
    }

    // Close the files
    fclose(file1.file_ptr);
    fclose(file2.file_ptr);

    return 0;
}