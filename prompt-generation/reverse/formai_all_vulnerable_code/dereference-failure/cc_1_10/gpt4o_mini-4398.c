//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 4096

void print_help() {
    printf("File Backup System\n");
    printf("Usage:\n");
    printf("  backup <source_directory> <backup_directory>\n");
    printf("  restore <backup_directory> <restore_directory>\n");
    printf("  list <backup_directory>\n");
    printf("  help\n");
}

void copy_file(const char *src, const char *dest) {
    int source_fd = open(src, O_RDONLY);
    if (source_fd < 0) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    int dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(source_fd);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    
    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to destination");
            close(source_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    close(source_fd);
    close(dest_fd);
}

void backup_directory(const char *src, const char *dest) {
    struct dirent *entry;
    DIR *dp = opendir(src);

    if (dp == NULL) {
        perror("Error opening source directory");
        exit(EXIT_FAILURE);
    }

    if (mkdir(dest, 0777) == -1) {
        perror("Error creating backup directory");
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char src_path[MAX_PATH_LENGTH];
            char dest_path[MAX_PATH_LENGTH];

            snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

            if (entry->d_type == DT_DIR) {
                backup_directory(src_path, dest_path);
            } else {
                copy_file(src_path, dest_path);
                printf("Copied: %s to %s\n", src_path, dest_path);
            }
        }
    }

    closedir(dp);
}

void list_backups(const char *backup_directory) {
    struct dirent *entry;
    DIR *dp = opendir(backup_directory);

    if (dp == NULL) {
        perror("Error opening backup directory");
        exit(EXIT_FAILURE);
    }

    printf("Backed up files in %s:\n", backup_directory);
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printf("  %s\n", entry->d_name);
        }
    }

    closedir(dp);
}

void restore_directory(const char *backup_dir, const char *restore_dir) {
    struct dirent *entry;
    DIR *dp = opendir(backup_dir);

    if (dp == NULL) {
        perror("Error opening backup directory");
        exit(EXIT_FAILURE);
    }

    if (mkdir(restore_dir, 0777) == -1) {
        perror("Error creating restore directory");
    }

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char backup_path[MAX_PATH_LENGTH];
            char restore_path[MAX_PATH_LENGTH];

            snprintf(backup_path, sizeof(backup_path), "%s/%s", backup_dir, entry->d_name);
            snprintf(restore_path, sizeof(restore_path), "%s/%s", restore_dir, entry->d_name);

            if (entry->d_type == DT_DIR) {
                restore_directory(backup_path, restore_path);
            } else {
                copy_file(backup_path, restore_path);
                printf("Restored: %s to %s\n", backup_path, restore_path);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "backup") == 0 && argc == 4) {
        backup_directory(argv[2], argv[3]);
    } else if (strcmp(argv[1], "restore") == 0 && argc == 4) {
        restore_directory(argv[2], argv[3]);
    } else if (strcmp(argv[1], "list") == 0 && argc == 3) {
        list_backups(argv[2]);
    } else if (strcmp(argv[1], "help") == 0) {
        print_help();
    } else {
        print_help();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}