//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME_LEN 256
#define BACKUP_DIR "backups/"
#define DATE_FORMAT_SIZE 20

// Function to create backup directory if it doesn't exist
void create_backup_directory() {
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

// Function to get the current date and time as a formatted string
void get_current_datetime(char *buffer, size_t size) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(buffer, size, "%04d-%02d-%02d_%02d-%02d-%02d",
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
             tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// Function to create a backup of the specified file
int create_backup(const char *filename) {
    char backup_filename[MAX_FILENAME_LEN];
    char datetime[DATE_FORMAT_SIZE];

    get_current_datetime(datetime, sizeof(datetime));
    
    snprintf(backup_filename, sizeof(backup_filename), "%s%s_%s.bak", 
             BACKUP_DIR, filename, datetime);
    
    FILE *source = fopen(filename, "rb");
    if (source == NULL) {
        fprintf(stderr, "Error opening source file %s: %s\n", filename, strerror(errno));
        return -1;
    }
    
    FILE *destination = fopen(backup_filename, "wb");
    if (destination == NULL) {
        fclose(source);
        fprintf(stderr, "Error creating backup file %s: %s\n", backup_filename, strerror(errno));
        return -1;
    }
    
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    printf("Backup created successfully: %s\n", backup_filename);
    return 0;
}

// Function to display the usage information
void display_usage() {
    printf("Usage: file_backup [file1] [file2] ... [fileN]\n");
    printf("Creates backups of the specified files in the '%s' directory.\n", BACKUP_DIR);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        display_usage();
    }

    create_backup_directory();

    for (int i = 1; i < argc; i++) {
        printf("Backing up %s...\n", argv[i]);
        if (create_backup(argv[i]) != 0) {
            fprintf(stderr, "Failed to backup: %s\n", argv[i]);
        }
    }

    printf("All specified backups processed.\n");
    return 0;
}