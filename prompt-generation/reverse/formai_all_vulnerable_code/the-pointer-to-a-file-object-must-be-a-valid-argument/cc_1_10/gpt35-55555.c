//FormAI DATASET v1.0 Category: File Synchronizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

// function to recursively synchronize files in two directories
void syncDirectories(char *srcDirPath, char *destDirPath) {
    struct dirent *de;
    DIR *srcDir = opendir(srcDirPath);
    DIR *destDir = opendir(destDirPath);
    char *srcFilePath = malloc((strlen(srcDirPath) + 256) * sizeof(char));
    char *destFilePath = malloc((strlen(destDirPath) + 256) * sizeof(char));
    
    while ((de = readdir(srcDir)) != NULL) {
        if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
            // build absolute paths for source and destination files
            sprintf(srcFilePath, "%s/%s", srcDirPath, de->d_name);
            sprintf(destFilePath, "%s/%s", destDirPath, de->d_name);
            struct stat srcFileStat, destFileStat;
            
            if (lstat(srcFilePath, &srcFileStat) == -1) {
                printf("Error: Unable to get file information for %s\n", srcFilePath);
                continue;
            }
            
            if (!S_ISDIR(srcFileStat.st_mode)) {
                // synchronize only if destination file does not exist or is older than source file
                bool synchronize = false;
                
                if (lstat(destFilePath, &destFileStat) == -1) {
                    synchronize = true;
                } else {
                    if (srcFileStat.st_mtime > destFileStat.st_mtime) {
                        synchronize = true;
                    }
                }
                
                if (synchronize) {
                    // copy source file to destination directory
                    FILE *srcFile = fopen(srcFilePath, "r");
                    FILE *destFile = fopen(destFilePath, "w");
                    char buffer[512];
                    
                    while (fgets(buffer, 512, srcFile)) {
                        fputs(buffer, destFile);
                    }
                    
                    fclose(srcFile);
                    fclose(destFile);
                }
            } else {
                // synchronize subdirectories
                if (lstat(destFilePath, &destFileStat) == -1) {
                    mkdir(destFilePath, srcFileStat.st_mode);
                }
                syncDirectories(srcFilePath, destFilePath);
            }
        }
    }
    
    free(srcFilePath);
    free(destFilePath);
    closedir(srcDir);
    closedir(destDir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }
    
    syncDirectories(argv[1], argv[2]);
    printf("Synchronization complete!\n");
    return 0;
}