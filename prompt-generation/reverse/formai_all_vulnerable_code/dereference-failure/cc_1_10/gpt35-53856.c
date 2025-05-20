//FormAI DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    char value[20];
    struct node* next;
};

struct list {
    struct node* head;
};

struct hashtable {
    int size;
    struct list* table;
};

struct hashtable* create_hashtable(int size) {
    struct hashtable* hashtable = malloc(sizeof(struct hashtable));
    hashtable->size = size;
    hashtable->table = malloc(sizeof(struct list) * size);
    for (int i = 0; i < size; i++) {
        hashtable->table[i].head = NULL;
    }
    return hashtable;
}

int hash(int size, int key) {
    return key % size;
}

void hashtable_add(struct hashtable* hashtable, int key, char* value) {
    int index = hash(hashtable->size, key);
    struct node* new_node = malloc(sizeof(struct node));
    new_node->key = key;
    strcpy(new_node->value, value);
    new_node->next = hashtable->table[index].head;
    hashtable->table[index].head = new_node;
}

char* hashtable_get(struct hashtable* hashtable, int key) {
    int index = hash(hashtable->size, key);
    struct node* node = hashtable->table[index].head;
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void hashtable_free(struct hashtable* hashtable) {
    for (int i = 0; i < hashtable->size; i++) {
        struct node* node = hashtable->table[i].head;
        while (node != NULL) {
            struct node* next = node->next;
            free(node);
            node = next;
        }
    }
    free(hashtable->table);
    free(hashtable);
}

int main() {
    struct hashtable* hashtable = create_hashtable(10);
    
    hashtable_add(hashtable, 1, "value1");
    hashtable_add(hashtable, 2, "value2");
    hashtable_add(hashtable, 3, "value3");
    
    printf("%s\n", hashtable_get(hashtable, 1));
    printf("%s\n", hashtable_get(hashtable, 2));
    printf("%s\n", hashtable_get(hashtable, 3));
    
    hashtable_free(hashtable);
    
    return 0;
}