//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_SIGNATURES 5
#define MAX_FILE_SIZE 1024 * 1024 // 1 MB
#define SIGNATURE_LENGTH 50

// Sample virus signatures for demonstration
const char *virus_signatures[MAX_SIGNATURES] = {
    "VIRUS:W32/Example.1",
    "VIRUS:W32/Example.2",
    "VIRUS:W32/Example.3",
    "VIRUS:W32/Example.4",
    "VIRUS:W32/Example.5"
};

// Function to check if the file contains any known virus signatures
int scan_file(const char *file_path) {
    FILE *file;
    char *buffer;
    size_t bytes_read;
    int i, j;

    file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    buffer = malloc(MAX_FILE_SIZE);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return -1;
    }

    bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    for (i = 0; i < MAX_SIGNATURES; i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            printf("Potential Virus Detected: %s in %s\n", virus_signatures[i], file_path);
            free(buffer);
            return 1; // Virus found
        }
    }

    free(buffer);
    return 0; // No virus
}

// Function to scan a directory recursively
void scan_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat statbuf;
    char path[1024];
    DIR *dp = opendir(dir_path);

    if (!dp) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            stat(path, &statbuf);

            if (S_ISDIR(statbuf.st_mode)) {
                // Recursively scan the subdirectory
                scan_directory(path);
            } else if (S_ISREG(statbuf.st_mode)) {
                // Scan the file
                scan_file(path);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan complete.\n");

    return EXIT_SUCCESS;
}