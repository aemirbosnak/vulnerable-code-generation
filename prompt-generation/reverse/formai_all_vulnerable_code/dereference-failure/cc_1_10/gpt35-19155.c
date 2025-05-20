//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: distributed
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

#define MAX_PATH_LEN 1024

struct dir_entry{
    char name[MAX_PATH_LEN];
    int size;
};

void get_dir_size(char *dir_path, int *dir_size){
    DIR *dir;
    struct dirent *dirent;
    struct stat statbuf;
    char full_path[MAX_PATH_LEN];

    /*Open Directory*/
    if((dir = opendir(dir_path)) == NULL)
    {
        fprintf(stderr, "Failed to open directory \"%s\" - %s\n",
        dir_path, strerror(errno));
        exit(1);
    }

    /*Read Directory*/
    while((dirent = readdir(dir)) != NULL)
    {
        /*Build full path*/
        snprintf(full_path, MAX_PATH_LEN, "%s/%s", dir_path, dirent->d_name);
        /*Get info about file/directory*/
        if(stat(full_path, &statbuf) < 0)
        {
            fprintf(stderr, "Unable to stat file \"%s\" - %s\n", full_path, strerror(errno));
            continue;
        }
        if(S_ISDIR(statbuf.st_mode)){
            /*Skip Parent and Current Directories*/
            if(strcmp(".", dirent->d_name) == 0 || strcmp("..", dirent->d_name) == 0)
                continue;
            /*Recurse*/
            get_dir_size(full_path, dir_size);
        }else{
            /*Add to Total Directory Size*/
            *dir_size += statbuf.st_size;
        }
    }
    /*Close Directory*/
    closedir(dir);
}

int main(int argc, char** argv) {
    if(argc != 2){
        fprintf(stderr, "Incorrect number of arguments!\n Usage: %s <directory path>\n", argv[0]);
        return 1;
    }

    char *dir_path = argv[1];
    int dir_size = 0;
    get_dir_size(dir_path, &dir_size);
    printf("Size of directory \"%s\": %d bytes\n", dir_path, dir_size);

    struct dir_entry entries[100];
    int entry_count = 0;

    DIR *dir;
    struct dirent *dirent;
    struct stat statbuf;
    char full_path[MAX_PATH_LEN];

    if((dir = opendir(dir_path)) == NULL){
        fprintf(stderr, "Failed to open directory \"%s\" - %s\n",
        dir_path, strerror(errno));
        exit(1);
    }

    while((dirent = readdir(dir)) != NULL){
        snprintf(full_path, MAX_PATH_LEN, "%s/%s", dir_path, dirent->d_name);
        if(stat(full_path, &statbuf) < 0){
            fprintf(stderr, "Unable to stat file \"%s\" - %s\n", full_path, strerror(errno));
            continue;
        }
        if(S_ISDIR(statbuf.st_mode)){
            if(strcmp(".", dirent->d_name) == 0 || strcmp("..", dirent->d_name) == 0)
                continue;
            int sub_dir_size = 0;
            get_dir_size(full_path, &sub_dir_size);
            snprintf(entries[entry_count].name, MAX_PATH_LEN, "%s", dirent->d_name);
            entries[entry_count].size = sub_dir_size;
            entry_count++;
        }
    }
    closedir(dir);

    printf("\nSub-Directories in \"%s\": (%d total)\n", dir_path, entry_count);
    for(int i = 0; i < entry_count; i++){
        printf("%d. %s - %d bytes\n", i+1, entries[i].name, entries[i].size);
    }

    return 0;
}