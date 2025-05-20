//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH 1024
#define BACKUP_DIR "backups"

void create_backup_directory() {
    struct stat st;
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
        printf("Backup directory created: %s\n", BACKUP_DIR);
    } else {
        printf("Backup directory already exists: %s\n", BACKUP_DIR);
    }
}

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }
    FILE *dest = fopen(destination, "wb");
    if (!dest) {
        fclose(src);
        perror("Failed to open destination file");
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Backup of '%s' completed to '%s'\n", source, destination);
}

void backup_file(const char *file) {
    char backupPath[MAX_PATH];
    snprintf(backupPath, sizeof(backupPath), "%s/%s.bak", BACKUP_DIR, basename(file));
    
    copy_file(file, backupPath);
}

void list_files_in_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Only regular files
            printf("Found file: %s/%s\n", directory, entry->d_name);
            backup_file(entry->d_name);
        }
    }
    closedir(dp);
}

void backup_directory(const char *directory) {
    create_backup_directory();
    list_files_in_directory(directory);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_to_backup>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    backup_directory(argv[1]);

    printf("Backup operation completed. All files backed up to '%s/'\n", BACKUP_DIR);
    return 0;
}