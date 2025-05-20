//FormAI DATASET v1.0 Category: File Synchronizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

// Function to get the last modified time of a file
time_t getModifiedTime(const char *filePath){
    struct stat fileStat;
    stat(filePath, &fileStat);
    return fileStat.st_mtime;
}

// Function to copy a file from source to destination
void copyFile(const char *src, const char *dest){
    FILE *srcFile, *destFile;
    char c;
    srcFile = fopen(src, "r");
    destFile = fopen(dest, "w");
    while ((c = fgetc(srcFile)) != EOF){
        fputc(c, destFile);
    }
    fclose(srcFile);
    fclose(destFile);
}

// Function to synchronize files between two directories
void synchronize(const char *srcDir, const char *destDir){
    DIR *dir;
    struct dirent *ent;
    char srcPath[256];
    char destPath[256];
    time_t srcTime, destTime;
    int fileExists = 0;
    if ((dir = opendir(srcDir)) != NULL){
        while ((ent = readdir(dir)) != NULL){
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0){
                continue;
            }
            snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, ent->d_name);
            snprintf(destPath, sizeof(destPath), "%s/%s", destDir, ent->d_name);
            if ((access(destPath, F_OK)) != -1){
                srcTime = getModifiedTime(srcPath);
                destTime = getModifiedTime(destPath);
                if (srcTime > destTime){
                    copyFile(srcPath, destPath);
                    printf("%s synchronized from %s to %s.\n", ent->d_name, srcDir, destDir);
                }
                else{
                    continue;
                }
            }
            else{
                copyFile(srcPath, destPath);
                printf("%s copied from %s to %s.\n", ent->d_name, srcDir, destDir);
            }
            fileExists = 1;
        }
        closedir(dir);
    }
    if (fileExists == 0){
        printf("No files in %s to synchronize.\n", srcDir);
    }
}

int main(){
    const char *srcDir = "medieval/src";
    const char *destDir = "medieval/dest";
    synchronize(srcDir, destDir);
    return 0;
}