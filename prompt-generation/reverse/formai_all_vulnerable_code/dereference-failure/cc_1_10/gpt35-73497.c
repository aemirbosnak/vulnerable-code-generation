//FormAI DATASET v1.0 Category: File Synchronizer ; Style: brave
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>

// Define the maximum length for file names and file paths
#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_PATH_LENGTH 512

// Define the buffer size for file reading and writing
#define BUFFER_SIZE 4096

// Function to check if the path is a directory or not
bool is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

// Function to synchronize files from the source directory to the target directory
void synchronize_directories(const char *source_directory, const char *target_directory) {
    DIR *source_dir = opendir(source_directory);
    DIR *target_dir = opendir(target_directory);
    
    // Check if both directories are open correctly
    if (source_dir == NULL || target_dir == NULL) {
        printf("Failed to open directories\n");
        return;
    }
    
    struct dirent *source_dirent;
    struct dirent *target_dirent;
    
    // Iterate through the files in the source directory
    while ((source_dirent = readdir(source_dir)) != NULL) {
        // Skip the '.' and '..' directories
        if (strcmp(source_dirent->d_name, ".") == 0 || strcmp(source_dirent->d_name, "..") == 0) {
            continue;
        }
        
        char source_filepath[MAX_FILE_PATH_LENGTH];
        snprintf(source_filepath, MAX_FILE_PATH_LENGTH, "%s/%s", source_directory, source_dirent->d_name);
        
        char target_filepath[MAX_FILE_PATH_LENGTH];
        snprintf(target_filepath, MAX_FILE_PATH_LENGTH, "%s/%s", target_directory, source_dirent->d_name);
        
        // Check if the file exists in the target directory
        target_dirent = NULL;
        rewinddir(target_dir);
        while ((target_dirent = readdir(target_dir)) != NULL) {
            if (strcmp(source_dirent->d_name, target_dirent->d_name) == 0) {
                break;
            }
        }
        
        if (target_dirent == NULL) {
            // File does not exist in target directory, so copy it over
            FILE *source_file = fopen(source_filepath, "rb");
            FILE *target_file = fopen(target_filepath, "wb");
            
            // Check if both files open correctly
            if (source_file == NULL || target_file == NULL) {
                printf("Failed to open files\n");
                return;
            }
            
            char buffer[BUFFER_SIZE];
            size_t n;
            while ((n = fread(buffer, 1, sizeof(buffer), source_file))) {
                fwrite(buffer, 1, n, target_file);
            }
            
            printf("Copied %s to %s\n", source_filepath, target_filepath);
            
            fclose(source_file);
            fclose(target_file);
        } else {
            // File exists in target directory, so compare their modification times
            char target_filepath[MAX_FILE_PATH_LENGTH];
            snprintf(target_filepath, MAX_FILE_PATH_LENGTH, "%s/%s", target_directory, target_dirent->d_name);
            
            struct stat source_stat, target_stat;
            stat(source_filepath, &source_stat);
            stat(target_filepath, &target_stat);
            
            if (difftime(source_stat.st_mtime, target_stat.st_mtime) > 0) {
                // Source file is more recent than target file, so copy it over
                FILE *source_file = fopen(source_filepath, "rb");
                FILE *target_file = fopen(target_filepath, "wb");
                
                // Check if both files open correctly
                if (source_file == NULL || target_file == NULL) {
                    printf("Failed to open files\n");
                    return;
                }
                
                char buffer[BUFFER_SIZE];
                size_t n;
                while ((n = fread(buffer, 1, sizeof(buffer), source_file))) {
                    fwrite(buffer, 1, n, target_file);
                }
                
                printf("Updated %s in %s\n", source_dirent->d_name, target_directory);
                
                fclose(source_file);
                fclose(target_file);
            }
        }
    }
    
    // Close the directories
    closedir(source_dir);
    closedir(target_dir);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s source_directory target_directory\n", argv[0]);
        return 0;
    }
    
    if (!is_directory(argv[1]) || !is_directory(argv[2])) {
        printf("Both source and target directories must exist\n");
        return 0;
    }
    
    synchronize_directories(argv[1], argv[2]);
    
    return 0;
}