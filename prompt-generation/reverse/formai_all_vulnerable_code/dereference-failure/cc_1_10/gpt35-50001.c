//FormAI DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the file name
#define MAX_FILENAME_LENGTH 100

// Define the maximum length of the backup file name
#define MAX_BACKUP_FILENAME_LENGTH 120

// Define the maximum length of the command line input
#define MAX_INPUT_LENGTH 1000

// Define the backup directory
#define BACKUP_DIRECTORY "backup/"

void backup(char* filename);

int main()
{
    char input[MAX_INPUT_LENGTH];

    // Prompt the user for a file name to backup
    printf("Enter file name to backup: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove the newline character from the end of the string
    strtok(input, "\n");

    // Call the backup function with the input file name
    backup(input);

    return 0;
}

void backup(char* filename)
{
    FILE* fp, * backupfp;
    char backupfilename[MAX_BACKUP_FILENAME_LENGTH];
    char line[MAX_INPUT_LENGTH];

    // Create the backup directory if it does not exist
    system("mkdir -p " BACKUP_DIRECTORY);

    // Open the input file for reading
    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    // Create a backup file name with the current date and time
    snprintf(backupfilename, MAX_BACKUP_FILENAME_LENGTH, BACKUP_DIRECTORY "%s_%s.bak", filename, __TIME__);

    // Open the backup file for writing
    backupfp = fopen(backupfilename, "w");

    if(backupfp == NULL)
    {
        printf("Error: Could not create backup file %s.\n", backupfilename);
        return;
    }

    // Copy the contents of the input file to the backup file
    while(fgets(line, MAX_INPUT_LENGTH, fp) != NULL)
    {
        fputs(line, backupfp);
    }

    printf("File %s backed up successfully to %s.\n", filename, backupfilename);

    // Close the input and backup files
    fclose(fp);
    fclose(backupfp);
}