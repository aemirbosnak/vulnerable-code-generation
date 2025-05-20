//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BACKUP_DIR "backup/"
#define DATE_FORMAT "%Y-%m-%d_%H-%M-%S"

void create_backup_directory() {
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

char* get_timestamp() {
    time_t rawtime;
    struct tm *timeinfo;
    char *timestamp = malloc(20);
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    strftime(timestamp, 20, DATE_FORMAT, timeinfo);
    return timestamp;
}

void copy_file(const char* source, const char* destination) {
    FILE *src = fopen(source, "rb");
    FILE *dst = fopen(destination, "wb");
    
    if (src == NULL || dst == NULL) {
        perror("File operation failed");
        exit(EXIT_FAILURE);
    }
    
    char buffer[1024];
    size_t n;
    
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }
    
    fclose(src);
    fclose(dst);
}

void backup_file(const char* filename) {
    char *timestamp = get_timestamp();
    char backup_filename[MAX_PATH];
    
    snprintf(backup_filename, MAX_PATH, "%s%s_%s.bak", BACKUP_DIR, filename, timestamp);
    copy_file(filename, backup_filename);
    
    printf("Backup created: %s\n", backup_filename);
    free(timestamp);
}

void backup_files_in_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Only regular files
            printf("Found file: %s\n", entry->d_name);
            backup_file(entry->d_name);
        }
    }
    
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    
    create_backup_directory();
    
    // Navigate to the source directory
    if (chdir(source_directory) != 0) {
        perror("Failed to change directory");
        return EXIT_FAILURE;
    }
    
    backup_files_in_directory(".");

    return EXIT_SUCCESS;
}