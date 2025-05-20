//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000

struct file_system {
    char name[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
};

struct file_system files[100];

void create_file(char* filename, char* data) {
    int i;
    struct file_system* new_file = malloc(sizeof(struct file_system));
    if (new_file == NULL) {
        printf("Error: Cannot allocate memory for file.\n");
        return;
    }
    strcpy(new_file->name, filename);
    strcpy(new_file->data, data);
    for (i = 0; i < 100; i++) {
        if (strcmp(new_file->name, files[i].name) == 0) {
            printf("Error: File already exists.\n");
            free(new_file);
            return;
        }
    }
    files[i] = *new_file;
}

void read_file(char* filename) {
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(filename, files[i].name) == 0) {
            printf("File name: %s\n", files[i].name);
            printf("File data: %s\n", files[i].data);
            break;
        }
    }
}

void delete_file(char* filename) {
    int i;
    for (i = 0; i < 100; i++) {
        if (strcmp(filename, files[i].name) == 0) {
            free(files[i].name);
            free(files[i].data);
            files[i] = (struct file_system){0, 0};
            break;
        }
    }
}

void main() {
    char filename[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    printf("Create a new file: ");
    scanf("%s", filename);
    printf("Write data to file: ");
    scanf("%s", data);
    create_file(filename, data);
    printf("Read file: ");
    scanf("%s", filename);
    read_file(filename);
    printf("Delete file: ");
    scanf("%s", filename);
    delete_file(filename);
}