//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void copy_file(const char *src, const char *dst) {
    FILE *sourceFile = fopen(src, "rb");
    FILE *destFile = fopen(dst, "wb");
    
    if (sourceFile == NULL || destFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
}

int file_exists(const char *filepath) {
    struct stat buffer;
    return (stat(filepath, &buffer) == 0);
}

int files_are_different(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");

    if (!f1 || !f2) {
        fclose(f1);
        fclose(f2);
        return 1; // if any file doesn't exist, consider them different
    }

    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    size_t bytesRead1, bytesRead2;

    while (1) {
        bytesRead1 = fread(buffer1, 1, BUFFER_SIZE, f1);
        bytesRead2 = fread(buffer2, 1, BUFFER_SIZE, f2);

        if (bytesRead1 != bytesRead2) {
            fclose(f1);
            fclose(f2);
            return 1; // files are different
        }

        if (bytesRead1 == 0) {
            break; // end of both files
        }

        if (memcmp(buffer1, buffer2, bytesRead1) != 0) {
            fclose(f1);
            fclose(f2);
            return 1; // files are different
        }
    }

    fclose(f1);
    fclose(f2);
    return 0; // files are the same
}

void sync_directories(const char *srcDir, const char *dstDir) {
    DIR *dir = opendir(srcDir);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char srcPath[PATH_MAX];
            char dstPath[PATH_MAX];

            snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
            snprintf(dstPath, sizeof(dstPath), "%s/%s", dstDir, entry->d_name);

            if (entry->d_type == DT_REG) { // Regular file
                if (!file_exists(dstPath) || files_are_different(srcPath, dstPath)) {
                    printf("Copying: %s to %s\n", srcPath, dstPath);
                    copy_file(srcPath, dstPath);
                }
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *sourceDirectory = argv[1];
    const char *destinationDirectory = argv[2];

    sync_directories(sourceDirectory, destinationDirectory);

    printf("Synchronization completed from %s to %s.\n", sourceDirectory, destinationDirectory);
    return 0;
}