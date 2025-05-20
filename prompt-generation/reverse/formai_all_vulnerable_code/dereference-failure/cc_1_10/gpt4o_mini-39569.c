//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 1024
#define DEFAULT_BACKUP_DIR "backup"

// Function to get the current timestamp as a string
void get_current_timestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, 20, "%Y-%m-%d_%H-%M-%S", tm_info);
}

// Function to create a backup directory if it does not exist
void create_backup_dir(const char *backup_dir) {
    struct stat st;
    if (stat(backup_dir, &st) != 0) {
        mkdir(backup_dir, 0777);
    }
}

// Function to copy a file to the backup directory
int copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Error opening source file");
        return -1;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, sizeof(char), bytes, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}

// Function to create a backup of specified files
void backup_files(const char **files, int file_count, const char *backup_dir) {
    char timestamp[20];
    get_current_timestamp(timestamp);
    
    for (int i = 0; i < file_count; i++) {
        char backup_file[MAX_PATH];
        sprintf(backup_file, "%s/%s_%s.bak", backup_dir, strrchr(files[i], '/') ? strrchr(files[i], '/') + 1 : files[i], timestamp);
        
        printf("Backing up %s to %s\n", files[i], backup_file);
        if (copy_file(files[i], backup_file) != 0) {
            fprintf(stderr, "Failed to backup %s\n", files[i]);
        }
    }
}

// Function to list files in a directory
void list_files(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("Files in directory '%s':\n", dir_path);
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *backup_dir = DEFAULT_BACKUP_DIR;
    create_backup_dir(backup_dir);
    
    // Display files to backup
    printf("Files to backup:\n");
    for (int i = 1; i < argc; i++) {
        printf(" - %s\n", argv[i]);
    }

    // Backup files
    backup_files((const char**)&argv[1], argc - 1, backup_dir);

    // List backed up files
    list_files(backup_dir);

    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}