//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define BUFFER_SIZE 8192

void create_backup_directory(const char *backup_dir) {
    struct stat st = {0};
    if (stat(backup_dir, &st) == -1) {
        mkdir(backup_dir, 0700);
    }
}

void copy_file(const char *source_path, const char *destination_path) {
    FILE *src_file = fopen(source_path, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest_file = fopen(destination_path, "wb");
    if (!dest_file) {
        perror("Failed to create destination file");
        fclose(src_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

void get_current_time(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 100, "%Y%m%d_%H%M%S", t);
}

void backup_file(const char *file_path, const char *backup_dir) {
    char timestamp[100];
    get_current_time(timestamp);

    char *file_name = strrchr(file_path, '/');
    file_name = (file_name == NULL) ? (char *)file_path : (file_name + 1);

    char backup_file_path[MAX_PATH_LENGTH];
    snprintf(backup_file_path, sizeof(backup_file_path), "%s/%s_%s.bak", backup_dir, file_name, timestamp);

    copy_file(file_path, backup_file_path);
    printf("Backup of '%s' created at '%s'\n", file_path, backup_file_path);
}

void backup_directory(const char *dir_path, const char *backup_dir) {
    DIR *dir = opendir(dir_path);
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char source_path[MAX_PATH_LENGTH];
        snprintf(source_path, sizeof(source_path), "%s/%s", dir_path, entry->d_name);
        
        if (entry->d_type == DT_DIR) {
            char new_backup_dir[MAX_PATH_LENGTH];
            snprintf(new_backup_dir, sizeof(new_backup_dir), "%s/%s", backup_dir, entry->d_name);
            create_backup_directory(new_backup_dir);
            backup_directory(source_path, new_backup_dir);
        } else if (entry->d_type == DT_REG) {
            backup_file(source_path, backup_dir);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory_or_file> <backup_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source = argv[1];
    const char *backup_dir = argv[2];

    create_backup_directory(backup_dir);

    struct stat st;
    if (stat(source, &st) == -1) {
        perror("Source path error");
        return EXIT_FAILURE;
    }

    if (S_ISDIR(st.st_mode)) {
        backup_directory(source, backup_dir);
    } else if (S_ISREG(st.st_mode)) {
        backup_file(source, backup_dir);
    } else {
        fprintf(stderr, "Unsupported file type\n");
        return EXIT_FAILURE;
    }

    printf("Backup process completed!\n");
    return EXIT_SUCCESS;
}