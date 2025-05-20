//FormAI DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME 100
#define MAX_BACKUP_NAME 200

int main()
{
    char file_name[MAX_FILE_NAME];
    char backup_name[MAX_BACKUP_NAME];
    struct tm* time_info;
    time_t raw_time;

    printf("Enter the name of the file to backup: ");
    fgets(file_name, MAX_FILE_NAME, stdin);
    file_name[strcspn(file_name, "\n")] = 0;

    // Backup file name format: {file_name}_{year-month-day_hour-minute-second}
    time(&raw_time);
    time_info = localtime(&raw_time);
    sprintf(backup_name, "%s_%04d-%02d-%02d_%02d-%02d-%02d", file_name,
            time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday,
            time_info->tm_hour, time_info->tm_min, time_info->tm_sec);

    // Open file in read mode
    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error while opening file %s", file_name);
        exit(1);
    }

    // Open backup file in write mode
    FILE* backup = fopen(backup_name, "w");
    if (backup == NULL)
    {
        printf("Error while creating backup file %s", backup_name);
        exit(1);
    }

    // Copy content of file to backup file
    char buffer[1024];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    while (bytes_read > 0)
    {
        fwrite(buffer, 1, bytes_read, backup);
        bytes_read = fread(buffer, 1, sizeof(buffer), file);
    }

    printf("File %s backed up to %s successfully.", file_name, backup_name);

    // Close file handles
    fclose(file);
    fclose(backup);

    return 0;
}