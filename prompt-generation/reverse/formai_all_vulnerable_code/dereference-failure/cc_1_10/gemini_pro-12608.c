//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* word;
    int count;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** table;
    int size;
} HashTable;

HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (Node**)malloc(sizeof(Node*) * size);
    ht->size = size;

    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }

    return ht;
}

void insertWord(HashTable* ht, char* word) {
    int index = hash(word, ht->size);
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

int hash(char* word, int size) {
    int hash_value = 0;

    for (int i = 0; i < strlen(word); i++) {
        hash_value += word[i];
    }

    return hash_value % size;
}

int findWord(HashTable* ht, char* word) {
    int index = hash(word, ht->size);
    Node* current = ht->table[index];

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->count;
        }
        current = current->next;
    }

    return 0;
}

void printHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Node* current = ht->table[i];

        while (current != NULL) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

int main() {
    HashTable* ht = createHashTable(100);
    char* words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};

    for (int i = 0; i < 9; i++) {
        insertWord(ht, words[i]);
    }

    printHashTable(ht);

    return 0;
}