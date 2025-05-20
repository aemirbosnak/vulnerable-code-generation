//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

#define MAX_PATH 4096
#define BACKUP_DIR "backup"
#define TIME_FORMAT "%Y-%m-%d_%H-%M-%S"

// Function to get the current timestamp as a string
void get_current_time(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, TIME_FORMAT, t);
}

// Function to create a backup directory if it doesn't exist
void create_backup_directory() {
    struct stat st = {0};

    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

// Function to copy a file to the backup directory
void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Source file opening failed");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        perror("Destination file opening failed");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

// Function to perform the backup of a file
void backup_file(const char *filename) {
    char timestamp[20];
    get_current_time(timestamp, sizeof(timestamp));

    char backup_filename[MAX_PATH];
    snprintf(backup_filename, sizeof(backup_filename), "%s/%s_%s.bak", BACKUP_DIR, filename, timestamp);
    
    copy_file(filename, backup_filename);
    printf("Backup of %s created: %s\n", filename, backup_filename);
}

// Function to backup all files in the given directory
void backup_directory(const char *directory) {
    DIR *dir = opendir(directory);
    if (!dir) {
        perror("Directory opening failed");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filepath[MAX_PATH];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            backup_file(filepath);
        }
    }

    closedir(dir);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file or directory to backup>\n", argv[0]);
        return EXIT_FAILURE;
    }

    create_backup_directory();

    struct stat path_stat;
    stat(argv[1], &path_stat);

    if (S_ISREG(path_stat.st_mode)) {
        backup_file(argv[1]);
    } else if (S_ISDIR(path_stat.st_mode)) {
        backup_directory(argv[1]);
    } else {
        fprintf(stderr, "Error: Not a valid file or directory\n");
    }

    return EXIT_SUCCESS;
}