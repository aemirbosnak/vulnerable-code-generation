//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

// Global variable to keep track of total disk space
long long int total_disk_space = 0;

// Function to convert bytes to readable string format
char* bytes_to_string(long long int bytes) {
    char *buffer = malloc(20);
    const char *suffixes[] = {"B", "KB", "MB", "GB", "TB"};
    int suffix_index = 0;
    double size = bytes;
    
    while (size > 1024 && suffix_index < 4) {
        size /= 1024;
        suffix_index++;
    }
    
    snprintf(buffer, 20, "%.2f %s", size, suffixes[suffix_index]);
    return buffer;
}

// Function to analyze disk space of a directory and its subdirectories
void analyze_directory(char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat file_stat;
    char *fullpath;
    
    if (!dir) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        
        fullpath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(fullpath, "%s/%s", path, entry->d_name);
        
        if (lstat(fullpath, &file_stat) < 0) {
            perror("lstat");
            free(fullpath);
            continue;
        }
        
        if (S_ISDIR(file_stat.st_mode)) {
            analyze_directory(fullpath); // Recursive call to analyze subdirectory
        } else {
            total_disk_space += file_stat.st_size; // Add size of file to total disk space
        }
        
        free(fullpath);
    }
    
    closedir(dir);
}

int main() {
    char directory[256];
    printf("Enter the path of the directory to analyze: ");
    fgets(directory, sizeof(directory), stdin);
    directory[strcspn(directory, "\n")] = '\0'; // Remove trailing newline character
    
    analyze_directory(directory);
    
    printf("Total disk space used by directory '%s': %s\n", directory, bytes_to_string(total_disk_space));
    
    return 0;
}