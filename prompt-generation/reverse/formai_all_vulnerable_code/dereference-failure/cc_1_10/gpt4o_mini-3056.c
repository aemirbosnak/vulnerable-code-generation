//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void traverseDirectory(const char *dirPath, int depth);
void printIndentation(int depth);
int countFilesAndDirectories(const char *dirPath);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    
    printf("Traversing directory: %s\n\n", directoryPath);
    traverseDirectory(directoryPath, 0);
    
    int totalCount = countFilesAndDirectories(directoryPath);
    printf("\nTotal files and directories: %d\n", totalCount);

    return EXIT_SUCCESS;
}

void traverseDirectory(const char *dirPath, int depth) {
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    char subPath[PATH_MAX];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printIndentation(depth);
            printf("%s\n", entry->d_name);
            snprintf(subPath, sizeof(subPath), "%s/%s", dirPath, entry->d_name);

            // If it is a directory, recursively traverse it
            if (entry->d_type == DT_DIR) {
                traverseDirectory(subPath, depth + 1);
            } else if (entry->d_type == DT_REG) {
                // Handle regular files if needed
                continue;
            }
        }
    }

    closedir(dir);
}

void printIndentation(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("    "); // Print spaces for each depth level
    }
}

int countFilesAndDirectories(const char *dirPath) {
    int count = 0;
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        perror("opendir");
        return count;
    }

    struct dirent *entry;
    char subPath[PATH_MAX];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            count++; // Count the current entry
            snprintf(subPath, sizeof(subPath), "%s/%s", dirPath, entry->d_name);
            
            if (entry->d_type == DT_DIR) {
                count += countFilesAndDirectories(subPath); // Recursively count in the subdirectory
            }
        }
    }

    closedir(dir);
    return count;
}