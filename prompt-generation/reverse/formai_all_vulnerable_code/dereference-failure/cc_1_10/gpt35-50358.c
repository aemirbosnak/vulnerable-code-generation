//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

void traverseDirectory(const char* dirPath, int depth);

int main(int argc, char* argv[]) {
    
    if(argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(0);
    }
    int depth = 0;
    traverseDirectory(argv[1], depth);
    return 0;
}

void traverseDirectory(const char* dirPath, int depth) {
    DIR* dir = opendir(dirPath);
    if(dir) {
        struct dirent* dirEntry;
        while((dirEntry = readdir(dir)) != NULL) {
            if(strcmp(dirEntry->d_name, ".") && strcmp(dirEntry->d_name, "..")) {
                for(int i=0; i<depth; i++) {
                    printf("| ");
                }
                printf("|--%s\n", dirEntry->d_name);
                char newPath[1024];
                strcpy(newPath, dirPath);
                strcat(newPath, "/");
                strcat(newPath, dirEntry->d_name);
                struct stat fileStat;
                if(stat(newPath, &fileStat)) {
                    printf("Error: Invalid file / directory\n");
                    exit(0);
                }
                if(S_ISDIR(fileStat.st_mode)) {
                    traverseDirectory(newPath, depth+1);
                } else {
                    char sizeStr[10];
                    int fileSize = (int)fileStat.st_size;
                    if(fileSize < 1024) {
                        sprintf(sizeStr, "%d B", fileSize);
                    } else if(fileSize < (1024*1024)) {
                        sprintf(sizeStr, "%.2f KB", (float)fileSize/1024.0f);
                    } else {
                        sprintf(sizeStr, "%.2f MB", (float)fileSize/(1024.0f*1024.0f));
                    }
                    for(int i=0; i<=depth; i++) {
                        printf("| ");
                    }
                    printf("+-- %s (%s)\n", dirEntry->d_name, sizeStr);
                }   
            }
        }
    } else {
        printf("Error: Invalid directory path\n");
        exit(0);
    }
}