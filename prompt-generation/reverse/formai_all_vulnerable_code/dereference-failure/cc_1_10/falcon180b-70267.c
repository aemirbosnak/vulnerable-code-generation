//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    int is_backup_created;
} File;

void create_backup_file_name(char* file_name, char* backup_file_name) {
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");
}

int create_backup(char* file_name, char* backup_file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", file_name);
        return 1;
    }

    FILE* backup_file = fopen(backup_file_name, "wb");
    if (backup_file == NULL) {
        printf("Error: could not create backup file '%s'\n", backup_file_name);
        fclose(file);
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    while (fread(buffer, 1, MAX_FILE_SIZE, file) > 0) {
        fwrite(buffer, 1, fread(buffer, 1, MAX_FILE_SIZE, file), backup_file);
    }

    fclose(file);
    fclose(backup_file);

    return 0;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <file_name> <backup_file_name>\n", argv[0]);
        return 1;
    }

    File file;
    strcpy(file.file_name, argv[1]);
    strcpy(file.backup_file_name, argv[2]);

    if (create_backup(file.file_name, file.backup_file_name)) {
        printf("Error: failed to create backup file\n");
        return 1;
    }

    printf("Backup created successfully\n");

    return 0;
}