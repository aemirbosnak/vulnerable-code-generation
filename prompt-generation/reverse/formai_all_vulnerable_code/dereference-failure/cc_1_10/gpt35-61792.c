//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_FILE_COUNT 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int size;
    char* content;
} File;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int file_count;
    File files[MAX_FILE_COUNT];
} Directory;

Directory* root;

void create_file(char* name, int size, char* content) {
    if (root->file_count == MAX_FILE_COUNT) {
        printf("Maximum number of files reached!\n");
        return;
    }

    File new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    new_file.content = malloc(size * sizeof(char));
    strcpy(new_file.content, content);

    root->files[root->file_count++] = new_file;

    printf("File created successfully!\n");
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < root->file_count; i++) {
        if (strcmp(root->files[i].name, name) == 0) {
            free(root->files[i].content);
            int j;
            for (j = i; j < root->file_count - 1; j++) {
                root->files[j] = root->files[j + 1];
            }
            root->file_count--;
            printf("File deleted successfully!\n");
            return;
        }
    }

    printf("File not found!\n");
}

void list_files() {
    int i;
    if (root->file_count > 0) {
        printf("Files in root directory:\n");
        for (i = 0; i < root->file_count; i++) {
            printf("- %s\n", root->files[i].name);
        }
    } else {
        printf("No files in root directory!\n");
    }
}

int main() {
    root = malloc(sizeof(Directory));
    strcpy(root->name, "root");
    root->file_count = 0;

    while (1) {
        printf("Enter command (create/delete/list/exit): ");
        
        char command[MAX_NAME_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char name[MAX_NAME_LENGTH];
            int size;
            char content[MAX_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file size: ");
            scanf("%d", &size);
            printf("Enter file content: ");
            scanf("%s", content);
            create_file(name, size, content);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    printf("Exiting...\n");
    return 0;
}