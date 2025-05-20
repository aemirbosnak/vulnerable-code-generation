//FormAI DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * The purpose of this program is to create a backup system
 * for C files. The program will prompt the user for the name
 * of the file they want to backup. If the file exists,
 * it will create a backup file with a suffix of ".bak".
 * The program will then prompt the user to continue editing
 * the original file or switch to the backup file.
 *
 * Author: Chatbot
 */

int main(void) {
    char filename[100], backupname[100];
    FILE *file, *backup;
    int choice, count = 1;

    printf("Welcome to the C File Backup System!\n");
    printf("Please enter the name of the file you want to backup: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if(file == NULL) {
        printf("Error: The file %s does not exist.\n", filename);
        return 1;
    } else {
        printf("The file %s has been found.\n", filename);
        fclose(file);
    }

    sprintf(backupname, "%s.bak%d", filename, count);
    backup = fopen(backupname, "w");

    file = fopen(filename, "r");

    if(backup == NULL) {
        printf("Error: Could not create backup file.\n");
        return 1;
    } else {
        printf("Backup file %s has been created.\n", backupname);
        count++;
    }

    char ch;

    while((ch = fgetc(file)) != EOF) {
        fputc(ch, backup);
    }

    fclose(file);
    fclose(backup);

    printf("Would you like to continue editing %s or switch to %s?\n", filename, backupname);
    printf("1) Continue editing %s\n", filename);
    printf("2) Switch to %s\n", backupname);
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have chosen to continue editing %s.\n", filename);
            break;
        case 2:
            printf("You have chosen to switch to %s.\n", backupname);
            remove(filename);
            rename(backupname, filename);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}