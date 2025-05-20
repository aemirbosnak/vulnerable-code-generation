//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

// Function to get current date and time
char* getDateTime() {
    time_t now = time(NULL);
    char* date_time = asctime(localtime(&now));
    date_time[strlen(date_time) - 1] = '\0'; // remove newline character
    return date_time;
}

int main() {
    char file_name[MAX_SIZE], backup_name[MAX_SIZE], command[MAX_SIZE + 50];
    char* date_time;
    int option;
    FILE *source, *backup;

    printf("***Welcome to C File Backup System***\n");

    printf("Enter filename to backup: ");
    fgets(file_name, MAX_SIZE, stdin);
    file_name[strlen(file_name) - 1] = '\0'; // remove newline character

    // Check if file exists
    if ((source = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Error: File %s not found\n", file_name);
        exit(EXIT_FAILURE);
    }

    // Generate backup file name with date and time
    date_time = getDateTime();
    sprintf(backup_name, "%s_backup_%s.c", file_name, date_time);

    printf("Backup file name will be: %s\n", backup_name);

    // Open backup file for writing
    backup = fopen(backup_name, "w");

    // Copy contents of source file to backup file
    int c;
    while ((c = fgetc(source)) != EOF) {
        fputc(c, backup);
    }

    printf("Backup successful\n");

    // Ask user if they want to view contents of backup file
    printf("Do you want to view the contents of the backup file? (1 = yes, 0 = no): ");
    scanf("%d", &option);

    if (option) {
        sprintf(command, "cat %s", backup_name);
        system(command);
    }

    fclose(source);
    fclose(backup);

    return 0;
}