//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILE_SIZE 1024 * 1024 // 1 MB max file size
#define SIGNATURES_COUNT 3

const char *virus_signatures[SIGNATURES_COUNT] = {
    "VIRUS_SIGNATURE_1",
    "VIRUS_SIGNATURE_2",
    "VIRUS_SIGNATURE_3"
};

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    // Scan for virus signatures
    for (int i = 0; i < SIGNATURES_COUNT; i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            printf("Virus detected in file: %s (signature: %s)\n", file_path, virus_signatures[i]);
            return;
        }
    }
    printf("No viruses found in file: %s\n", file_path);
}

void scan_directory(const char *directory_path) {
    struct dirent *entry;
    DIR *dp = opendir(directory_path);

    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        // Skip the "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full file path
        char file_path[512];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);

        // Check if the entry is a directory
        if (entry->d_type == DT_DIR) {
            scan_directory(file_path); // Recursively scan subdirectories
        } else {
            scan_file(file_path); // Scan the file for viruses
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);

    return EXIT_SUCCESS;
}