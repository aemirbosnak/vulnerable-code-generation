//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_BACKUP_SIZE 10

typedef struct Backup {
    char original[MAX_PATH];
    char backup[MAX_PATH];
} Backup;

void create_backup(const char *filename, const char *backup_dir) {
    char backup_path[MAX_PATH];
    snprintf(backup_path, sizeof(backup_path), "%s/%s.bak", backup_dir, filename);
    
    FILE *src = fopen(filename, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }
    
    FILE *dest = fopen(backup_path, "wb");
    if (!dest) {
        perror("Failed to open backup file");
        fclose(src);
        return;
    }

    char buffer[8192];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(src);
    fclose(dest);
    printf("Backup of %s created at %s\n", filename, backup_path);
}

void list_backups(const char *backup_dir) {
    DIR *dir = opendir(backup_dir);
    if (!dir) {
        perror("Failed to open backup directory");
        return;
    }

    struct dirent *entry;
    printf("List of backups in %s:\n", backup_dir);
    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".bak")) {
            printf("- %s\n", entry->d_name);
        }
    }
    closedir(dir);
}

void restore_backup(const char *backup_name, const char *restore_dir) {
    char original_path[MAX_PATH];
    char backup_path[MAX_PATH];
    
    snprintf(backup_path, sizeof(backup_path), "%s/%s", restore_dir, backup_name);
    char *dot = strrchr(backup_name, '.');
    if (dot) {
        snprintf(original_path, sizeof(original_path), "%s/%.*s", restore_dir, (int)(dot - backup_name), backup_name);
    } else {
        printf("Invalid backup filename.\n");
        return;
    }

    FILE *src = fopen(backup_path, "rb");
    if (!src) {
        perror("Failed to open backup file");
        return;
    }

    FILE *dest = fopen(original_path, "wb");
    if (!dest) {
        perror("Failed to open target file");
        fclose(src);
        return;
    }

    char buffer[8192];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Restored %s from backup %s\n", original_path, backup_name);
}

void remove_old_backups(const char *backup_dir) {
    DIR *dir = opendir(backup_dir);
    if (!dir) {
        perror("Failed to open backup directory");
        return;
    }

    struct dirent *entry;
    Backup backups[MAX_BACKUP_SIZE];
    int count = 0;

    while ((entry = readdir(dir)) != NULL && count < MAX_BACKUP_SIZE) {
        if (strstr(entry->d_name, ".bak")) {
            snprintf(backups[count].backup, sizeof(backups[count].backup), "%s/%s", backup_dir, entry->d_name);
            snprintf(backups[count].original, sizeof(backups[count].original), "%s/%.*s", backup_dir, 
                     (int)(strstr(entry->d_name, ".bak") - entry->d_name), entry->d_name);
            count++;
        }
    }
    closedir(dir);

    if (count >= MAX_BACKUP_SIZE) {
        printf("Removing the oldest backup: %s\n", backups[0].backup);
        remove(backups[0].backup);
        for (int i = 1; i < count; i++) {
            backups[i - 1] = backups[i];
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <file-to-backup> <backup-dir>\n", argv[0]);
        return 1;
    }

    const char *file_to_backup = argv[1];
    const char *backup_dir = argv[2];

    mkdir(backup_dir, 0777);  // Create backup directory if it doesn't exist
    remove_old_backups(backup_dir);  // Clean up old backups
    create_backup(file_to_backup, backup_dir);  // Create a backup
    
    list_backups(backup_dir);  // List all backups

    // Example restore call
    // Modify the "example.bak" to match a file in the backup directory
    // restore_backup("example.bak", backup_dir);

    return 0;
}