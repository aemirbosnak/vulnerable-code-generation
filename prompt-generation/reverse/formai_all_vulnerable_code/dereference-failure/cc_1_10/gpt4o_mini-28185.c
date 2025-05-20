//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

// Function prototypes
void displayMenu();
void backupFile(const char *sourceFile, const char *backupDir);
void createBackupDirectory(const char *backupDir);
int isFileExists(const char *filename);

int main() {
    char sourceFile[256];
    char backupDir[256];
    int choice;

    printf("Welcome to the Relaxed File Backup System!\n");
    printf("Let's make your files safe and sound.\n");

    // Get the backup directory from the user
    printf("Enter the backup directory: ");
    scanf("%s", backupDir);
    createBackupDirectory(backupDir);

    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Backup a file
                printf("Enter the path of the file to backup: ");
                scanf("%s", sourceFile);
                if (isFileExists(sourceFile)) {
                    backupFile(sourceFile, backupDir);
                } else {
                    printf("File does not exist! Please check the path.\n");
                }
                break;
            case 2:
                // Exit the program
                printf("Exiting. Your files are safe!\n");
                exit(0);
            case 3:
                // List backed up files
                printf("Files backed up in %s:\n", backupDir);
                DIR *dir = opendir(backupDir);
                struct dirent *entry;
                while ((entry = readdir(dir)) != NULL) {
                    if (entry->d_name[0] != '.') { // Skip hidden files
                        printf("- %s\n", entry->d_name);
                    }
                }
                closedir(dir);
                break;
            case 4:
                // Help menu
                printf("Help Menu:\n");
                printf("1. Backup a file: Provide the file path to back it up.\n");
                printf("2. Exit: Close the program.\n");
                printf("3. List backed up files: Show all files in the backup directory.\n");
                printf("4. Help: Display this help menu.\n");
                break;
            default:
                printf("Invalid choice! Please select between 1 to 4.\n");
                break;
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Menu ===\n");
    printf("1. Backup a File\n");
    printf("2. Exit\n");
    printf("3. List Backed Up Files\n");
    printf("4. Help\n");
}

void backupFile(const char *sourceFile, const char *backupDir) {
    char backupFilePath[512];
    snprintf(backupFilePath, sizeof(backupFilePath), "%s/%s.backup", backupDir, strrchr(sourceFile, '/') ? strrchr(sourceFile, '/') + 1 : sourceFile);

    FILE *source = fopen(sourceFile, "rb");
    if (!source) {
        printf("Error: Unable to open source file.\n");
        return;
    }

    FILE *dest = fopen(backupFilePath, "wb");
    if (!dest) {
        printf("Error: Unable to create backup file.\n");
        fclose(source);
        return;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    printf("Backup of '%s' created at '%s'.\n", sourceFile, backupFilePath);
    fclose(source);
    fclose(dest);
}

void createBackupDirectory(const char *backupDir) {
    struct stat st = {0};
    if (stat(backupDir, &st) == -1) {
        mkdir(backupDir, 0700);
        printf("Backup directory created at: %s\n", backupDir);
    } else {
        printf("Backup directory already exists at: %s\n", backupDir);
    }
}

int isFileExists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}