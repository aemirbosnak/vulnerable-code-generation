//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/*
 * This program analyzes the disk space in the C drive by recursively
 * traversing all directories and files and calculating their sizes.
 * It outputs the total size of each directory and the size of individual
 * files on the console.
 */

void printSize(double size, char* unit) {
    printf("%.2f %s\n", size, unit);
}

void analyzeDirSize(char* dirPath, int depth) {
    DIR* dir;
    struct dirent* entry;
    struct stat fileStat;
    double fileSize = 0, dirSize = 0;
    char* filePath;
    
    // Open the directory
    dir = opendir(dirPath);
    if (dir == NULL) {
        printf("Unable to open directory %s\n", dirPath);
        return;
    }
    
    // Traverse all files and subdirectories in the directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Get the full path of the file or subdirectory
        filePath = malloc(strlen(dirPath) + strlen(entry->d_name) + 2);
        sprintf(filePath, "%s/%s", dirPath, entry->d_name);
        
        // Get the stats of the file or subdirectory
        if (stat(filePath, &fileStat) == -1) {
            printf("Unable to read file stats for %s\n", filePath);
            free(filePath);
            continue;
        }
        
        if (S_ISDIR(fileStat.st_mode)) {
            // Analyze the subdirectory recursively
            analyzeDirSize(filePath, depth + 1);
            // Add the size of the subdirectory to the total directory size
            dirSize += fileSize;
        } else if (S_ISREG(fileStat.st_mode)) {
            // Add the size of the file to the total file size
            fileSize += fileStat.st_size;
            // Print the size of the file with appropriate unit
            printf("%*c%s: ", depth * 4, ' ', entry->d_name);
            if (fileSize < 1024) {
                printSize(fileSize, "bytes");
            } else if (fileSize < 1048576) {
                printSize(fileSize / 1024, "KB");
            } else if (fileSize < 1073741824) {
                printSize(fileSize / 1048576, "MB");
            } else {
                printSize(fileSize / 1073741824, "GB");
            }
        }
        
        free(filePath);
    }
    
    // Print the size of the directory with appropriate unit
    printf("%*c%s\\: ", depth * 4, ' ', dirPath);
    if (dirSize < 1024) {
        printSize(dirSize, "bytes");
    } else if (dirSize < 1048576) {
        printSize(dirSize / 1024, "KB");
    } else if (dirSize < 1073741824) {
        printSize(dirSize / 1048576, "MB");
    } else {
        printSize(dirSize / 1073741824, "GB");
    }
    
    closedir(dir);
}

int main() {
    char* cDrivePath = "C:";
    analyzeDirSize(cDrivePath, 0);
    return 0;
}