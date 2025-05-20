//FormAI DATASET v1.0 Category: File Backup System ; Style: scientific
/* 
 * C File Backup System
 * Author: John Doe
 * Date: 01/01/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BACKUP_COUNT 10

typedef struct file_data {
    char filename[MAX_FILENAME_LENGTH];
    char data[100];
} file_data_t;

typedef struct backup_history {
    file_data_t backups[MAX_BACKUP_COUNT];
    int count;
} backup_history_t;

/* Function prototypes */
void backup_file(char* filename, backup_history_t* backup_history);
void show_backup_history(backup_history_t* backup_history);

int main() {
    backup_history_t backup_history = {0};
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter filename to backup: ");
    scanf("%s", filename);

    backup_file(filename, &backup_history);
    show_backup_history(&backup_history);

    return 0;
}

/* 
 * Function to backup file 
 * Adds a copy of the file to
 * the backup_history array
 */
void backup_file(char* filename, backup_history_t* backup_history) {
    FILE* fp;
    char file_copy[MAX_FILENAME_LENGTH+4];
    time_t t;
    struct tm* tm_info;

    /* Open file in read mode */
    fp = fopen(filename, "r");

    /* If file doesn't exist, exit function */
    if (fp == NULL) {
        printf("File does not exist. Aborting backup.\n");
        return;
    }

    /* Save current time */
    t = time(NULL);
    tm_info = localtime(&t);

    /* Generate filename for backup */
    sprintf(file_copy, "%s_%04d%02d%02d%02d%02d%02d", 
            filename, tm_info->tm_year+1900, tm_info->tm_mon+1, tm_info->tm_mday,
            tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);

    /* Create copy of file */
    FILE* fp_copy;
    fp_copy = fopen(file_copy, "w");

    char c;
    while ((c = getc(fp)) != EOF)
        putc(c, fp_copy);

    fclose(fp_copy);

    /* Add file copy to backup history */
    if (backup_history->count < MAX_BACKUP_COUNT) {
        file_data_t file_data;
        strcpy(file_data.filename, file_copy);
        rewind(fp);
        fread(file_data.data, sizeof(file_data.data), 1, fp);
        backup_history->backups[backup_history->count] = file_data;
        backup_history->count++;
    } else {
        printf("Backup limit exceeded. Unable to backup file.\n");
    }

    fclose(fp);
}

/* Function to show backup history */
void show_backup_history(backup_history_t* backup_history) {
    printf("\nBackup History:\n");
    if (backup_history->count == 0) {
        printf("No backups found.\n");
        return;
    }
    for (int i=0; i<backup_history->count; i++) {
        printf("%d. Filename: %s\n", i+1, backup_history->backups[i].filename);
        printf("   Data: %s\n", backup_history->backups[i].data);
    }
}