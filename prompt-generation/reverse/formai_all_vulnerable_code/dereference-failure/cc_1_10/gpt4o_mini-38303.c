//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_DIR_LENGTH 512
#define BUFFER_SIZE 1024

void create_backup_directory(const char *backup_dir) {
    if (mkdir(backup_dir, 0755) == -1 && errno != EEXIST) {
        perror("Error creating backup directory");
        exit(EXIT_FAILURE);
    }
}

void get_timestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, 25, "%Y%m%d%H%M%S", tm_info);
}

void backup_file(const char *source_file, const char *backup_dir) {
    FILE *src = fopen(source_file, "rb");
    if (!src) {
        perror("Error opening source file");
        return;
    }

    char backup_file[MAX_FILENAME_LENGTH + MAX_BACKUP_DIR_LENGTH];
    char timestamp[25];
    get_timestamp(timestamp);
    
    snprintf(backup_file, sizeof(backup_file), "%s/%s_%s.bak", backup_dir, 
             strrchr(source_file, '/') ? strrchr(source_file, '/') + 1 : source_file, timestamp);

    FILE *dest = fopen(backup_file, "wb");
    if (!dest) {
        perror("Error creating backup file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, dest);
    }
    
    fclose(src);
    fclose(dest);
    printf("Backup created: %s\n", backup_file);
}

void display_usage() {
    printf("Usage: backup_system <source_file> <backup_directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *source_file = argv[1];
    const char *backup_dir = argv[2];

    create_backup_directory(backup_dir);
    backup_file(source_file, backup_dir);

    return EXIT_SUCCESS;
}