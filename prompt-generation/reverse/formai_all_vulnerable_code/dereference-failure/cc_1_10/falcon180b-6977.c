//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define MAX_LINE_SIZE 1024

// Function to compare two files and synchronize them
void sync_files(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_SIZE];
    char line2[MAX_LINE_SIZE];
    int line_num = 0;

    while (fgets(line1, MAX_LINE_SIZE, file1)!= NULL) {
        line_num++;

        // Check if line is empty or contains only whitespace
        if (line1[0] == '\n' || strspn(line1, " \t\r\n") == strlen(line1)) {
            continue;
        }

        // Read line from file2
        fseek(file2, 0, SEEK_SET);
        while (fgets(line2, MAX_LINE_SIZE, file2)!= NULL) {
            if (strcmp(line1, line2) == 0) {
                break;
            }
        }

        // If line not found in file2, append it to file2
        if (strcmp(line2, "\n")!= 0) {
            fseek(file2, 0, SEEK_END);
            fprintf(file2, "%s", line1);
        }
    }

    // If file2 has extra lines, delete them
    while (fgets(line2, MAX_LINE_SIZE, file2)!= NULL) {
        if (strcmp(line2, "\n")!= 0) {
            fseek(file2, 0, SEEK_SET);
            fprintf(file2, "\n");
        }
    }

    printf("Files synchronized successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        printf("Error opening file %s.\n", argv[1]);
        exit(1);
    }

    FILE *file2 = fopen(argv[2], "r+");
    if (file2 == NULL) {
        printf("Error opening file %s.\n", argv[2]);
        exit(1);
    }

    sync_files(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}