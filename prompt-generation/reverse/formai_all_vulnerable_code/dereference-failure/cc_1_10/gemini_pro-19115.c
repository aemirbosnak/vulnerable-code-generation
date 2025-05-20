//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char* name;
    char* data;
    int size;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name, char* data, int size) {
    if (num_files == MAX_FILES) {
        printf("Error: Too many files open.\n");
        return;
    }

    files[num_files].name = strdup(name);
    files[num_files].data = strdup(data);
    files[num_files].size = size;
    num_files++;
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            free(files[i].name);
            free(files[i].data);
            files[i] = files[num_files - 1];
            num_files--;
            return;
        }
    }

    printf("Error: File not found.\n");
}

void read_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("%s", files[i].data);
            return;
        }
    }

    printf("Error: File not found.\n");
}

void write_file(char* name, char* data, int size) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            if (size > files[i].size) {
                files[i].data = realloc(files[i].data, size);
            }
            strcpy(files[i].data, data);
            files[i].size = size;
            return;
        }
    }

    printf("Error: File not found.\n");
}

int main() {
    char input[1024];
    char* command;
    char* filename;
    char* data;
    int size;

    while (1) {
        printf("> ");
        fgets(input, 1024, stdin);

        command = strtok(input, " ");

        if (strcmp(command, "create") == 0) {
            filename = strtok(NULL, " ");
            data = strtok(NULL, "\n");
            size = strlen(data);
            create_file(filename, data, size);
        } else if (strcmp(command, "delete") == 0) {
            filename = strtok(NULL, "\n");
            delete_file(filename);
        } else if (strcmp(command, "read") == 0) {
            filename = strtok(NULL, "\n");
            read_file(filename);
        } else if (strcmp(command, "write") == 0) {
            filename = strtok(NULL, " ");
            data = strtok(NULL, "\n");
            size = strlen(data);
            write_file(filename, data, size);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}