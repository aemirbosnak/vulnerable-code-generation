//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// Function to convert file size from bytes to human-readable format
void humanReadableSize(double size, char *buf) {
    int i = 0;
    char *units[] = {"B", "KB", "MB", "GB", "TB"};

    while (size > 1024 && i < 4) {
        size /= 1024;
        i++;
    }

    sprintf(buf, "%.2f %s", size, units[i]);
}

// Function to recursively scan the directory and its subdirectories
void scanDirectory(char *dirPath, double *totalSize) {
    DIR *dir = opendir(dirPath);
    struct dirent *dirEntry;
    struct stat fileStat;
    char filePath[250];
    
    if (!dir) {
        printf("Error: Could not open directory %s\n", dirPath);
        return;
    }
    
    while ((dirEntry = readdir(dir)) != NULL) {
        if ((strcmp(dirEntry->d_name, ".") == 0) | (strcmp(dirEntry->d_name, "..") == 0)) {
            continue;
        }
        
        sprintf(filePath, "%s/%s", dirPath, dirEntry->d_name);
        
        if (stat(filePath, &fileStat) < 0) {
            printf("Error: Could not stat file %s\n", filePath);
            continue;
        }
        
        if (S_ISREG(fileStat.st_mode)) {
	    // Increment the totalSize variable with the size of the file
            *totalSize += (double) fileStat.st_size;
        } else if (S_ISDIR(fileStat.st_mode)) {
	    // Recursively scan the subdirectory
            scanDirectory(filePath, totalSize);
        }
    }
    
    closedir(dir);
}

int main() {
    double totalSize = 0.0;
    char buf[20];
    
    // Change this line to the path of the directory you want to analyze
    char dirPath[] = "/home/user/Documents";
    
    scanDirectory(dirPath, &totalSize);
    humanReadableSize(totalSize, buf);

    printf("Total disk space used by %s: %s\n", dirPath, buf);
    
    return 0;
}