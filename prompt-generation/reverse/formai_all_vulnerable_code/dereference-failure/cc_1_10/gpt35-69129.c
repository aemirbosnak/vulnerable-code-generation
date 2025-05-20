//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

long long int calculate_directory_size(const char *dirname){
    struct dirent *de;
    DIR *dir = opendir(dirname);
    struct stat st;

    long long int size = 0;

    if(dir==NULL){
        printf("Could not open directory '%s'\n", dirname);
        return 0;
    }

    while(de = readdir(dir)){
        char path[512];
        sprintf(path, "%s/%s", dirname, de->d_name);

        if(de->d_type == 4 && strcmp(de->d_name, ".") !=0 && strcmp(de->d_name, "..") != 0){
            size += calculate_directory_size(path);
        }

        else if(de->d_type == 8){
            if(stat(path, &st)==0){
                size += st.st_size;
            }
        }

    }

    closedir(dir);

    return size;
}


int main(){
    printf("Welcome to Disk Space Analyzer program!\n\n");

    char dirname[512];

    printf("Please enter the name of the directory that you want to analyze:\n");
    scanf("%s", dirname);

    long long int size = calculate_directory_size(dirname);

    printf("The size of the directory %s is %lld bytes.\n", dirname, size);

    return 0;
}