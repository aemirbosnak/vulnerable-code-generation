//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

#define BLOCK_SIZE 512
#define MAX_FILES 100
#define FILENAME_LENGTH 256

typedef struct {
    char name[FILENAME_LENGTH];
    long size;
} FileInfo;

void scanDisk(char *path, FileInfo *files, int *fileCount);
void recoverFile(const char *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *directory = argv[1];
    FileInfo files[MAX_FILES];
    int fileCount = 0;

    // Scan the specified directory
    scanDisk(directory, files, &fileCount);

    if (fileCount == 0) {
        printf("No recoverable files found.\n");
        return EXIT_SUCCESS;
    }

    // Display recoverable files
    printf("Recoverable files found:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%d: %s (Size: %ld bytes)\n", i + 1, files[i].name, files[i].size);
    }

    // Prompt user for files to recover
    printf("Enter the number of the file to recover (0 to exit): ");
    int choice;
    while (scanf("%d", &choice) && choice != 0) {
        if (choice < 1 || choice > fileCount) {
            printf("Invalid choice. Try again: ");
            continue;
        }
        recoverFile(files[choice - 1].name);
        printf("Enter the number of the file to recover (0 to exit): ");
    }

    return EXIT_SUCCESS;
}

void scanDisk(char *path, FileInfo *files, int *fileCount) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullPath[FILENAME_LENGTH];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        
        // Check if the entry is a regular file
        if (entry->d_type == DT_REG) {
            // Get file size
            int fd = open(fullPath, O_RDONLY);
            if (fd == -1) {
                perror("open");
                continue;
            }
            long fileSize = lseek(fd, 0, SEEK_END);
            close(fd);

            // Store file info
            strncpy(files[*fileCount].name, fullPath, FILENAME_LENGTH);
            files[*fileCount].size = fileSize;
            (*fileCount)++;

            if (*fileCount >= MAX_FILES) {
                break;
            }
        }
    }
    closedir(dir);
}

void recoverFile(const char *filename) {
    char outputName[FILENAME_LENGTH];
    snprintf(outputName, sizeof(outputName), "recovered_%s", strrchr(filename, '/') + 1);

    FILE *srcFile = fopen(filename, "rb");
    if (!srcFile) {
        perror("fopen");
        return;
    }

    FILE *destFile = fopen(outputName, "wb");
    if (!destFile) {
        perror("fopen");
        fclose(srcFile);
        return;
    }

    char buffer[BLOCK_SIZE];
    size_t bytesRead;
    
    printf("Recovering file: %s to %s\n", filename, outputName);
    while ((bytesRead = fread(buffer, 1, BLOCK_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    // Clean up
    fclose(srcFile);
    fclose(destFile);
    printf("Recovery complete.\n");
}