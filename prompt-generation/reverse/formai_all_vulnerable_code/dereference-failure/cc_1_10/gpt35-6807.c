//FormAI DATASET v1.0 Category: File Synchronizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//function to check if a directory exists or not
int dir_exists(char* dir_path){
    DIR* dir = opendir(dir_path);
    if (dir){
        closedir(dir);
        return 1;
    }
    return 0;
}

//function to create a directory
void create_dir(char* dir_path){
    mkdir(dir_path, 0777); //create directory with full permissions
}

//function to check if a file exists or not
int file_exists(char* file_path){
    if (access(file_path, F_OK) != -1){
        return 1;
    }
    return 0;
}

//function to copy a file
void copy_file(char* source, char* destination){
    FILE* src_file = fopen(source, "r");
    FILE* dest_file = fopen(destination, "w");
    int ch;
    while ((ch = fgetc(src_file)) != EOF){
        fputc(ch, dest_file);
    }
    fclose(src_file);
    fclose(dest_file);
}

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("Invalid arguments! Please provide source and destination directories.\n");
        return 1;
    }
    char* source = argv[1]; //path to source directory
    char* destination = argv[2]; //path to destination directory
    
    if (!dir_exists(source)){
        printf("Source directory does not exist!\n");
        return 1;
    }
    
    if (!dir_exists(destination)){
        printf("Destination directory does not exist!\n");
        create_dir(destination);
        printf("Created destination directory.\n");
    }
    
    DIR* source_dir = opendir(source);
    struct dirent* ent;

    while ((ent = readdir(source_dir)) != NULL) {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) { //ignore . and ..
            char source_file_path[100];
            char destination_file_path[100];
            sprintf(source_file_path, "%s/%s", source, ent->d_name); //path to source file
            sprintf(destination_file_path, "%s/%s", destination, ent->d_name); //path to destination file
            
            if (dir_exists(source_file_path)){ //if source is a directory
                if (!dir_exists(destination_file_path)){ //if destination directory does not exist, create it
                    create_dir(destination_file_path);
                    printf("Created directory %s.\n", destination_file_path);
                }
                continue;
            }
            
            if (!file_exists(destination_file_path)){ //if destination file does not exist
                copy_file(source_file_path, destination_file_path);
                printf("Copied %s to %s.\n", source_file_path, destination_file_path);
            }
        }
    }
    
    closedir(source_dir);
    printf("File synchronization successful!\n");
    return 0;
}