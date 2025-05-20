//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MB 1048576 // 1 MB in bytes
#define GB 1073741824 // 1 GB in bytes

// Function to format file size to be more easily readable
char* formatSize(double size) {
    static char formattedSize[10];
    if (size < MB) {
        sprintf(formattedSize, "%.2f KB", size / 1024);
    }
    else if (size >= MB && size < GB) {
        sprintf(formattedSize, "%.2f MB", size / MB);
    }
    else {
        sprintf(formattedSize, "%.2f GB", size / GB);
    }
    return formattedSize;
}

// Function to recursively traverse all files and directories in a directory
double traverse(char* path) {
    double folderSize = 0;
    struct stat s;
    if (stat(path, &s) == 0) {
        if (s.st_mode & S_IFDIR) {
            DIR *dir;
            struct dirent *entry;
            if ((dir = opendir(path))) {
                while ((entry = readdir(dir)) != NULL) {
                    if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                        char newPath[strlen(path) + strlen(entry->d_name) + 2];
                        sprintf(newPath, "%s/%s", path, entry->d_name);
                        folderSize += traverse(newPath);
                    }
                }
                closedir(dir);
            }
        }
        else {
            folderSize += s.st_size;
        }
    }
    return folderSize;
}

int main() {
    char path[256];
    printf("Enter directory path: ");
    scanf("%s", path);

    double folderSize = traverse(path);

    printf("\n%s folder size: %s", path, formatSize(folderSize));
    return 0;
}