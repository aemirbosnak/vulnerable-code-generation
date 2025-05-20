//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a backup of a file
void backup_file(char *original_file_name, char *backup_file_name, char *backup_location) {
    FILE *original_file, *backup_file;

    // Open the original file
    original_file = fopen(original_file_name, "r");
    if (original_file == NULL) {
        printf("Error opening original file\n");
        exit(1);
    }

    // Open the backup file
    backup_file = fopen(backup_location, backup_file_name);
    if (backup_file == NULL) {
        printf("Error opening backup file\n");
        exit(1);
    }

    // Read the original file contents
    fseek(original_file, 0, SEEK_END);
    long file_size = ftell(original_file);
    rewind(original_file);

    char *file_contents = (char *)malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    fread(file_contents, file_size, 1, original_file);
    file_contents[file_size] = '\0';

    // Write the file contents to the backup file
    fwrite(file_contents, file_size, 1, backup_file);

    // Close the files
    fclose(original_file);
    fclose(backup_file);
}

// Function to restore a backup to the original file
void restore_file(char *original_file_name, char *backup_file_name, char *backup_location) {
    FILE *original_file, *backup_file;

    // Open the original file
    original_file = fopen(original_file_name, "w");
    if (original_file == NULL) {
        printf("Error opening original file\n");
        exit(1);
    }

    // Open the backup file
    backup_file = fopen(backup_location, backup_file_name);
    if (backup_file == NULL) {
        printf("Error opening backup file\n");
        exit(1);
    }

    // Read the backup file contents
    fseek(backup_file, 0, SEEK_END);
    long file_size = ftell(backup_file);
    rewind(backup_file);

    char *backup_contents = (char *)malloc(file_size + 1);
    if (backup_contents == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    fread(backup_contents, file_size, 1, backup_file);
    backup_contents[file_size] = '\0';

    // Write the backup contents to the original file
    fwrite(backup_contents, file_size, 1, original_file);

    // Close the files
    fclose(original_file);
    fclose(backup_file);
}

int main() {
    char original_file_name[100], backup_file_name[100], backup_location[100];
    printf("Enter the original file name: ");
    fgets(original_file_name, sizeof(original_file_name), stdin);
    printf("Enter the backup file name: ");
    fgets(backup_file_name, sizeof(backup_file_name), stdin);
    printf("Enter the backup location: ");
    fgets(backup_location, sizeof(backup_location), stdin);

    // Create a backup
    backup_file(original_file_name, backup_file_name, backup_location);

    // Restore the backup
    restore_file(original_file_name, backup_file_name, backup_location);

    return 0;
}