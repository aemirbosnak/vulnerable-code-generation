//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <dirent.h>
#include <string.h>

// Function to scan a file for viruses
void scanFile(char *filename) {
    printf("Scanning %s...\n", filename);
    // Add virus scanning logic here
}

// Function to scan a directory for potential viruses
void scanDirectory(char *path) {
    DIR *directory;
    struct dirent *entry;

    directory = opendir(path);
    if (directory == NULL) {
        printf("Error opening directory %s\n", path);
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Ignore parent and current directories
            if (strcmp(entry->d_name, ".") == 0 ||
                strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // Recursively scan subdirectories
            char new_path[1024];
            sprintf(new_path, "%s/%s", path, entry->d_name);
            scanDirectory(new_path);
        }
        else {
            scanFile(entry->d_name);
        }
    }

    closedir(directory);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory to scan>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    printf("Scanning directory %s...\n", path);
    scanDirectory(path);

    printf("Scan complete.\n");

    return 0;
}