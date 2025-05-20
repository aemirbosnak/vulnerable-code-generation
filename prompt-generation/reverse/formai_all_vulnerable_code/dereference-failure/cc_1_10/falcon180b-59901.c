//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char *file_content;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char *file_name, int file_size) {
    File *new_file = NULL;

    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            printf("File already exists.\n");
            return;
        }
    }

    if (num_files >= MAX_FILES) {
        printf("Maximum number of files reached.\n");
        return;
    }

    new_file = &files[num_files];
    strcpy(new_file->file_name, file_name);
    new_file->file_size = file_size;
    new_file->file_content = (char *)malloc(file_size);

    num_files++;

    printf("File created successfully.\n");
}

void delete_file(char *file_name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            free(files[i].file_content);
            strcpy(files[i].file_name, "");
            files[i].file_size = 0;

            printf("File deleted successfully.\n");
            return;
        }
    }

    printf("File not found.\n");
}

void read_file(char *file_name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            printf("File content:\n%s", files[i].file_content);
            return;
        }
    }

    printf("File not found.\n");
}

void write_file(char *file_name, char *file_content) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            strcpy(files[i].file_content, file_content);

            printf("File updated successfully.\n");
            return;
        }
    }

    printf("File not found.\n");
}

int main() {
    create_file("test.txt", 10);
    write_file("test.txt", "Hello, world!");
    read_file("test.txt");
    delete_file("test.txt");

    return 0;
}