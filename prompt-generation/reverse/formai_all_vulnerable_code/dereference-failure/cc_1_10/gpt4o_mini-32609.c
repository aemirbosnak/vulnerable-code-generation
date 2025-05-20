//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function prototypes
void create_backup(const char *source_dir, const char *backup_dir);
void copy_file(const char *source_file, const char *backup_file);
void handle_error(const char *message);
void display_usage();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return 1;
    }

    const char *source_dir = argv[1];
    const char *backup_dir = argv[2];

    create_backup(source_dir, backup_dir);
    printf("Backup of '%s' created successfully in '%s'\n", source_dir, backup_dir);
    return 0;
}

void create_backup(const char *source_dir, const char *backup_dir) {
    struct stat st;
    if (stat(source_dir, &st) != 0 || !S_ISDIR(st.st_mode)) {
        handle_error("Source directory does not exist or is not a directory");
    }

    // Create backup directory if it doesn't exist
    if (stat(backup_dir, &st) != 0) {
        if (mkdir(backup_dir, 0755) != 0) {
            handle_error("Failed to create backup directory");
        }
    }

    DIR *dir = opendir(source_dir);
    if (!dir) {
        handle_error("Failed to open source directory");
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip '.' and '..'
        }

        char source_path[PATH_MAX];
        char backup_path[PATH_MAX];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(backup_path, sizeof(backup_path), "%s/%s", backup_dir, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Create directory in backup
            if (mkdir(backup_path, 0755) != 0) {
                handle_error("Failed to create directory in backup");
            }
            // Recursive backup for directory
            create_backup(source_path, backup_path);
        } else if (entry->d_type == DT_REG) {
            // Copy regular file
            copy_file(source_path, backup_path);
        }
    }

    closedir(dir);
}

void copy_file(const char *source_file, const char *backup_file) {
    FILE *src = fopen(source_file, "rb");
    if (!src) {
        handle_error("Failed to open source file");
    }

    FILE *dest = fopen(backup_file, "wb");
    if (!dest) {
        fclose(src);
        handle_error("Failed to open backup file");
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    fclose(src);
    fclose(dest);
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void display_usage() {
    printf("Usage: file_backup <source_directory> <backup_directory>\n");
    printf("Example: file_backup /path/to/source /path/to/backup\n");
}