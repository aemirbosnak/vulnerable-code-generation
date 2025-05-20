//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_DIRECTORY_DEPTH 10

typedef struct directory {
    char name[MAX_FILE_NAME_LENGTH];
    struct directory *next;
} directory;

directory *head = NULL;

void add_directory(char *name) {
    directory *new_directory = (directory *) malloc(sizeof(directory));
    strcpy(new_directory->name, name);
    new_directory->next = NULL;
    if (head == NULL) {
        head = new_directory;
    } else {
        directory *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_directory;
    }
}

void list_directories() {
    directory *current = head;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void create_file(char *file_name, char *content) {
    char full_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(full_file_name, "./");
    strcat(full_file_name, file_name);
    FILE *file = fopen(full_file_name, "w");
    if (file == NULL) {
        printf("Error: Unable to create file %s\n", file_name);
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
}

void list_files() {
    char *current_directory = "./";
    directory *current = head;
    while (current!= NULL) {
        if (strncmp(current->name, current_directory, strlen(current_directory)) == 0) {
            char full_file_name[MAX_FILE_NAME_LENGTH];
            strcpy(full_file_name, "./");
            strcat(full_file_name, current->name);
            FILE *file = fopen(full_file_name, "r");
            if (file!= NULL) {
                char buffer[MAX_FILE_NAME_LENGTH];
                fgets(buffer, MAX_FILE_NAME_LENGTH, file);
                printf("%s\n", buffer);
                fclose(file);
            }
        }
        current = current->next;
    }
}

int main() {
    char directory_name[MAX_FILE_NAME_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_NAME_LENGTH];
    printf("Enter a directory name: ");
    fgets(directory_name, MAX_FILE_NAME_LENGTH, stdin);
    directory_name[strcspn(directory_name, "\n")] = '\0';
    add_directory(directory_name);
    printf("Enter a file name: ");
    fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);
    file_name[strcspn(file_name, "\n")] = '\0';
    printf("Enter a file content: ");
    fgets(content, MAX_FILE_NAME_LENGTH, stdin);
    content[strcspn(content, "\n")] = '\0';
    create_file(file_name, content);
    list_files();
    list_directories();
    return 0;
}