//FormAI DATASET v1.0 Category: File Backup System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<time.h>

#define MAX_FILES 50
#define MAX_PATH 200

void backup(char* filename);

int main(){
    DIR* dir;
    struct dirent* ent;
    char* path = "/home/user/files/";
    char files[MAX_FILES][MAX_PATH];
    int file_count = 0;

    if((dir = opendir(path)) != NULL){
        while((ent = readdir(dir)) != NULL){
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0){
                strcpy(files[file_count], path);
                strcat(files[file_count], ent->d_name);
                file_count++;
            }
        }
        closedir(dir);

        for(int i = 0; i < file_count; i++){
            backup(files[i]);
        }
        printf("Backup Successful!\n");
    }
    else{
        printf("Error: Unable to open directory.\n");
    }

    return 0;
}

void backup(char* filename){
    FILE* file = fopen(filename, "r");
    char* backup_name = malloc(MAX_PATH);
    char* timestamp = malloc(20);
    time_t now = time(NULL);

    strftime(timestamp, 20, "_%Y%m%d%H%M%S", localtime(&now));
    strcpy(backup_name, filename);
    strcat(backup_name, timestamp);

    FILE* backup_file = fopen(backup_name, "w");

    char c;
    while((c = fgetc(file)) != EOF){
        fputc(c, backup_file);
    }

    fclose(backup_file);
    fclose(file);
    free(backup_name);
    free(timestamp);
}