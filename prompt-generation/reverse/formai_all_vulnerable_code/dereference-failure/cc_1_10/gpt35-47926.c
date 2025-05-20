//FormAI DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

// Function to check if a file or directory exists
bool doesExist(const char* filePath) {
    struct stat fileStat;
    return (stat(filePath, &fileStat) == 0);
}

// Function to recursively copy files from source to destination directory
void copyDirectory(const char* srcDir, const char* destDir) {
    DIR* dir = opendir(srcDir);
    
    // Create destination directory if it does not exist
    if (!doesExist(destDir)) {
        mkdir(destDir, 0777);
    }
    
    // Loop through all files and directories in source directory
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char srcPath[1000];
        strcpy(srcPath, srcDir);
        strcat(srcPath, "/");
        strcat(srcPath, entry->d_name);
        
        char destPath[1000];
        strcpy(destPath, destDir);
        strcat(destPath, "/");
        strcat(destPath, entry->d_name);
        
        // If the file or directory in the source directory is a directory, recursively call copyDirectory function
        if (entry->d_type == DT_DIR) {
            copyDirectory(srcPath, destPath);
        }
        // If the file or directory in the source directory is a file, copy it to the destination directory
        else if (entry->d_type == DT_REG) {
            FILE* srcFile = fopen(srcPath, "rb");
            FILE* destFile = fopen(destPath, "wb");
            if (srcFile != NULL && destFile != NULL) {
                char buffer[1000];
                int bytes;
                while ((bytes = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
                    fwrite(buffer, 1, bytes, destFile);
                }
            }
            fclose(srcFile);
            fclose(destFile);
        }
    }
    closedir(dir);
}

// Function to synchronize two directories
void syncDirectories(const char* srcDir, const char* destDir) {
    // Copy files and directories from source to destination directory
    copyDirectory(srcDir, destDir);
    
    // Delete files and directories from destination directory that do not exist in source directory
    DIR* dir = opendir(destDir);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char destPath[1000];
        strcpy(destPath, destDir);
        strcat(destPath, "/");
        strcat(destPath, entry->d_name);
        
        char srcPath[1000];
        strcpy(srcPath, srcDir);
        strcat(srcPath, "/");
        strcat(srcPath, entry->d_name);
        
        // If a file or directory exists in destination directory but not in source directory, delete it
        if (!doesExist(srcPath)) {
            if (entry->d_type == DT_DIR) {
                rmdir(destPath);
            }
            else if (entry->d_type == DT_REG) {
                remove(destPath);
            }
        }
    }
    closedir(dir);
}

int main() {
    syncDirectories("src_dir", "dest_dir");
    printf("Directories synchronized successfully.\n");
    return 0;
}