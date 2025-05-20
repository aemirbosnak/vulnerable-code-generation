//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1MB

typedef struct {
    char filename[100];
    FILE *file;
    int size;
} file_t;

void backup_file(file_t *file) {
    char backup_filename[100];
    strcpy(backup_filename, file->filename);
    strcat(backup_filename, ".bak");

    FILE *backup_file = fopen(backup_filename, "w");

    if (backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        exit(1);
    }

    int ch;
    while ((ch = fgetc(file->file))!= EOF) {
        fputc(ch, backup_file);
    }

    fclose(backup_file);
    printf("Backup created.\n");
}

int main() {
    file_t file;

    printf("Enter filename to backup: ");
    scanf("%s", file.filename);

    file.file = fopen(file.filename, "r");

    if (file.file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fseek(file.file, 0, SEEK_END);
    file.size = ftell(file.file);

    if (file.size > MAX_FILE_SIZE) {
        printf("Error: File is too large.\n");
        exit(1);
    }

    printf("Backup created.\n");

    return 0;
}