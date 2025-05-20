//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a file exists
int fileExists(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        return 0;
    }
    fclose(f);
    return 1;
}

// Function to create a new file
void createFile(const char* filename) {
    FILE* f = fopen(filename, "w");
    if (f == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fclose(f);
}

// Function to copy the contents of one file to another
void copyFile(const char* src, const char* dst) {
    FILE* src_f = fopen(src, "r");
    FILE* dst_f = fopen(dst, "w");
    if (src_f == NULL || dst_f == NULL) {
        perror("Error opening files");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src_f)!= NULL) {
        fputs(buffer, dst_f);
    }

    fclose(src_f);
    fclose(dst_f);
}

// Function to compare two files
int compareFiles(const char* src, const char* dst) {
    FILE* src_f = fopen(src, "r");
    FILE* dst_f = fopen(dst, "r");
    if (src_f == NULL || dst_f == NULL) {
        perror("Error opening files");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src_f)!= NULL && fgets(buffer, sizeof(buffer), dst_f)!= NULL) {
        if (strcmp(buffer, buffer)!= 0) {
            printf("Files are not identical!\n");
            return 0;
        }
    }

    fclose(src_f);
    fclose(dst_f);
    return 1;
}

int main() {
    char src[1024];
    char dst[1024];
    printf("Enter source file name: ");
    fgets(src, sizeof(src), stdin);
    printf("Enter destination file name: ");
    fgets(dst, sizeof(dst), stdin);

    if (!fileExists(src) ||!fileExists(dst)) {
        printf("One or more files do not exist.\n");
        return 1;
    }

    if (!compareFiles(src, dst)) {
        printf("Files are identical.\n");
        return 0;
    }

    printf("Copying file...\n");
    copyFile(src, dst);

    printf("File synchronization complete.\n");

    return 0;
}