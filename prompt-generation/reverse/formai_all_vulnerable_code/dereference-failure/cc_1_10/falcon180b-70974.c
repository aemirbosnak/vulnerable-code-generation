//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BACKUP_FILES 10

typedef struct backup_file {
    char name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    int size;
} BackupFile;

BackupFile backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

void create_backup_file(char *name) {
    BackupFile *file = &backup_files[num_backup_files];
    strcpy(file->name, name);
    file->file = fopen(name, "w");
    if (file->file == NULL) {
        printf("Error creating backup file %s\n", name);
        exit(1);
    }
    file->size = 0;
    num_backup_files++;
}

void write_to_backup_file(char *data, int size) {
    BackupFile *file = &backup_files[num_backup_files - 1];
    if (fwrite(data, size, 1, file->file)!= 1) {
        printf("Error writing to backup file\n");
        exit(1);
    }
    file->size += size;
}

void close_backup_files() {
    for (int i = 0; i < num_backup_files; i++) {
        BackupFile *file = &backup_files[i];
        if (file->file!= NULL) {
            fclose(file->file);
            file->file = NULL;
        }
    }
}

int main() {
    create_backup_file("backup1.txt");
    write_to_backup_file("Hello, world!", strlen("Hello, world!"));
    write_to_backup_file("This is a test.", strlen("This is a test."));
    close_backup_files();
    return 0;
}