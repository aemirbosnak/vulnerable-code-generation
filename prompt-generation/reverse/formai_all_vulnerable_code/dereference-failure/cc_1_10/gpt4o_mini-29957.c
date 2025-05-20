//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024

void log_event(const char *event) {
    FILE *log_file = fopen("system_admin.log", "a");
    if (log_file) {
        time_t now;
        time(&now);
        fprintf(log_file, "[%s] %s\n", ctime(&now), event);
        fclose(log_file);
    } else {
        perror("Log file error:");
    }
}

void list_directory(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        log_event("Failed to open directory");
        return;
    }

    log_event("Listing directory contents:");
    printf("Contents of %s:\n", path);
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') {
            printf("%s\n", entry->d_name);
            log_event(entry->d_name);
        }
    }
    closedir(dp);
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        log_event("Failed to create file");
        perror("File creation error:");
        return;
    }
    fprintf(file, "This is a test file created by the system administration program.\n");
    fclose(file);
    log_event("Created a new file");
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        log_event("Deleted a file");
        printf("Deleted file: %s\n", filename);
    } else {
        log_event("Failed to delete file");
        perror("File deletion error:");
    }
}

void display_disk_usage() {
    system("df -h > disk_usage.txt");
    log_event("Disk usage details saved to disk_usage.txt");
    printf("Disk usage details saved to disk_usage.txt\n");
}

void backup_directory(const char *source, const char *destination) {
    char command[MAX_PATH_LENGTH];
    snprintf(command, sizeof(command), "cp -r %s %s", source, destination);
    if (system(command) == 0) {
        log_event("Directory backup completed");
        printf("Backup from %s to %s completed!\n", source, destination);
    } else {
        log_event("Directory backup failed");
        perror("Backup error:");
    }
}

int main() {
    char choice;
    char path[MAX_PATH_LENGTH];
    char filename[MAX_PATH_LENGTH];
    char backup_path[MAX_PATH_LENGTH];

    printf("=== System Administration Tool ===\n");
    log_event("Started System Administration Tool");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. List directory contents\n");
        printf("2. Create a file\n");
        printf("3. Delete a file\n");
        printf("4. Display disk usage\n");
        printf("5. Backup a directory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        choice = getchar();
        while (getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case '1':
                printf("Enter directory path to list: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = '\0'; // Remove newline
                list_directory(path);
                break;
            case '2':
                printf("Enter filename to create: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                create_file(filename);
                break;
            case '3':
                printf("Enter filename to delete: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                delete_file(filename);
                break;
            case '4':
                display_disk_usage();
                break;
            case '5':
                printf("Enter source directory: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = '\0'; // Remove newline
                printf("Enter destination for backup: ");
                fgets(backup_path, sizeof(backup_path), stdin);
                backup_path[strcspn(backup_path, "\n")] = '\0'; // Remove newline
                backup_directory(path, backup_path);
                break;
            case '6':
                log_event("Exiting System Administration Tool");
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}