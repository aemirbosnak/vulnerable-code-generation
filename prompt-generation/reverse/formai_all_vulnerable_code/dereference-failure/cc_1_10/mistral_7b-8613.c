//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TABLE_SIZE 101

typedef struct {
    char name[50];
    int roll_number;
} Student;

int hash_func(char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        hash += tolower(str[i]);
    }
    return hash % TABLE_SIZE;
}

struct HashNode {
    Student data;
    struct HashNode *next;
};

struct HashTable {
    struct HashNode **data;
};

void init_hash_table(struct HashTable *ht) {
    ht->data = (struct HashNode **)calloc(TABLE_SIZE, sizeof(struct HashNode *));
}

void insert_student(struct HashTable *ht, Student student) {
    int hash = hash_func(student.name);
    struct HashNode *new_node = (struct HashNode *)malloc(sizeof(struct HashNode));
    new_node->data = student;
    new_node->next = ht->data[hash];
    ht->data[hash] = new_node;
}

void print_students(struct HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (ht->data[i] != NULL) {
            struct HashNode *current = ht->data[i];
            while (current != NULL) {
                printf("Name: %s, Roll Number: %d\n", current->data.name, current->data.roll_number);
                current = current->next;
            }
        }
    }
}

int main() {
    struct HashTable ht;
    init_hash_table(&ht);

    Student students[5] = {
        {"Alice", 1},
        {"Bob", 2},
        {"Charlie", 3},
        {"David", 4},
        {"Eve", 5}
    };

    for (int i = 0; i < 5; ++i) {
        insert_student(&ht, students[i]);
    }

    print_students(&ht);

    return 0;
}