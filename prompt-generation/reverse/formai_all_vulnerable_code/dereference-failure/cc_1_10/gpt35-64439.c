//FormAI DATASET v1.0 Category: File Synchronizer ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

void synchronizer(char* source_path, char* dest_path){
    DIR *dir_pointer;
    struct dirent *dir_entry;

    dir_pointer = opendir(source_path);
    if(dir_pointer == NULL){
        printf("\nError: Not able to find the directory %s\n", source_path);
        exit(EXIT_FAILURE);
    }

    while((dir_entry = readdir(dir_pointer)) != NULL){
        
        char source_file[1024], dest_file[1024];
        struct stat source_file_stat, dest_file_stat;

        if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0){
            continue;
        }

        sprintf(source_file, "%s/%s", source_path, dir_entry->d_name);
        sprintf(dest_file, "%s/%s", dest_path, dir_entry->d_name);

        if(stat(source_file, &source_file_stat) == -1){
            printf("\nError: Not able to get the file status of %s\n", source_file);
            exit(EXIT_FAILURE);
        }

        if(stat(dest_file, &dest_file_stat) == -1){
            if(S_ISDIR(source_file_stat.st_mode)){
                mkdir(dest_file, 0777);
            } else {
                if(rename(source_file, dest_file) != 0){
                    printf("\nError: Not able to move the file %s to %s\n", source_file, dest_file);
                    exit(EXIT_FAILURE);
                }
            }
        } else {
            if(S_ISDIR(source_file_stat.st_mode)){
                synchronizer(source_file, dest_file);
            } else {
                if(source_file_stat.st_mtime > dest_file_stat.st_mtime){
                    if(rename(source_file, dest_file) != 0){
                        printf("\nError: Not able to move the file %s to %s\n", source_file, dest_file);
                        exit(EXIT_FAILURE);
                    }
                } else if(source_file_stat.st_mtime == dest_file_stat.st_mtime){
                    continue;
                }
            }
        }
    }
    closedir(dir_pointer);
}

int main(){
    char source_path[1024], dest_path[1024];

    printf("\nEnter the source directory path: ");
    scanf("%s", source_path);
    printf("\nEnter the destination directory path: ");
    scanf("%s", dest_path);

    synchronizer(source_path, dest_path);

    printf("\nSynchronization complete!\n");
    return 0;
}