//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_SIGNATURE_LENGTH 32
#define MAX_FILE_PATH 1024
#define MAX_SIGNATURES 10

// List of known virus signatures (for example purposes)
const char *virus_signatures[MAX_SIGNATURES] = {
    "VIRUS1_SIGNATURE",
    "VIRUS2_SIGNATURE",
    "VIRUS3_SIGNATURE",
    "VIRUS4_SIGNATURE",
    "VIRUS5_SIGNATURE",
    "VIRUS6_SIGNATURE",
    "VIRUS7_SIGNATURE",
    "VIRUS8_SIGNATURE",
    "VIRUS9_SIGNATURE",
    "VIRUS10_SIGNATURE"
};

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    int found = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(buffer, virus_signatures[i])) {
                printf("Virus found: %s in file: %s\n", virus_signatures[i], file_path);
                found = 1;
                break; // No need to search for more signatures in this file
            }
        }
        if (found) break;
    }

    fclose(file);
}

void scan_directory(const char *directory_path) {
    struct dirent *entry;
    DIR *dp = opendir(directory_path);
    if (!dp) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char file_path[MAX_FILE_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);
            scan_file(file_path);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *directory_to_scan = argv[1];

    printf("Scanning directory: %s\n", directory_to_scan);
    scan_directory(directory_to_scan);

    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}