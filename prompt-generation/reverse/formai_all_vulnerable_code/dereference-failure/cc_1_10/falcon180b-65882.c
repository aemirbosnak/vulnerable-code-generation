//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to compare two files and synchronize them
void file_sync(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char ch1, ch2, line1[100], line2[100];
    int i, j, flag = 0;

    // Open files in read-only mode
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    // Check if files are opened successfully
    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file(s)!\n");
        exit(1);
    }

    // Initialize line pointers
    i = 0;
    j = 0;

    // Loop through both files
    while ((ch1 = fgetc(fp1))!= EOF || (ch2 = fgetc(fp2))!= EOF) {
        // Convert to lowercase for case-insensitivity
        ch1 = tolower(ch1);
        ch2 = tolower(ch2);

        // Check for end of line
        if (ch1 == '\n' || ch2 == '\n') {
            // Compare lines and print differences
            if (flag) {
                printf("Line %d:\n%s\n", i + 1, line1);
                printf("Line %d:\n%s\n", j + 1, line2);
                flag = 0;
            }
            i++;
            j++;
            strcpy(line1, "");
            strcpy(line2, "");
        }
        else {
            // Add character to line
            strncat(line1, &ch1, 1);
            strncat(line2, &ch2, 1);
        }
    }

    // Compare remaining lines and print differences
    if (flag) {
        printf("Line %d:\n%s\n", i + 1, line1);
        printf("Line %d:\n%s\n", j + 1, line2);
    }

    // Close files
    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    // Call file_sync function
    file_sync(argv[1], argv[2]);

    return 0;
}