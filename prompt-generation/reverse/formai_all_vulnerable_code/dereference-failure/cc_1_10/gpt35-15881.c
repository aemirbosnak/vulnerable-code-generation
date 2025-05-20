//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define constants for byte sizes
#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)

// Define a struct to hold file information
typedef struct {
    char* name;
    char* path;
    double size;
} FileInfo;

// Function to calculate the size of a file or directory
double calculateSize(char* path) {
    struct stat fileStat;
    if (stat(path, &fileStat) < 0) {
        perror("Error with file/directory stat");
        exit(EXIT_FAILURE);
    }

    if (S_ISDIR(fileStat.st_mode)) {
        DIR* dir = opendir(path);
        if (dir == NULL) {
            perror("Error opening directory");
            exit(EXIT_FAILURE);
        }

        double size = 0;
        struct dirent* item;
        while ((item = readdir(dir)) != NULL) {
            if (strcmp(item->d_name, ".") == 0 || strcmp(item->d_name, "..") == 0) {
                continue;
            }

            char* childPath = malloc(strlen(path) + strlen(item->d_name) + 2);
            sprintf(childPath, "%s/%s", path, item->d_name);
            size += calculateSize(childPath);
            free(childPath);
        }
        closedir(dir);
        return size;
    } else {
        return (double) fileStat.st_size;
    }
}

// Function to sort FileInfo array by size
int compareFileSizes(const void* a, const void* b) {
    const FileInfo* fa = *(FileInfo**) a;
    const FileInfo* fb = *(FileInfo**) b;

    if (fa->size < fb->size) {
        return 1;
    } else if (fa->size > fb->size) {
        return -1;
    } else {
        return 0;
    }
}

// Main program entry point
int main(int argc, char* argv[]) {
    // Handle command line arguments
    char* path;
    if (argc < 2) {
        path = ".";
    } else {
        path = argv[1];
    }

    // Calculate disk usage for specified path and all subdirectories
    double totalSize = calculateSize(path);
    printf("Total Size: %.2f GB\n", totalSize / GB);

    // Get file information for all files and directories
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    FileInfo** files = malloc(sizeof(FileInfo*) * 100);
    int numFiles = 0;

    struct dirent* item;
    while ((item = readdir(dir)) != NULL) {
        if (strcmp(item->d_name, ".") == 0 || strcmp(item->d_name, "..") == 0) {
            continue;
        }

        char* childPath = malloc(strlen(path) + strlen(item->d_name) + 2);
        sprintf(childPath, "%s/%s", path, item->d_name);

        FileInfo* file = malloc(sizeof(FileInfo));
        file->name = strdup(item->d_name);
        file->path = childPath;
        file->size = calculateSize(childPath);

        files[numFiles++] = file;

        if (numFiles % 100 == 0) {
            files = realloc(files, sizeof(FileInfo*) * (numFiles + 100));
        }
    }
    closedir(dir);

    // Sort files by size
    qsort(files, numFiles, sizeof(FileInfo*), compareFileSizes);

    // Print out file information
    for (int i = 0; i < numFiles; i++) {
        double size = files[i]->size;
        char* unit = "B";
        if (size >= GB) {
            size /= GB;
            unit = "GB";
        } else if (size >= MB) {
            size /= MB;
            unit = "MB";
        } else if (size >= KB) {
            size /= KB;
            unit = "KB";
        }

        printf("%s - %.2f %s\n", files[i]->path, size, unit);

        free(files[i]->name);
        free(files[i]->path);
        free(files[i]);
    }
    free(files);

    return 0;
}