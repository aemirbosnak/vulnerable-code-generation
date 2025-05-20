//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 255

typedef struct FileEntry {
    char filename[MAX_FILE_NAME_LEN];
    struct FileEntry* next;
} FileEntry;

typedef struct BackupSystem {
    FileEntry* head;
    FILE* backup_file;
} BackupSystem;

BackupSystem* create_backup_system() {
    BackupSystem* system = malloc(sizeof(BackupSystem));
    system->head = NULL;
    system->backup_file = NULL;
    return system;
}

void add_file_to_backup(BackupSystem* system, char* filename) {
    FileEntry* new_entry = malloc(sizeof(FileEntry));
    strcpy(new_entry->filename, filename);
    new_entry->next = system->head;
    system->head = new_entry;
}

void backup_files(BackupSystem* system) {
    system->backup_file = fopen("backup.dat", "w");
    FileEntry* current_entry = system->head;
    while (current_entry) {
        fprintf(system->backup_file, "%s\n", current_entry->filename);
        current_entry = current_entry->next;
    }
    fclose(system->backup_file);
}

int main() {
    BackupSystem* system = create_backup_system();
    add_file_to_backup(system, "foo.txt");
    add_file_to_backup(system, "bar.txt");
    backup_files(system);

    system = create_backup_system();
    add_file_to_backup(system, "baz.txt");
    backup_files(system);

    return 0;
}