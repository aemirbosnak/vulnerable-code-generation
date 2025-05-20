//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int value;
    char* description;
} Item;

typedef struct HashTable {
    Item** table;
    int size;
} HashTable;

HashTable* create_table(int size) {
    HashTable* h_table = (HashTable*)malloc(sizeof(HashTable));
    if (!h_table) {
        perror("Unable to allocate hash table memory");
        exit(EXIT_FAILURE);
    }
    
    h_table->size = size;
    h_table->table = (Item**)malloc(sizeof(Item*) * size);
    
    for (int i = 0; i < size; i++) {
        h_table->table[i] = NULL;
    }
    
    return h_table;
}

unsigned long hash(int key, int size) {
    return key % size;
}

void insert(HashTable* h_table, int key, char* description) {
    unsigned long index = hash(key, h_table->size);
    
    Item* new_item = (Item*)malloc(sizeof(Item));
    new_item->value = key;
    new_item->description = description;
    
    if (h_table->table[index] != NULL) {
        free(h_table->table[index]);
    }
    
    h_table->table[index] = new_item;
}

Item* search(HashTable* h_table, int key) {
    unsigned long index = hash(key, h_table->size);
    
    if (h_table->table[index] != NULL && h_table->table[index]->value == key) {
        return h_table->table[index];
    }
    
    return NULL;
}

void delete_item(HashTable* h_table, int key) {
    unsigned long index = hash(key, h_table->size);
    
    if (h_table->table[index] != NULL) {
        free(h_table->table[index]);
        h_table->table[index] = NULL;
    }
}

void free_table(HashTable* h_table) {
    for (int i = 0; i < h_table->size; i++) {
        if (h_table->table[i] != NULL) {
            free(h_table->table[i]);
        }
    }
    free(h_table->table);
    free(h_table);
}

void print_table(HashTable* h_table) {
    for (int i = 0; i < h_table->size; i++) {
        if (h_table->table[i] != NULL) {
            printf("Index %d: Value %d, Description: %s\n", i, h_table->table[i]->value, h_table->table[i]->description);
        } else {
            printf("Index %d: (empty)\n", i);
        }
    }
}

int main() {
    HashTable* my_table = create_table(10);
    
    insert(my_table, 15, "Fifteen");
    insert(my_table, 25, "Twenty Five");
    insert(my_table, 35, "Thirty Five");
    insert(my_table, 10, "Ten");
    
    printf("Hash Table Contents:\n");
    print_table(my_table);

    int key_to_search = 25;
    Item* result = search(my_table, key_to_search);
    
    if (result != NULL) {
        printf("Found: Value %d, Description: %s\n", result->value, result->description);
    } else {
        printf("Key %d not found in the table.\n", key_to_search);
    }

    printf("Deleting key 15...\n");
    delete_item(my_table, 15);
    print_table(my_table);

    free_table(my_table);
    return 0;
}