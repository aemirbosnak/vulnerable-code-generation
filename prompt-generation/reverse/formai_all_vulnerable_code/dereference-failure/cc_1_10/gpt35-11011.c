//FormAI DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    FILE *original_file, *backup_file;
    char original_file_name[100], backup_file_name[100];
    char buffer[1024];
    time_t current_time;
    struct tm *time_info;
    char time_string[20];

    printf("Enter the name of the file that you want to backup:\n");
    scanf("%s", original_file_name);

    // Open the original file
    original_file = fopen(original_file_name, "r");
    if (original_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Generate the backup file name using the current time
    current_time = time(NULL);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d_%H-%M-%S", time_info);
    sprintf(backup_file_name, "%s_%s", original_file_name, time_string);

    // Open the backup file
    backup_file = fopen(backup_file_name, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file!\n");
        return 1;
    }

    // Loop through the original file and write it to the backup file
    while (fgets(buffer, sizeof(buffer), original_file) != NULL) {
        fputs(buffer, backup_file);
    }

    // Close the files
    fclose(original_file);
    fclose(backup_file);

    printf("Backup created successfully with name %s\n", backup_file_name);

    return 0;
}