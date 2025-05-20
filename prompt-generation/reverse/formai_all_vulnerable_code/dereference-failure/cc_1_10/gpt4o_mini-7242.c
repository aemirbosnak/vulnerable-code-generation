//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_PATH 512

// Function to get current timestamp as a string
void get_current_timestamp(char *timestamp, size_t length) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(timestamp, length, "%Y%m%d%H%M%S", t);
}

// Function to check if a path is a directory
int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

// Function to create a backup of a file
void backup_file(const char *file_path, const char *backup_dir) {
    char backup_file[MAX_BACKUP_PATH];
    char timestamp[20];

    get_current_timestamp(timestamp, sizeof(timestamp));

    snprintf(backup_file, sizeof(backup_file), "%s/%s_backup_%s", backup_dir, basename(file_path), timestamp);

    FILE *source = fopen(file_path, "rb");
    if (!source) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE *destination = fopen(backup_file, "wb");
    if (!destination) {
        fclose(source);
        perror("Error creating backup file");
        exit(EXIT_FAILURE);
    }

    size_t bytes;
    char buffer[BUFSIZ];
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    printf("Backup created: %s\n", backup_file);
}

// Function to perform backup of all files in the directory
void backup_directory(const char *dir_path, const char *backup_dir) {
    DIR *d;
    struct dirent *dir;

    d = opendir(dir_path);
    if (!d) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
            char full_path[MAX_BACKUP_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, dir->d_name);

            if (is_directory(full_path)) {
                backup_directory(full_path, backup_dir); // Recurse into subdirectory
            } else {
                backup_file(full_path, backup_dir); // Backup the file
            }
        }
    }
    closedir(d);
}

// Function to display usage information
void display_usage(const char *program_name) {
    printf("Usage: %s <source_path> <backup_directory>\n", program_name);
    printf("This program creates a backup of files and directories.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_path = argv[1];
    const char *backup_dir = argv[2];

    if (!is_directory(source_path)) {
        printf("Source path is not a directory. Treating it as a single file.\n");
        backup_file(source_path, backup_dir);
    } else {
        backup_directory(source_path, backup_dir);
    }

    return EXIT_SUCCESS;
}