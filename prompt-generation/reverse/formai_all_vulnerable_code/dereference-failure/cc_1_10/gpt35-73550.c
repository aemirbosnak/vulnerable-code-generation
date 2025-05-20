//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

// Node to hold each word and its frequency count
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    int count;
    struct Node* next;
} Node;

// Calculates the hash value
unsigned int hash(char* word, int bucket_size) {
    unsigned long hash_val = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        hash_val = hash_val * 31 + word[i];
    }
    return hash_val % bucket_size;
}

// Searches the linked list and returns a pointer to the node if found
Node* find_node(Node* head, char* word) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Inserts a node into the hash table
void insert_node(Node** hash_table, char* word, int bucket_size) {
    // Calculate hash value
    unsigned int hash_val = hash(word, bucket_size);
    // Create node
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    // Check if bucket is empty
    if (hash_table[hash_val] == NULL) {
        hash_table[hash_val] = new_node;
    }
    else {
        Node* current = hash_table[hash_val];
        // Search for existing node
        Node* existing_node = find_node(current, word);
        if (existing_node == NULL) {
            // Insert new node
            new_node->next = current;
            hash_table[hash_val] = new_node;
        }
        else {
            // Increment count of existing node
            existing_node->count++;
            free(new_node);
        }
    }
}

// Prints the hash table
void print_hash_table(Node** hash_table, int bucket_size) {
    for (int i = 0; i < bucket_size; i++) {
        printf("Bucket %d: ", i);
        Node* current = hash_table[i];
        while (current != NULL) {
            printf("%s (%d) -> ", current->word, current->count);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize hash table
    int bucket_size = 100;
    Node** hash_table = (Node**) malloc(bucket_size * sizeof(Node*));
    for (int i = 0; i < bucket_size; i++) {
        hash_table[i] = NULL;
    }
    // Read file line by line
    FILE* file = fopen("input.txt", "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Split line into words
        char* token = strtok(line, " ");
        while (token != NULL) {
            // Remove newline character from end of word
            int length = strlen(token);
            if (token[length-1] == '\n') {
                token[length-1] = '\0';
            }
            // Insert word into hash table
            insert_node(hash_table, token, bucket_size);
            // Get next word
            token = strtok(NULL, " ");
        }
    }
    // Print hash table
    print_hash_table(hash_table, bucket_size);
    // Free memory
    for (int i = 0; i < bucket_size; i++) {
        Node* current = hash_table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash_table);
    fclose(file);
    return 0;
}