//FormAI DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_SIZE 1024

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to synchronize the contents of two directories
void sync_dirs(const char *dir1, const char *dir2) {
    DIR *d1, *d2;
    struct dirent *dir_entry;
    char path1[MAX_SIZE], path2[MAX_SIZE], new_path1[MAX_SIZE], new_path2[MAX_SIZE];
    
    // Open the two directories
    d1 = opendir(dir1);
    d2 = opendir(dir2);
    
    // Loop through all entries in dir1
    while ((dir_entry = readdir(d1)) != NULL) {
        // Ignore . and ..
        if (strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
            // Construct paths for this file in both directories
            sprintf(path1, "%s/%s", dir1, dir_entry->d_name);
            sprintf(path2, "%s/%s", dir2, dir_entry->d_name);
            
            // Check if this is a directory
            if (dir_entry->d_type == DT_DIR) {
                // Check if this directory exists in dir2
                if (!file_exists(path2)) {
                    // If it doesn't exist, create it
                    mkdir(path2, S_IRWXU | S_IRWXG | S_IRWXO);
                }
                
                // Recursively synchronize the contents of this directory
                sync_dirs(path1, path2);
            } else {
                // Check if this file exists in dir2
                if (!file_exists(path2)) {
                    // If it doesn't exist, copy it
                    sprintf(new_path2, "%s/%s", dir2, dir_entry->d_name);
                    symlink(path1, new_path2);
                } else {
                    // If it does exist, compare modification times
                    struct stat stat1, stat2;
                    
                    stat(path1, &stat1);
                    stat(path2, &stat2);
                    
                    // If the file in dir1 is newer, copy it
                    if (stat1.st_mtime > stat2.st_mtime) {
                        sprintf(new_path2, "%s/%s", dir2, dir_entry->d_name);
                        symlink(path1, new_path2);
                    }
                    
                    // If the file in dir2 is newer, copy it
                    if (stat2.st_mtime > stat1.st_mtime) {
                        sprintf(new_path1, "%s/%s", dir1, dir_entry->d_name);
                        symlink(path2, new_path1);
                    }
                }
            }
        }
    }
    
    // Close the directories
    closedir(d1);
    closedir(d2);
}

int main() {
    // Synchronize the contents of two directories
    sync_dirs("/dir1", "/dir2");
    
    return 0;
}