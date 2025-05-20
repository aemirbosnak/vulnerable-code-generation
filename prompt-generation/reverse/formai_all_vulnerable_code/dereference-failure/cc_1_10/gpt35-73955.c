//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void syncFiles(const char* srcPath, const char* destPath) {
    DIR* sourceDir = opendir(srcPath);
    DIR* destDir = opendir(destPath);
    
    if (sourceDir == NULL) {
        printf("Error: Failed to open source directory %s\n", srcPath);
        return;
    }
    
    if (destDir == NULL) {
        printf("Error: Failed to open destination directory %s\n", destPath);
        return;
    }
    
    printf("--- Starting file synchronization ---\n");
    
    struct dirent* sourceEnt;
    
    while ((sourceEnt = readdir(sourceDir)) != NULL) {
        if (strcmp(sourceEnt->d_name, ".") == 0 || strcmp(sourceEnt->d_name, "..") == 0) {
            continue;
        }
        
        char srcFile[1024], destFile[1024];
        snprintf(srcFile, sizeof(srcFile), "%s/%s", srcPath, sourceEnt->d_name);
        snprintf(destFile, sizeof(destFile), "%s/%s", destPath, sourceEnt->d_name);
        
        struct stat srcStat, destStat;
        if (stat(srcFile, &srcStat) == -1) {
            printf("Error: Failed to get stat for source file %s\n", srcFile);
            continue;
        }
        
        if (stat(destFile, &destStat) != -1) {
            if (srcStat.st_mtime <= destStat.st_mtime) {
                printf("%s is up to date\n", srcFile);
                continue;
            }
        }
        
        if (S_ISDIR(srcStat.st_mode)) {
            mkdir(destFile, srcStat.st_mode);
            syncFiles(srcFile, destFile);
        } else {
            FILE* srcFileOpen = fopen(srcFile, "r");
            FILE* destFileOpen = fopen(destFile, "w");
            
            if (srcFileOpen == NULL) {
                printf("Error: Failed to open source file %s\n", srcFile);
                continue;
            }
            
            if (destFileOpen == NULL) {
                printf("Error: Failed to open destination file %s\n", destFile);
                continue;
            }
            
            char buffer[1024];
            size_t bytesRead;
            
            while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFileOpen)) > 0) {
                fwrite(buffer, 1, bytesRead, destFileOpen);
            }
            
            fclose(srcFileOpen);
            fclose(destFileOpen);
            
            printf("Copied file %s\n", srcFile);
        }
    }
    
    closedir(sourceDir);
    closedir(destDir);
    
    printf("--- File synchronization complete ---\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_path> <dest_path>\n", argv[0]);
        return 1;
    }
    
    syncFiles(argv[1], argv[2]);
    
    return 0;
}