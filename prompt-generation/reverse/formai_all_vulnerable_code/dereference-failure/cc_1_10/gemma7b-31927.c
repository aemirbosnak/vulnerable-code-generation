//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
    char name[255];
    char data[10000];
    struct File* next;
} File;

File* file_head = NULL;

void add_file(char* name, char* data) {
    File* new_file = malloc(sizeof(File));
    strcpy(new_file->name, name);
    strcpy(new_file->data, data);
    new_file->next = NULL;

    if (file_head == NULL) {
        file_head = new_file;
    } else {
        file_head->next = new_file;
        file_head = new_file;
    }
}

void backup_files() {
    FILE* backup_file = fopen("backup.dat", "w");
    File* current_file = file_head;

    while (current_file) {
        fprintf(backup_file, "File name: %s\n", current_file->name);
        fprintf(backup_file, "File data: %s\n", current_file->data);
        fprintf(backup_file, "\n");
        current_file = current_file->next;
    }

    fclose(backup_file);
}

int main() {
    add_file("my_file.txt", "This is my file data.");
    add_file("another_file.doc", "This is another file data.");

    backup_files();

    return 0;
}