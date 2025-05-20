//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node for the word frequency linked list
typedef struct node
{
    char *word;
    int count;
    struct node *next;
} node_t;

// Hash table for storing the word frequencies
typedef struct hash_table
{
    int size;
    node_t **table;
} hash_table_t;

// Create a new hash table
hash_table_t *create_hash_table(int size)
{
    hash_table_t *hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));
    hash_table->size = size;
    hash_table->table = (node_t **)malloc(sizeof(node_t *) * size);
    for (int i = 0; i < size; i++)
    {
        hash_table->table[i] = NULL;
    }
    return hash_table;
}

// Free a hash table
void free_hash_table(hash_table_t *hash_table)
{
    for (int i = 0; i < hash_table->size; i++)
    {
        node_t *current = hash_table->table[i];
        while (current != NULL)
        {
            node_t *next = current->next;
            free(current->word);
            free(current);
            current = next;
        }
    }
    free(hash_table->table);
    free(hash_table);
}

// Insert a word into the hash table
void insert_word(hash_table_t *hash_table, char *word)
{
    int index = hash(word, hash_table->size);
    node_t *current = hash_table->table[index];

    // Check if the word is already in the hash table
    while (current != NULL)
    {
        if (strcmp(current->word, word) == 0)
        {
            current->count++;
            return;
        }
        current = current->next;
    }

    // Create a new node for the word
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    // Insert the new node into the hash table
    hash_table->table[index] = new_node;
}

// Get the frequency of a word from the hash table
int get_word_frequency(hash_table_t *hash_table, char *word)
{
    int index = hash(word, hash_table->size);
    node_t *current = hash_table->table[index];

    // Search for the word in the hash table
    while (current != NULL)
    {
        if (strcmp(current->word, word) == 0)
        {
            return current->count;
        }
        current = current->next;
    }

    // The word is not in the hash table
    return 0;
}

// Print the word frequencies in the hash table
void print_word_frequencies(hash_table_t *hash_table)
{
    for (int i = 0; i < hash_table->size; i++)
    {
        node_t *current = hash_table->table[i];
        while (current != NULL)
        {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

// Hash function for strings
int hash(char *string, int size)
{
    int hash_value = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        hash_value += string[i];
    }
    return hash_value % size;
}

// Main function
int main()
{
    // Create a hash table
    hash_table_t *hash_table = create_hash_table(1000);

    // Read the text from the file
    FILE *file = fopen("text.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        // Tokenize the text and insert the words into the hash table
        char *token = strtok(buffer, " ");
        while (token != NULL)
        {
            // Convert the token to lowercase
            for (int i = 0; token[i] != '\0'; i++)
            {
                token[i] = tolower(token[i]);
            }

            // Insert the word into the hash table
            insert_word(hash_table, token);

            // Get the next token
            token = strtok(NULL, " ");
        }
    }
    fclose(file);

    // Print the word frequencies
    print_word_frequencies(hash_table);

    // Free the hash table
    free_hash_table(hash_table);

    return 0;
}