//FormAI DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1000

void createBackup(char fileName[]);
void restoreBackup(char fileName[]);
void deleteOldBackups(char fileName[]);

int main()
{
    char fileName[MAX_FILE_SIZE];

    printf("Enter the file name to backup: ");
    fgets(fileName, MAX_FILE_SIZE, stdin);
    fileName[strcspn(fileName, "\n")] = 0; // remove trailing newline character from fgets

    createBackup(fileName);

    printf("Backup created successfully.\n");

    restoreBackup(fileName);

    printf("Backup restored successfully.\n");

    deleteOldBackups(fileName);

    printf("Old backups deleted successfully.\n");

    return 0;
}

void createBackup(char fileName[])
{
    char backupFileName[MAX_FILE_SIZE + 30];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // get current date and time to append to backup file name
    sprintf(backupFileName, "%s_backup_%d-%02d-%02d_%02d-%02d-%02d.txt", fileName,
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    FILE *file = fopen(fileName, "r");
    FILE *backupFile = fopen(backupFileName, "w");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    if (backupFile == NULL)
    {
        printf("Error creating backup file.\n");
        exit(1);
    }

    // copy contents of original file to backup file
    int c;
    while ((c = fgetc(file)) != EOF)
    {
        fputc(c, backupFile);
    }

    fclose(file);
    fclose(backupFile);
}

void restoreBackup(char fileName[])
{
    char backupFileName[MAX_FILE_SIZE + 30];
    printf("Enter the backup file name to restore from: ");
    fgets(backupFileName, MAX_FILE_SIZE + 30, stdin);
    backupFileName[strcspn(backupFileName, "\n")] = 0;

    FILE *file = fopen(fileName, "w");
    FILE *backupFile = fopen(backupFileName, "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    if (backupFile == NULL)
    {
        printf("Error opening backup file.\n");
        exit(1);
    }

    // copy contents of backup file to original file
    int c;
    while ((c = fgetc(backupFile)) != EOF)
    {
        fputc(c, file);
    }

    fclose(file);
    fclose(backupFile);
}

void deleteOldBackups(char fileName[])
{
    char command[MAX_FILE_SIZE + 40];
    sprintf(command, "find . -type f -name \"%s_backup_*\" -mtime +7 -exec rm {} \\;", fileName);

    // execute command to delete all backups older than 7 days
    system(command);
}