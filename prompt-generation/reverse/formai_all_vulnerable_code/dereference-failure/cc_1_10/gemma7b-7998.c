//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
    int data[1024];
} File;

File* head = NULL;

void insert_file(char* name) {
    File* new_file = malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->next = head;
    head = new_file;
}

void read_file(char* name) {
    File* file = head;
    while (file) {
        if (strcmp(file->name, name) == 0) {
            for (int i = 0; i < file->data[0]; i++) {
                printf("%c ", file->data[i + 1]);
            }
            break;
        }
        file = file->next;
    }
    printf("\n");
}

void write_file(char* name, int data) {
    File* file = head;
    while (file) {
        if (strcmp(file->name, name) == 0) {
            file->data[0] = data;
            for (int i = 0; i < data; i++) {
                file->data[i + 1] = data;
            }
            break;
        }
        file = file->next;
    }
    printf("File %s updated.\n", name);
}

int main() {
    insert_file("test.txt");
    insert_file("another.txt");
    write_file("test.txt", 10);
    read_file("test.txt");
    return 0;
}