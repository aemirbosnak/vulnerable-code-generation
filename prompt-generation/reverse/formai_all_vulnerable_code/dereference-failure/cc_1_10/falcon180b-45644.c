//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Function to compare two files
int compare_files(FILE *file1, FILE *file2) {
    char buffer1[MAX_FILE_SIZE], buffer2[MAX_FILE_SIZE];
    int bytes_read1, bytes_read2, result = 0;

    while ((bytes_read1 = fread(buffer1, sizeof(char), MAX_FILE_SIZE, file1)) == MAX_FILE_SIZE &&
           (bytes_read2 = fread(buffer2, sizeof(char), MAX_FILE_SIZE, file2)) == MAX_FILE_SIZE) {
        if (memcmp(buffer1, buffer2, MAX_FILE_SIZE)!= 0) {
            result = 1;
            break;
        }
    }

    if (bytes_read1!= bytes_read2) {
        result = 1;
    }

    return result;
}

// Function to synchronize files
void synchronize_files(FILE *file1, FILE *file2) {
    int bytes_read1, bytes_read2;
    char buffer[MAX_FILE_SIZE];

    while ((bytes_read1 = fread(buffer, sizeof(char), MAX_FILE_SIZE, file1)) == MAX_FILE_SIZE) {
        if (bytes_read1!= fwrite(buffer, sizeof(char), MAX_FILE_SIZE, file2)) {
            printf("Error writing to file 2\n");
        }
    }

    while ((bytes_read2 = fread(buffer, sizeof(char), MAX_FILE_SIZE, file2)) == MAX_FILE_SIZE) {
        if (bytes_read2!= fwrite(buffer, sizeof(char), MAX_FILE_SIZE, file1)) {
            printf("Error writing to file 1\n");
        }
    }
}

// Function to main function
int main() {
    FILE *file1, *file2;
    char filename1[100], filename2[100];

    // Get filenames from user
    printf("Enter filename 1: ");
    scanf("%s", filename1);
    printf("Enter filename 2: ");
    scanf("%s", filename2);

    // Open files
    file1 = fopen(filename1, "r+");
    file2 = fopen(filename2, "r+");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files\n");
        exit(1);
    }

    // Compare files
    if (compare_files(file1, file2)) {
        printf("Files are different\n");
        synchronize_files(file1, file2);
        printf("Files synchronized\n");
    } else {
        printf("Files are the same\n");
    }

    // Close files
    fclose(file1);
    fclose(file2);

    return 0;
}