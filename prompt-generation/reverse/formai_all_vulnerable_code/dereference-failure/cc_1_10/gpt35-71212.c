//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void printDir(char *);

void printDir(char *path){
    DIR *dirp;
    struct dirent *dp;
    struct stat sb;
    char nextPath[1024];
    int level = 0;

    if((dirp = opendir(path)) == NULL){
        fprintf(stderr, "Error opening directory: %s\n", path);
        exit(EXIT_FAILURE);
    }

    while((dp = readdir(dirp)) != NULL){
        if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
            continue;
        }

        printf("%*s%s\n", level*4, "", dp->d_name);

        snprintf(nextPath, sizeof(nextPath), "%s/%s", path, dp->d_name);
        if(lstat(nextPath, &sb) == -1){
            fprintf(stderr, "Error getting stat on file: %s\n", nextPath);
            continue;
        }

        if(S_ISDIR(sb.st_mode)){
            level++;
            printDir(nextPath);
            level--;
        }
    }

    if(closedir(dirp) == -1){
        fprintf(stderr, "Error closing directory: %s\n", path);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <directory path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printDir(argv[1]);

    exit(EXIT_SUCCESS);
}