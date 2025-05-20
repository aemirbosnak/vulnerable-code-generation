//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void analyze_directory(char *path, int depth);

int main(int argc, char *argv[]) {
    // Check if path is provided as argument
    if (argc < 2) {
        printf("Please provide path to analyze!\n");
        return 1;
    }
    
    // Ensure provided path exists and is a directory
    char *path = argv[1];
    struct stat s;
    if (stat(path, &s) == -1) {
        printf("Provided path does not exist!\n");
        return 1;
    }
    if (!(s.st_mode & S_IFDIR)) {
        printf("Provided path is not a directory!\n");
        return 1;
    }
    
    // Start analysis
    printf("Starting analysis of %s\n", path);
    analyze_directory(path, 0);
    
    return 0;
}

void analyze_directory(char *path, int depth) {
    // Initialize variables
    DIR *dir;
    struct dirent *entry;
    struct stat s;
    char filepath[1024];
    unsigned long long total_size = 0;
    
    // Open directory and loop through files
    if (!(dir = opendir(path))) {
        printf("Could not open directory %s\n", path);
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        // Ignore current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        // Prepare filepath to file/directory
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
        
        // Get information about file/directory
        if (stat(filepath, &s) == -1) {
            printf("Could not get information about file/directory %s\n", filepath);
            continue;
        }
        
        // Handle directories by analyzing recursively
        if (s.st_mode & S_IFDIR) {
            analyze_directory(filepath, depth+1);
            total_size += s.st_size;
        }
        // Handle files by adding to total_size
        else {
            total_size += s.st_size;
        }
    }
    closedir(dir);
    
    // Print results of directory analysis
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s - %llu bytes\n", path, total_size);
}