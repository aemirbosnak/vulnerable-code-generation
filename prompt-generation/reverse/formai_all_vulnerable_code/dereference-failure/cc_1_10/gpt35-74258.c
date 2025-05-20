//FormAI DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFER_SIZE 1024

char *get_time() {
    time_t raw_time;
    struct tm *time_info;
    char *buffer = (char *) malloc(sizeof(char) * 80);

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(buffer, 80, "%Y-%m-%d_%H-%M-%S", time_info);

    return buffer;
}

void backup_directory(char *source_dir, char *backup_dir) {
    DIR *dir;
    struct dirent *entry;
    char source_path[BUFFER_SIZE], backup_path[BUFFER_SIZE];
    struct stat stat_buf;

    dir = opendir(source_dir);
    if (!dir) {
        printf("Error opening directory %s\n", source_dir);
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        strcpy(source_path, source_dir);
        strcat(source_path, "/");
        strcat(source_path, entry->d_name);

        if (lstat(source_path, &stat_buf) == -1) {
            printf("Failed to lstat %s, skipping...\n", source_path);
            continue;
        }

        if (S_ISDIR(stat_buf.st_mode)) {
            char backup_subdir[BUFFER_SIZE];
            sprintf(backup_subdir, "%s/%s", backup_dir, entry->d_name);

            if (access(backup_subdir, F_OK) == -1) {
                // Create directory if it does not exist
                mkdir(backup_subdir, stat_buf.st_mode);
            }

            backup_directory(source_path, backup_subdir);
        } else if (S_ISREG(stat_buf.st_mode)) {
            char *timestamp = get_time();
            sprintf(backup_path, "%s/%s_%s", backup_dir, entry->d_name, timestamp);
            free(timestamp);

            FILE *source_file = fopen(source_path, "rb");
            if (!source_file) {
                printf("Failed to read %s, skipping...\n", source_path);
                continue;
            }

            FILE *backup_file = fopen(backup_path, "wb");
            if (!backup_file) {
                printf("Failed to write to %s, skipping...\n", backup_path);
                fclose(source_file);
                continue;
            }

            size_t n;
            unsigned char buffer[BUFFER_SIZE];
            while ((n = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
                fwrite(buffer, 1, n, backup_file);
            }

            fclose(source_file);
            fclose(backup_file);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_dir backup_dir\n", argv[0]);
        return 1;
    }

    backup_directory(argv[1], argv[2]);

    return 0;
}