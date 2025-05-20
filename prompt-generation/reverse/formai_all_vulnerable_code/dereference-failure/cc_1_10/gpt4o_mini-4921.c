//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

// Simple virus signature (In a real scenario, this would come from a database)
const char *virus_signature = "VIRUS_SIG";

// Function to scan a file for a given signature
int scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("fopen");
        return 0;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        if (memmem(buffer, bytes_read, virus_signature, strlen(virus_signature))) {
            fclose(file);
            return 1; // Virus found
        }
    }

    fclose(file);
    return 0; // No virus found
}

// Function to recursively scan a directory
void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;
    struct stat statbuf;

    if (!dir) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir))) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        // Check file status
        if (stat(path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        // If it's a directory, recurse into it
        if (S_ISDIR(statbuf.st_mode)) {
            scan_directory(path);
        }
        // If it's a regular file, scan it
        else if (S_ISREG(statbuf.st_mode)) {
            if (scan_file(path)) {
                printf("Virus found in file: %s\n", path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];
    scan_directory(directory_to_scan);

    return EXIT_SUCCESS;
}