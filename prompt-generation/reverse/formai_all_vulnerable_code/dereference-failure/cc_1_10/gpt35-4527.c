//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>

void analyzeDirectory(const char* directoryPath, const int indentationLevel);

bool analyzeFile(const char* filePath);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s [directory path]\n", argv[0]);
        return 1;
    }

    const char* directoryPath = argv[1];
    analyzeDirectory(directoryPath, 0);

    return 0;
}

void analyzeDirectory(const char* directoryPath, const int indentationLevel) {
    DIR* directory = opendir(directoryPath);
    if (directory == NULL) {
        printf("Error opening directory %s\n", directoryPath);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(directory)) != NULL) {
        const char* entryName = entry->d_name;
        if (entryName[0] == '.') {
            continue; // skip hidden files and directories
        }

        char entryPath[1024];
        snprintf(entryPath, sizeof(entryPath), "%s/%s", directoryPath, entryName);

        struct stat entryStat;
        if (lstat(entryPath, &entryStat) == -1) {
            printf("Error getting file stats for %s\n", entryPath);
            continue;
        }

        if (S_ISDIR(entryStat.st_mode)) {
            // print directory name
            printf("%*s- %s/\n", indentationLevel * 4, "", entryName);

            // recursively analyze subdirectory
            analyzeDirectory(entryPath, indentationLevel + 1);
        } else if (S_ISREG(entryStat.st_mode)) {
            // analyze regular file
            bool success = analyzeFile(entryPath);
            if (!success) {
                printf("%*s- %s\n", indentationLevel * 4, "", entryName);
            }
        } else {
            printf("%*s- %s [unknown type]\n", indentationLevel * 4, "", entryName);
        }
    }

    closedir(directory);
}

bool analyzeFile(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filePath);
        return false;
    }

    // get file size
    fseek(file, 0L, SEEK_END);
    long fileSize = ftell(file);
    fclose(file);

    // print file name and size
    printf("%s (%ld bytes)\n", filePath, fileSize);

    return true;
}