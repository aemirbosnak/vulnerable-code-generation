//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define BACKUP_FILE "backup.txt"
#define MAX_FILE_SIZE 1000000

struct file_info {
    char filename[MAX_BUFFER_SIZE];
    int size;
    time_t last_modified;
};

void backup_file(char* filename) {
    FILE* backup_file = fopen(BACKUP_FILE, "a");
    if (backup_file == NULL) {
        printf("Error: Failed to open backup file.\n");
        return;
    }

    struct stat file_stat;
    if (stat(filename, &file_stat)!= 0) {
        printf("Error: Failed to get file info.\n");
        return;
    }

    struct file_info file_info;
    strcpy(file_info.filename, filename);
    file_info.size = file_stat.st_size;
    file_info.last_modified = file_stat.st_mtime;

    if (fwrite(&file_info, sizeof(struct file_info), 1, backup_file)!= 1) {
        printf("Error: Failed to write to backup file.\n");
        return;
    }

    fclose(backup_file);
}

void restore_file(char* filename) {
    FILE* backup_file = fopen(BACKUP_FILE, "r");
    if (backup_file == NULL) {
        printf("Error: Failed to open backup file.\n");
        return;
    }

    struct file_info file_info;
    while (fread(&file_info, sizeof(struct file_info), 1, backup_file) == 1) {
        if (strcasecmp(file_info.filename, filename) == 0) {
            printf("Restoring file: %s\n", filename);

            FILE* backup_file_handle = fopen(file_info.filename, "wb");
            if (backup_file_handle == NULL) {
                printf("Error: Failed to open file for writing.\n");
                return;
            }

            char buffer[MAX_BUFFER_SIZE];
            int bytes_read;

            rewind(backup_file);
            while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, backup_file)) > 0) {
                if (fwrite(buffer, 1, bytes_read, backup_file_handle)!= bytes_read) {
                    printf("Error: Failed to write to file.\n");
                    return;
                }
            }

            fclose(backup_file_handle);
            break;
        }
    }

    fclose(backup_file);
}

int main() {
    char filename[MAX_BUFFER_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);

    struct stat file_stat;
    if (stat(filename, &file_stat)!= 0) {
        printf("Error: File not found.\n");
        return 1;
    }

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds limit.\n");
        return 1;
    }

    backup_file(filename);
    printf("File backed up successfully.\n");

    restore_file(filename);
    printf("File restored successfully.\n");

    return 0;
}