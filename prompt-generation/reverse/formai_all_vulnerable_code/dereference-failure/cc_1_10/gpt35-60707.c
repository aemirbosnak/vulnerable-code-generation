//FormAI DATASET v1.0 Category: File Synchronizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

#define CHUNKSIZE 1024

// Function declarations
void syncFiles(char*, char*);
bool isFile(const char*);
bool isDirectory(const char*);
void copyFile(char*, char*);
void createDirectory(char*, char*);
void writeToFile(char*, char*);

int main(int argc, char** argv) {

    // Check if correct number of arguments provided
    if (argc != 3) {
        printf("Usage: ./sync <dir1> <dir2>\n");
        exit(EXIT_FAILURE);
    }

    // Call file synchronizer
    syncFiles(argv[1], argv[2]);

    return 0;
}

void syncFiles(char* dir1, char* dir2) {

    // Open the first directory
    DIR* d1 = opendir(dir1);
    if (d1 == NULL) {
        printf("Error opening directory: %s\n", dir1);
        exit(EXIT_FAILURE);
    }

    struct dirent *de1, *de2;
    while ((de1 = readdir(d1))) { // For each entry in directory 1

        // Ignore "." and ".." directories
        if (strcmp(de1->d_name, ".") == 0 || strcmp(de1->d_name, "..") == 0) {
            continue;
        }

        // Create full file paths
        char* path1 = malloc(strlen(dir1) + strlen(de1->d_name) + 2); // +2 for slash and null terminator
        sprintf(path1, "%s/%s", dir1, de1->d_name);

        char* path2 = malloc(strlen(dir2) + strlen(de1->d_name) + 2); // +2 for slash and null terminator
        sprintf(path2, "%s/%s", dir2, de1->d_name);

        if (isFile(path1)) { // If this is a file

            if (!isFile(path2)) { // If file doesn't exist in directory 2, copy it over
                copyFile(path1, path2);
                printf("Copied file %s to %s\n", path1, path2);
            }
            else if (isFile(path2)) { // If file already exists in directory 2

                // Get file sizes for both files
                struct stat statbuf1, statbuf2;
                stat(path1, &statbuf1);
                stat(path2, &statbuf2);

                if (statbuf1.st_mtime > statbuf2.st_mtime) { // If file in directory 1 is newer, copy it over
                    copyFile(path1, path2);
                    printf("Updated file %s to %s\n", path1, path2);
                }
            }

            free(path1);
            free(path2);
        }
        else if (isDirectory(path1)) { // If this is a subdirectory

            if (!isDirectory(path2)) { // If directory doesn't exist in directory 2, create it
                createDirectory(path1, path2);
                printf("Created directory %s in %s\n", de1->d_name, dir2);
            }

            // Recursively call function on subdirectory
            syncFiles(path1, path2);

            free(path1);
            free(path2);
        }

    }

    // Close directory
    closedir(d1);
}

// Function to check if a path points to a file
bool isFile(const char* path) {

    struct stat statbuf;

    if (stat(path, &statbuf) != 0) { // Error with stat call
        return false;
    }

    return S_ISREG(statbuf.st_mode); // Check if it is a regular file
}

// Function to check if a path points to a directory
bool isDirectory(const char* path) {

    struct stat statbuf;

    if (stat(path, &statbuf) != 0) { // Error with stat call
        return false;
    }

    return S_ISDIR(statbuf.st_mode); // Check if it is a directory
}

// Function to copy a file from path1 to path2
void copyFile(char* path1, char* path2) {

    // Open input file
    FILE* f1 = fopen(path1, "rb");

    // Create output file
    FILE* f2 = fopen(path2, "wb");

    // Copy file chunk by chunk
    char buf[CHUNKSIZE];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), f1)) > 0) {
        fwrite(buf, 1, n, f2);
    }

    // Close files
    fclose(f1);
    fclose(f2);
}

// Function to create a new directory in path2
void createDirectory(char* path1, char* path2) {

    struct stat st = {0};

    // Create new directory using mkdir() function
    if (stat(path2, &st) == -1) {
        mkdir(path2, 0700);
    }
}

// Function to write a string to a file
void writeToFile(char* path, char* text) {

    FILE* f = fopen(path, "w+");

    fwrite(text, sizeof(char), strlen(text), f);

    fclose(f);
}