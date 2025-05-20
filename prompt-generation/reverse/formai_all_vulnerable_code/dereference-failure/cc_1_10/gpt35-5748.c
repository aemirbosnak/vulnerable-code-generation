//FormAI DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_TABLE_SIZE 10000 // Size for our hash table

// Node struct for linked list of words
typedef struct node {
    char data[50];
    struct node *next;
} Node;

// Function prototypes
Node* create_node(char*);
unsigned long hash(char*);
void insert(Node**, char*);
int lookup(Node**, char*);
void spell_check(char*, Node**);


int main() {
    // Initialize hash table as an array of NULL pointers
    Node *hash_table[HASH_TABLE_SIZE] = {NULL};
    
    // Add words from a text file to our hash table
    char filename[] = "dictionary.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char word[50];
    while (fscanf(fp, "%s", word) != EOF) {
        insert(hash_table, word);
    }
    fclose(fp);
    
    // Prompt user for input to spell check
    char input[200];
    printf("Please enter text to spell check:\n");
    fgets(input, 200, stdin);
    
    // Remove newline character from input
    input[strlen(input) - 1] = '\0';
    
    // Spell check input by iterating over each word and checking if it is in the dictionary
    spell_check(input, hash_table);
    
    // Free memory allocated for hash table
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node *current = hash_table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    return 0;
}

// Create new node for linked list of words
Node* create_node(char *word) {
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->data, word);
    new_node->next = NULL;
    return new_node;
}

// Hash function to convert string into an index for our hash table
unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_TABLE_SIZE;
}

// Insert word into hash table
void insert(Node **hash_table, char *word) {
    unsigned long index = hash(word);
    Node *new_node = create_node(word);
    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        Node *current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Look up word in hash table
int lookup(Node **hash_table, char *word) {
    unsigned long index = hash(word);
    Node *current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->data, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Spell check input by iterating over each word and checking if it is in the dictionary
void spell_check(char *input, Node **hash_table) {
    char *word = strtok(input, " ,.;:-!?\"()\n");
    while (word != NULL) {
        int i;
        for (i = 0; word[i]; i++) {
            if (!isalpha(word[i])) {
                break;
            }
        }
        if (i == strlen(word)) {
            if (!lookup(hash_table, word)) {
                printf("Unknown word: %s\n", word);
            }
        }
        word = strtok(NULL, " ,.;:-!?\"()\n");
    }
}