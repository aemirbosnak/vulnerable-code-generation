//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void printSpace(int size, const char *path) {
    printf("🎉 Disk space used by '%s': %d bytes\n", path, size);
}

int getDirectorySize(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    int totalSize = 0;

    if (!(dir = opendir(path))) {
        perror("Couldn't open directory");
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (stat(fullPath, &fileStat) == 0) {
                if (S_ISDIR(fileStat.st_mode)) {
                    // Recursively get size of directories
                    totalSize += getDirectorySize(fullPath);
                } else {
                    // Add size of files
                    totalSize += fileStat.st_size;
                }
            } else {
                perror("File stat error");
            }
        }
    }

    closedir(dir);
    printSpace(totalSize, path);
    return totalSize;
}

void analyzeDiskSpace(const char *startPath) {
    printf("\n💖 Analyzing disk space from: '%s' 💖\n", startPath);
    int totalSize = getDirectorySize(startPath);
    printf("\n✨ Total space used in '%s': %d bytes ✨\n", startPath, totalSize);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("🌟 Please provide a directory path to analyze! 🌟\n");
        return EXIT_FAILURE;
    }

    analyzeDiskSpace(argv[1]);

    printf("\n🎈 Thank you for using this Disk Space Analyzer! 🎈\n");
    return EXIT_SUCCESS;
}