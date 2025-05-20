//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 13

typedef struct FileNode {
    char name[50];
    int size;
    struct FileNode *next;
} FileNode;

typedef struct HashTableNode {
    int index;
    struct FileNode *head;
} HashTableNode;

HashTableNode *hash_table;

void init_hash_table() {
    int i;
    hash_table = (HashTableNode *)malloc(TABLE_SIZE * sizeof(HashTableNode));

    for (i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].index = i;
        hash_table[i].head = NULL;
    }
}

int hash_func(char *str) {
    int hash = 0, i;

    for (i = 0; str[i]; i++) {
        hash += tolower(str[i]);
    }

    hash %= TABLE_SIZE;
    return hash;
}

void create_file(char *name, int size) {
    int index = hash_func(name);
    FileNode *new_file = (FileNode *)malloc(sizeof(FileNode));

    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->next = hash_table[index].head;

    hash_table[index].head = new_file;
}

void print_files() {
    int i;

    printf("Files in the system:\n");

    for (i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i].head) {
            printf("Index %d:\n", i);
            FileNode *current = hash_table[i].head;

            while (current) {
                printf("Name: %s, Size: %d\n", current->name, current->size);
                current = current->next;
            }
        }
    }
}

int main() {
    init_hash_table();

    create_file("file1.txt", 10);
    create_file("file2.txt", 20);
    create_file("file3.txt", 30);

    print_files();

    return 0;
}