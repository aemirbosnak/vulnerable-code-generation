//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_SIGNATURES 10
#define MAX_FILENAME 256
#define MAX_PATH 512
#define SIGNATURE_LENGTH 32

// Example virus signatures
const char *virus_signatures[MAX_SIGNATURES] = {
    "malicious_code_1",
    "virus_example_2",
    "dangerous_payload_3",
    "malware_signature_4",
    "trojan_code_5",
    "spyware_bit_6",
    "ransomware_marker_7",
    "adware_string_8",
    "worm_signature_9",
    "rootkit_identifier_10"
};

// Function to check if a file contains any virus signatures
int contains_virus(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Unable to open file");
        return 0; // Assume no virus if we can't open the file
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                fclose(file);
                return 1; // Virus signature found
            }
        }
    }

    fclose(file);
    return 0; // No virus signatures found
}

// Function to scan a directory for files
void scan_directory(const char *dirpath) {
    DIR *dir = opendir(dirpath);
    struct dirent *entry;

    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullpath[MAX_PATH];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", dirpath, entry->d_name);

        struct stat statbuf;
        if (stat(fullpath, &statbuf) == -1) {
            perror("Unable to get file status");
            continue;
        }

        // If it's a directory, scan it recursively
        if (S_ISDIR(statbuf.st_mode)) {
            scan_directory(fullpath);
        } else {
            if (contains_virus(fullpath)) {
                printf("Virus detected in file: %s\n", fullpath);
            } else {
                printf("No virus found in file: %s\n", fullpath);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];

    printf("Starting virus scan in directory: %s\n", directory_path);
    scan_directory(directory_path);
    printf("Virus scan completed.\n");

    return EXIT_SUCCESS;
}