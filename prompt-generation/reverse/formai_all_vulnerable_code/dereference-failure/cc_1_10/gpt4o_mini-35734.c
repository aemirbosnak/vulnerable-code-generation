//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define SIGNATURE_COUNT 3
#define BUFFER_SIZE 1024

// List of virus signatures (keywords)
const char *virus_signatures[SIGNATURE_COUNT] = {
    "VIRUS_PAYLOAD_1",
    "MALICIOUS_CODE_2",
    "DANGEROUS_SCRIPT_3"
};

// Function to check for signatures in a given file
int check_file_for_viruses(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open file");
        return -1; // Error opening file
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (strstr(buffer, virus_signatures[i])) {
                printf("Virus signature '%s' found in file: %s\n", virus_signatures[i], filepath);
                fclose(file);
                return 1; // Virus found
            }
        }
    }

    fclose(file);
    return 0; // No virus found
}

// Function to scan files in a given directory
void scan_directory(const char *dirpath) {
    DIR *dir = opendir(dirpath);
    if (!dir) {
        perror("Failed to open directory");
        return; // Error opening directory
    }

    struct dirent *entry;
    char filepath[MAX_PATH];

    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);

        // Check if the entry is a directory
        struct stat statbuf;
        if (stat(filepath, &statbuf) == -1) {
            perror("Failed to get file stats");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            // Recursive call for directories
            scan_directory(filepath);
        } else {
            // Assume it's a file and check for viruses
            int result = check_file_for_viruses(filepath);
            if (result == -1) {
                printf("Error checking file: %s\n", filepath);
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

    printf("Scanning directory: %s for viruses...\n", argv[1]);
    scan_directory(argv[1]);

    printf("Scan complete!\n");
    return EXIT_SUCCESS;
}