//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILES 1024
#define MAX_FILE_SIZE 1024 * 1024

typedef struct file_backup_entry {
    char filename[MAX_FILE_SIZE];
    long size;
    struct file_backup_entry *next;
} file_backup_entry;

file_backup_entry *head = NULL;

void add_file(char *filename, long size) {
    file_backup_entry *new_entry = malloc(sizeof(file_backup_entry));
    strcpy(new_entry->filename, filename);
    new_entry->size = size;
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        head->next = new_entry;
        head = new_entry;
    }
}

void backup_files() {
    FILE *fp;
    char filename[MAX_FILE_SIZE];

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    long size = 0;
    while (!feof(fp)) {
        size += fread(filename, 1, MAX_FILE_SIZE, fp);
    }

    fclose(fp);

    add_file(filename, size);
}

int main() {
    while (1) {
        printf("Enter 'b' to back up a file, 'q' to quit: ");
        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'b':
                backup_files();
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}