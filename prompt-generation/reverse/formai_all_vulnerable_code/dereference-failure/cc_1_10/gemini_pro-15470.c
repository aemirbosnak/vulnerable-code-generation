//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

// Define the maximum number of files to backup
#define MAX_FILES 100

// Define the maximum size of a file to backup (in bytes)
#define MAX_FILE_SIZE 1024 * 1024 * 1024

// Define the backup directory
#define BACKUP_DIR "/tmp/backups/"

// Define the log file
#define LOG_FILE "/tmp/backup.log"

// Function to get the current time
char *get_current_time() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *time_str = malloc(sizeof(char) * 100);
    strftime(time_str, 100, "%Y-%m-%d %H:%M:%S", tm);
    return time_str;
}

// Function to log a message to the log file
void log_message(char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(1);
    }
    fprintf(log_file, "%s: %s\n", get_current_time(), message);
    fclose(log_file);
}

// Function to create a backup directory
void create_backup_dir() {
    if (mkdir(BACKUP_DIR, 0755) != 0) {
        perror("Error creating backup directory");
        exit(1);
    }
}

// Function to get a list of files to backup
char **get_files_to_backup(int *num_files) {
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        exit(1);
    }
    struct dirent *entry;
    char **files = malloc(sizeof(char *) * MAX_FILES);
    int i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            struct stat statbuf;
            if (stat(entry->d_name, &statbuf) != 0) {
                perror("Error getting file status");
                exit(1);
            }
            if (statbuf.st_size <= MAX_FILE_SIZE) {
                files[i] = malloc(sizeof(char) * strlen(entry->d_name) + 1);
                strcpy(files[i], entry->d_name);
                i++;
            }
        }
    }
    closedir(dir);
    *num_files = i;
    return files;
}

// Function to backup a file
void backup_file(char *file) {
    FILE *src_file = fopen(file, "r");
    if (src_file == NULL) {
        perror("Error opening source file");
        exit(1);
    }
    char *backup_file_name = malloc(sizeof(char) * strlen(BACKUP_DIR) + strlen(file) + 1);
    strcpy(backup_file_name, BACKUP_DIR);
    strcat(backup_file_name, file);
    FILE *dst_file = fopen(backup_file_name, "w");
    if (dst_file == NULL) {
        perror("Error opening destination file");
        exit(1);
    }
    char buffer[1024];
    int num_bytes_read;
    while ((num_bytes_read = fread(buffer, 1, 1024, src_file)) > 0) {
        fwrite(buffer, 1, num_bytes_read, dst_file);
    }
    fclose(src_file);
    fclose(dst_file);
    log_message("File backed up: ");
}

// Function to run the backup system
void run_backup_system() {
    create_backup_dir();
    int num_files;
    char **files = get_files_to_backup(&num_files);
    for (int i = 0; i < num_files; i++) {
        backup_file(files[i]);
    }
    log_message("Backup system complete.");
}

// Main function
int main() {
    run_backup_system();
    return 0;
}