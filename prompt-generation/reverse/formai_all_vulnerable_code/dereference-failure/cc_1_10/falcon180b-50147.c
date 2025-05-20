//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_FILES 100
#define MAX_FILE_NAME_SIZE 128

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    FILE *fp;
} FILE_HANDLE;

void backup_file(FILE_HANDLE *file, const char *backup_dir) {
    char backup_path[MAX_LINE_SIZE];
    sprintf(backup_path, "%s/%s", backup_dir, file->name);
    FILE *backup_fp = fopen(backup_path, "wb");

    if (!backup_fp) {
        fprintf(stderr, "Error: Could not create backup file '%s'.\n", backup_path);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE_SIZE];
    while (fgets(buffer, MAX_LINE_SIZE, file->fp)) {
        fputs(buffer, backup_fp);
    }

    fclose(backup_fp);
    fprintf(stdout, "Backup of '%s' created.\n", file->name);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source_file> <backup_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char source_file[MAX_LINE_SIZE];
    strcpy(source_file, argv[1]);

    char backup_dir[MAX_LINE_SIZE];
    strcpy(backup_dir, argv[2]);

    FILE_HANDLE file;
    file.fp = fopen(source_file, "rb");

    if (!file.fp) {
        fprintf(stderr, "Error: Could not open source file '%s'.\n", source_file);
        return EXIT_FAILURE;
    }

    backup_file(&file, backup_dir);

    fclose(file.fp);
    return EXIT_SUCCESS;
}