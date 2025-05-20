//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define SIGNATURE_COUNT 5

const char *signatures[SIGNATURE_COUNT] = {
    "malware_signature1",
    "virus_signature2",
    "trojan_signature3",
    "ransomware_signature4",
    "spyware_signature5"
};

void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char buffer[512];
    size_t bytes_read;
    int found = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (memmem(buffer, bytes_read, signatures[i], strlen(signatures[i])) != NULL) {
                printf("Warning: Malware signature detected in %s\n", file_path);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    fclose(file);
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat file_stat;
    char full_path[MAX_PATH];

    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (stat(full_path, &file_stat) == -1) {
            perror("Could not stat file");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            scan_directory(full_path);
        } else if (S_ISREG(file_stat.st_mode)) {
            scan_file(full_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting scan in directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    printf("Scan completed.\n");

    return EXIT_SUCCESS;
}