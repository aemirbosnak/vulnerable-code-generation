//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

#define MAX_PATH_LENGTH 256
#define VIRUS_SIGNATURE "AEIOU" // Change this to a known virus signature.

bool is_virus(char* buffer, int buffer_size){
    for(int i=0; i<buffer_size-4; i++){
        if(buffer[i] == 'A' && buffer[i+1] == 'E' && buffer[i+2] == 'I' && buffer[i+3] == 'O' && buffer[i+4] == 'U'){
            return true;
        }
    }
    return false;
}

void scan_file(char* filename){
    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        printf("Error opening file: %s\n", filename);
        return;
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = (char*)malloc(file_size);
    fread(buffer, 1, file_size, file);
    fclose(file);
    
    if(is_virus(buffer, file_size)){
        printf("Virus detected in file: %s\n", filename);
    }
    
    free(buffer);
}

void scan_directory(char* path){
    DIR* dir = opendir(path);
    if(dir == NULL){
        printf("Error opening directory: %s\n", path);
        return;
    }
    struct dirent* dp;
    while((dp = readdir(dir)) != NULL){
        if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
            char filepath[MAX_PATH_LENGTH];
            snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", path, dp->d_name);
            if(dp->d_type == DT_DIR){
                scan_directory(filepath);
            }else if(dp->d_type == DT_REG){
                scan_file(filepath);
            }
        }
    }
    closedir(dir);
}

int main(){
    char* path = "/home/user/Documents"; // Change this to the directory you want to scan.
    printf("Scanning directory: %s\n", path);
    scan_directory(path);
    printf("Scan complete!\n");
    return 0;
}