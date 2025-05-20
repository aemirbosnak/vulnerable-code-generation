//Falcon-180B DATASET v1.0 Category: System administration ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX 100

char *dir_path;
char *file_name;
char command[MAX];
char file_path[MAX];

void search_directory(char *path){
    DIR *dp;
    struct dirent *dirp;
    dp = opendir(path);
    if(dp == NULL){
        printf("Error opening directory %s\n", path);
        return;
    }
    while((dirp = readdir(dp))!= NULL){
        if(dirp->d_type == DT_DIR){
            strcpy(file_name, dirp->d_name);
            strcat(file_path, path);
            strcat(file_path, "/");
            strcat(file_path, dirp->d_name);
            search_directory(file_path);
        }
        else{
            strcpy(file_name, dirp->d_name);
            sprintf(command, "ls -l %s", path);
            system(command);
            sprintf(command, "cp %s /home/user/backup", file_path);
            system(command);
        }
    }
    closedir(dp);
}

int main(int argc, char **argv){
    if(argc < 2){
        printf("Usage:./program directory_path\n");
        exit(1);
    }
    strcpy(dir_path, argv[1]);
    strcat(dir_path, "/");
    search_directory(dir_path);
    return 0;
}