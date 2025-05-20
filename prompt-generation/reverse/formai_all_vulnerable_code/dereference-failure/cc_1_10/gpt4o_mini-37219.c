//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILENAME_LENGTH 30

typedef struct {
    char name[FILENAME_LENGTH];
    int size; // Size in KB
} File;

typedef struct {
    File *files[MAX_FILES];
    int count;
} Directory;

Directory *create_directory() {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    dir->count = 0;
    return dir;
}

void free_directory(Directory *dir) {
    for (int i = 0; i < dir->count; i++) {
        free(dir->files[i]);
    }
    free(dir);
}

void create_file(Directory *dir, const char *name, int size) {
    if (dir->count >= MAX_FILES) {
        printf("Directory is full! Cannot create more files.\n");
        return;
    }
    File *new_file = (File *)malloc(sizeof(File));
    strncpy(new_file->name, name, FILENAME_LENGTH);
    new_file->size = size;
    dir->files[dir->count++] = new_file;
    printf("File '%s' created with size %d KB.\n", name, size);
}

void delete_file(Directory *dir, const char *name) {
    for (int i = 0; i < dir->count; i++) {
        if (strcmp(dir->files[i]->name, name) == 0) {
            free(dir->files[i]);
            dir->files[i] = dir->files[--dir->count]; // Move last file to current position
            printf("File '%s' deleted.\n", name);
            return;
        }
    }
    printf("File '%s' not found.\n", name);
}

void list_files(Directory *dir) {
    if (dir->count == 0) {
        printf("Directory is empty.\n");
        return;
    }
    printf("Files in directory:\n");
    for (int i = 0; i < dir->count; i++) {
        printf("%s (%d KB)\n", dir->files[i]->name, dir->files[i]->size);
    }
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Create File\n");
    printf("2. Delete File\n");
    printf("3. List Files\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Directory *dir = create_directory();
    int choice;
    char filename[FILENAME_LENGTH];
    int filesize;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter filesize (in KB): ");
                scanf("%d", &filesize);
                create_file(dir, filename, filesize);
                break;
            case 2:
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                delete_file(dir, filename);
                break;
            case 3:
                list_files(dir);
                break;
            case 4:
                free_directory(dir);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}