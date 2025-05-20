//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_BACKUPS 10
#define BACKUP_DIR "./backups/"

void create_backup_directory() {
    struct stat st;
    if (stat(BACKUP_DIR, &st) == -1) {
        if (errno == ENOENT) {
            // Directory doesn't exist, create it
            if (mkdir(BACKUP_DIR, 0777) == -1) {
                perror("Could not create backup directory");
                exit(EXIT_FAILURE);
            }
            printf("Backup directory created successfully: %s\n", BACKUP_DIR);
        } else {
            perror("Error checking backup directory");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Backup directory already exists: %s\n", BACKUP_DIR);
    }
}

void backup_file(const char *filename) {
    char backup_filename[256];
    int backup_count = 0;

    // Check for existing backups
    while (backup_count < MAX_BACKUPS) {
        snprintf(backup_filename, sizeof(backup_filename), "%s%s.bak.%d", BACKUP_DIR, filename, backup_count);
        if (access(backup_filename, F_OK) == -1) {
            // Backup file does not exist, we can use this name
            break;
        }
        backup_count++;
    }

    // If maximum backups reached, remove the oldest backup
    if (backup_count >= MAX_BACKUPS) {
        snprintf(backup_filename, sizeof(backup_filename), "%s%s.bak.%d", BACKUP_DIR, filename, 0);
        remove(backup_filename);
        printf("Removed oldest backup: %s\n", backup_filename);
        // Shift other backups down
        for (int i = 1; i < MAX_BACKUPS; i++) {
            snprintf(backup_filename, sizeof(backup_filename), "%s%s.bak.%d", BACKUP_DIR, filename, i);
            char new_filename[256];
            snprintf(new_filename, sizeof(new_filename), "%s%s.bak.%d", BACKUP_DIR, filename, i - 1);
            rename(backup_filename, new_filename);
        }
        backup_count = MAX_BACKUPS - 1;
    }

    // Perform the backup
    FILE *source = fopen(filename, "rb");
    if (!source) {
        perror("Could not open source file");
        exit(EXIT_FAILURE);
    }

    FILE *destination = fopen(backup_filename, "wb");
    if (!destination) {
        perror("Could not open destination file");
        fclose(source);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, sizeof(char), bytes, destination);
    }

    fclose(source);
    fclose(destination);
    printf("Backup created: %s\n", backup_filename);
}

void list_backups(const char *filename) {
    char backup_filename[256];
    printf("Listing backups for: %s\n", filename);
    for (int i = 0; i < MAX_BACKUPS; i++) {
        snprintf(backup_filename, sizeof(backup_filename), "%s%s.bak.%d", BACKUP_DIR, filename, i);
        if (access(backup_filename, F_OK) != -1) {
            printf("Found: %s\n", backup_filename);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];

    create_backup_directory();
    
    // Create a backup
    backup_file(filename);

    // List backups
    list_backups(filename);

    return EXIT_SUCCESS;
}