//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/*
 * This program analyzes the disk space usage of a given directory and 
 * its subdirectories. It displays the total size for each subdirectory 
 * as well as the grand total for the entire directory.
 * 
 * To use this program, simply input the path to the directory you want 
 * to analyze when prompted.
 */

// Global variables for tracking directory sizes
long int folderTotalSize = 0;
long int grandTotalSize = 0;

// Recursive function to analyze disk space usage in a folder and its subfolders
void analyzeFolder(char path[]) {

    DIR *dir;
    struct dirent *ent;
    struct stat fileStat;
    long int folderSize = 0;

    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            char filePath[1024];
            sprintf(filePath, "%s/%s", path, ent->d_name);
            stat(filePath, &fileStat);
            if (S_ISDIR(fileStat.st_mode)) {
                if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                    continue;
                }
                analyzeFolder(filePath);
                folderSize += folderTotalSize;
            } else {
                folderSize += fileStat.st_size;
            }
        }
        closedir(dir);
        printf("\nTotal size of \"%s\": %ld bytes\n", path, folderSize);
        folderTotalSize = folderSize;
        grandTotalSize += folderSize;
    }
}

int main() {

    char path[1024];
    printf("Enter the path of the directory to analyze: ");
    fgets(path, 1024, stdin);
    path[strcspn(path, "\n")] = 0; // Remove trailing newline

    analyzeFolder(path);
    printf("\nGrand total: %ld bytes\n", grandTotalSize);
    
    return 0;
}