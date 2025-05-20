//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define SIGNATURE_COUNT 3
#define BUFFER_SIZE 4096

const char *malware_signatures[SIGNATURE_COUNT] = {
    "MaliciousCode1",
    "VirusSignature2",
    "TrojanThreat3"
};

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int found = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (memmem(buffer, bytes_read, malware_signatures[i], strlen(malware_signatures[i])) != NULL) {
                printf("Malware detected! Signature: %s in file: %s\n", malware_signatures[i], file_path);
                found = 1;
                break; // Stop searching after finding a signature
            }
        }
        if (found) break;
    }

    fclose(file);
}

void scan_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    char full_path[MAX_PATH];

    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        struct stat path_stat;
        stat(full_path, &path_stat);

        if (S_ISDIR(path_stat.st_mode)) {
            scan_directory(full_path); // Recursively scan sub-directories
        } else {
            scan_file(full_path); // Scan file for malware
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    printf("Scanning completed.\n");
    return EXIT_SUCCESS;
}