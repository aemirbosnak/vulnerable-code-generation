//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_DIR_PATH_LEN 200

typedef struct {
    char filename[MAX_FILENAME_LEN];
    char dir_path[MAX_DIR_PATH_LEN];
} FileInfo;

void backup_file(FileInfo *file_info, char *backup_dir) {
    char backup_path[MAX_DIR_PATH_LEN];

    strcpy(backup_path, backup_dir);
    strcat(backup_path, "/");
    strcat(backup_path, file_info->filename);

    FILE *backup_file = fopen(backup_path, "wb");

    if (backup_file == NULL) {
        printf("Error: Could not create backup file %s\n", backup_path);
        exit(1);
    }

    FILE *original_file = fopen(file_info->dir_path, "rb");

    if (original_file == NULL) {
        printf("Error: Could not open original file %s\n", file_info->dir_path);
        exit(1);
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("Backup of file %s created in directory %s\n", file_info->filename, backup_dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [backup_directory] [file1] [file2]...\n", argv[0]);
        return 1;
    }

    char backup_dir[MAX_DIR_PATH_LEN];
    strcpy(backup_dir, argv[1]);

    FileInfo file_info;

    for (int i = 2; i < argc; i++) {
        strcpy(file_info.filename, argv[i]);
        strcpy(file_info.dir_path, argv[i]);

        backup_file(&file_info, backup_dir);
    }

    return 0;
}