//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

// function declarations
void analyze(char* path, int tabs);

// function to calculate the size of a directory
unsigned long long dir_size(char* dir){
    DIR* directory = opendir(dir);

    if(directory == NULL){
        return 0;
    }

    struct dirent *deread;
    struct stat st;
    unsigned long long size = 0;

    while((deread = readdir(directory)) != NULL){
        char path[1024];
        sprintf(path, "%s/%s", dir, deread->d_name);

        if(deread->d_type == DT_DIR && strcmp(".",deread->d_name) != 0 && strcmp("..",deread->d_name) != 0){
            size += dir_size(path);
        } else if(stat(path, &st) == 0) {
            size += st.st_size;
        }
    }

    closedir(directory);
    return size;
}

// main function
int main(){
    char* start_path = "/"; // start at root directory
    analyze(start_path, 0);
    return 0;
}

// function to analyze disk space usage
void analyze(char* path, int tabs){
    DIR* directory = opendir(path);

    if(directory == NULL){
        printf("Error: Directory does not exist!\n");
        return;
    }

    struct dirent *deread;
    struct stat st;
    unsigned long long size = 0;

    // print directory name
    for(int i=0; i<tabs; i++){
        printf("\t");
    }
    printf("-> %s\n", path);

    while((deread = readdir(directory)) != NULL){
        char next_path[1024];
        sprintf(next_path, "%s/%s", path, deread->d_name);

        if(deread->d_type == DT_DIR && strcmp(".",deread->d_name) != 0 && strcmp("..",deread->d_name) != 0){
            analyze(next_path, tabs+1);
            size += dir_size(next_path);
        } else if(stat(next_path, &st) == 0) {
            size += st.st_size;
        }
    }

    // print disk space used by directory
    for(int i=0; i<tabs; i++){
        printf("\t");
    }
    printf("-> Directory size: %lld bytes\n\n", size);

    closedir(directory);
}