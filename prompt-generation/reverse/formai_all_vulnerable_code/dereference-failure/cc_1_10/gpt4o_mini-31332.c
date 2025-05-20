//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>

// Function prototypes
void backup_file(const char *source, const char *destination);
void create_backup_directory(const char *backup_dir);
void list_files(const char *directory);
void backup_from_directory(const char *source_dir, const char *backup_dir);
void print_usage();

// Global variable to keep track of the backup directory
char backup_dir[256];

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage();
        return 1;
    }

    // Create backup directory if it does not exist
    strcpy(backup_dir, argv[2]);
    create_backup_directory(backup_dir);

    // Determine if source is a file or a directory
    struct stat path_stat;
    stat(argv[1], &path_stat);

    if (S_ISREG(path_stat.st_mode)) {
        // It's a file
        backup_file(argv[1], backup_dir);
    } else if (S_ISDIR(path_stat.st_mode)) {
        // It's a directory
        backup_from_directory(argv[1], backup_dir);
    } else {
        fprintf(stderr, "Error: %s is neither a file nor a directory.\n", argv[1]);
        return 1;
    }

    printf("Backup completed successfully to '%s'.\n", backup_dir);
    return 0;
}

void backup_file(const char *source, const char *destination) {
    char dest_path[512];
    snprintf(dest_path, sizeof(dest_path), "%s/%s", destination, strrchr(source, '/') + 1);

    FILE *source_file = fopen(source, "rb");
    if (!source_file) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest_file = fopen(dest_path, "wb");
    if (!dest_file) {
        perror("Failed to create destination file");
        fclose(source_file);
        return;
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
    printf("Backup of file '%s' to '%s' completed!\n", source, dest_path);
}

void create_backup_directory(const char *backup_dir) {
    struct stat st;

    if (stat(backup_dir, &st) != 0) {
        if (mkdir(backup_dir, 0755) != 0) {
            perror("Error creating backup directory");
            exit(EXIT_FAILURE);
        }
    }
}

void list_files(const char *directory) {
    DIR *dir = opendir(directory);
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Print the file or directory name
            printf("Found file: %s\n", entry->d_name);
        }
    }
    closedir(dir);
}

void backup_from_directory(const char *source_dir, const char *backup_dir) {
    DIR *dir = opendir(source_dir);
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char source_path[512];
            snprintf(source_path, sizeof(source_path), "%s/%s", source_dir, entry->d_name);
            
            struct stat path_stat;
            stat(source_path, &path_stat);

            if (S_ISREG(path_stat.st_mode)) {
                backup_file(source_path, backup_dir);
            }
        }
    }

    closedir(dir);
}

void print_usage() {
    printf("Usage: file_backup <source> <destination>\n");
    printf("Backup a file or directory to the specified destination.\n");
    printf("Example:\n");
    printf("  file_backup my_file.txt /backup/location\n");
    printf("  file_backup my_directory /backup/location\n");
}