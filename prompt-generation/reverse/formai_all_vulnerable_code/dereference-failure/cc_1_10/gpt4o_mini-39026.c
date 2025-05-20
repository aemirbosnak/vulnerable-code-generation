//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

#define MAX_PATH 1024
#define BACKUP_EXT ".bak"
#define TIMESTAMP_SIZE 20

void get_current_timestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, TIMESTAMP_SIZE, "%Y%m%d_%H%M%S", t);
}

int create_backup(const char *source_path, const char *backup_path) {
    FILE *source_file = fopen(source_path, "rb");
    if (!source_file) {
        perror("Error opening source file");
        return -1;
    }

    FILE *backup_file = fopen(backup_path, "wb");
    if (!backup_file) {
        perror("Error creating backup file");
        fclose(source_file);
        return -1;
    }

    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes, backup_file);
    }

    fclose(source_file);
    fclose(backup_file);
    return 0;
}

void backup_file(const char *file_name) {
    char backup_name[MAX_PATH];
    char timestamp[TIMESTAMP_SIZE];
    get_current_timestamp(timestamp);
    
    snprintf(backup_name, sizeof(backup_name), "%s_%s%s", file_name, timestamp, BACKUP_EXT);
    
    if (create_backup(file_name, backup_name) == 0) {
        printf("Backup created: %s\n", backup_name);
    } else {
        fprintf(stderr, "Failed to backup: %s\n", file_name);
    }
}

void process_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') continue;  // Skip hidden files
        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISREG(statbuf.st_mode)) {
            backup_file(path);
        } else if (S_ISDIR(statbuf.st_mode)) {
            process_directory(path);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_directory(argv[1]);
    return EXIT_SUCCESS;
}