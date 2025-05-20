//MISTRAL-7B DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BACKUP_DIR "backups/"
#define MAX_PATH 1024
#define MAX_FILENAME 256

// Function to create a backup of a file with a unique timestamp
void create_backup(char *file_path) {
    char backup_file[MAX_PATH];
    struct tm *current_time;
    time_t timestamp;

    current_time = localtime(&timestamp);

    strcpy(backup_file, BACKUP_DIR);
    strcat(backup_file, file_path);
    strcat(backup_file, "_");
    strftime(backup_file + strlen(backup_file), sizeof(backup_file) - strlen(backup_file) - 1, "%Y-%m-%d-%H-%M-%S.bak", current_time);

    if (rename(file_path, backup_file) != 0) {
        perror("Error creating backup file");
        exit(EXIT_FAILURE);
    }

    printf("Backup created: %s\n", backup_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char file_path[MAX_PATH];
    strcpy(file_path, argv[1]);

    // Create the backups directory if it doesn't exist
    if (access(BACKUP_DIR, 0) != 0) {
        if (mkdir(BACKUP_DIR, 0755) != 0) {
            perror("Error creating backups directory");
            exit(EXIT_FAILURE);
        }
    }

    // Create a backup of the specified file
    create_backup(file_path);

    return EXIT_SUCCESS;
}