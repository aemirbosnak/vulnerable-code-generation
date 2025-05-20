//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Structure to hold file information
typedef struct {
    char name[256];
    off_t size;
} FileInfo;

// Function to compare FileInfo by size for sorting
int compareFileInfo(const void *a, const void *b) {
    return ((FileInfo *)b)->size - ((FileInfo *)a)->size; // Sort in descending order
}

// Function to analyze disk space usage of a given directory
void analyzeDiskSpace(const char *dirPath, FileInfo *files, int *fileCount, off_t *totalSize) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    if ((dir = opendir(dirPath)) == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[512];
        
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", dirPath, entry->d_name);

            if (stat(path, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode)) {
                    // Recursive call for directories
                    analyzeDiskSpace(path, files, fileCount, totalSize);
                } else {
                    // Storing file information
                    strcpy(files[*fileCount].name, path);
                    files[*fileCount].size = statbuf.st_size;
                    *totalSize += statbuf.st_size;
                    (*fileCount)++;
                }
            } else {
                perror("Failed to get file status");
            }
        }
    }
    closedir(dir);
}

// Function to print file information
void printFileInfo(FileInfo *files, int fileCount, off_t totalSize) {
    printf("\n--- Disk Space Usage Analysis ---\n");
    printf("Total size: %lld bytes\n", (long long)totalSize);
    printf("Files:\n");

    for (int i = 0; i < fileCount; ++i) {
        printf("%s - %lld bytes\n", files[i].name, (long long)files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileInfo files[1000] = {0}; // Adjust size as needed
    int fileCount = 0;
    off_t totalSize = 0;

    analyzeDiskSpace(argv[1], files, &fileCount, &totalSize);

    // Sort the files array by size
    qsort(files, fileCount, sizeof(FileInfo), compareFileInfo);

    // Print file information
    printFileInfo(files, fileCount, totalSize);

    return EXIT_SUCCESS;
}