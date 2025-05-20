//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

void print_usage() {
    printf("Usage: file_backup <source_directory> <backup_directory>\n");
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void copy_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (!dest) {
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

void backup_directory(const char *source, const char *backup) {
    DIR *dir = opendir(source);
    if (!dir) {
        perror("Error opening source directory");
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directories
        }

        char source_path[MAX_PATH];
        char backup_path[MAX_PATH];

        snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
        snprintf(backup_path, sizeof(backup_path), "%s/%s", backup, entry->d_name);

        if (is_directory(source_path)) {
            mkdir(backup_path, 0755); // Create the directory
            backup_directory(source_path, backup_path); // Recursive call
        } else {
            copy_file(source_path, backup_path); // Copy file
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_dir = argv[1];
    const char *backup_dir = argv[2];

    if (!is_directory(source_dir)) {
        fprintf(stderr, "Source path is not a directory: %s\n", source_dir);
        return EXIT_FAILURE;
    }

    if (!is_directory(backup_dir)) {
        if (mkdir(backup_dir, 0755) != 0) {
            perror("Error creating backup directory");
            return EXIT_FAILURE;
        }
    }

    backup_directory(source_dir, backup_dir);
    printf("Backup completed from '%s' to '%s'\n", source_dir, backup_dir);
    return EXIT_SUCCESS;
}