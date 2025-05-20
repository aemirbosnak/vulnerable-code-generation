//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_PATH_SIZE 1024

int is_regular_file(const char *path);
long long int get_folder_size(const char* folder_path);
int get_folder_contents(const char* folder_path);


int main(int argc, char *argv[]) {
    
    if(argc <= 1) {
        printf("Please provide a folder path to analyze.\n");
        return 1;
    }
    
    char* folder_path = argv[1];
    
    if(is_regular_file(folder_path)) {
        printf("The specified path is a file. Please provide a folder path to analyze.\n");
        return 1;
    }
    
    printf("Analyzing folder: %s\n", folder_path);
    
    get_folder_contents(folder_path);
    
    long long int folder_size = get_folder_size(folder_path);
    
    printf("Total size of %s: %lld bytes\n", folder_path, folder_size);
    
    return 0;
}

// Function to check if a path is a regular file.
int is_regular_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

// Function to get the total size of a folder.
long long int get_folder_size(const char* folder_path) {
    DIR *d;
    struct dirent *dir;
    long long int folder_size = 0;
    
    d = opendir(folder_path);
    
    if(d) {
        while((dir = readdir(d)) != NULL) {
            if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                continue;
            }
            char file_path[MAX_PATH_SIZE];
            snprintf(file_path, sizeof(file_path), "%s/%s", folder_path, dir->d_name);
            if(is_regular_file(file_path)) {
                struct stat file_stat;
                if(stat(file_path, &file_stat) == 0) {
                    folder_size += file_stat.st_size;
                }
            } else {
                folder_size += get_folder_size(file_path);
            }
        }
        closedir(d);
    }
    
    return folder_size;
}

// Function to get the contents of a folder.
int get_folder_contents(const char* folder_path) {
    DIR *d;
    struct dirent *dir;
    
    d = opendir(folder_path);
    
    if(d) {
        while((dir = readdir(d)) != NULL) {
            if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                continue;
            }
            char file_path[MAX_PATH_SIZE];
            snprintf(file_path, sizeof(file_path), "%s/%s", folder_path, dir->d_name);
            if(is_regular_file(file_path)) {
                printf("File: %s\n", file_path);
            } else {
                printf("Folder: %s\n", file_path);
            }
        }
        closedir(d);
    }
    
    return 0;
}