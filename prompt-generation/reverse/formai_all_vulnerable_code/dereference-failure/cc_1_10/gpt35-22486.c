//FormAI DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to get the size of a file
long int getFileSize(char *filename) {
    FILE *file;
    long int size;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }
    
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fclose(file);
    
    return size;
}

// Function to check if a file exists
int fileExists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to copy a file from source directory to destination directory
int copyFile(char *srcFile, char *destDir) {
    char destFile[300];
    
    // Get the filename from the source path
    char *filename = strrchr(srcFile, '/');
    if (filename == NULL) {
        filename = srcFile;
    } else {
        filename = filename + 1;
    }
    
    // Create the destination file path
    snprintf(destFile, sizeof(destFile), "%s/%s", destDir, filename);
    
    // Check if the destination file already exists
    if (fileExists(destFile)) {
        long int srcSize = getFileSize(srcFile);
        long int destSize = getFileSize(destFile);
        
        // Check if the file sizes differ
        if (srcSize == destSize) {
            return 0;
        }
    }
    
    // Open the source and destination files
    FILE *src = fopen(srcFile, "r");
    FILE *dest = fopen(destFile, "w");
    
    // Copy the contents of the source file to the destination file
    char buffer[1024];
    size_t size;
    while((size = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, size, dest);
    }
    
    // Close the files
    fclose(src);
    fclose(dest);
    
    return 1;
}

// Recursive function to synchronize the files in two directories
int syncDirs(char *srcDir, char *destDir) {
    DIR *src;
    struct dirent *srcDirEntry;
    
    // Open the source directory
    src = opendir(srcDir);
    if (src == NULL) {
        printf("Error: Could not open source directory.\n");
        return -1;
    }
    
    // Synchronize the files and subdirectories in the source directory 
    while((srcDirEntry = readdir(src))) {
        if (srcDirEntry->d_name[0] == '.') {
        	// Ignore hidden files and directories
            continue;
        }
        
        // Get the source file path
        char srcPath[300];
        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, srcDirEntry->d_name);
        
        if (srcDirEntry->d_type == DT_DIR) {
            // If a directory, recursively synchronize its contents
            char destPath[300];
            snprintf(destPath, sizeof(destPath), "%s/%s", destDir, srcDirEntry->d_name);
            
            // Check if the destination directory exists, create it if not
            if (!fileExists(destPath)) {
                mkdir(destPath, 0777);
            }
            
            syncDirs(srcPath, destPath);
        } else {
            // If a file, copy it to the destination directory
            copyFile(srcPath, destDir);
        }
    }
    
    // Close the directory
    closedir(src);
    
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return 0;
    }
    
    syncDirs(argv[1], argv[2]);
    
    printf("Files synchronized successfully.\n");
    
    return 0;
}