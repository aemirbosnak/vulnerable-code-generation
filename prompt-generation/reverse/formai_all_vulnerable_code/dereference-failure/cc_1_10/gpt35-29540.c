//FormAI DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_MAX_LEN 100
#define BUFFER_SIZE 1024

// struct to hold the data for each backup file
typedef struct BackupFile {
    char filename[FILENAME_MAX_LEN]; // name of the backup file
    char date_created[20]; // date the backup was created
    long size; // size of the backup file in bytes
} BackupFile;

// linked list node to hold backup data and point to the next backup file
typedef struct BackupListNode {
    BackupFile data; // data for the backup file
    struct BackupListNode *next; // pointer to the next backup file
} BackupListNode;

// function to create a new backup list node and add it to the list
void add_backup_file(BackupListNode **list, const char *filename) {
    BackupListNode *new_node = malloc(sizeof(BackupListNode));
    strcpy(new_node->data.filename, filename);
    strcpy(new_node->data.date_created, "01/01/2022"); // for example purposes only
    new_node->data.size = 0; // for example purposes only
    new_node->next = *list;
    *list = new_node;
}

int main() {
    BackupListNode *backup_list = NULL;

    char filename[FILENAME_MAX_LEN];
    printf("Enter the name of the file to backup: ");
    scanf("%s", filename);

    // open the file to backup
    FILE *file_to_backup = fopen(filename, "r");
    if (file_to_backup == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // create the backup file
    char backup_filename[FILENAME_MAX_LEN];
    snprintf(backup_filename, FILENAME_MAX_LEN, "%s_backup", filename);
    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: could not create backup file\n");
        return 1;
    }

    // copy the contents of the file to backup into the backup file
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file_to_backup) != NULL) {
        fputs(buffer, backup_file);
    }

    // update the backup list with the new backup file
    add_backup_file(&backup_list, backup_filename);

    // close the files
    fclose(file_to_backup);
    fclose(backup_file);

    // print the list of backup files
    printf("List of backup files:\n");
    BackupListNode *current_node = backup_list;
    while (current_node != NULL) {
        printf("%s\t%s\t%ld bytes\n", current_node->data.filename,
               current_node->data.date_created, current_node->data.size);
        current_node = current_node->next;
    }

    return 0;
}