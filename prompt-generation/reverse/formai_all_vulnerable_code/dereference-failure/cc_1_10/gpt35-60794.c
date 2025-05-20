//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void analyzeDir(char *filename);

int main(){
    char dirname[100];

    printf("Enter directory path:");
    scanf("%s", dirname);
    analyzeDir(dirname);

    return 0; 
}

void analyzeDir(char *filename){
    DIR *dir;
    struct dirent *sd;
    struct stat st;
    char path[100];

    if ((dir = opendir(filename)) == NULL){
        printf("Unable to open directory %s\n", filename);
        return;
    }
    printf("Directory: %s\n", filename);

    while ((sd = readdir(dir)) != NULL){
        if (strcmp(sd->d_name, ".") == 0 || strcmp(sd->d_name, "..") == 0){
            continue;
        }

        sprintf(path, "%s/%s", filename, sd->d_name);
        if (lstat(path, &st) == -1){
            printf("Unable to access %s\n", path);
            continue;
        }

        if (S_ISDIR(st.st_mode) != 0){
            printf("\nDirectory: %s\n", path);
            analyzeDir(path);
        }
        else if (S_ISREG(st.st_mode) != 0){
            printf("Filename: %s\t\tSize: %lld bytes\n", path, (long long)st.st_size);
        }
    }

    closedir(dir);
}