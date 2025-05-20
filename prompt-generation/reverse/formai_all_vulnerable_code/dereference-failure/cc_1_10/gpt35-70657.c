//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    printf("Welcome to the C File Backup System!\n\n");

    char original_file[50], backup_file[50];

    printf("Enter the name of the file you wish to backup: ");
    scanf("%s", original_file);

    // open the original file
    FILE *original = fopen(original_file, "r");
    if (original == NULL) 
    {
        printf("Could not open %s\n", original_file);
        exit(1);
    }

    printf("\nEnter the name of the backup file: ");
    scanf("%s", backup_file);

    // check if backup file already exists
    FILE *backup = fopen(backup_file, "r");
    if (backup != NULL) 
    {
        printf("\nThe file %s already exists, would you like to overwrite it?\n", backup_file);
        char answer;
        scanf(" %c", &answer);
        if (answer == 'y' || answer == 'Y') 
        {
            fclose(backup);
            backup = fopen(backup_file, "w");
        }
        else 
        {
            fclose(original);
            exit(0);
        }
    } 
    else 
    {
        backup = fopen(backup_file, "w");
    }

    char c;
    while ((c = getc(original)) != EOF) 
    {
        putc(c, backup);
    }

    fclose(original);
    fclose(backup);

    printf("\n%s has been successfully backed up to %s!\n", original_file, backup_file);

    return 0;
}