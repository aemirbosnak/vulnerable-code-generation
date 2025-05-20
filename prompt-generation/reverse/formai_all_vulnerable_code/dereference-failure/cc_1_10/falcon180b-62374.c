//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
    int num_lines;
} File;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    File file1, file2;
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int num_lines1 = 0, num_lines2 = 0;
    int common_lines = 0;

    // Open file 1
    strcpy(file1.file_name, argv[1]);
    file1.fp = fopen(file1.file_name, "r");
    if (file1.fp == NULL) {
        printf("Error: Could not open file %s\n", file1.file_name);
        return 1;
    }

    // Open file 2
    strcpy(file2.file_name, argv[2]);
    file2.fp = fopen(file2.file_name, "r");
    if (file2.fp == NULL) {
        printf("Error: Could not open file %s\n", file2.file_name);
        return 1;
    }

    // Read file 1
    while (fgets(line1, MAX_LINE_LENGTH, file1.fp)!= NULL) {
        num_lines1++;
        // Remove newline character
        line1[strcspn(line1, "\n")] = '\0';
        // Convert to uppercase
        for (int i = 0; i < strlen(line1); i++) {
            line1[i] = toupper(line1[i]);
        }
    }

    // Read file 2
    while (fgets(line2, MAX_LINE_LENGTH, file2.fp)!= NULL) {
        num_lines2++;
        // Remove newline character
        line2[strcspn(line2, "\n")] = '\0';
        // Convert to uppercase
        for (int i = 0; i < strlen(line2); i++) {
            line2[i] = toupper(line2[i]);
        }
    }

    // Compare files
    if (num_lines1 == num_lines2) {
        printf("The files are identical.\n");
    } else {
        printf("The files are different.\n");
    }

    // Close files
    fclose(file1.fp);
    fclose(file2.fp);

    return 0;
}