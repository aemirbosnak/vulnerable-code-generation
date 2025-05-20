//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define SIGNATURE_LENGTH 10

// Array of sample virus signatures (just as examples)
const char *virus_signatures[] = {
    "VIRUS1SIGN",
    "VIRUS2SIGN",
    "VIRUS3SIGN",
    NULL
};

void scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    unsigned char buffer[100];
    size_t bytes_read;
    int found = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; virus_signatures[i] != NULL; i++) {
            if (strstr((const char *)buffer, virus_signatures[i]) != NULL) {
                printf("Virus found in file: %s - Signature: %s\n", filepath, virus_signatures[i]);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (found == 0) {
        printf("No viruses found in file: %s\n", filepath);
    }
    fclose(file);
}

void scan_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            char filepath[MAX_PATH];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            scan_file(filepath);
        } else if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char subdir[MAX_PATH];
                snprintf(subdir, sizeof(subdir), "%s/%s", directory, entry->d_name);
                scan_directory(subdir);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Scanning directory: %s\n", argv[1]);
    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}