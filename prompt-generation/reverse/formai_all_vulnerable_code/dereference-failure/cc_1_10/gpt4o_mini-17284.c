//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 260
#define BUFFER_SIZE 1024

void display_help() {
    printf("Usage: file_backup [source_directory] [backup_directory]\n");
    printf("Copies files from source_directory to backup_directory.\n");
    printf("Example: file_backup ./myfiles ./backup\n");
}

int create_backup_directory(const char *backup_dir) {
    struct stat st = {0};
    if (stat(backup_dir, &st) == -1) {
        if (mkdir(backup_dir, 0700) != 0) {
            perror("Error creating backup directory");
            return -1;
        }
    }
    return 0;
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

void backup_files(const char *source_dir, const char *backup_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            char src_path[MAX_PATH], dest_path[MAX_PATH];
            snprintf(src_path, sizeof(src_path), "%s/%s", source_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", backup_dir, entry->d_name);
            copy_file(src_path, dest_path);
            printf("Copied: %s to %s\n", src_path, dest_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_help();
        return 1;
    }

    char *source_directory = argv[1];
    char *backup_directory = argv[2];

    if (create_backup_directory(backup_directory) != 0) {
        return 1;
    }

    backup_files(source_directory, backup_directory);
    printf("Backup completed successfully!\n");

    return 0;
}