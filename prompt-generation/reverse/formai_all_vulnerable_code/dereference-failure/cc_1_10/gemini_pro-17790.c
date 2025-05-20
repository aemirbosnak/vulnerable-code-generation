//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Define the maximum number of files to backup
#define MAX_FILES 100

// Define the maximum size of a file that can be backed up
#define MAX_FILE_SIZE 1024 * 1024

// Define the path to the backup directory
#define BACKUP_DIR "/tmp/backups"

// Define the file extension for backup files
#define BACKUP_EXT ".bak"

// Function to get the current time
time_t get_current_time() {
    time_t t;
    time(&t);
    return t;
}

// Function to get the file size
long get_file_size(const char *path) {
    struct stat st;
    stat(path, &st);
    return st.st_size;
}

// Function to create a backup of a file
int backup_file(const char *path) {
    // Check if the file size is greater than the maximum file size
    long file_size = get_file_size(path);
    if (file_size > MAX_FILE_SIZE) {
        printf("File size is too large to backup: %s\n", path);
        return -1;
    }

    // Get the current time
    time_t t = get_current_time();

    // Create a backup file name
    char backup_file[256];
    snprintf(backup_file, sizeof(backup_file), "%s.%ld%s", path, t, BACKUP_EXT);

    // Open the original file for reading
    FILE *fp_read = fopen(path, "rb");
    if (fp_read == NULL) {
        printf("Error opening file for reading: %s\n", path);
        return -1;
    }

    // Open the backup file for writing
    FILE *fp_write = fopen(backup_file, "wb");
    if (fp_write == NULL) {
        printf("Error opening backup file for writing: %s\n", backup_file);
        fclose(fp_read);
        return -1;
    }

    // Copy the data from the original file to the backup file
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp_read)) > 0) {
        fwrite(buffer, 1, bytes_read, fp_write);
    }

    // Close the files
    fclose(fp_read);
    fclose(fp_write);

    return 0;
}

// Function to backup all files in a directory
int backup_directory(const char *path) {
    // Open the directory
    DIR *d = opendir(path);
    if (d == NULL) {
        printf("Error opening directory: %s\n", path);
        return -1;
    }

    // Iterate over the files in the directory
    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if the file is a regular file
        struct stat st;
        stat(entry->d_name, &st);
        if (!S_ISREG(st.st_mode)) {
            continue;
        }

        // Backup the file
        char file_path[256];
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);
        backup_file(file_path);
    }

    // Close the directory
    closedir(d);

    return 0;
}

// Main function
int main() {
    // Create the backup directory if it doesn't exist
    if (mkdir(BACKUP_DIR, 0755) != 0) {
        printf("Error creating backup directory: %s\n", BACKUP_DIR);
        return -1;
    }

    // Backup all files in the current directory
    backup_directory(".");

    return 0;
}