//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define ONE_GB (1024 * 1024 * 1024)
#define ONE_MB (1024 * 1024)

long long total_size = 0;

void analyze_directory(char *current_dir, int depth) {
    if (depth > 3) {
        // We only want to traverse up to a maximum of 3 subdirectories
        return;
    }
    
    DIR *dirp = opendir(current_dir);
    if (!dirp) {
        printf("Unable to open directory %s\n", current_dir);
        return;
    }
    
    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            // Skip the current directory and the parent directory
            continue;
        }
        
        char path[1000];
        snprintf(path, sizeof(path), "%s/%s", current_dir, dp->d_name);
        
        struct stat file_stat;
        if (lstat(path, &file_stat) == -1) {
            printf("Unable to get information for %s\n", path);
            continue;
        }
        
        if (S_ISDIR(file_stat.st_mode)) {
            // Recurse into this directory
            analyze_directory(path, depth + 1);
        } else {
            // Add the file size to the total size
            total_size += file_stat.st_size;
        }
    }
    
    closedir(dirp);
}

int main() {
    analyze_directory(".", 0);
    
    printf("Total disk usage: %.2f GB (%lld bytes)\n", (double)total_size / ONE_GB, total_size);
    
    if (total_size > 200 * ONE_MB) {
        printf("Warning: Current directory is using more than 200 MB of disk space!\n");
    }
    
    return 0;
}