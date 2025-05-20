//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define SIGNATURE_COUNT 3
#define MAX_PATH_LENGTH 1024

const char* signatures[SIGNATURE_COUNT] = {
    "malware_signature1",
    "malware_signature2",
    "malware_signature3"
};

// Function to check for malware signatures in a file
int check_file_for_signatures(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0; // Could not open file
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (strstr(line, signatures[i])) {
                fclose(file);
                return 1; // Signature found
            }
        }
    }

    fclose(file);
    return 0; // No signatures found
}

// Recursive function to traverse directories and check for malware
void scan_directory(const char* directory) {
    struct dirent *entry;
    struct stat entry_stat;
    char path[MAX_PATH_LENGTH];

    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("opendir failed");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directories
        }

        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
        if (stat(path, &entry_stat) == -1) {
            perror("stat failed");
            continue;
        }

        if (S_ISDIR(entry_stat.st_mode)) {
            // It's a directory, recurse into it
            scan_directory(path);
        } else if (S_ISREG(entry_stat.st_mode)) {
            // It's a file, check for signatures
            if (check_file_for_signatures(path)) {
                printf("Malware signature found in: %s\n", path);
            } else {
                printf("No malware found in: %s\n", path);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}