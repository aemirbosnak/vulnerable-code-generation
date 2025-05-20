//FormAI DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backup(char *filename, char *backup_dir);
char *get_backup_filename(char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *backup_dir = "./backup/";
    char *filename = argv[1];

    backup(filename, backup_dir);

    return 0;
}

void backup(char *filename, char *backup_dir) {
    // get backup file name
    char *backup_filename = get_backup_filename(filename);

    // create backup directory if not exists
    char command[100];
    sprintf(command, "mkdir -p %s", backup_dir);
    system(command);

    // copy file to backup directory
    sprintf(command, "cp %s %s%s", filename, backup_dir, backup_filename);
    system(command);

    printf("Backup successful!\n");
    printf("Original file: %s\nBackup file: %s\n", filename, backup_filename);

    // free allocated memory
    free(backup_filename);
}

char *get_backup_filename(char *filename) {
    char *backup_filename = (char*) malloc(strlen(filename) + 20);

    // get current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // create backup file name
    sprintf(backup_filename, "%s_backup_%04d%02d%02d_%02d%02d%02d",
            filename,
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec);

    return backup_filename;
}