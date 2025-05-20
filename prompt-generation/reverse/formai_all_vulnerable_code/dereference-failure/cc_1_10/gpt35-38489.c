//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// function to get the size of a file in bytes
long long getFileSize(const char* filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return (long long)st.st_size;
    }
    return -1;
}

// function to get the size of a directory and its subdirectories in bytes
long long getFolderSize(const char* path) {
    DIR* dir;
    struct dirent* entry;
    struct stat st;
    long long totalSize = 0;
    char fullPath[1024];

    dir = opendir(path);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        sprintf(fullPath, "%s/%s", path, entry->d_name);
        if (stat(fullPath, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                totalSize += getFolderSize(fullPath);
            } else if (S_ISREG(st.st_mode)) {
                totalSize += getFileSize(fullPath);
            }
        }
    }
    closedir(dir);
    return totalSize;
}

// function to format bytes as a human-readable string
void formatBytes(long long bytes, char* buffer) {
    const char* suffixes[] = { "B", "KB", "MB", "GB", "TB" };
    int suffixIndex = 0;

    while (bytes > 1024 && suffixIndex < 4) {
        bytes /= 1024;
        suffixIndex++;
    }

    sprintf(buffer, "%lld %s", bytes, suffixes[suffixIndex]);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    long long totalSize = getFolderSize(argv[1]);
    char formattedSize[32];
    formatBytes(totalSize, formattedSize);

    printf("Total size of \"%s\": %s\n", argv[1], formattedSize);

    return 0;
}