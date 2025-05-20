//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_SIGNATURES 10
#define SIGNATURE_LENGTH 16
#define BUFFER_SIZE 1024

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

int check_file_for_viruses(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("File opening failed");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t signature_length = SIGNATURE_LENGTH;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (bytes_read < signature_length) {
                continue; // Not enough data to compare
            }
            // Search for a virus signature in the buffer
            if (memmem(buffer, bytes_read, virus_signatures[i], signature_length)) {
                fclose(file);
                return i; // Return the index of the infected signature
            }
        }
    }

    fclose(file);
    return -1; // No viruses found
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("opendir failed");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it is a regular file
            char file_path[256];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

            int result = check_file_for_viruses(file_path);
            if (result != -1) {
                printf("Virus detected in file: %s -> Signature: %s\n", file_path, virus_signatures[result]);
            } else {
                printf("No virus found in file: %s\n", file_path);
            }
        } else if (entry->d_type == DT_DIR) {
            // Skip directories (handled by scan_directory)
            continue;
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting scan on directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed.\n");

    return EXIT_SUCCESS;
}