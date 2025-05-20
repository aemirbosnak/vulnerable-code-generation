//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 1024
#define BACKUP_DIR "backups"

void create_backup(const char *filename) {
    char command[MAX_PATH];
    snprintf(command, sizeof(command), "cp %s %s/%s.bak", filename, BACKUP_DIR, filename);
    system(command);
    printf("Backup of '%s' created successfully!\n", filename);
}

void list_backups() {
    struct dirent *entry;
    DIR *dp = opendir(BACKUP_DIR);
    
    if (dp == NULL) {
        printf("Error: Could not open backup directory '%s'\n", BACKUP_DIR);
        return;
    }
    
    printf("Existing Backups:\n");
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf(" - %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void restore_backup(const char *filename) {
    char command[MAX_PATH];
    snprintf(command, sizeof(command), "cp %s/%s %s", BACKUP_DIR, filename, filename);
    system(command);
    printf("Restored '%s' from backup successfully!\n", filename);
}

void print_menu() {
    printf("\n--- File Backup System ---\n");
    printf("1. Create Backup\n");
    printf("2. List Backups\n");
    printf("3. Restore Backup\n");
    printf("4. Exit\n");
    printf("-------------------------\n");
    printf("Choose an option: ");
}

int main() {
    char choice[2];
    char filename[MAX_PATH];

    // Create backup directory if it doesn't exist
    system("mkdir -p " BACKUP_DIR);

    while (1) {
        print_menu();
        fgets(choice, sizeof(choice), stdin);
        
        switch (atoi(choice)) {
            case 1:
                printf("Enter the filename to backup: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                create_backup(filename);
                break;
            case 2:
                list_backups();
                break;
            case 3:
                printf("Enter the backup filename to restore (e.g., file.txt.bak): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                restore_backup(filename);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}