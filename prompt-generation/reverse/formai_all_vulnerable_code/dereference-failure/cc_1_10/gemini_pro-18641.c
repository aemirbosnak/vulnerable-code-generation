//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

// Define backup file extension
#define BACKUP_EXT ".bak"

// Define maximum file size
#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100 MB

// Define backup directory
#define BACKUP_DIR "backup"

// Function to get current time as a string
char *get_current_time() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *time_str = malloc(sizeof(char) * 20);
    strftime(time_str, 20, "%Y-%m-%d_%H-%M-%S", tm);
    return time_str;
}

// Function to create a backup directory if it does not exist
void create_backup_dir() {
    DIR *dir = opendir(BACKUP_DIR);
    if (dir == NULL) {
        mkdir(BACKUP_DIR, 0755);
    }
    closedir(dir);
}

// Function to get the size of a file
long get_file_size(const char *filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

// Function to copy a file
void copy_file(const char *src_filename, const char *dst_filename) {
    FILE *src_file = fopen(src_filename, "rb");
    if (src_file == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *dst_file = fopen(dst_filename, "wb");
    if (dst_file == NULL) {
        perror("Error opening destination file");
        fclose(src_file);
        return;
    }

    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
}

// Function to create a backup of a file
void backup_file(const char *filename) {
    // Check if file is too large
    long file_size = get_file_size(filename);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File %s is too large to backup (%ld MB).\n", filename, file_size / (1024 * 1024));
        return;
    }

    // Get current time
    char *time_str = get_current_time();

    // Create backup file name
    char *backup_filename = malloc(sizeof(char) * (strlen(filename) + strlen(BACKUP_EXT) + strlen(time_str) + 1));
    strcpy(backup_filename, filename);
    strcat(backup_filename, "_");
    strcat(backup_filename, time_str);
    strcat(backup_filename, BACKUP_EXT);

    // Create backup directory if it does not exist
    create_backup_dir();

    // Copy file to backup directory
    char *backup_path = malloc(sizeof(char) * (strlen(BACKUP_DIR) + strlen(backup_filename) + 2));
    strcpy(backup_path, BACKUP_DIR);
    strcat(backup_path, "/");
    strcat(backup_path, backup_filename);
    copy_file(filename, backup_path);

    printf("Backup of file %s created successfully: %s\n", filename, backup_path);

    free(time_str);
    free(backup_filename);
    free(backup_path);
}

// Function to scan a directory for files and backup them
void backup_directory(const char *dir_name) {
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *path = malloc(sizeof(char) * (strlen(dir_name) + strlen(entry->d_name) + 2));
        strcpy(path, dir_name);
        strcat(path, "/");
        strcat(path, entry->d_name);

        if (entry->d_type == DT_REG) {
            backup_file(path);
        } else if (entry->d_type == DT_DIR) {
            backup_directory(path);
        }

        free(path);
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    backup_directory(argv[1]);

    return 0;
}