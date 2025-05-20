//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH 512
#define BACKUP_DIR "backup"

void create_backup_directory() {
    mkdir(BACKUP_DIR, 0755);
}

void get_current_time(char *buffer, size_t size) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(buffer, size, "%04d-%02d-%02d_%02d-%02d-%02d",
             tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
             tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void backup_file(const char *filename) {
    char backup_filename[MAX_PATH];
    char timestamp[20];
    
    get_current_time(timestamp, sizeof(timestamp));
    snprintf(backup_filename, sizeof(backup_filename), "%s/%s_%s.bak", BACKUP_DIR, filename, timestamp);
    
    FILE *source = fopen(filename, "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return;
    }
    
    FILE *dest = fopen(backup_filename, "wb");
    if (dest == NULL) {
        perror("Error creating backup file");
        fclose(source);
        return;
    }
    
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) != 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(source);
    fclose(dest);

    printf("Backup of '%s' created as '%s'\n", filename, backup_filename);
}

void backup_directory(const char *dir) {
    struct dirent *entry;
    DIR *dp = opendir(dir);

    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            char filepath[MAX_PATH];
            snprintf(filepath, sizeof(filepath), "%s/%s", dir, entry->d_name);
            backup_file(filepath);
        }
    }

    closedir(dp);
}

void display_help() {
    printf("Usage: file_backup [options] [file/directory]\n");
    printf("Options:\n");
    printf("  -h, --help    Show this help message\n");
    printf("If no options are provided, the program will backup the specified file/directory.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No file or directory specified.\n");
        display_help();
        return EXIT_FAILURE;
    }
    
    // Create backup directory if it doesn't exist
    create_backup_directory();

    // Processing command line arguments
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        display_help();
        return EXIT_SUCCESS;
    }

    struct stat path_stat;
    stat(argv[1], &path_stat);

    if (S_ISDIR(path_stat.st_mode)) {
        backup_directory(argv[1]);
    } else if (S_ISREG(path_stat.st_mode)) {
        backup_file(argv[1]);
    } else {
        fprintf(stderr, "Error: '%s' is neither a regular file nor a directory.\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}