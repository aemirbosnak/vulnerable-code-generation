//FormAI DATASET v1.0 Category: File Synchronizer ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

char* current_dir;
int file_count = 0, dir_count = 0;

void copy_file(char *srcPath, char *destPath){
    FILE *src, *dest;
    char ch;

    src = fopen(srcPath,"r");
    dest = fopen(destPath,"w");

    while((ch = fgetc(src)) != EOF){
        fputc(ch,dest);
    }

    fclose(src);
    fclose(dest);
}

void copy_dir(char *srcPath, char *destPath){
    DIR *src, *dest;
    struct dirent *dir;
    struct stat st;
    char path[256], srcPathTemp[256], destPathTemp[256];

    src = opendir(srcPath);
    dest = opendir(destPath);

    while(dir = readdir(src)){

        if(dir->d_name[0] == '.')
            continue;

        sprintf(srcPathTemp, "%s/%s", srcPath, dir->d_name);
        sprintf(destPathTemp, "%s/%s", destPath, dir->d_name);

        stat(srcPathTemp, &st);

        if(S_ISDIR(st.st_mode)){
            if(!opendir(destPathTemp)){
                mkdir(destPathTemp, st.st_mode);
                printf("Directory created: %s\n", destPathTemp);
                dir_count++;
            }
            copy_dir(srcPathTemp, destPathTemp);
        }else{
            if(!fopen(destPathTemp, "r")){
                copy_file(srcPathTemp, destPathTemp);
                printf("%s -> %s\n", srcPathTemp, destPathTemp);
                file_count++;
            }
        }
    }
    closedir(src);
    closedir(dest);
}

void sync_files(char* srcPath, char* destPath){
    struct stat st;
    char path[256];

    if(lstat(srcPath, &st) == -1){
        printf("Source path not found!\n");
        exit(1);
    }

    if(S_ISDIR(st.st_mode)){
        if(mkdir(destPath, st.st_mode) == -1 && !opendir(destPath)){
            printf("Unable to create directory %s\n", destPath);
            exit(1);
        }

        printf("Directory created: %s\n", destPath);
        dir_count++;
        copy_dir(srcPath, destPath);
    }else{
        if(!fopen(destPath, "r")){
            copy_file(srcPath, destPath);
            printf("%s -> %s\n", srcPath, destPath);
            file_count++;
        }
    }
}

int main(){
    char srcPath[256], destPath[256];
    current_dir = getenv("PWD");

    printf("Enter source file/directory path:\n");
    fgets(srcPath, 256, stdin);
    srcPath[strlen(srcPath)-1] = '\0';

    printf("Enter destination path:\n");
    fgets(destPath, 256, stdin);
    destPath[strlen(destPath)-1] = '\0';

    sync_files(srcPath, destPath);

    printf("\n%d File(s) Copied and %d Directory(s) Created!\n", file_count, dir_count);
    return 0;
}