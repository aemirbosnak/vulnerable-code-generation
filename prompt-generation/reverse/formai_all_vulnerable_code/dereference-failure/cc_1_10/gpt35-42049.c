//FormAI DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100 // Maximum number of files that can be backed up
#define MAX_FILENAME_LENGTH 50 // Maximum length for file names
#define MAX_BACKUP_NAME_LENGTH 100 // Maximum length for backup names

// Function prototypes
int backup_files(char **files, int num_files, char *backup_name);
int print_all_files(char **files, int num_files);

int main() {
    char *files[MAX_FILES]; // Array to hold file names
    int num_files = 0; // Number of files currently in array

    int option = -1; // User-selected menu option

    char backup_name[MAX_BACKUP_NAME_LENGTH]; // Name for backup

    while (option != 0) {
        // Print menu options
        printf("\n====== FILE BACKUP SYSTEM ======\n");
        printf("1. Backup Files\n");
        printf("2. Print All Files\n");
        printf("0. Exit\n");

        // Get user input
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Get backup name from user
                printf("\nEnter backup name: ");
                scanf("%s", backup_name);

                // Get file names from user and add to array
                char file_name[MAX_FILENAME_LENGTH];
                printf("\nEnter file names (type 'done' to finish):\n");
                while (1) {
                    scanf("%s", file_name);

                    if (strcmp(file_name, "done") == 0) {
                        break;
                    }

                    // Allocate space for file name in array
                    files[num_files] = (char*) malloc(strlen(file_name) * sizeof(char));
                    strcpy(files[num_files], file_name);
                    num_files++;
                }

                // Call backup_files function
                if (backup_files(files, num_files, backup_name) == 0) {
                    // Backup successful
                    printf("\nBackup successful!\n");
                } else {
                    // Backup failed
                    printf("\nBackup failed.\n");
                }

                // Free memory allocated for file names in array
                for (int i = 0; i < num_files; i++) {
                    free(files[i]);
                }
                num_files = 0;

                break;
            case 2:
                // Call print_all_files function
                print_all_files(files, num_files);
                break;
            case 0:
                // Exit program
                printf("\nExiting program...\n");
                break;
            default:
                // Invalid option selected
                printf("\nInvalid option selected.\n");
                break;
        }
    }

    return 0;
}

// Function to backup files
int backup_files(char **files, int num_files, char *backup_name) {
    FILE *backup_file; // Pointer to backup file
    char file_name[MAX_FILENAME_LENGTH]; // Array to hold file names from file array

    // Create backup file
    backup_file = fopen(backup_name, "w");

    if (backup_file == NULL) {
        // Unable to create backup file
        return -1;
    }

    // Write each file name to backup file
    for (int i = 0; i < num_files; i++) {
        strcpy(file_name, files[i]);

        // Open file for reading
        FILE *file = fopen(file_name, "r");

        if (file == NULL) {
            // Unable to open file for reading
            return -1;
        }

        // Copy contents of file to backup file
        char c;
        while ((c = fgetc(file)) != EOF) {
            fputc(c, backup_file);
        }

        // Add newline character to separate files
        fputc('\n', backup_file);

        // Close file
        fclose(file);
    }

    // Close backup file
    fclose(backup_file);

    return 0;
}

// Function to print all file names in array
int print_all_files(char **files, int num_files) {
    if (num_files == 0) {
        // No files in array
        printf("\nNo files to print.\n");
        return 0;
    }

    printf("\nFiles:\n");

    for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i]);
    }

    return 0;
}