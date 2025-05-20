//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FILENAME_SIZE 256
#define MAX_BACKUP_FILES 100

void create_backup(const char *filename);
void list_backups();
void restore_backup(const char *backup_filename);
void clear_backups();
void show_usage();

char *backup_files[MAX_BACKUP_FILES];
int backup_count = 0;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        show_usage();
        return 1;
    }

    if (strcmp(argv[1], "backup") == 0 && argc >= 3) {
        create_backup(argv[2]);
    } else if (strcmp(argv[1], "list") == 0) {
        list_backups();
    } else if (strcmp(argv[1], "restore") == 0 && argc >= 3) {
        restore_backup(argv[2]);
    } else if (strcmp(argv[1], "clear") == 0) {
        clear_backups();
    } else {
        show_usage();
    }
    return 0;
}

void create_backup(const char *filename) {
    FILE *source_file = fopen(filename, "rb");
    if (!source_file) {
        perror("Error opening source file");
        return;
    }

    char backup_filename[FILENAME_SIZE];
    snprintf(backup_filename, sizeof(backup_filename), "%s.bak", filename);

    FILE *backup_file = fopen(backup_filename, "wb");
    if (!backup_file) {
        perror("Error creating backup file");
        fclose(source_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source_file)) != 0) {
        fwrite(buffer, 1, bytes, backup_file);
    }

    fclose(source_file);
    fclose(backup_file);

    backup_files[backup_count] = strdup(backup_filename);
    backup_count++;

    printf("Backup created: %s\n", backup_filename);
}

void list_backups() {
    printf("List of backup files:\n");
    for (int i = 0; i < backup_count; i++) {
        printf("  %s\n", backup_files[i]);
    }
    
    if (backup_count == 0) {
        printf("  No backups found.\n");
    }
}

void restore_backup(const char *backup_filename) {
    FILE *backup_file = fopen(backup_filename, "rb");
    if (!backup_file) {
        perror("Error opening backup file");
        return;
    }

    char original_filename[FILENAME_SIZE];
    snprintf(original_filename, sizeof(original_filename), "%s.tmp", backup_filename);

    FILE *restored_file = fopen(original_filename, "wb");
    if (!restored_file) {
        perror("Error creating the restored file");
        fclose(backup_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), backup_file)) != 0) {
        fwrite(buffer, 1, bytes, restored_file);
    }

    fclose(backup_file);
    fclose(restored_file);

    if (rename(original_filename, backup_filename) != 0) {
        perror("Error renaming the restored file");
    } else {
        printf("Restored file from backup: %s\n", backup_filename);
    }
}

void clear_backups() {
    for (int i = 0; i < backup_count; i++) {
        if (remove(backup_files[i]) == 0) {
            printf("Deleted backup file: %s\n", backup_files[i]);
            free(backup_files[i]);
        } else {
            perror("Error deleting backup file");
        }
    }
    backup_count = 0;
}

void show_usage() {
    printf("Usage: ./backup_system [command] [filename]\n");
    printf("Commands:\n");
    printf("  backup [filename]  : Creates a backup of the specified file\n");
    printf("  list               : Lists all backup files\n");
    printf("  restore [filename] : Restores the specified backup file\n");
    printf("  clear              : Deletes all backup files\n");
}