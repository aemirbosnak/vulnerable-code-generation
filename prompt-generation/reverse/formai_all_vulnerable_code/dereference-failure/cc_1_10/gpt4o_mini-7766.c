//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024

void create_backup_directory(const char *backup_dir) {
    struct stat st = {0};
    if (stat(backup_dir, &st) == -1) {
        mkdir(backup_dir, 0700);
        printf("Backup directory created at: %s\n", backup_dir);
    } else {
        printf("Backup directory already exists: %s\n", backup_dir);
    }
}

void copy_file(const char *source, const char *destination) {
    FILE *src_file = fopen(source, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest_file = fopen(destination, "wb");
    if (!dest_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    printf("File copied from %s to %s\n", source, destination);
}

void backup_files(const char *source_dir, const char *backup_dir) {
    struct dirent *entry;
    DIR *dp = opendir(source_dir);
    if (!dp) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char source_path[MAX_PATH];
            char backup_path[MAX_PATH];

            snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
            snprintf(backup_path, sizeof(backup_path), "%s/%s", backup_dir, entry->d_name);

            if (entry->d_type == DT_DIR) {
                create_backup_directory(backup_path);  // Create directory in backup
                backup_files(source_path, backup_path); // Recursive call for directories
            } else if (entry->d_type == DT_REG) {  // Regular file
                copy_file(source_path, backup_path);
            }
        }
    }
    closedir(dp);
}

void show_usage() {
    printf("Usage: backup [source_directory] [backup_directory]\n");
    printf("Example: backup /home/user/documents /home/user/backup\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        show_usage();
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *backup_dir = argv[2];

    create_backup_directory(backup_dir);
    backup_files(source_dir, backup_dir);

    printf("Backup completed successfully.\n");
    return EXIT_SUCCESS;
}