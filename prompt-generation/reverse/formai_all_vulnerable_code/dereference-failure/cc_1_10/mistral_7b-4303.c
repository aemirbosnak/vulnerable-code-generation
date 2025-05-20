//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 20
#define MAX_DATA_LENGTH 100

typedef struct File {
    char name[MAX_NAME_LENGTH + 1];
    char data[MAX_DATA_LENGTH + 1];
    int size;
    struct File *next;
} File;

File *head = NULL;

void createFile(char *name, int size) {
    File *newFile = (File *) malloc(sizeof(File));

    strcpy(newFile->name, name);
    newFile->size = size;

    if (head == NULL) {
        head = newFile;
        newFile->next = NULL;
    } else {
        File *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newFile;
        newFile->next = NULL;
    }
}

void writeToFile(char *name, char *data) {
    File *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strcpy(current->data, data);
            printf("Successfully wrote to file: %s\n", name);
            return;
        }
        current = current->next;
    }

    printf("Error: File not found!\n");
}

void printFiles() {
    File *current = head;
    printf("Current contents of the disk:\n");
    while (current != NULL) {
        printf("File: %s, Size: %d, Data: %s\n", current->name, current->size, current->data);
        current = current->next;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s COMMAND [OPTIONS]\n", argv[0]);
        return 1;
    }

    char command = argv[1][0];

    switch (command) {
        case 'C':
            if (argc != 3) {
                printf("Usage: %s C <filename> <size>\n", argv[0]);
                return 1;
            }
            createFile(argv[2], atoi(argv[3]));
            break;

        case 'W':
            if (argc != 3) {
                printf("Usage: %s W <filename> <data>\n", argv[0]);
                return 1;
            }
            writeToFile(argv[2], argv[3]);
            break;

        case 'L':
            printFiles();
            break;

        default:
            printf("Error: Invalid command!\n");
            printf("Usage: %s C <filename> <size> | W <filename> <data> | L\n", argv[0]);
            return 1;
    }

    return 0;
}