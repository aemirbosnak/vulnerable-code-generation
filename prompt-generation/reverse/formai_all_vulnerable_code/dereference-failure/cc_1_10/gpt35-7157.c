//FormAI DATASET v1.0 Category: File Backup System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_LENGTH 200
#define BUFFER_SIZE 1024

void create_backup(char*, char*);
void restore_backup(char*, char*);

int main(){
    char original_file[MAX_FILE_LENGTH];
    char backup_file[MAX_FILE_LENGTH];
    int choice;
    printf("Enter the name of the file to be backed up: ");
    scanf("%s", original_file);
    printf("Enter the name of the backup file: ");
    scanf("%s", backup_file);
    printf("Choose an option: \n");
    printf("1. Create backup\n2. Restore backup\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            create_backup(original_file, backup_file);
            break;
        case 2:
            restore_backup(original_file, backup_file);
            break;
        default:
            printf("Invalid option!");
            break;
    }
    return 0;
}

void create_backup(char* original_file, char* backup_file){
    FILE *original_fp, *backup_fp;
    char buffer[BUFFER_SIZE];
    int read_size;
    original_fp = fopen(original_file, "rb");
    if(original_fp == NULL){
        printf("Error opening the original file!");
        exit(1);
    }
    backup_fp = fopen(backup_file, "wb");
    if(backup_fp == NULL){
        printf("Error creating backup file!");
        exit(1);
    }
    while((read_size = fread(buffer, 1, BUFFER_SIZE, original_fp)) > 0){
        fwrite(buffer, read_size, 1, backup_fp);
    }
    fclose(original_fp);
    fclose(backup_fp);
    printf("Backup created successfully!\n");
}

void restore_backup(char* original_file, char* backup_file){
    FILE *original_fp, *backup_fp;
    char buffer[BUFFER_SIZE];
    int read_size;
    original_fp = fopen(original_file, "wb");
    if(original_fp == NULL){
        printf("Error creating the original file!");
        exit(1);
    }
    backup_fp = fopen(backup_file, "rb");
    if(backup_fp == NULL){
        printf("Error opening backup file!");
        exit(1);
    }
    while((read_size = fread(buffer, 1, BUFFER_SIZE, backup_fp)) > 0){
        fwrite(buffer, read_size, 1, original_fp);
    }
    fclose(original_fp);
    fclose(backup_fp);
    printf("Backup restored successfully!\n");
}