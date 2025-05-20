//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE (1024*1024*100) // 100MB

typedef struct {
    char filename[256];
    char backup_filename[256];
    time_t timestamp;
} BackupFile;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    BackupFile backup_file;

    strcpy(backup_file.filename, filename);
    strcat(backup_file.backup_filename, ".bak");
    strcat(backup_file.backup_filename, filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    fclose(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File too large.\n");
        return 1;
    }

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    file_size = fread(backup_file.filename, 1, file_size, file);
    fclose(file);

    backup_file.timestamp = time(NULL);

    file = fopen(backup_file.backup_filename, "wb");
    if (file == NULL) {
        printf("Error: Failed to create backup file.\n");
        return 1;
    }

    fwrite(backup_file.filename, 1, file_size, file);
    fclose(file);

    printf("Backup created successfully.\n");
    return 0;
}