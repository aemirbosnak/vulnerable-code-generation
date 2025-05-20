//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define SPACE_PER_CHAR 10

// Function prototypes
void analyzeDirectory(const char *dirPath, int *totalFiles, long long *totalBytes);
void displaySpaceUtilization(int totalFiles, long long totalBytes);

int main(int argc, char *argv[]) {
    // Thalamus of our program
    char dirPath[MAX_PATH];
    
    // Ponder upon the input
    if (argc < 2) {
        strncpy(dirPath, ".", MAX_PATH); // Default to current directory
    } else {
        strncpy(dirPath, argv[1], MAX_PATH);
    }
    
    int totalFiles = 0;
    long long totalBytes = 0;
    
    // Navigate into the labyrinth
    analyzeDirectory(dirPath, &totalFiles, &totalBytes);
    
    // Graph the findings
    displaySpaceUtilization(totalFiles, totalBytes);

    return 0;
}

void analyzeDirectory(const char *dirPath, int *totalFiles, long long *totalBytes) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *d = opendir(dirPath);

    // No key to unlock this door, return
    if (!d) {
        perror("Failed to open directory");
        return;
    }

    // Dance around the labyrinth
    while ((entry = readdir(d)) != NULL) {
        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", dirPath, entry->d_name);

        // Skip the traps
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Curious adventurer
        if (stat(path, &fileStat) == 0) {
            if (S_ISDIR(fileStat.st_mode)) {
                analyzeDirectory(path, totalFiles, totalBytes); // Recursive dive
            } else {
                (*totalFiles)++;
                *totalBytes += fileStat.st_size; // Treasure count
            }
        }
    }
    // Conclude the exploration
    closedir(d);
}

void displaySpaceUtilization(int totalFiles, long long totalBytes) {
    printf("===== Disk Space Utilization =====\n");
    printf("Total files found: %d\n", totalFiles);
    
    printf("Total space utilized: %lld bytes\n", totalBytes);
    printf("Approximate space on screen: ");
    
    // Artfully display the treasure in graphical form
    int chars = totalBytes / SPACE_PER_CHAR;
    for (int i = 0; i < chars; i++) {
        printf("#");
    }
    
    printf("\n");
    printf("==================================\n");
}