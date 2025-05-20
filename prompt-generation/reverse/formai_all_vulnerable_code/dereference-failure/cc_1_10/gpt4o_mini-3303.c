//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_FILENAME 256
#define MAX_BACKUP_DIR 512
#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: file_backup <source_file> <backup_directory>\n");
    printf("Backup a file to the specified directory.\n");
}

int create_backup_directory(const char *backup_dir) {
    struct stat st = {0};

    if (stat(backup_dir, &st) == -1) {
        if (mkdir(backup_dir, 0700) != 0) {
            perror("Error creating backup directory");
            return 0;
        }
    }
    return 1;
}

void backup_file(const char *source_file, const char *backup_dir) {
    char backup_path[MAX_BACKUP_DIR];
    FILE *source, *dest;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    snprintf(backup_path, sizeof(backup_path), "%s/%s.bak", backup_dir, source_file);

    if ((source = fopen(source_file, "rb")) == NULL) {
        perror("Error opening source file");
        return;
    }

    if ((dest = fopen(backup_path, "wb")) == NULL) {
        fclose(source);
        perror("Error creating backup file");
        return;
    }

    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dest);
    }

    fclose(source);
    fclose(dest);
    printf("Backup of '%s' created at '%s'.\n", source_file, backup_path);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    const char *source_file = argv[1];
    const char *backup_directory = argv[2];

    if (strlen(source_file) > MAX_FILENAME || strlen(backup_directory) > MAX_BACKUP_DIR) {
        fprintf(stderr, "Error: filename or directory is too long.\n");
        return 1;
    }

    if (!create_backup_directory(backup_directory)) {
        return 1;
    }

    backup_file(source_file, backup_directory);

    return 0;
}