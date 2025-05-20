//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_FILENAME_LEN 256
#define BUFFER_SIZE 8192

void print_usage() {
    printf("Usage: backup_system <source_directory> <backup_directory>\n");
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void create_backup(const char *src, const char *backup) {
    DIR *dir;
    struct dirent *entry;
    char src_path[MAX_FILENAME_LEN];
    char backup_path[MAX_FILENAME_LEN];

    if (!(dir = opendir(src))) {
        perror("Source directory could not be opened");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
            snprintf(backup_path, sizeof(backup_path), "%s/%s", backup, entry->d_name);

            if (is_directory(src_path)) {
                mkdir(backup_path, 0755); // Create sub-directory in backup
                create_backup(src_path, backup_path); // Recursive call
            } else {
                FILE *source_file = fopen(src_path, "rb");
                FILE *dest_file = fopen(backup_path, "wb");

                if (source_file && dest_file) {
                    char buffer[BUFFER_SIZE];
                    size_t bytes;

                    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, source_file)) > 0) {
                        fwrite(buffer, sizeof(char), bytes, dest_file);
                    }
                    printf("Backed up: %s to %s\n", src_path, backup_path);
                } else {
                    perror("File error");
                }

                fclose(source_file);
                fclose(dest_file);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *backup_directory = argv[2];

    if (!is_directory(source_directory)) {
        fprintf(stderr, "Error: Source directory does not exist or is not a directory.\n");
        return EXIT_FAILURE;
    }

    mkdir(backup_directory, 0755); // Create backup directory if it doesn't exist

    create_backup(source_directory, backup_directory);
    printf("Backup completed successfully!\n");

    return EXIT_SUCCESS;
}