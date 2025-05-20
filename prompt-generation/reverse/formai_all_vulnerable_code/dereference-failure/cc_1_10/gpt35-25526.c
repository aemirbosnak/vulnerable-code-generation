//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
/* Romeo and Juliet's Disk Space Analyzer */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to convert bytes to human-readable format
char* humanize(long long bytes) {
    char* sizes[] = {"Bytes", "KB", "MB", "GB", "TB"};
    int sizeIndex = 0;
    double doubleBytes = (double)bytes;
    
    while (doubleBytes >= 1024 && sizeIndex < 5) {
        sizeIndex++;
        doubleBytes /= 1024;
    }
    
    size_t len = snprintf(NULL, 0, "%.2f %s", doubleBytes, sizes[sizeIndex]);
    char* humanized = malloc(len + 1);
    snprintf(humanized, len + 1, "%.2f %s", doubleBytes, sizes[sizeIndex]);
    
    return humanized;   
}

// Function to recursively traverse through directories and calculate disk space usage
long long calculateDiskUsage(char* path) {
    long long totalSize = 0;
    DIR* directory = opendir(path);
    struct dirent* entry;
    
    while ((entry = readdir(directory)) != NULL) {
        struct stat statbuf;
        char entryPath[1024];
        sprintf(entryPath, "%s/%s", path, entry->d_name);
        
        if (stat(entryPath, &statbuf) != -1) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                // Ignore "." and ".." directories
                continue;
            }
            
            if (S_ISDIR(statbuf.st_mode)) {
                // If entry is a directory, recursively call the function to calculate its size
                long long size = calculateDiskUsage(entryPath);
                totalSize += size;
            } else {
                // If entry is a file, add its size to total size
                totalSize += statbuf.st_size;
            }
        }
    }
    
    closedir(directory);
    
    printf("Oh, cruel disk! Why must thou store so much?\n");
    printf("From %s, we have collected %s of data.\n", path, humanize(totalSize));
    printf("Wherefore art thou, disk space?\n\n");

    return totalSize;
}

int main() {
    char path[1024];
    printf("My bounty is as boundless as the sea, my love as deep; \n");
    printf("the more I give to thee, the more I have, for both are infinite.\n\n");
    printf("Please enter the directory you would like to analyze: ");
    scanf("%s", path);
    
    long long totalSize = calculateDiskUsage(path);
    
    printf("Good night, good night! Parting is such sweet sorrow, \n");
    printf("that I shall say good night till it be morrow.\n");
    printf("The total disk space used by %s is %s.\n", path, humanize(totalSize));
    
    return 0;
}