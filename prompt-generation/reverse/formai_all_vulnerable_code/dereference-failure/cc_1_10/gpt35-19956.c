//FormAI DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_CONTENT_LENGTH 65536
#define MAX_BACKUP_COUNT 5

typedef struct Backup {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
} Backup;

int main() {
    Backup backups[MAX_BACKUP_COUNT];
    int backupCount = 0;
    
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to backup: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character
    
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s: %s\n", filename, strerror(errno));
        exit(1);
    }
    
    // Read file content
    char content[MAX_FILE_CONTENT_LENGTH];
    int bytesRead = fread(content, 1, MAX_FILE_CONTENT_LENGTH - 1, file);
    content[bytesRead] = '\0'; // Add null terminator
    
    // Create backup
    Backup backup;
    strcpy(backup.filename, filename);
    strcpy(backup.content, content);
    
    // Add backup to backups array
    if (backupCount < MAX_BACKUP_COUNT) {
        backups[backupCount++] = backup;
    } else {
        char *backupFilename = backups[0].filename;
        printf("Deleting oldest backup: %s\n", backupFilename);
        for (int i = 1; i < MAX_BACKUP_COUNT; i++) {
            backups[i - 1] = backups[i];
        }
        backups[MAX_BACKUP_COUNT - 1] = backup;
        printf("Overwriting backup: %s\n", backupFilename);
    }
    
    // Write backup to file
    char backupFilename[MAX_FILENAME_LENGTH];
    sprintf(backupFilename, "%s.bak", filename);
    FILE *backupFile;
    backupFile = fopen(backupFilename, "w");
    if (backupFile == NULL) {
        printf("Error opening backup file %s: %s\n", backupFilename, strerror(errno));
        exit(1);
    }
    fputs(content, backupFile);
    fclose(backupFile);
    
    fclose(file);
    
    printf("Backup complete!\n");
    
    return 0;
}