//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PATH 256

void display_help() {
    printf("Usage: file_backup <source_file> <backup_folder>\n");
    printf("Example: file_backup /path/to/file.txt /path/to/backup/\n");
}

int create_directory(const char *path) {
    struct stat st = {0};
    if (stat(path, &st) == -1) {
        if (mkdir(path, 0700) == -1) {
            perror("Error creating backup directory");
            return -1;
        }
    }
    return 0;
}

int backup_file(const char *source_file, const char *backup_folder) {
    FILE *source = fopen(source_file, "rb");
    if (!source) {
        perror("Error opening source file");
        return -1;
    }

    char backup_file[MAX_PATH];
    snprintf(backup_file, sizeof(backup_file), "%s/%s.bak", backup_folder, strrchr(source_file, '/') + 1);

    FILE *destination = fopen(backup_file, "wb");
    if (!destination) {
        perror("Error opening backup file");
        fclose(source);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, destination);
        if (bytes_written < bytes_read) {
            perror("Error writing to backup file");
            fclose(source);
            fclose(destination);
            return -1;
        }
    }

    if (ferror(source)) {
        perror("Error reading source file");
    }

    fclose(source);
    fclose(destination);
    printf("Backup successful: %s\n", backup_file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_help();
        return EXIT_FAILURE;
    }

    const char *source_file = argv[1];
    const char *backup_folder = argv[2];

    if (create_directory(backup_folder) == -1) {
        return EXIT_FAILURE;
    }

    if (backup_file(source_file, backup_folder) == -1) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}