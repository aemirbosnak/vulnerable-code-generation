//FormAI DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
/*
    C File Synchronizer Example Program
    By [Your Name]
    
    This program is designed to synchronize two directories by copying any files from the 
    source directory that are not already in the destination directory. The program will 
    not delete any files from the destination directory, only copy over new files from the 
    source directory. 

    To use the program, run the executable with the following command line arguments:
    -source <source directory path> -destination <destination directory path>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 260 // Maximum length for Windows file paths

// Function to print an error message and exit the program
void fatalError(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Function to copy a file from the source directory to the destination directory
void copyFile(const char* srcPath, const char* dstPath) {
    FILE* srcFile = fopen(srcPath, "rb");
    FILE* dstFile = fopen(dstPath, "wb");
    
    if (!srcFile || !dstFile) {
        fatalError("Failed to open file for copying");
    }
    
    char buffer[4096];
    size_t bytesRead = 0;
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile))) {
        fwrite(buffer, 1, bytesRead, dstFile);
    }
    
    fclose(srcFile);
    fclose(dstFile);
}

// Function to recursively synchronize the source folder with the destination folder
void synchronizeFolders(const char* srcFolder, const char* dstFolder) {
    DIR* srcDir = opendir(srcFolder);
    struct dirent* file;
    
    if (!srcDir) {
        fatalError("Failed to open source directory");
    }
    
    while ((file = readdir(srcDir))) {
        if (!strcmp(file->d_name, ".") || !strcmp(file->d_name, "..")) {
            continue;
        }
        
        char srcPath[MAX_PATH_LENGTH];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcFolder, file->d_name);
        
        char dstPath[MAX_PATH_LENGTH];
        snprintf(dstPath, sizeof(dstPath), "%s/%s", dstFolder, file->d_name);
        
        if (file->d_type == DT_DIR) {
            // Recursively synchronize subdirectory
            synchronizeFolders(srcPath, dstPath);
        } else {
            // Check if file already exists in destination directory
            FILE* dstFile = fopen(dstPath, "rb");
            
            if (!dstFile) {
                // File does not exist, copy it over
                copyFile(srcPath, dstPath);
            } else {
                fclose(dstFile);
            }
        }
    }
    
    closedir(srcDir);
}

int main(int argc, char* argv[]) {
    char* srcFolderPath = NULL;
    char* dstFolderPath = NULL;
    
    // Parse command line arguments
    for (int i = 1; i < argc; i += 2) {
        if (!strcmp(argv[i], "-source")) {
            srcFolderPath = argv[i + 1];
        } else if (!strcmp(argv[i], "-destination")) {
            dstFolderPath = argv[i + 1];
        } else {
            fatalError("Invalid command line argument");
        }
    }
    
    if (!srcFolderPath || !dstFolderPath) {
        fatalError("Missing command line argument(s)");
    }
    
    // Synchronize folders
    synchronizeFolders(srcFolderPath, dstFolderPath);
    
    printf("File synchronization complete\n");
    
    return 0;
}