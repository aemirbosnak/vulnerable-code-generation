//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to check if file A is newer than file B
int isNewer(const char *fileA, const char *fileB) {
    struct stat statA, statB;
    if (stat(fileA, &statA) == -1 || stat(fileB, &statB) == -1) return 0;
    return (statA.st_mtime > statB.st_mtime);
}

// Function to copy file A to file B
void copyFile(const char *src, const char *dest) {
    FILE *sourceFile = fopen(src, "rb");
    FILE *destFile = fopen(dest, "wb");
    if (!sourceFile || !destFile) {
        perror("File open error");
        return;
    }
    char buffer[8192];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytes, destFile);
    }
    fclose(sourceFile);
    fclose(destFile);
}

// Function to synchronize directories
void syncDirectories(const char *srcDir, const char *destDir) {
    struct dirent *entry;
    DIR *d = opendir(srcDir);
    if (!d) {
        perror("Directory open error");
        return;
    }

    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) 
            continue;

        char srcPath[1024], destPath[1024];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Directory - synchronize recursively
            mkdir(destPath, 0755); // Create destination directory
            syncDirectories(srcPath, destPath);
        } else {
            // File - synchronize
            if (access(destPath, F_OK) != -1) {
                // Destination file exists
                if (isNewer(srcPath, destPath)) {
                    printf("Updating file: %s -> %s\n", srcPath, destPath);
                    copyFile(srcPath, destPath);
                }
            } else {
                // Destination file doesn't exist
                printf("Copying new file: %s -> %s\n", srcPath, destPath);
                copyFile(srcPath, destPath);
            }
        }
    }
    closedir(d);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Check existence of source directory
    struct stat srcStat;
    if (stat(argv[1], &srcStat) == -1 || !S_ISDIR(srcStat.st_mode)) {
        fprintf(stderr, "Error: Source directory does not exist or is not a directory.\n");
        return EXIT_FAILURE;
    }

    // Create destination directory if it doesn't exist
    struct stat destStat;
    if (stat(argv[2], &destStat) == -1) {
        if (mkdir(argv[2], 0755) == -1) {
            perror("Failed to create destination directory");
            return EXIT_FAILURE;
        }
    }

    // Start synchronization
    syncDirectories(argv[1], argv[2]);
    printf("Synchronization completed.\n");
    return EXIT_SUCCESS;
}