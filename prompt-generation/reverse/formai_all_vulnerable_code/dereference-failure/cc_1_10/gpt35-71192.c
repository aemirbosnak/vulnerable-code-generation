//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyzeDiskSpace(char *path);

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    char *path = argv[1];
    printf("Analyzing disk space at %s:\n", path);
    analyzeDiskSpace(path);
    printf("Done!\n");
    return 0;
}

void analyzeDiskSpace(char *path){
    DIR *dir = opendir(path);
    if(dir == NULL){
        printf("Error: Unable to open directory\n");
        return;
    }
    struct dirent *entry;
    struct stat info;
    long long totalSize = 0;
    while((entry = readdir(dir)) != NULL){
        char *name = entry->d_name;
        char fullPath[1024];
        sprintf(fullPath, "%s/%s", path, name);
        if(stat(fullPath, &info) == -1){
            printf("Error: Unable to get file stats\n");
            continue;
        }
        if(strcmp(name, ".") == 0 || strcmp(name, "..") == 0){
            continue;
        }
        if(S_ISDIR(info.st_mode)){
            printf("--> %s (directory)\n", name);
            analyzeDiskSpace(fullPath);
        } else {
            printf("%s (%lld bytes)\n", name, info.st_size);
            totalSize += info.st_size;
        }
    }
    printf("Total size of %s: %lld bytes\n", path, totalSize);
    closedir(dir);
}