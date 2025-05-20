//FormAI DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUPS_PER_FILE 5

int main()
{
    char file_name[MAX_FILE_NAME_LENGTH];
    int num_backups = 0;
    char backup_names[MAX_BACKUPS_PER_FILE][MAX_FILE_NAME_LENGTH];
    int i;
    char backup_file_name[MAX_FILE_NAME_LENGTH + 20];
    time_t current_time;
    struct tm* time_info;

    printf("Enter the name of the file to backup: ");
    fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);
    strtok(file_name, "\n"); // remove newline character at end of filename

    // check if file exists
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("File does not exist.\n");
        exit(1);
    }
    fclose(fp);

    // create backup file names
    for (i = 0; i < MAX_BACKUPS_PER_FILE; i++) {
        sprintf(backup_names[i], "%s.%d", file_name, i+1);
    }

    // find first available backup file name
    for (i = 0; i < MAX_BACKUPS_PER_FILE; i++) {
        fp = fopen(backup_names[i], "r");
        if (fp == NULL) {
            num_backups = i;
            break;
        }
        fclose(fp);
    }

    // create backup file
    current_time = time(NULL);
    time_info = localtime(&current_time);
    sprintf(backup_file_name, "%s.%d.%d-%d-%d-%d-%d-%d", file_name, num_backups + 1, time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday, time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
    fp = fopen(backup_file_name, "w");
    if (fp == NULL) {
        printf("Could not create backup file.\n");
        exit(1);
    }

    // copy contents of original file to backup file
    char c;
    fp = fopen(file_name, "r");
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, backup_file_name);
    }
    fclose(fp);
    fclose(backup_file_name);

    printf("Backup created: %s\n", backup_file_name);

    return 0;
}