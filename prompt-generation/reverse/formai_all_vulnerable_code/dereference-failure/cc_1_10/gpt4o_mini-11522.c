//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define SIGNATURE_COUNT 3
#define BUFFER_SIZE 1024

const char *signatures[SIGNATURE_COUNT] = {
    "malware_signature_1",
    "malware_signature_2",
    "malware_signature_3"
};

void scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    int found = 0;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        for (int i = 0; i < SIGNATURE_COUNT; i++) {
            if (strstr(buffer, signatures[i]) != NULL) {
                printf("Warning: Signature '%s' found in file: %s\n", signatures[i], filepath);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    fclose(file);

    if (!found) {
        printf("File is clean: %s\n", filepath);
    }
}

void scan_directory(const char *dirpath) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(dirpath);

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char filepath[PATH_MAX];
        snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);

        if (stat(filepath, &file_stat) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            scan_directory(filepath); // Recursive scan for directories
        } else {
            scan_file(filepath); // Scan the file
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