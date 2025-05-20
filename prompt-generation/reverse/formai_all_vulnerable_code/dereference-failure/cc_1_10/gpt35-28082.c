//FormAI DATASET v1.0 Category: File Synchronizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256

// Function to print error messages and exit program
void panic(char *message) {
    printf("Error: %s\n", message);
    exit(1);
}

// Function to compare two files and return their difference
int compare_files(char *file1_path, char *file2_path) {
    // Open the two files
    FILE *file1 = fopen(file1_path, "r");
    if (file1 == NULL) {
        panic("Could not open file 1");
    }
    FILE *file2 = fopen(file2_path, "r");
    if (file2 == NULL) {
        panic("Could not open file 2");
    }

    // Compare the two files line by line
    int line_number = 1;
    char file1_line[MAX_FILENAME_SIZE];
    char file2_line[MAX_FILENAME_SIZE];
    while (fgets(file1_line, MAX_FILENAME_SIZE, file1)) {
        if (!fgets(file2_line, MAX_FILENAME_SIZE, file2)) {
            printf("File 1 has more lines than file 2\n");
            return -1;
        }
        if (strcmp(file1_line, file2_line) != 0) {
            printf("Difference found on line %d\n", line_number);
            return line_number;
        }
        line_number++;
    }
    if (fgets(file2_line, MAX_FILENAME_SIZE, file2)) {
        printf("File 2 has more lines than file 1\n");
        return -1;
    }

    // Files are identical
    return 0;
}

// Function to synchronize two files
void sync_files(char *source_file_path, char *dest_file_path) {
    // Check if files are identical
    int diff_line = compare_files(source_file_path, dest_file_path);
    if (diff_line == 0) {
        printf("Files are identical\n");
        return;
    }

    // Find the difference between the files
    FILE *source_file = fopen(source_file_path, "r");
    if (source_file == NULL) {
        panic("Could not open source file");
    }
    FILE *dest_file = fopen(dest_file_path, "r+");
    if (dest_file == NULL) {
        panic("Could not open destination file");
    }
    fseek(dest_file, 0, SEEK_SET);
    int current_line = 1;
    char source_line[MAX_FILENAME_SIZE];
    while (fgets(source_line, MAX_FILENAME_SIZE, source_file)) {
        if (current_line < diff_line) {
            current_line++;
            continue;
        }
        char dest_line[MAX_FILENAME_SIZE];
        if (fgets(dest_line, MAX_FILENAME_SIZE, dest_file)) {
            // Line in destination file exists, replace it with line from source file
            fseek(dest_file, -strlen(dest_line), SEEK_CUR);
            fputs(source_line, dest_file);
        } else {
            // Line in destination file does not exist, append line from source file
            fputs(source_line, dest_file);
        }
    }
    fclose(source_file);
    fclose(dest_file);

    printf("Files synchronized\n");
}

int main() {
    char source_file_path[MAX_FILENAME_SIZE];
    char dest_file_path[MAX_FILENAME_SIZE];

    // Get source and destination file paths from user
    printf("Enter path to source file: ");
    scanf("%s", source_file_path);
    printf("Enter path to destination file: ");
    scanf("%s", dest_file_path);

    // Synchronize the two files
    sync_files(source_file_path, dest_file_path);

    return 0;
}