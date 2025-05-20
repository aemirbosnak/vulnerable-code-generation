//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int value;
    struct node *next;
} node;

node *hash_table[100];

int hash(char *key) {
    int sum = 0;
    int i = 0;
    while (key[i]!= '\0') {
        sum += key[i];
        i++;
    }
    return sum % 100;
}

void insert(char *key, int value) {
    int index = hash(key);
    node *new_node = (node *) malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int search(char *key) {
    int index = hash(key);
    node *temp = hash_table[index];
    while (temp!= NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void delete(char *key) {
    int index = hash(key);
    node *temp = hash_table[index];
    node *prev = NULL;
    while (temp!= NULL) {
        if (strcmp(temp->key, key) == 0) {
            if (prev == NULL) {
                hash_table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp->key);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void print_table() {
    int i;
    for (i = 0; i < 100; i++) {
        node *temp = hash_table[i];
        while (temp!= NULL) {
            printf("%s %d\n", temp->key, temp->value);
            temp = temp->next;
        }
    }
}

int main() {
    insert("apple", 5);
    insert("banana", 3);
    insert("orange", 7);
    insert("grape", 2);
    print_table();
    printf("Search banana: %d\n", search("banana"));
    printf("Search kiwi: %d\n", search("kiwi"));
    delete("banana");
    print_table();
    return 0;
}