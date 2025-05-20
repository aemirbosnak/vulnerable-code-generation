//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_FILE_EXTENSION ".bak"

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE* file_pointer;
} File;

void backup_file(char* file_name) {
    char* backup_file_name = malloc(MAX_FILE_NAME_LENGTH * sizeof(char));
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, BACKUP_FILE_EXTENSION);

    File backup_file = {
       .file_name = backup_file_name,
       .file_pointer = NULL
    };

    backup_file.file_pointer = fopen(backup_file.file_name, "w");

    if (backup_file.file_pointer == NULL) {
        printf("Error: Could not create backup file '%s'\n", backup_file.file_name);
        exit(1);
    }

    FILE* original_file_pointer = fopen(file_name, "r");

    if (original_file_pointer == NULL) {
        printf("Error: Could not open original file '%s'\n", file_name);
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), original_file_pointer)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file.file_pointer);
    }

    fclose(original_file_pointer);
    fclose(backup_file.file_pointer);

    printf("Backup file created: %s\n", backup_file.file_name);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char* file_name = argv[1];

    if (strlen(file_name) >= MAX_FILE_NAME_LENGTH) {
        printf("Error: File name is too long\n");
        return 1;
    }

    for (int i = 0; i < strlen(file_name); i++) {
        if (!isalnum(file_name[i]) && file_name[i]!= '_' && file_name[i]!= '.') {
            printf("Error: File name contains invalid characters\n");
            return 1;
        }
    }

    backup_file(file_name);

    return 0;
}