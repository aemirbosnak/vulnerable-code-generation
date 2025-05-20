//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_SUFFIX "_backup"

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
} FileBackup;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    FileBackup backup_file = {0};

    strcpy(backup_file.file_name, file_name);
    strcat(backup_file.backup_file_name, BACKUP_SUFFIX);

    if (backup_file.backup_file_name[strlen(backup_file.backup_file_name) - 1] == '.') {
        backup_file.backup_file_name[strlen(backup_file.backup_file_name) - 1] = '\0';
    }

    printf("Creating backup of %s to %s\n", file_name, backup_file.backup_file_name);

    FILE *backup_file_ptr = fopen(backup_file.backup_file_name, "wb");
    if (backup_file_ptr == NULL) {
        printf("Error: Failed to create backup file.\n");
        return 1;
    }

    FILE *file_ptr = fopen(file_name, "rb");
    if (file_ptr == NULL) {
        printf("Error: Failed to open file.\n");
        fclose(backup_file_ptr);
        return 1;
    }

    char buffer[1024];
    while (fread(buffer, 1, sizeof(buffer), file_ptr) > 0) {
        fwrite(buffer, 1, sizeof(buffer), backup_file_ptr);
    }

    fclose(file_ptr);
    fclose(backup_file_ptr);

    printf("Backup created successfully.\n");
    return 0;
}