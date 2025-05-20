//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two strings
int compare_strings(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1!= *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    return 0;
}

// Function to synchronize files
void sync_files(char *filename1, char *filename2) {
    // Open files for reading
    FILE *file1 = fopen(filename1, "r");
    FILE *file2 = fopen(filename2, "r");
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files!\n");
        return;
    }

    // Get file size
    int file_size1 = 0;
    int file_size2 = 0;
    fseek(file1, 0, SEEK_END);
    file_size1 = ftell(file1);
    fseek(file2, 0, SEEK_END);
    file_size2 = ftell(file2);

    // Compare file sizes
    if (file_size1!= file_size2) {
        printf("Files have different sizes!\n");
        return;
    }

    // Synchronize files
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file1)!= NULL) {
        char *str1 = strdup(buffer);
        char *str2 = strdup(buffer);
        str1[strlen(str1) - 1] = '\0';
        str2[strlen(str2) - 1] = '\0';
        int diff = compare_strings(str1, str2);
        if (diff!= 0) {
            printf("File contents differ at line %d!\n", diff);
            free(str1);
            free(str2);
        } else {
            fputs(buffer, file2);
            free(str1);
            free(str2);
        }
    }
    fclose(file1);
    fclose(file2);
}

int main() {
    char filename1[256];
    char filename2[256];

    // Get file names from user
    printf("Enter filename1: ");
    fgets(filename1, sizeof(filename1), stdin);
    printf("Enter filename2: ");
    fgets(filename2, sizeof(filename2), stdin);

    // Synchronize files
    sync_files(filename1, filename2);

    return 0;
}