//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SIGNATURE "VIRUS" // A sample virus signature to look for

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        if (strstr(buffer, SIGNATURE) != NULL) {
            printf("Potential virus detected in file: %s\n", file_path);
            fclose(file);
            return;
        }
    }
    
    fclose(file);
}

void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[BUFFER_SIZE];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively scan the directory
            scan_directory(path);
        } else if (S_ISREG(statbuf.st_mode)) {
            // Scan the file for virus signatures
            scan_file(path);
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting scan in directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed.\n");
    
    return EXIT_SUCCESS;
}