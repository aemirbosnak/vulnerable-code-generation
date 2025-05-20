//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define HASH_SIZE 256

// Node structure for linked list in the hash table
typedef struct Node {
    char *data;
    int count;
    struct Node *next;
} Node;

// Hash table structure
typedef struct HashTable {
    Node **table;
} HashTable;

// Function to create a new hash table
HashTable* createHashTable() {
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->table = (Node **)malloc(HASH_SIZE * sizeof(Node *));
    
    for (int i = 0; i < HASH_SIZE; i++) {
        ht->table[i] = NULL;
    }
    
    return ht;
}

// Hash function
unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % HASH_SIZE;
}

// Function to read data and compress it using the hash table
void compressData(HashTable *ht, const char *input) {
    char *token = strtok((char *)input, " ");
    
    while (token != NULL) {
        unsigned int index = hash(token);
        Node *node = ht->table[index];
        Node *prev = NULL;

        while (node != NULL) {
            if (strcmp(node->data, token) == 0) {
                node->count++;
                break;
            }
            prev = node;
            node = node->next;
        }

        if (node == NULL) {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = strdup(token);
            newNode->count = 1;
            newNode->next = NULL;
            if (prev == NULL) {
                ht->table[index] = newNode;
            } else {
                prev->next = newNode;
            }
        }
        
        token = strtok(NULL, " ");
    }
}

// Function to decompress data from hash table
void decompressData(HashTable *ht) {
    printf("Decompressed Data:\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *node = ht->table[i];
        
        while (node != NULL) {
            for (int j = 0; j < node->count; j++) {
                printf("%s ", node->data);
            }
            node = node->next;
        }
    }
    printf("\n");
}

// Free memory associated with hash table
void freeHashTable(HashTable *ht) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *node = ht->table[i];
        
        while (node != NULL) {
            Node *temp = node;
            node = node->next;
            free(temp->data);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

// Main function to test the algorithm
int main() {
    // Input string
    char input[MAX_INPUT_SIZE];
    
    printf("Enter a string to compress (max %d characters):\n", MAX_INPUT_SIZE - 1);
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    // Remove newline character at the end if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Create hash table
    HashTable *ht = createHashTable();
    
    // Compressing data
    compressData(ht, input);
    
    // Decompressing data
    decompressData(ht);
    
    // Free allocated memory
    freeHashTable(ht);
    
    return 0;
}