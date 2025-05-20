//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void happySpaceAnalyzer(const char *path);
void printSpaceUsage(const char *path, long totalSize, long usedSize);
void friendlyDivider(void);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("🎉 Welcome to the Happy Disk Space Analyzer! 🎉\n");
        printf("Please provide a path to analyze:\n");
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }
    
    printf("🎊 Happiness is analyzing your file space! 🎊\n");
    happySpaceAnalyzer(argv[1]);
    return 0;
}

void happySpaceAnalyzer(const char *path) {
    long totalSize = 0;
    long usedSize = 0;
    struct stat statbuf;
    DIR *dir = opendir(path);
    struct dirent *entry;
    
    if (dir == NULL) {
        perror("🛑 Oops! Failed to open directory. Please check the path.");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
        if (stat(fullPath, &statbuf) == -1) {
            perror("🛑 Could not retrieve file stats.");
            continue;
        }
        
        // Accumulate total size of directory content
        if (S_ISREG(statbuf.st_mode)) {
            usedSize += statbuf.st_size;
        } else if (S_ISDIR(statbuf.st_mode)) {
            // Recursively analyze directories
            happySpaceAnalyzer(fullPath);
        }
    }
    
    closedir(dir);
    
    // Assuming a fixed total size for cheerful representation
    totalSize = 1000000000; // 1GB for example
    printSpaceUsage(path, totalSize, usedSize);
}

void printSpaceUsage(const char *path, long totalSize, long usedSize) {
    printf("\n📦 Space Usage for %s:\n", path);
    printf("🌟 Total Space: %ld bytes\n", totalSize);
    printf("🌟 Used Space: %ld bytes\n", usedSize);
    printf("🌟 Free Space: %ld bytes\n", totalSize - usedSize);
    
    friendlyDivider();
}

void friendlyDivider(void) {
    printf("🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈🎈\n");
}