//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFSIZE 8192

// Function to get file size
long getFileSize(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

// Function to copy the contents of one file to another
void copyFile(const char *source, const char *destination) {
    char buffer[BUFSIZE];
    FILE *src, *dest;
    size_t bytes;

    src = fopen(source, "rb");
    dest = fopen(destination, "wb");

    if (src == NULL || dest == NULL) {
        perror("Error opening file for copying");
        return;
    }

    while ((bytes = fread(buffer, sizeof(char), BUFSIZE, src)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

// Romance blooms between the files
void synchronizeFiles(const char *fileA, const char *fileB) {
    long sizeA = getFileSize(fileA);
    long sizeB = getFileSize(fileB);

    if (sizeA == -1 || sizeB == -1) {
        printf("One of the files does not exist, love cannot bloom!\n");
        return;
    }

    if (sizeA != sizeB) {
        printf("Lengths of %s and %s differ, a fated mismatch!\n", fileA, fileB);
        if (sizeA > sizeB) {
            printf("But fear not, I shall lovingly write %s to %s!\n", fileA, fileB);
            copyFile(fileA, fileB);
        } else {
            printf("But I shall gently weave the words of %s into %s!\n", fileB, fileA);
            copyFile(fileB, fileA);
        }
    } else {
        printf("Oh my darling files! Your sizes are harmoniously in sync.\n");
        printf("No need for my delicate touch; you are perfectly matched!\n");
    }
}

// List files in a given directory
void listFilesInDirectory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("Error while opening directory");
        return;
    }

    printf("Files in %@ the directory '%s':\n", directory);
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // If the entry is a regular file
            printf("   - %s\n", entry->d_name);
        }
    }

    closedir(dp);
}

int main() {
    char inputA[256], inputB[256];
    char directory[256];

    printf("Welcome to the 'Heartfelt File Synchronizer'.\n");
    printf("Please enter the path of the first file you'd like to sync:\n");
    scanf("%255s", inputA);
    
    printf("Please enter the path of the second file you'd like to sync:\n");
    scanf("%255s", inputB);
    
    synchronizeFiles(inputA, inputB);

    printf("\nAs the sun sets, let me list the files in your loving embrace,\n");
    printf("Please enter a directory path to cherish:\n");
    scanf("%255s", directory);
    
    listFilesInDirectory(directory);

    printf("\nOur synchronizing journey comes to an end,\n");
    printf("May your files and hearts remain in perfect harmony.\n");

    return 0;
}