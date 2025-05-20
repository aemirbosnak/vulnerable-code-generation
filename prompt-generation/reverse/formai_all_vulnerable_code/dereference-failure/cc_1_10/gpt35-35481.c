//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void printErrorMessage(const char* message) {
    printf("Error: %s\n", message);
}

void analyzeDirectory(const char* directory) {
    printf("\nAnalyzing directory: %s\n", directory);
    DIR* dir = opendir(directory);
    if (!dir) {
        printErrorMessage("Failed to open directory");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {  // if entry is a directory
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;  // skip current and parent directory
            }
            char newDirectory[1000];
            sprintf(newDirectory, "%s/%s", directory, entry->d_name);
            analyzeDirectory(newDirectory);  // recursively analyze subdirectory
        } else {  // if entry is a file
            struct stat fileStat;
            char filePath[1000];
            sprintf(filePath, "%s/%s", directory, entry->d_name);
            if (lstat(filePath, &fileStat) < 0) {
                printErrorMessage("Failed to get file stats");
                continue;
            }
            printf("%s\t%ld bytes\n", filePath, fileStat.st_size);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printErrorMessage("Directory argument is missing");
        return 1;
    }
    const char* directory = argv[1];

    analyzeDirectory(directory);
    return 0;
}