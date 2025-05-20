//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

// Function to get the current timestamp
char* get_timestamp() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *timestamp = malloc(20);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", tm);
    return timestamp;
}

// Function to create a backup of a file
int create_backup(char *filename) {
    // Get the current timestamp
    char *timestamp = get_timestamp();

    // Create the backup filename
    char *backup_filename = malloc(strlen(filename) + strlen(timestamp) + 1);
    strcpy(backup_filename, filename);
    strcat(backup_filename, "_");
    strcat(backup_filename, timestamp);

    // Open the original file
    FILE *original_file = fopen(filename, "r");
    if (original_file == NULL) {
        printf("Error opening the original file: %s\n", filename);
        return -1;
    }

    // Open the backup file
    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error opening the backup file: %s\n", backup_filename);
        return -1;
    }

    // Copy the contents of the original file to the backup file
    char buffer[1024];
    while (fgets(buffer, 1024, original_file) != NULL) {
        fputs(buffer, backup_file);
    }

    // Close the original and backup files
    fclose(original_file);
    fclose(backup_file);

    // Free the allocated memory
    free(timestamp);
    free(backup_filename);

    return 0;
}

// Main function
int main() {
    // Get the filename from the user
    char filename[100];
    printf("Enter the filename to backup: ");
    scanf("%s", filename);

    // Create a backup of the file
    int result = create_backup(filename);
    if (result == -1) {
        printf("Error creating the backup\n");
    } else {
        printf("Backup created successfully\n");
    }

    return 0;
}