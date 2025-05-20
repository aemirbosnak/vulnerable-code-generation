//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 13

typedef struct File {
    char name[32];
    int size;
    struct File *next;
} File;

typedef struct HashNode {
    File *file;
    struct HashNode *next;
} HashNode;

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void create_file(HashNode **table, char *name, int size) {
    unsigned long index = hash(name);
    HashNode *current = table[index];

    while (current != NULL && strcmp(current->file->name, name) != 0)
        current = current->next;

    if (current == NULL) {
        File *new_file = malloc(sizeof(File));
        strcpy(new_file->name, name);
        new_file->size = size;
        new_file->next = table[index];
        table[index] = (HashNode *)new_file;
    }
}

void delete_file(HashNode **table, char *name) {
    unsigned long index = hash(name);
    HashNode *prev = NULL, *current = table[index];

    while (current != NULL && strcmp(current->file->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
        printf("File not found.\n");
    else {
        if (prev == NULL)
            table[index] = current->next;
        else
            prev->next = current->next;
        free(current->file);
        free(current);
    }
}

void list_files(HashNode **table) {
    int i;

    for (i = 0; i < TABLE_SIZE; i++) {
        HashNode *current = table[i];

        if (current == NULL)
            continue;

        printf("Index %d:\n", i);

        while (current != NULL) {
            printf("%s (%d bytes)\n", current->file->name, current->file->size);
            current = current->next;
        }
    }
}

int main() {
    HashNode *table[TABLE_SIZE] = {NULL};

    create_file(table, "file1.txt", 10);
    create_file(table, "file2.txt", 20);
    create_file(table, "file3.txt", 30);

    list_files(table);

    delete_file(table, "file2.txt");

    list_files(table);

    return 0;
}