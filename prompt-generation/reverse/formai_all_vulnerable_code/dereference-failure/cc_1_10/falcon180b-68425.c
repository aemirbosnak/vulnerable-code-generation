//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 512
#define MAX_FILE_NAME_SIZE 256
#define MAX_BACKUP_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    char backup_file_name[MAX_FILE_NAME_SIZE];
    char backup_path[MAX_FILE_NAME_SIZE];
} FileBackup;

int main() {
    FILE *config_file;
    char line[MAX_LINE_SIZE];
    char backup_path[MAX_FILE_NAME_SIZE] = "backups/";
    int num_files_backed_up = 0;
    FileBackup backup_files[MAX_BACKUP_FILES];

    config_file = fopen("backup_config.txt", "r");
    if (config_file == NULL) {
        printf("Error: Could not open backup_config.txt file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, config_file)!= NULL) {
        if (num_files_backed_up >= MAX_BACKUP_FILES) {
            printf("Error: Maximum number of backup files reached.\n");
            exit(1);
        }

        char *file_name = strtok(line, " ");
        char *backup_file_name = strtok(NULL, " ");

        strcpy(backup_files[num_files_backed_up].file_name, file_name);
        strcpy(backup_files[num_files_backed_up].backup_file_name, backup_file_name);
        strcat(backup_files[num_files_backed_up].backup_path, backup_path);
        strcat(backup_files[num_files_backed_up].backup_path, backup_file_name);

        num_files_backed_up++;
    }

    fclose(config_file);

    for (int i = 0; i < num_files_backed_up; i++) {
        FILE *backup_file;

        backup_file = fopen(backup_files[i].backup_path, "w");
        if (backup_file == NULL) {
            printf("Error: Could not create backup file for %s.\n", backup_files[i].file_name);
            exit(1);
        }

        FILE *file;
        char line[MAX_LINE_SIZE];

        file = fopen(backup_files[i].file_name, "r");
        if (file == NULL) {
            printf("Error: Could not open file %s.\n", backup_files[i].file_name);
            exit(1);
        }

        while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
            fprintf(backup_file, "%s", line);
        }

        fclose(file);
        fclose(backup_file);
    }

    printf("Backup complete!\n");

    return 0;
}