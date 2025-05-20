//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

// Function declarations
void create_backup(const char *source, const char *destination);
int copy_file(const char *source_file, const char *dest_file);
int is_directory(const char *path);
void backup_directory(const char *source_dir, const char *dest_dir);
void get_formatted_time(char *buffer, size_t size);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <backup_destination>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create backup
    create_backup(argv[1], argv[2]);
    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}

void create_backup(const char *source, const char *destination) {
    if (is_directory(source)) {
        backup_directory(source, destination);
    } else {
        // Creating parent directories for destination
        char dest_dir[512];
        snprintf(dest_dir, sizeof(dest_dir), "%s", destination);
        char *last_slash = strrchr(dest_dir, '/');
        if (last_slash) {
            *last_slash = '\0';
            mkdir(dest_dir, 0777);
        }
        copy_file(source, destination);
    }
}

// Function to copy file from source to destination
int copy_file(const char *source_file, const char *dest_file) {
    FILE *src = fopen(source_file, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return -1;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        fclose(src);
        perror("Error opening destination file");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}

// Function to check if a path is a directory
int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

// Function to backup an entire directory
void backup_directory(const char *source_dir, const char *dest_dir) {
    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        perror("Error opening source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[512];
        char dest_path[512];

        snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        if (is_directory(source_path)) {
            mkdir(dest_path, 0777); // Create a new directory for the backup
            backup_directory(source_path, dest_path);
        } else {
            copy_file(source_path, dest_path);
        }
    }

    closedir(dir);
}