//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Function to get the size of a file
long int getFileSize(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

// Function to recursively calculate the size of a directory
long int dirSize(const char *path) {
    long int size = 0;
    DIR *d = opendir(path);
    if (d == NULL) {
        return -1;
    }
    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char newPath[strlen(path) + strlen(entry->d_name) + 2];
        sprintf(newPath, "%s/%s", path, entry->d_name);
        if (entry->d_type == DT_DIR) {
            size += dirSize(newPath);
        } else {
            size += getFileSize(newPath);
        }
    }
    closedir(d);
    return size;
}

int main() {
    char path[1024];
    printf("Enter the path to the directory you want to analyze: ");
    scanf("%s", path);

    long int size = dirSize(path);
    if (size == -1) {
        printf("Error: Could not calculate the size of the directory.\n");
    } else {
        printf("The size of the directory '%s' is %ld bytes.\n", path, size);
    }
    return 0;
}