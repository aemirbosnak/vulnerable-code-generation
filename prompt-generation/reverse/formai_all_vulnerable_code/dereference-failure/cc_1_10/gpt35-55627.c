//FormAI DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_DIRECTORY_LENGTH 200

void create_backup_directory(char *backup_directory) {
    time_t raw_time;
    struct tm *time_info;
    char current_time[MAX_FILENAME_LENGTH];

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(current_time, MAX_FILENAME_LENGTH, "%Y%m%d_%H%M%S", time_info);
    sprintf(backup_directory, "backup_%s", current_time);

    mkdir(backup_directory);
}

void backup_file(char *filename, char *backup_directory) {
    char *backup_filename = (char*)malloc(MAX_FILENAME_LENGTH * sizeof(char));
    sprintf(backup_filename, "%s/%s", backup_directory, filename);

    FILE *original_file = fopen(filename, "rb");
    FILE *backup_file = fopen(backup_filename, "wb");

    if (original_file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", backup_filename);
        exit(1);
    }

    int buffer_size = 1024;
    unsigned char *buffer = (unsigned char*)malloc(buffer_size * sizeof(unsigned char));
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(unsigned char), buffer_size, original_file)) > 0) {
        fwrite(buffer, sizeof(unsigned char), bytes_read, backup_file);
    }

    free(buffer);
    fclose(original_file);
    fclose(backup_file);

    printf("Successfully backed up file: %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 0;
    }

    char *filename = argv[1];
    char backup_directory[MAX_BACKUP_DIRECTORY_LENGTH];
    create_backup_directory(backup_directory);
    backup_file(filename, backup_directory);

    return 0;
}