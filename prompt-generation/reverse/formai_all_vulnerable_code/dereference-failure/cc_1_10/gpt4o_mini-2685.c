//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_FILENAME_LENGTH 256
#define BACKUP_DIR "backups"

void create_backup_directory() {
    struct stat st = {0};

    if (stat(BACKUP_DIR, &st) == -1) {
        if (mkdir(BACKUP_DIR, 0700) != 0) {
            printf("Error creating backup directory: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
}

void backup_file(const char *filename) {
    FILE *source_file, *dest_file;
    char dest_filename[MAX_FILENAME_LENGTH];
    char ch;

    snprintf(dest_filename, sizeof(dest_filename), "%s/%s.bak", BACKUP_DIR, filename);
    
    source_file = fopen(filename, "rb");
    if (source_file == NULL) {
        printf("Error opening file %s: %s\n", filename, strerror(errno));
        return;
    }

    dest_file = fopen(dest_filename, "wb");
    if (dest_file == NULL) {
        printf("Error creating backup file %s: %s\n", dest_filename, strerror(errno));
        fclose(source_file);
        return;
    }

    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, dest_file);
    }

    printf("Backup of %s created as %s\n", filename, dest_filename);

    fclose(source_file);
    fclose(dest_file);
}

void list_backups() {
    FILE *fp;
    char path[1035];

    // Open the command for reading.
    fp = popen("ls backups", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    printf("List of backup files:\n");
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("%s", path);
    }

    // Close the command.
    pclose(fp);
}

int main() {
    int choice;
    char filename[MAX_FILENAME_LENGTH];

    create_backup_directory();

    while (1) {
        printf("\n=== File Backup System ===\n");
        printf("1. Create Backup\n");
        printf("2. List Backups\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the file name to backup: ");
                scanf("%s", filename);
                backup_file(filename);
                break;

            case 2:
                list_backups();
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}