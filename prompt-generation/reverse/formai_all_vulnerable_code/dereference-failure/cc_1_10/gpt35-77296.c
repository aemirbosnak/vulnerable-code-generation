//FormAI DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 256
#define BUF_SIZE 1024

// function to check if a file is a directory
int isDir(char* path) {
    struct stat stats;
    if(stat(path, &stats) == 0 && S_ISDIR(stats.st_mode))
        return 1;
    else
        return 0;
}

// function to copy a file
void copyFile(char* src, char* dest) {
    int fdIn, fdOut, numRead;
    char buf[BUF_SIZE];
    
    fdIn = open(src, O_RDONLY);
    if(fdIn == -1) {
        printf("\nError: Unable to open source file '%s'\n", src);
        exit(1);
    }
    
    fdOut = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fdOut == -1) {
        printf("\nError: Unable to create/open destination file '%s'\n", dest);
        exit(1);
    }
    
    while((numRead = read(fdIn, buf, BUF_SIZE)) > 0)
        write(fdOut, buf, numRead);
    
    close(fdIn);
    close(fdOut);
}

// function to synchronize a directory recursively
void syncDir(char* src, char* dest) {
    DIR* dir;
    struct dirent* ent;
    char srcPath[MAX_PATH_LEN], destPath[MAX_PATH_LEN];
    
    if(isDir(dest) == 0)
        mkdir(dest, 0777);
    
    if((dir = opendir(src)) != NULL) {
        while((ent = readdir(dir)) != NULL) {
            if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;
            
            snprintf(srcPath, MAX_PATH_LEN, "%s/%s", src, ent->d_name);
            snprintf(destPath, MAX_PATH_LEN, "%s/%s", dest, ent->d_name);
            
            if(isDir(srcPath) == 1)
                syncDir(srcPath, destPath);
            else
                copyFile(srcPath, destPath);
        }
        
        closedir(dir);
    } else {
        printf("\nError: Unable to open directory '%s'\n", src);
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    // check that we have at least two arguments
    if(argc < 3) {
        printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(1);
    }
    
    // sync the directories
    syncDir(argv[1], argv[2]);
    
    printf("Directories synchronized successfully!\n");
    
    return 0;
}