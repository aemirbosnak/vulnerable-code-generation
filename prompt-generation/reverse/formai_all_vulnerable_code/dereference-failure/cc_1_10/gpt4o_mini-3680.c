//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILES 100

void print_usage() {
    printf("Usage: file_backup <source_directory> <backup_directory>\n");
    printf("This program will back up all files from the source directory to the backup directory.\n");
}

int is_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

void create_backup(const char *source, const char *backup) {
    struct dirent *entry;
    DIR *dp = opendir(source);
    
    if (!dp) {
        perror("opendir");
        return;
    }
    
    char source_path[MAX_PATH_LENGTH];
    char backup_path[MAX_PATH_LENGTH];
    
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] == '.') { // Skip hidden files and directories
            continue;
        }
        
        snprintf(source_path, sizeof(source_path), "%s/%s", source, entry->d_name);
        snprintf(backup_path, sizeof(backup_path), "%s/%s", backup, entry->d_name);
        
        if (is_file(source_path)) {
            FILE *src_file = fopen(source_path, "rb");
            FILE *dest_file = fopen(backup_path, "wb");

            if (src_file && dest_file) {
                char buffer[4096];
                size_t n;
                
                while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, n, dest_file);
                }
                fclose(src_file);
                fclose(dest_file);
                printf("Backed up: %s\n", source_path);
            } else {
                if (src_file) fclose(src_file);
                if (dest_file) fclose(dest_file);
                fprintf(stderr, "Error backing up file: %s\n", source_path);
            }
        }
    }
    
    closedir(dp);
}

void create_backup_directory(const char *backup) {
    struct stat st = {0};
    
    if (stat(backup, &st) == -1) {
        if (mkdir(backup, 0700) == -1) {
            perror("mkdir");
            exit(EXIT_FAILURE);
        }
        printf("Backup directory created at: %s\n", backup);
    } else {
        printf("Backup directory already exists at: %s\n", backup);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *backup_directory = argv[2];

    printf("Starting backup from '%s' to '%s'...\n", source_directory, backup_directory);

    create_backup_directory(backup_directory);
    create_backup(source_directory, backup_directory);

    printf("Backup completed successfully!\n");
    return EXIT_SUCCESS;
}