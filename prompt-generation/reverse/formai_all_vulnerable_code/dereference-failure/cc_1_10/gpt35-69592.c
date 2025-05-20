//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MB 1048576
#define MAX_PATH 1024

void print_error(char *msg){
    printf("\nError: %s\n", msg);
    exit(EXIT_FAILURE);
}

void get_dir_size(char *dir_path, int *size){
    DIR *dir;
    struct dirent *entry;
    struct stat info;
    char cwd[MAX_PATH];

    if ((dir = opendir(dir_path)) == NULL){
        print_error("Could not open directory");
    }

    while ((entry = readdir(dir)) != NULL){
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
            if (chdir(dir_path) != 0){
                print_error("Could not change directory");
            }
            if (stat(entry->d_name, &info) != 0){
                print_error("Could not get file info");
            }
            if (S_ISDIR(info.st_mode)){
                get_dir_size(entry->d_name, size);
                if (chdir(cwd) != 0){
                    print_error("Could not change directory back");
                }
            } else {
                *size += info.st_size;
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]){
    int total_size = 0;
    char *path = argv[1];

    if (argc != 2){
        print_error("Incorrect number of arguments");
    }

    get_dir_size(path, &total_size);

    printf("\n%s size is: %.2f MB\n", path, (float) total_size / MB);

    return 0;
}