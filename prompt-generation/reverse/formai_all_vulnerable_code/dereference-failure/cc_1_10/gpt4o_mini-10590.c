//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024
#define BACKUP_DIR "backup"

void create_backup_directory() {
    struct stat st = {0};

    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
        printf("Backup directory created: %s\n", BACKUP_DIR);
    } else {
        printf("Backup directory already exists: %s\n", BACKUP_DIR);
    }
}

void copy_file(const char *src, const char *dest) {
    FILE *sourceFile = fopen(src, "rb");
    FILE *destFile = fopen(dest, "wb");

    if (sourceFile == NULL) {
        fprintf(stderr, "Error: Cannot open source file %s\n", src);
        return;
    }
    
    if (destFile == NULL) {
        fprintf(stderr, "Error: Cannot create destination file %s\n", dest);
        fclose(sourceFile);
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);
    printf("Backed up file: %s to %s\n", src, dest);
}

int is_file(const char *path) {
    struct stat statbuf;
    return (stat(path, &statbuf) == 0 && S_ISREG(statbuf.st_mode));
}

void backup_file(const char *file_path) {
    char dest[MAX_PATH_LEN];
    snprintf(dest, sizeof(dest), "%s/%s.bak", BACKUP_DIR, basename(file_path));
    copy_file(file_path, dest);
}

void list_files_in_directory(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    if (dir == NULL) {
        fprintf(stderr, "Error: Cannot open directory %s\n", dir_path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH_LEN];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            if (is_file(full_path)) {
                backup_file(full_path);
            }
        }
    }

    closedir(dir);
}

void display_help() {
    printf("Simple C File Backup System\n");
    printf("Usage:\n");
    printf("  backup -d [directory_path] : Backup all files in the specified directory.\n");
    printf("  backup -h                   : Display this help message.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_help();
        return 1;
    }

    if (strcmp(argv[1], "-d") == 0) {
        create_backup_directory();
        list_files_in_directory(argv[2]);
    } else if (strcmp(argv[1], "-h") == 0) {
        display_help();
    } else {
        display_help();
        return 1;
    }

    printf("Backup process completed successfully.\n");
    return 0;
}