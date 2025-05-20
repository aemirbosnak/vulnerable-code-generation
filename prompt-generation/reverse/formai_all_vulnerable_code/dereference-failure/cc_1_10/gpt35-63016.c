//FormAI DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

// Function to copy file contents
void copyFile(char* srcPath, char* destPath){
    FILE* srcFile;
    FILE* destFile;
    char buffer[1024];

    // Open source and destination file
    srcFile = fopen(srcPath, "r");
    destFile = fopen(destPath, "w");

    // Copy content of source file to destination file
    while(fread(buffer, 1, sizeof(buffer), srcFile) > 0){
        fwrite(buffer, 1, sizeof(buffer), destFile);
    }

    // Close files
    fclose(srcFile);
    fclose(destFile);
}

// Function to copy a directory recursively
void copyDirectory(char* srcPath, char* destPath){
    DIR* dir;
    struct dirent *ent;
    struct stat st;

    // Open source directory
    dir = opendir(srcPath);
    if(dir == NULL){
        perror("");
        exit(EXIT_FAILURE);
    }

    // If destination directory does not exist create it
    if(stat(destPath, &st) == -1){
        mkdir(destPath, 0700);
    }

    // Copy files and directories recursively
    while((ent = readdir(dir)) != NULL){
        // Ignore "." and ".." directories
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0){
            continue;
        }

        char srcFilePath[1024];
        char destFilePath[1024];
        sprintf(srcFilePath, "%s/%s", srcPath, ent->d_name);
        sprintf(destFilePath, "%s/%s", destPath, ent->d_name);

        // If this is a directory copy it recursively
        if(ent->d_type == DT_DIR){
            copyDirectory(srcFilePath, destFilePath);
        } else {
            // Otherwise copy the file
            copyFile(srcFilePath, destFilePath);
        }
    }

    // Close directory
    closedir(dir);
}

int main(int argc, char* argv[]){
    // Check for correct number of arguments
    if(argc != 3){
        printf("Usage: %s <source directory> <destination directory>", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Copy directories recursively
    copyDirectory(argv[1], argv[2]);

    printf("Directories synchronized successfully.\n");

    return 0;
}