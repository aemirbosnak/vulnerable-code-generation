//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_PATH_LENGTH 1024
#define SIG_COUNT 3

const char *viruses[SIG_COUNT] = {"virus1_signature", "virus2_signature", "virus3_signature"};

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Cannot open file: %s\n", filename);
        return;
    }

    char *buffer = malloc(1024);
    size_t read_size;
    int found = 0;

    while ((read_size = fread(buffer, 1, 1024, file)) > 0) {
        for (int i = 0; i < SIG_COUNT; i++) {
            if (memmem(buffer, read_size, viruses[i], strlen(viruses[i])) != NULL) {
                printf("Virus detected in file: %s (signature: %s)\n", filename, viruses[i]);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    free(buffer);
    fclose(file);
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    struct stat file_info;
    DIR *directory = opendir(dir_path);

    if (!directory) {
        printf("Cannot open directory: %s\n", dir_path);
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (stat(full_path, &file_info) == 0) {
                if (S_ISDIR(file_info.st_mode)) {
                    scan_directory(full_path);  // Recursive scanning
                } else if (S_ISREG(file_info.st_mode)) {
                    scan_file(full_path);  // Scan the file
                }
            } else {
                printf("Could not retrieve stats for: %s\n", full_path);
            }
        }
    }

    closedir(directory);
}

void usage(const char *program_name) {
    printf("Usage: %s <directory>\n", program_name);
    printf("This program scans the specified directory for infected files based on known virus signatures.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *directory_path = argv[1];
    scan_directory(directory_path);
    printf("Scanning complete. Stay safe!\n");

    return EXIT_SUCCESS;
}