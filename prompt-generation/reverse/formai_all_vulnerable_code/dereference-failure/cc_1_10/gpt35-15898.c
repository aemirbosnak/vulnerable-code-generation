//FormAI DATASET v1.0 Category: File Backup System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_BACKUPS 10

// Struct to hold backup information
struct backup_info {
    char *filename;
    char *backupname;
};

// Struct to hold node information for linked list of backups
struct backup_node {
    struct backup_info backup;
    struct backup_node *next;
};

// Global variables
struct backup_node *head = NULL;
int num_backups = 0;
pthread_mutex_t mutex;

// Function to backup a file
void *backup_file(void *info) {
    struct backup_info *backup_info = (struct backup_info *) info;
    
    // Create backup command string
    char command[100];
    strcpy(command, "cp ");
    strcat(command, backup_info->filename);
    strcat(command, " ");
    strcat(command, backup_info->backupname);

    // Execute backup command
    system(command);
    
    // Lock mutex and remove backup from linked list
    pthread_mutex_lock(&mutex);
    struct backup_node *current = head;
    struct backup_node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->backup.backupname, backup_info->backupname) == 0) {
            // Remove backup from linked list
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            num_backups--;
            break;
        }
        previous = current;
        current = current->next;
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Function to add a backup to the linked list and start a new thread to backup the file
void add_backup(char *filename) {
    // Lock mutex and add backup to linked list
    pthread_mutex_lock(&mutex);
    struct backup_info backup_info;
    backup_info.filename = filename;
    char *backupname = malloc(strlen(filename) + 5);
    sprintf(backupname, "%s.bak", filename);
    backup_info.backupname = backupname;

    struct backup_node *new_node = malloc(sizeof(struct backup_node));
    new_node->backup = backup_info;
    new_node->next = head;
    head = new_node;

    num_backups++;
    pthread_mutex_unlock(&mutex);

    // Start new thread to backup the file
    pthread_t backup_thread;
    pthread_create(&backup_thread, NULL, backup_file, (void *) &backup_info);
    pthread_detach(backup_thread);
}

int main(int argc, char **argv) {
    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Add initial backups
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            add_backup(argv[i]);
        }
    }

    // Main loop
    while (1) {
        sleep(10);
        if (num_backups < MAX_BACKUPS) {
            // Add new backup
            add_backup(argv[0]);
        }
    }

    return 0;
}