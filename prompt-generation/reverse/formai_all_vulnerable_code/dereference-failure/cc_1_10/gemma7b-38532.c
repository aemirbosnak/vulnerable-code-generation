//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define BACKUP_DIR "/home/backup"

typedef struct BackupFile {
    char *filename;
    struct BackupFile *next;
} BackupFile;

BackupFile *backup_file_insert(BackupFile *head, char *filename) {
    BackupFile *new_file = (BackupFile *)malloc(sizeof(BackupFile));
    new_file->filename = strdup(filename);
    new_file->next = NULL;

    if (head == NULL) {
        head = new_file;
    } else {
        head->next = new_file;
    }

    return head;
}

void backup_file_list(BackupFile *head) {
    BackupFile *current = head;
    while (current) {
        printf("%s\n", current->filename);
        current = current->next;
    }
}

int main() {
    BackupFile *backup_head = NULL;

    // Simulate some file backups
    backup_file_insert(backup_head, "file1.txt");
    backup_file_insert(backup_head, "photo.jpg");
    backup_file_insert(backup_head, "document.doc");

    // List all backups
    backup_file_list(backup_head);

    // Print backup directory status
    struct stat stat_buf;
    if (stat(BACKUP_DIR, &stat_buf) == 0) {
        printf("Backup directory size: %d bytes\n", stat_buf.st_size);
    } else {
        perror("Error statting backup directory");
    }

    return 0;
}