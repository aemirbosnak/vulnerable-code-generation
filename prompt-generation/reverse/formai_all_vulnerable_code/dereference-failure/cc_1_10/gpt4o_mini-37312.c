//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void create_backup(const char* source, const char* destination) {
    FILE *src_file = fopen(source, "rb");
    if (src_file == NULL) {
        perror("Could not open source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest_file = fopen(destination, "wb");
    if (dest_file == NULL) {
        perror("Could not open destination file");
        fclose(src_file);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        fwrite(buffer, 1, bytes, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
    printf("Backup created from %s to %s\n", source, destination);
}

void backup_directory(const char* source_dir, const char* backup_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Could not open source directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char src_path[1024];
            char dest_path[1024];

            snprintf(src_path, sizeof(src_path), "%s/%s", source_dir, entry->d_name);
            snprintf(dest_path, sizeof(dest_path), "%s/%s.bak", backup_dir, entry->d_name);

            struct stat sb;
            if (stat(src_path, &sb) == -1) {
                perror("stat error");
                continue;
            }

            if (S_ISREG(sb.st_mode)) {
                create_backup(src_path, dest_path);
            } else if (S_ISDIR(sb.st_mode)) {
                mkdir(dest_path, 0755); // Create subdirectory
                backup_directory(src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <backup_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *backup = argv[2];

    struct stat sb;
    if (stat(source, &sb) == -1) {
        perror("Source error");
        return EXIT_FAILURE;
    }

    if (!S_ISDIR(sb.st_mode)) {
        fprintf(stderr, "Source must be a directory\n");
        return EXIT_FAILURE;
    }

    mkdir(backup, 0755);  // Create backup directory if it does not exist
    backup_directory(source, backup);

    printf("Backup completed successfully.\n");
    return EXIT_SUCCESS;
}