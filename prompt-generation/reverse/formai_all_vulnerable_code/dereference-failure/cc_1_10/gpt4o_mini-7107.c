//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH 512
#define MAX_KEYWORDS 5
#define BUFFER_SIZE 1024

const char *malicious_keywords[MAX_KEYWORDS] = {
    "virus",
    "malware",
    "trojan",
    "spyware",
    "ransomware"
};

// Function to check if the file contains any malicious keywords
int check_file_for_keywords(const char *filepath) {
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Error opening file");
        return 0; // Assume file is clean if it cannot be opened
    }

    char buffer[BUFFER_SIZE];
    int found = 0;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        for (int i = 0; i < MAX_KEYWORDS; i++) {
            if (strstr(buffer, malicious_keywords[i])) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    fclose(file);
    return found;
}

// Function to scan a directory for files
void scan_directory(const char *dirpath) {
    DIR *dir = opendir(dirpath);
    struct dirent *entry;

    if (!dir) {
        perror("Error opening directory");
        return;
    }

    printf("Scanning directory: %s\n", dirpath);

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char filepath[MAX_PATH];
        snprintf(filepath, sizeof(filepath), "%s/%s", dirpath, entry->d_name);

        if (entry->d_type == DT_REG) {
            // Regular file, check for malicious content
            printf("Checking file: %s\n", filepath);
            if (check_file_for_keywords(filepath)) {
                printf("WARNING: Malicious content found in %s!\n", filepath);
            } else {
                printf("File %s is clean.\n", filepath);
            }
        } else if (entry->d_type == DT_DIR) {
            // Directory, scan recursively
            scan_directory(filepath);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dirpath = argv[1];
    scan_directory(dirpath);

    return EXIT_SUCCESS;
}