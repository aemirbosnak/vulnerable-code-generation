//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME 256
#define SIGNATURES_SIZE 3
#define BUFFER_SIZE 1024

char *virus_signatures[SIGNATURES_SIZE] = {
    "VIRUS_SIGNATURE_1",
    "VIRUS_SIGNATURE_2",
    "VIRUS_SIGNATURE_3"
};

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    int found = 0;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (int i = 0; i < SIGNATURES_SIZE; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                printf("Virus signature found in file: %s\n", filename);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    fclose(file);
}

void scan_directory(const char *dir_name) {
    DIR *dir = opendir(dir_name);
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    struct dirent *entry;
    char file_path[MAX_FILENAME];

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_REG) {  // Check if entry is a regular file
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
            scan_file(file_path);
        } else if (entry->d_type == DT_DIR) {  // Check if entry is a directory
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);
                scan_directory(file_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);

    return EXIT_SUCCESS;
}