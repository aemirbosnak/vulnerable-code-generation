//FormAI DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_NUMBER 5
#define BACKUP_FOLDER_NAME "backups/"

char* get_current_time_string();
void create_folder_if_not_exists(char* folder_name);
void make_backup(char* file_name);

int main(void) {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to backup: ");
    scanf("%s", file_name);
    make_backup(file_name);
    return 0;
}

char* get_current_time_string() {
    time_t current_time;
    struct tm *time_info;
    char* time_string = (char*) malloc(sizeof(char) * 50);

    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, 50, "%m-%d-%Y_%H:%M:%S", time_info);

    return time_string;
}

void create_folder_if_not_exists(char* folder_name) {
    char command[100];
    if (system(NULL)) {
        sprintf(command, "mkdir %s 2> /dev/null || true", folder_name);
        system(command);
    } else {
        printf("System command is not available.\n");
        exit(1);
    }
}

void make_backup(char* file_name) {
    char* backup_path = (char*) malloc(sizeof(char) * 100);
    char* current_time_string = get_current_time_string();
    sprintf(backup_path, "%s%s_%s", BACKUP_FOLDER_NAME, file_name, current_time_string);

    // Open the input file
    FILE *input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error: Cannot open the input file.\n");
        exit(1);
    }

    // Open the output file
    FILE *output_file = fopen(backup_path, "w");
    if (output_file == NULL) {
        printf("Error: Cannot create the backup file.\n");
        exit(1);
    }

    // Copy contents
    int c;
    while ((c = fgetc(input_file)) != EOF) {
        fputc(c, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    free(current_time_string);

    // Delete old backups
    int backup_number;
    for (backup_number = MAX_BACKUP_NUMBER - 1; backup_number >= 0; backup_number--) {
        char* old_backup_path = (char*) malloc(sizeof(char) * 100);
        sprintf(old_backup_path, "%s%s_backup_%d", BACKUP_FOLDER_NAME, file_name, backup_number);
        remove(old_backup_path);
        free(old_backup_path);

        if (backup_number > 0) {
            char* new_backup_path = (char*) malloc(sizeof(char) * 100);
            sprintf(new_backup_path, "%s%s_backup_%d", BACKUP_FOLDER_NAME, file_name, backup_number);
            char* old_backup_path = (char*) malloc(sizeof(char) * 100);
            sprintf(old_backup_path, "%s%s_backup_%d", BACKUP_FOLDER_NAME, file_name, backup_number - 1);
            rename(old_backup_path, new_backup_path);
            free(new_backup_path);
            free(old_backup_path);
        }
    }

    // Rename the recent backup
    char* new_backup_path = (char*) malloc(sizeof(char) * 100);
    sprintf(new_backup_path, "%s%s_backup_0", BACKUP_FOLDER_NAME, file_name);
    rename(backup_path, new_backup_path);
    free(new_backup_path);

    create_folder_if_not_exists(BACKUP_FOLDER_NAME);
}