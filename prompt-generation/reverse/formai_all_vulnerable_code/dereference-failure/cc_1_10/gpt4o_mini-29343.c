//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH 260
#define LOG_FILE "backup_log.txt"

void log_operation(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file != NULL) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    } else {
        perror("Error opening log file");
    }
}

int create_backup_directory(const char *backup_path) {
    struct stat st;
    if (stat(backup_path, &st) == -1) {
        if (mkdir(backup_path, 0755) == -1) {
            perror("Error creating backup directory");
            return -1;
        }
        log_operation("Backup directory created.");
    }
    return 0;
}

void copy_file(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    char message[MAX_PATH + 50];
    snprintf(message, sizeof(message), "Copied %s to %s", src_file, dest_file);
    log_operation(message);
}

void backup_files(const char *source_dir, const char *backup_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check for regular files
            char src_path[MAX_PATH];
            char dest_path[MAX_PATH];
            snprintf(src_path, sizeof(src_path), "%s/%s", source_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", backup_dir, entry->d_name);
            copy_file(src_path, dest_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <backup_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *backup_directory = argv[2];

    if (create_backup_directory(backup_directory) != 0) {
        return EXIT_FAILURE;
    }

    backup_files(source_directory, backup_directory);

    printf("Backup completed successfully.\n");
    return EXIT_SUCCESS;
}