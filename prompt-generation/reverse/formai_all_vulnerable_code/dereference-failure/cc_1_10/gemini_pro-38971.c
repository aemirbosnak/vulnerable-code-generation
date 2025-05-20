//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

// Define the maximum size of a file path
#define MAX_PATH_SIZE 256

// Define the number of files to backup
#define NUM_FILES 5

// Define the directory to backup
#define BACKUP_DIR "backup"

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buf;
    return (stat(filename, &buf) == 0);
}

// Function to create a directory
int create_directory(const char *dirname) {
    return mkdir(dirname, 0755);
}

// Function to copy a file
int copy_file(const char *src, const char *dst) {
    FILE *src_file, *dst_file;

    // Open the source file
    src_file = fopen(src, "rb");
    if (src_file == NULL) {
        return -1;
    }

    // Open the destination file
    dst_file = fopen(dst, "wb");
    if (dst_file == NULL) {
        fclose(src_file);
        return -1;
    }

    // Copy the file data
    while (!feof(src_file)) {
        char buffer[1024];
        size_t bytes_read = fread(buffer, 1, 1024, src_file);
        fwrite(buffer, 1, bytes_read, dst_file);
    }

    // Close the files
    fclose(src_file);
    fclose(dst_file);

    return 0;
}

// Function to backup a file
int backup_file(const char *filename) {
    char backup_path[MAX_PATH_SIZE];

    // Create the backup directory if it doesn't exist
    if (!file_exists(BACKUP_DIR)) {
        if (create_directory(BACKUP_DIR) != 0) {
            return -1;
        }
    }

    // Create the backup path
    snprintf(backup_path, MAX_PATH_SIZE, "%s/%s", BACKUP_DIR, filename);

    // Copy the file to the backup path
    if (copy_file(filename, backup_path) != 0) {
        return -1;
    }

    return 0;
}

// Function to backup a directory
int backup_directory(const char *dirname) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    dir = opendir(dirname);
    if (dir == NULL) {
        return -1;
    }

    // Iterate over the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Create the full path to the file
        char filepath[MAX_PATH_SIZE];
        snprintf(filepath, MAX_PATH_SIZE, "%s/%s", dirname, entry->d_name);

        // Backup the file
        if (backup_file(filepath) != 0) {
            closedir(dir);
            return -1;
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}

int main() {
    // Get the current working directory
    char cwd[MAX_PATH_SIZE];
    getcwd(cwd, MAX_PATH_SIZE);

    // Backup the current working directory
    if (backup_directory(cwd) != 0) {
        return -1;
    }

    printf("Files backed up successfully!\n");

    return 0;
}