//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LEN 512
#define BACKUP_DIR "cyber_backup/"

void create_backup_directory() {
    struct stat st = {0};

    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

void get_current_time(char *buffer, size_t size) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, size, "%Y%m%d_%H%M%S", timeinfo);
}

void create_backup(const char *source_file) {
    char backup_file[MAX_PATH_LEN];
    char timestamp[20];

    get_current_time(timestamp, sizeof(timestamp));
    snprintf(backup_file, sizeof(backup_file), "%s%s_backup_%s.bak", BACKUP_DIR, source_file, timestamp);

    FILE *source = fopen(source_file, "rb");
    FILE *dest = fopen(backup_file, "wb");

    if (source == NULL) {
        fprintf(stderr, "Error: Source file '%s' cannot be opened.\n", source_file);
        return;
    }

    if (dest == NULL) {
        fprintf(stderr, "Error: Destination file '%s' cannot be created.\n", backup_file);
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
    printf("Backup of '%s' created as '%s'\n", source_file, backup_file);
}

void backup_files_from_directory(const char *dir_path) {
    DIR *d;
    struct dirent *dir;

    d = opendir(dir_path);

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG) { // Check if the entry is a regular file
                char full_path[MAX_PATH_LEN];
                snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, dir->d_name);
                create_backup(full_path);
            }
        }
        closedir(d);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_backup>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *source_directory = argv[1];

    create_backup_directory();
    backup_files_from_directory(source_directory);

    printf("Neon lights flicker as the backups are securely stored in \"%s\"\n", BACKUP_DIR);
    return EXIT_SUCCESS;
}