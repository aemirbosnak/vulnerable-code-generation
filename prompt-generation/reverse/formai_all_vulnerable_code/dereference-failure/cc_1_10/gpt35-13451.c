//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH 256

int get_dir_size(char *path);
void print_usage();

int main(int argc, char *argv[]) {
    char path[MAX_PATH];
    
    if (argc < 2) {
        print_usage();
        return 1;
    }
    
    // Get path argument
    if (strlen(argv[1]) >= MAX_PATH) {
        printf("Error: Path too long\n");
        return 1;
    }
    strcpy(path, argv[1]);
    
    printf("Analyzing disk space usage in %s...\n", path);
    
    // Call function to get directory size
    int size = get_dir_size(path);
    if (size == -1) {
        printf("Error: Failed to get directory size\n");
        return 1;
    }
    
    // Convert size to human-readable format
    char size_human[16];
    if (size < 1024) {
        sprintf(size_human, "%d B", size);
    } else if (size < 1024*1024) {
        sprintf(size_human, "%.2f KB", size / 1024.0);
    } else if (size < 1024*1024*1024) {
        sprintf(size_human, "%.2f MB", size / (1024.0*1024));
    } else {
        sprintf(size_human, "%.2f GB", size / (1024.0*1024*1024));
    }
    
    printf("Total disk space used: %s\n", size_human);
    
    return 0;
}

int get_dir_size(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    int total_size = 0;
    
    // Open directory
    dir = opendir(path);
    if (!dir) {
        printf("Error: Failed to open directory\n");
        return -1;
    }
    
    // Loop through directory entries
    while ((entry = readdir(dir)) != NULL) {
        char sub_path[MAX_PATH];
        
        // Ignore "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Construct sub-path
        snprintf(sub_path, MAX_PATH, "%s/%s", path, entry->d_name);
        
        // Call stat() to get file info
        if (stat(sub_path, &file_stat) == -1) {
            printf("Error: Failed to get file info\n");
            return -1;
        }
        
        // Add file size to total size
        if (S_ISREG(file_stat.st_mode)) {
            total_size += file_stat.st_size;
        } else if (S_ISDIR(file_stat.st_mode)) {
            int sub_dir_size = get_dir_size(sub_path);
            if (sub_dir_size == -1) {
                return -1;
            }
            total_size += sub_dir_size;
        }
    }
    
    closedir(dir);
    
    return total_size;
}

void print_usage() {
    printf("Usage: disk-space-analyzer <path>\n");
}