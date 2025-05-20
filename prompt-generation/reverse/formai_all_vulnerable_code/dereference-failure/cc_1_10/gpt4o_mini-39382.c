//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 256
#define BACKUP_DIR "backup"

void create_backup_directory();
void get_current_time(char *buffer, size_t size);
void backup_file(const char *source_file);
void list_files(const char *path);
int is_file(const char *path);
void copy_file(const char *source, const char *destination);
void log_backup(const char *file_name);

int main() {
    char source_directory[MAX_PATH_LEN];

    printf("Welcome to the Imaginative C File Backup System!\n");
    printf("Please enter the directory you wish to backup: ");
    fgets(source_directory, sizeof(source_directory), stdin);
    source_directory[strcspn(source_directory, "\n")] = 0;  // Remove newline

    create_backup_directory();
    list_files(source_directory);

    return 0;
}

void create_backup_directory() {
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
        printf("Backup directory '%s' created successfully!\n", BACKUP_DIR);
    } else {
        printf("Backup directory '%s' already exists.\n", BACKUP_DIR);
    }
}

void get_current_time(char *buffer, size_t size) {
    time_t rawtime;
    struct tm *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, size, "%Y%m%d_%H%M%S", timeinfo);
}

void backup_file(const char *source_file) {
    char backup_file_path[MAX_PATH_LEN];
    char current_time[20];  
    get_current_time(current_time, sizeof(current_time));

    snprintf(backup_file_path, sizeof(backup_file_path), "%s/%s_backup_%s", BACKUP_DIR, strrchr(source_file, '/') + 1, current_time);
    
    copy_file(source_file, backup_file_path);
    log_backup(backup_file_path);
}

void list_files(const char *path) {
    struct dirent *dp;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("Couldn't open the directory");
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            char full_path[MAX_PATH_LEN];
            snprintf(full_path, sizeof(full_path), "%s/%s", path, dp->d_name);
            if (is_file(full_path)) {
                printf("Backing up file: %s\n", full_path);
                backup_file(full_path);
            }
        }
    }
    closedir(dir);
}

int is_file(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0 && S_ISREG(buffer.st_mode));
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");

    if (src == NULL || dest == NULL) {
        perror("File operation error");
        exit(1);
    }

    char buffer[1024];
    size_t n;

    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }

    fclose(src);
    fclose(dest);
    printf("File copied to: %s\n", destination);
}

void log_backup(const char *file_name) {
    FILE *log_file = fopen("backup_log.txt", "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        return;
    }
    fprintf(log_file, "%s backed up at %s\n", file_name, BACKUP_DIR);
    fclose(log_file);
    printf("Backup logged for: %s\n", file_name);
}