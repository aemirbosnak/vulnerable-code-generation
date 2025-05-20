//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_FILE_NAME_LENGTH 1000
#define BACKUP_EXTENSION ".bak"

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
} FileInfo;

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    FileInfo file_info;
    strcpy(file_info.file_name, argv[1]);

    // Add backup extension to file name
    strcat(file_info.file_name, BACKUP_EXTENSION);

    // Create backup file name by replacing.txt with.bak
    strcpy(file_info.backup_file_name, file_info.file_name);
    strcpy(file_info.backup_file_name+strlen(file_info.file_name)-4, "");
    strcat(file_info.backup_file_name, BACKUP_EXTENSION);

    // Check if file exists
    FILE *file = fopen(file_info.file_name, "r");
    if(file == NULL) {
        printf("File does not exist.\n");
        return 1;
    }

    // Check if backup file exists
    FILE *backup_file = fopen(file_info.backup_file_name, "r");
    if(backup_file!= NULL) {
        printf("Backup file already exists.\n");
        fclose(backup_file);
        return 1;
    }

    // Create backup file
    FILE *backup = fopen(file_info.backup_file_name, "w");
    if(backup == NULL) {
        printf("Could not create backup file.\n");
        return 1;
    }

    // Copy contents of original file to backup file
    char ch;
    while((ch = fgetc(file))!= EOF) {
        fputc(ch, backup);
    }

    // Close files
    fclose(file);
    fclose(backup);

    printf("Backup file created successfully.\n");
    return 0;
}