//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    // Data structure definitions
    typedef struct {
        int key;
        char *value;
    } Node;

    typedef struct {
        Node *data;
        int size;
    } HashTable;

    // Function prototypes
    void init_hash_table(HashTable *ht);
    void insert_node(HashTable *ht, int key, char *value);
    char *get_value(HashTable *ht, int key);

    // Function definitions
    void init_hash_table(HashTable *ht) {
        ht->data = NULL;
        ht->size = 0;
    }

    void insert_node(HashTable *ht, int key, char *value) {
        // Find an empty slot in the hash table
        int index = key % ht->size;
        while (ht->data[index].key != -1) {
            index = (index + 1) % ht->size;
        }

        // Insert the new node at the found slot
        ht->data[index].key = key;
        ht->data[index].value = value;
    }

    char *get_value(HashTable *ht, int key) {
        // Find the slot where the node with the given key is located
        int index = key % ht->size;
        while (ht->data[index].key != -1) {
            if (ht->data[index].key == key) {
                return ht->data[index].value;
            }
            index = (index + 1) % ht->size;
        }

        // If the node is not found, return NULL
        return NULL;
    }

    int main() {
        // Create a hash table with 10 slots
        HashTable ht;
        init_hash_table(&ht);

        // Insert some nodes into the hash table
        insert_node(&ht, 1, "apple");
        insert_node(&ht, 2, "banana");
        insert_node(&ht, 3, "cherry");

        // Get the value of a node with a given key
        char *value = get_value(&ht, 2);
        printf("%s\n", value);

        // Free the hash table
        free(ht.data);

        return 0;
    }