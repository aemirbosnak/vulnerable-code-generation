//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>         
#include <sys/stat.h>      

struct FileInfo{
    char name[256];
    long size;
};

int compare(const void * a, const void * b) { 
    return ((struct FileInfo*)b)->size - ((struct FileInfo*)a)->size;
}

long getDirectorySize(const char * dirPath){
    struct dirent * info;
    DIR * directory = opendir(dirPath);
    long size = 0;
    while((info = readdir(directory)) != NULL){
        char path[PATH_MAX];
        if(strcmp(info->d_name, ".") == 0 || strcmp(info->d_name, "..") == 0){
            continue;
        }
        snprintf(path, PATH_MAX, "%s/%s", dirPath, info->d_name);
        if(info->d_type == DT_DIR){
            size += getDirectorySize(path);
        } else if(info->d_type == DT_REG){
            struct stat file_info;
            if(stat(path, &file_info) == 0){
                size += file_info.st_size;
            }
        }
    }
    closedir(directory);
    return size;
}

void analyzeDirectory(const char * dirPath){
    struct FileInfo files[1024];
    int fileCount = 0;
    DIR * directory = opendir(dirPath);
    struct dirent * info;
    while((info = readdir(directory)) != NULL){
        char path[PATH_MAX];
        if(strcmp(info->d_name, ".") == 0 || strcmp(info->d_name, "..") == 0){
            continue;
        }
        snprintf(path, PATH_MAX, "%s/%s", dirPath, info->d_name);
        if(info->d_type == DT_DIR){
            printf("%*s%s/\n", fileCount * 2, "", info->d_name);
            analyzeDirectory(path);
        } else if(info->d_type != DT_LNK && info->d_type != DT_REG){
            printf("%*s%s*\n", fileCount * 2, "", info->d_name);
        } else {
            struct stat file_info;
            if(stat(path, &file_info) == 0){
                struct FileInfo fileInfo;
                strcpy(fileInfo.name, info->d_name);
                fileInfo.size = file_info.st_size;
                files[fileCount++] = fileInfo;
            }
        }
    }
    closedir(directory);
    qsort(files, fileCount, sizeof(struct FileInfo), compare);
    for(int i = 0, n = fileCount; i < n; i++){
        struct FileInfo fileInfo = files[i];
        printf("%*s%s (%ld bytes)\n", fileCount * 2, "", fileInfo.name, fileInfo.size);
    }
}

int main(int argc, char * argv[]) {
    if(argc < 2){
        printf("Usage: %s directory_path\n", argv[0]);
        return 0;
    }
    const char * dirPath = argv[1];
    long size = getDirectorySize(dirPath);
    printf("Size of directory %s: %ld bytes\n", dirPath, size);
    analyzeDirectory(dirPath);
    return 0;
}