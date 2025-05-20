//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

#define MAX_SIZE 256
#define LOG_FILE "admin_log.txt"
#define BACKUP_DIR "backup/"
#define FILE_PERMISSIONS 0644

void log_event(const char *event) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "%s: %s\n", event, ctime(&(time_t){time(NULL)}));
    fclose(log_file);
}

void create_backup(const char *source_file) {
    char command[MAX_SIZE];
    snprintf(command, sizeof(command), "cp %s %s%s.bak", source_file, BACKUP_DIR, source_file);
    if (system(command) == -1) {
        perror("Backup failed");
        exit(EXIT_FAILURE);
    }
    log_event("Backup created");
}

void create_directory(const char *dir) {
    if (mkdir(dir, 0755) == -1) {
        perror("Directory creation failed");
        exit(EXIT_FAILURE);
    }
    log_event("New directory created");
}

void list_files(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);

    if (dp == NULL) {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }

    printf("Files in directory '%s':\n", directory);
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') // Skip hidden files
            printf("%s\n", entry->d_name);
    }
    closedir(dp);
}

void monitor_disk_usage() {
    char command[MAX_SIZE];
    snprintf(command, sizeof(command), "df -h > %s", LOG_FILE);
    if (system(command) == -1) {
        perror("Disk usage monitoring failed");
        exit(EXIT_FAILURE);
    }
    log_event("Disk usage monitored");
}

void print_usage() {
    printf("Usage:\n");
    printf("1: Create Backup\n");
    printf("2: Create Directory\n");
    printf("3: List Files\n");
    printf("4: Monitor Disk Usage\n");
    printf("5: Exit\n");
}

int main(int argc, char *argv[]) {
    char input[MAX_SIZE];
    int choice;

    // Create backup directory if it doesn't exist
    struct stat st;
    if (stat(BACKUP_DIR, &st) == -1) {
        create_directory(BACKUP_DIR);
    }

    // Main loop
    while (1) {
        print_usage();
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:
                {
                    char source_file[MAX_SIZE];
                    printf("Enter the source file for backup: ");
                    fgets(source_file, sizeof(source_file), stdin);
                    source_file[strcspn(source_file, "\n")] = 0; // Remove newline
                    create_backup(source_file);
                }
                break;
            case 2:
                {
                    char dir_name[MAX_SIZE];
                    printf("Enter the name of directory to create: ");
                    fgets(dir_name, sizeof(dir_name), stdin);
                    dir_name[strcspn(dir_name, "\n")] = 0; // Remove newline
                    create_directory(dir_name);
                }
                break;
            case 3:
                {
                    char dir_name[MAX_SIZE];
                    printf("Enter the directory to list files: ");
                    fgets(dir_name, sizeof(dir_name), stdin);
                    dir_name[strcspn(dir_name, "\n")] = 0; // Remove newline
                    list_files(dir_name);
                }
                break;
            case 4:
                monitor_disk_usage();
                printf("Disk usage logged successfully.\n");
                break;
            case 5:
                printf("Exiting...\n");
                log_event("Admin program exited");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}