//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE* file_ptr;
    int is_open;
} FILE_BACKUP_STRUCT;

FILE_BACKUP_STRUCT* open_file(char* file_name) {
    FILE_BACKUP_STRUCT* file_backup_struct = malloc(sizeof(FILE_BACKUP_STRUCT));
    strcpy(file_backup_struct->file_name, file_name);
    file_backup_struct->file_ptr = fopen(file_name, "r");
    file_backup_struct->is_open = 1;
    return file_backup_struct;
}

void close_file(FILE_BACKUP_STRUCT* file_backup_struct) {
    if (file_backup_struct->is_open) {
        fclose(file_backup_struct->file_ptr);
        file_backup_struct->is_open = 0;
    }
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE_BACKUP_STRUCT* file_backup_struct;

    printf("Enter the file name to backup: ");
    scanf("%s", file_name);

    file_backup_struct = open_file(file_name);

    if (file_backup_struct == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file_backup_struct->file_ptr)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, stdout);
    }

    close_file(file_backup_struct);

    printf("Backup complete.\n");

    return 0;
}