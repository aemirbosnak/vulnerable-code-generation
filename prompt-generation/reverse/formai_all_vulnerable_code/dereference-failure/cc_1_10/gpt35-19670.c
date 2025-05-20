//FormAI DATASET v1.0 Category: File Backup System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_FILES 100
#define MAX_NAME_LENGTH 50

typedef struct file{
    char file_name[MAX_NAME_LENGTH];
    char file_contents[200];
}file;

typedef struct backup_system{
    file files[MAX_FILES];
    int num_files;
}backup_system;

backup_system* create_backup_system(){
    backup_system* backup = (backup_system*) malloc(sizeof(backup_system));
    backup->num_files = 0;
    return backup;
}

void add_file(backup_system* backup, char* file_name, char* file_contents){
    if(backup->num_files < MAX_FILES){
        strcpy(backup->files[backup->num_files].file_name, file_name);
        strcpy(backup->files[backup->num_files].file_contents, file_contents);
        backup->num_files++;
    }
    else{
        printf("Backup system is full!\n");
    }
}

int find_file(backup_system* backup, char* file_name){
    for(int i=0; i<backup->num_files; i++){
        if(strcmp(backup->files[i].file_name, file_name) == 0){
            return i;
        }
    }
    return -1;
}

void delete_file(backup_system* backup, char* file_name){
    int index = find_file(backup, file_name);
    if(index != -1){
        for(int i=index; i<backup->num_files-1; i++){
            backup->files[i] = backup->files[i+1];
        }
        backup->num_files--;
        printf("File deleted successfully!\n");
    }
    else{
        printf("File not found in backup system!\n");
    }
}

void display_file_contents(backup_system* backup, char* file_name){
    int index = find_file(backup, file_name);
    if(index != -1){
        printf("File Contents:\n%s", backup->files[index].file_contents);
    }
    else{
        printf("File not found in backup system!\n");
    }
}

void display_all_files(backup_system* backup){
    if(backup->num_files == 0){
        printf("Backup system is empty!\n");
    }
    else{
        printf("Files in Backup System:\n");
        for(int i=0; i<backup->num_files; i++){
            printf("%s\n", backup->files[i].file_name);
        }
    }
}

int main(){
    backup_system* backup = create_backup_system();
    add_file(backup, "file1.txt", "Contents of file1.txt");
    add_file(backup, "file2.txt", "Contents of file2.txt");
    display_all_files(backup);
    display_file_contents(backup, "file1.txt");
    delete_file(backup, "file2.txt");
    delete_file(backup, "file3.txt");
    display_all_files(backup);
    return 0;
}