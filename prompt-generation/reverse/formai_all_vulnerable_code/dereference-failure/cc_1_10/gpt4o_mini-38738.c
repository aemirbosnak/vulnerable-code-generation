//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate the checksum of a file
unsigned long calculate_checksum(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return 0;
    }

    unsigned long checksum = 0;
    int byte;
    while ((byte = fgetc(file)) != EOF) {
        checksum += byte;
    }

    fclose(file);
    return checksum;
}

// Function to scan a directory for files
void scan_directory(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        // Ignore the current and parent directories
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

            struct stat file_stat;
            if (stat(full_path, &file_stat) == 0) {
                // If it's a directory, recursively scan it
                if (S_ISDIR(file_stat.st_mode)) {
                    scan_directory(full_path);
                } else {
                    // Process the file
                    unsigned long checksum = calculate_checksum(full_path);
                    printf("File: %s, Checksum: %lu\n", full_path, checksum);
                    // Here you could compare the checksum against known malware signatures
                }
            } else {
                perror("stat");
            }
        }
    }

    closedir(dp);
}

void display_help() {
    printf("Usage: antivirus_scanner <directory_to_scan>\n");
    printf("This program scans for files in the specified directory and calculates their checksums.\n");
    printf("It can be extended to compare these checksums against known malware signatures.\n");
}

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 2) {
        display_help();
        return EXIT_FAILURE;
    }

    // Start scanning the directory provided by the user
    const char *directory_to_scan = argv[1];
    printf("Scanning directory: %s\n", directory_to_scan);
    scan_directory(directory_to_scan);
    
    printf("Scanning complete.\n");
    return EXIT_SUCCESS;
}