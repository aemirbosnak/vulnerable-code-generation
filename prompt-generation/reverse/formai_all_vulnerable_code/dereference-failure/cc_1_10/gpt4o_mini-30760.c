//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void createDirectory(const char *path) {
    // Create directory if it doesn't exist
    mkdir(path, 0755);
}

int copyFile(const char *source, const char *destination) {
    FILE *src, *dest;
    char buffer[1024];
    size_t bytesRead, bytesWritten;

    src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return -1;
    }

    dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return -1;
    }

    // Copy file content
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        bytesWritten = fwrite(buffer, 1, bytesRead, dest);
        if (bytesWritten < bytesRead) {
            perror("Error writing to destination file");
            fclose(src);
            fclose(dest);
            return -1;
        }
    }

    fclose(src);
    fclose(dest);
    return 0;
}

void backupFiles(const char *source, const char *destination) {
    struct stat statbuf;
    DIR *dir;
    struct dirent *entry;

    // Check if the source is a directory
    if (stat(source, &statbuf) == -1) {
        perror("Error accessing source");
        return;
    }

    if (S_ISDIR(statbuf.st_mode)) {
        // Create destination directory
        createDirectory(destination);

        // Open source directory
        dir = opendir(source);
        if (dir == NULL) {
            perror("Error opening source directory");
            return;
        }

        // Process each entry in the directory
        while ((entry = readdir(dir)) != NULL) {
            // Skip '.' and '..' entries
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char srcPath[1024], destPath[1024];

                // Create full path for source and destination
                snprintf(srcPath, sizeof(srcPath), "%s/%s", source, entry->d_name);
                snprintf(destPath, sizeof(destPath), "%s/%s", destination, entry->d_name);

                // Recur for directories or copy for files
                if (stat(srcPath, &statbuf) == 0) {
                    if (S_ISDIR(statbuf.st_mode)) {
                        backupFiles(srcPath, destPath); // recurse into subdirectory
                    } else {
                        if (copyFile(srcPath, destPath) == -1) {
                            fprintf(stderr, "Failed to copy file: %s to %s\n", srcPath, destPath);
                        }
                    }
                }
            }
        }
        closedir(dir);
    } else if (S_ISREG(statbuf.st_mode)) {
        // If it's a regular file, copy it directly
        if (copyFile(source, destination) == -1) {
            fprintf(stderr, "Failed to copy file: %s to %s\n", source, destination);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *sourceDir = argv[1];
    const char *destDir = argv[2];

    // Start the backup process
    backupFiles(sourceDir, destDir);

    printf("Backup from '%s' to '%s' completed successfully.\n", sourceDir, destDir);
    return EXIT_SUCCESS;
}