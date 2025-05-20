//FormAI DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BACKUPS 10
#define MAX_FILENAME_LENGTH 100

char **backup_list; // global variable for storing backup filenames

// function to add a backup to the list
void add_backup(char *filename) {

    // check if backup list is full
    if (sizeof(backup_list) >= MAX_BACKUPS) {
        printf("Backup list is full. Delete older backups to make space.\n");
        return;
    }

    // create new backup filename
    char *backup_name = (char *)malloc(MAX_FILENAME_LENGTH * sizeof(char));
    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(backup_name, MAX_FILENAME_LENGTH, "backup_%Y-%m-%d_%H%M%S.c", time_info);

    // create backup file
    FILE *source = fopen(filename, "rb");
    FILE *backup = fopen(backup_name, "wb");
    char buf[1024];
    size_t size;
    while ((size = fread(buf, 1, sizeof(buf), source)) > 0) {
        fwrite(buf, 1, size, backup);
    }
    fclose(source);
    fclose(backup);

    printf("Created backup file: %s\n", backup_name);

    // add backup filename to list
    backup_list[sizeof(backup_list)] = backup_name;

}

// function to remove a backup from the list
void remove_backup(char *filename) {

    int index = -1;
    for (int i = 0; i < sizeof(backup_list); i++) {
        if (strcmp(backup_list[i], filename) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Backup file not found.\n");
        return;
    }

    // delete backup file
    remove(backup_list[index]);
    printf("Deleted backup file: %s\n", backup_list[index]);

    // remove backup filename from list
    for (int i = index; i < sizeof(backup_list)-1; i++) {
        backup_list[i] = backup_list[i+1];
    }
    backup_list[sizeof(backup_list)-1] = NULL;

}

int main() {

    backup_list = (char **)malloc(MAX_BACKUPS * sizeof(char *));
    for (int i = 0; i < MAX_BACKUPS; i++) {
        backup_list[i] = NULL;
    }

    // do some code backups
    add_backup("main.c");
    add_backup("functions.c");
    add_backup("data_structures.c");

    // remove a backup
    remove_backup(backup_list[1]);

    return 0;
}