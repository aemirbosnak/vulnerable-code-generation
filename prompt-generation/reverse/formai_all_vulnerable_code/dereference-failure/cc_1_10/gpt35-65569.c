//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void printUsage() {
    printf("Usage: ./diskAnalyzer [directory path]\n");
}

void printError(char* message) {
    printf("Error: %s\n", message);
}

void analyzeDir(char* dirPath, int level, int* totalSize) {
    // Open directory
    DIR* dir = opendir(dirPath);
    if(!dir) {
        printError("Unable to open directory");
        return;
    }

    struct dirent* entry;
    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Create path string
        char path[strlen(dirPath) + strlen(entry->d_name) + 2]; // Plus 2 for slash and null terminator
        sprintf(path, "%s/%s", dirPath, entry->d_name);
        
        // Get file status
        struct stat s;
        if(stat(path, &s) != 0) {
            printError("Unable to get file status");
            continue;
        }

        // Print file info
        for(int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%d KB\t%s\n", s.st_size / 1024, entry->d_name);

        // Add size to total
        *totalSize += s.st_size;

        // Analyze subdirectories recursively
        if(S_ISDIR(s.st_mode)) {
            analyzeDir(path, level + 1, totalSize);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    // Check arguments
    if(argc <= 1) {
        printUsage();
        return 0;
    }

    // Get directory path
    char* dirPath = argv[1];

    // Check if directory exists
    struct stat s;
    if(stat(dirPath, &s) != 0) {
        printError("Directory does not exist");
        return 0;
    } else if(!S_ISDIR(s.st_mode)) {
        printError("Path is not a directory");
        return 0;
    }

    // Analyze directory
    int totalSize = 0;
    analyzeDir(dirPath, 0, &totalSize);

    // Print total size
    printf("Total size: %d KB\n", totalSize / 1024);

    return 0;
}