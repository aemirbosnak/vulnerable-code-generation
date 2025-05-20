//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

// Structure to hold disk space information
typedef struct {
    char *path;
    unsigned long long size;
} DiskInfo;

// Function to compare DiskInfo structures by size
int compareDiskInfo(const void *a, const void *b) {
    const DiskInfo *da = (const DiskInfo *)a;
    const DiskInfo *db = (const DiskInfo *)b;
    return da->size - db->size;
}

// Function to get the size of a directory
unsigned long long getDirSize(const char *path) {
    unsigned long long size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *newPath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(newPath, path);
        strcat(newPath, "/");
        strcat(newPath, entry->d_name);
        if (entry->d_type == DT_DIR) {
            size += getDirSize(newPath);
        } else {
            FILE *file = fopen(newPath, "r");
            if (file != NULL) {
                fseek(file, 0, SEEK_END);
                size += ftell(file);
                fclose(file);
            }
        }
        free(newPath);
    }
    closedir(dir);
    return size;
}

// Function to get the disk space information for a directory
DiskInfo *getDiskInfo(const char *path) {
    DiskInfo *info = malloc(sizeof(DiskInfo));
    info->path = malloc(strlen(path) + 1);
    strcpy(info->path, path);
    info->size = getDirSize(path);
    return info;
}

// Main function
int main(int argc, char **argv) {
    // Check if the user provided a path
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the disk space information for the specified path
    DiskInfo *info = getDiskInfo(argv[1]);

    // Sort the disk space information by size
    qsort(info, 1, sizeof(DiskInfo), compareDiskInfo);

    // Print the disk space information
    printf("Directory: %s\n", info->path);
    printf("Size: %llu bytes\n", info->size);

    // Free the memory allocated for the disk space information
    free(info->path);
    free(info);

    return EXIT_SUCCESS;
}