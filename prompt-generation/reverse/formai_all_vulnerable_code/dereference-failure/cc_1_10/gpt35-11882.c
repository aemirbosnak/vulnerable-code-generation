//FormAI DATASET v1.0 Category: File Synchronizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Function to check if the file/folder exists
int file_exists(const char* path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// Function to copy file from source to destination
int copy_file(const char* source_path, const char* dest_path) {
    FILE *source, *dest;
    int ch;

    source = fopen(source_path, "r");
    if (source == NULL) {
        return 0;
    }

    dest = fopen(dest_path, "w");
    if (dest == NULL) {
        fclose(source);
        return 0;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    fclose(source);
    fclose(dest);

    return 1;
}

// Function to copy folder recursively from source to destination
int copy_folder(const char* source_path, const char* dest_path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stats; 
    char source_file[256];
    char dest_file[256];

    dir = opendir(source_path);

    if (dir == NULL) {
        return 0;
    }

    // Create destination folder if it does not already exist
    if (!file_exists(dest_path)) {
        mkdir(dest_path, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            sprintf(source_file, "%s/%s", source_path, entry->d_name);
            sprintf(dest_file, "%s/%s", dest_path, entry->d_name);
            stat(source_file, &file_stats);

            if (S_ISDIR(file_stats.st_mode)) {
                // If it is a directory, recursively copy it
                copy_folder(source_file, dest_file);
            } else {
                // If it is a file, copy it
                copy_file(source_file, dest_file);
            }
        }
    }

    closedir(dir);

    return 1;
}

int main(int argc, char** argv) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: ./sync source_folder dest_folder\n");
        return 1;
    }

    const char* source_path = argv[1];
    const char* dest_path = argv[2];

    // Check if source folder exists
    if (!file_exists(source_path)) {
        printf("Error: Source folder %s does not exist\n", source_path);
        return 1;
    }

    // Check if destination folder exists
    if (!file_exists(dest_path)) {
        printf("Error: Destination folder %s does not exist\n", dest_path);
        return 1;
    }

    // Copy all files and folders recursively
    copy_folder(source_path, dest_path);

    printf("Sync successful!\n");

    return 0;
}