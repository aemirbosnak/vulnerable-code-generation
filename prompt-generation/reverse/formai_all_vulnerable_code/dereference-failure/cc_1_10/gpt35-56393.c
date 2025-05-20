//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>

#define GB_UNIT 1073741824.0        // convert bytes to GB

/* Function prototypes */
bool isDirectory(const char* path);     // check if a path is a directory
double getDirSize(const char* path);    // get the size of a directory recursively
void printDirSizes(const char* path);   // print the size of all subdirectories of a path

/* Main function */
int main(int argc, char** argv) {
    char* path = ".";       // default to current directory if no argument is given
    if (argc > 1)
        path = argv[1];

    printf("Disk usage of \"%s\":\n", path);
    printDirSizes(path);

    return 0;
}

/* Check if a path is a directory */
bool isDirectory(const char* path) {
    struct stat fileStat;
    if (stat(path, &fileStat) == -1)
        return false;
    return S_ISDIR(fileStat.st_mode);
}

/* Get the size of a directory recursively */
double getDirSize(const char* path) {
    double size = 0;

    DIR* dir = opendir(path);
    if (dir == NULL)
        return size;

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.')     // ignore hidden files and directories
            continue;

        char subpath[1024];
        snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);
        if (isDirectory(subpath))       // if subpath is a directory, recursively get its size
            size += getDirSize(subpath);
        else {                          // if subpath is a file, add its size to the total
            struct stat fileStat;
            if (stat(subpath, &fileStat) == -1)
                continue;
            size += fileStat.st_size;
        }
    }

    closedir(dir);
    return size;
}

/* Print the size of all subdirectories of a path */
void printDirSizes(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL)
        return;

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.')     // ignore hidden files and directories
            continue;

        char subpath[1024];
        snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);
        if (isDirectory(subpath)) {
            double size = getDirSize(subpath);
            printf("%-30s %.2f GB\n", subpath, size / GB_UNIT);
        }
    }

    closedir(dir);
}