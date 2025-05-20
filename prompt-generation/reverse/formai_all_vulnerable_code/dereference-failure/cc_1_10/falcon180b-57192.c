//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char filename[256];
    char backup_path[256];
    int file_size;
} file_t;

file_t* create_file(char* filename) {
    file_t* new_file = malloc(sizeof(file_t));
    strcpy(new_file->filename, filename);
    strcpy(new_file->backup_path, "backups/");
    strcat(new_file->backup_path, filename);
    new_file->file_size = 0;
    return new_file;
}

void backup_file(file_t* file) {
    FILE* backup_file = fopen(file->backup_path, "wb");
    FILE* original_file = fopen(file->filename, "rb");

    if (original_file == NULL || backup_file == NULL) {
        printf("Error: Failed to open file(s)\n");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, original_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
        file->file_size += bytes_read;
    }

    fclose(original_file);
    fclose(backup_file);
}

void restore_file(file_t* file) {
    FILE* backup_file = fopen(file->backup_path, "rb");
    FILE* original_file = fopen(file->filename, "wb");

    if (original_file == NULL || backup_file == NULL) {
        printf("Error: Failed to open file(s)\n");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, backup_file)) > 0) {
        fwrite(buffer, 1, bytes_read, original_file);
    }

    fclose(original_file);
    fclose(backup_file);
}

void delete_backup(file_t* file) {
    remove(file->backup_path);
    file->file_size = 0;
}

int main() {
    file_t* file = create_file("example.txt");

    backup_file(file);
    printf("File backed up successfully!\n");

    restore_file(file);
    printf("File restored successfully!\n");

    delete_backup(file);
    printf("Backup deleted successfully!\n");

    return 0;
}