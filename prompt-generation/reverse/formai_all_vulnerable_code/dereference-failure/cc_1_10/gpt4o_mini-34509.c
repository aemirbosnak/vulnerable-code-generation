//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_VIRUS_SIGNS 5

const char *virus_signatures[MAX_VIRUS_SIGNS] = {
    "malicious_code_segment_1",
    "malicious_code_segment_2",
    "infected_segment_xyz",
    "suspicious_activity",
    "disallowed_code"
};

void scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[1024];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < MAX_VIRUS_SIGNS; i++) {
            if (strstr(buffer, virus_signatures[i]) != NULL) {
                printf("Virus signature found in file: %s\n", filepath);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    fclose(file);
}

void scan_directory(const char *dirpath) {
    DIR *dir = opendir(dirpath);
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dirpath, entry->d_name);

        struct stat path_stat;
        stat(full_path, &path_stat);

        if (S_ISDIR(path_stat.st_mode)) {
            // Recursively scan subdirectories
            scan_directory(full_path);
        } else if (S_ISREG(path_stat.st_mode)) {
            // Scan regular files
            scan_file(full_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory = argv[1];
    scan_directory(directory);
    printf("Scan complete!\n");

    return EXIT_SUCCESS;
}