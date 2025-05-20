//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    FILE *backup_file;
    int file_size;
} File;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    File file = {0};

    strcpy(file.file_name, file_name);
    strcpy(file.backup_file_name, file_name);
    strcat(file.backup_file_name, ".bak");

    if ((file.file = fopen(file_name, "r+b")) == NULL) {
        printf("Error: Could not open file '%s'\n", file_name);
        return 1;
    }

    if ((file.backup_file = fopen(file.backup_file_name, "wb")) == NULL) {
        printf("Error: Could not create backup file '%s'\n", file.backup_file_name);
        return 1;
    }

    fseek(file.file, 0, SEEK_END);
    file.file_size = ftell(file.file);
    rewind(file.file);

    if (file.file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large to backup\n");
        return 1;
    }

    if (fread(file.file, file.file_size, 1, file.file)!= 1) {
        printf("Error: Could not read file '%s'\n", file_name);
        return 1;
    }

    if (fwrite(file.file, file.file_size, 1, file.backup_file)!= 1) {
        printf("Error: Could not write to backup file '%s'\n", file.backup_file_name);
        return 1;
    }

    printf("Backup complete: %s\n", file.backup_file_name);

    fclose(file.file);
    fclose(file.backup_file);

    return 0;
}