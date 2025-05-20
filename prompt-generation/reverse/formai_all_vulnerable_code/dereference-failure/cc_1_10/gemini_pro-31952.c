//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BACKUPS_PATH "/backups/"
#define MAX_PATH_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 // 1MB

// Function to get the current timestamp as a string
char* get_timestamp() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *timestamp = malloc(sizeof(char) * 30);
    strftime(timestamp, 30, "%Y-%m-%d_%H-%M-%S", tm);
    return timestamp;
}

// Function to create a backup of a file
int backup_file(char *file_path) {
    // Get the file size
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Create the backup path
    char backup_path[MAX_PATH_LENGTH];
    sprintf(backup_path, "%s%s_%s.bak", BACKUPS_PATH, get_timestamp(), file_path);

    // Create the backup file
    FILE *backup_file = fopen(backup_path, "wb");
    if (backup_file == NULL) {
        perror("Error creating backup file");
        fclose(file);
        return -1;
    }

    // Copy the file contents to the backup file
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    // Close the files
    fclose(file);
    fclose(backup_file);

    return 0;
}

// Function to restore a backup file
int restore_file(char *file_path, char *backup_path) {
    // Get the file size
    FILE *backup_file = fopen(backup_path, "rb");
    if (backup_file == NULL) {
        perror("Error opening backup file");
        return -1;
    }
    fseek(backup_file, 0, SEEK_END);
    long file_size = ftell(backup_file);
    fseek(backup_file, 0, SEEK_SET);

    // Create the restored file
    FILE *file = fopen(file_path, "wb");
    if (file == NULL) {
        perror("Error creating restored file");
        fclose(backup_file);
        return -1;
    }

    // Copy the backup file contents to the restored file
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), backup_file)) > 0) {
        fwrite(buffer, 1, bytes_read, file);
    }

    // Close the files
    fclose(backup_file);
    fclose(file);

    return 0;
}

// Function to print the help message
void print_help() {
    printf("Usage:\n");
    printf("  backup_system [command] [arguments]\n");
    printf("\nCommands:\n");
    printf("  backup  <file_path>  Creates a backup of the specified file\n");
    printf("  restore <file_path> <backup_path>  Restores the specified file from the specified backup\n");
    printf("  help    Displays this help message\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Parse the command-line arguments
    if (argc < 2) {
        print_help();
        return 0;
    }

    char *command = argv[1];

    if (strcmp(command, "backup") == 0) {
        if (argc != 3) {
            printf("Error: Invalid number of arguments for backup command\n");
            print_help();
            return -1;
        }

        char *file_path = argv[2];

        if (backup_file(file_path) != 0) {
            printf("Error: Failed to backup file\n");
            return -1;
        }

        printf("File backed up successfully\n");
    } else if (strcmp(command, "restore") == 0) {
        if (argc != 4) {
            printf("Error: Invalid number of arguments for restore command\n");
            print_help();
            return -1;
        }

        char *file_path = argv[2];
        char *backup_path = argv[3];

        if (restore_file(file_path, backup_path) != 0) {
            printf("Error: Failed to restore file\n");
            return -1;
        }

        printf("File restored successfully\n");
    } else if (strcmp(command, "help") == 0) {
        print_help();
    } else {
        printf("Error: Invalid command\n");
        print_help();
        return -1;
    }

    return 0;
}