//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct File {
    char name[256];
    int size;
    struct File *next;
} File;

unsigned int hash(char *str) {
    unsigned int hash = 0;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void create_file(File **table, char *name, int size) {
    unsigned int index = hash(name);
    File *file = (File *)calloc(1, sizeof(File));

    strcpy(file->name, name);
    file->size = size;

    file->next = table[index];
    table[index] = file;
}

void delete_file(File **table, char *name) {
    unsigned int index = hash(name);
    File *prev, *current = table[index];

    if (current && strcmp(current->name, name) == 0) {
        table[index] = current->next;
        free(current);
        return;
    }

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void list_files(File **table) {
    int i;

    for (i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            printf("Index %d:\n", i);
            File *current = table[i];

            while (current != NULL) {
                printf("Name: %s, Size: %d\n", current->name, current->size);
                current = current->next;
            }
        }
    }
}

int main() {
    File *table[TABLE_SIZE] = {NULL};

    create_file(table, "file1.txt", 10);
    create_file(table, "file2.txt", 20);
    create_file(table, "file3.txt", 30);

    list_files(table);

    delete_file(table, "file2.txt");

    list_files(table);

    return 0;
}