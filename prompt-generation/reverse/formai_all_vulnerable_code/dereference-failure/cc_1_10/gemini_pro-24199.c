//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word_node {
    char *word;
    int count;
    struct word_node *next;
} word_node;

int main() {
    char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas eget lacus eget nunc tincidunt laoreet. Sed eget lacus eget nunc tincidunt laoreet. Suspendisse potenti. Maecenas eget lacus eget nunc tincidunt laoreet. In hac habitasse platea dictumst. Maecenas eget lacus eget nunc tincidunt laoreet. Etiam faucibus libero ac arcu laoreet, eget consectetur quam tincidunt. Maecenas eget lacus eget nunc tincidunt laoreet. Aenean lacus nunc, tincidunt sit amet consectetur eget, consectetur sit amet nunc. Maecenas eget lacus eget nunc tincidunt laoreet. Mauris eget lacus eget nunc tincidunt laoreet. Integer eget lacus eget nunc tincidunt laoreet. Nam eget lacus eget nunc tincidunt laoreet. Maecenas eget lacus eget nunc tincidunt laoreet. Ut eget lacus eget nunc tincidunt laoreet. Maecenas eget lacus eget nunc tincidunt laoreet. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Maecenas eget lacus eget nunc tincidunt laoreet. Suspendisse potenti. Maecenas eget lacus eget nunc tincidunt laoreet. Nunc et lacus eget nunc tincidunt laoreet. Maecenas eget lacus eget nunc tincidunt laoreet. Sed eget lacus eget nunc tincidunt laoreet. Maecenas eget lacus eget nunc tincidunt laoreet. Aenean lacus nunc, tincidunt sit amet consectetur eget, consectetur sit amet nunc. Maecenas eget lacus eget nunc tincidunt laoreet. Mauris eget lacus eget nunc tincidunt laoreet. Integer eget lacus eget nunc tincidunt laoreet. Nam eget lacus eget nunc tincidunt laoreet. Maecenas eget lacus eget nunc tincidunt laoreet. Ut eget lacus eget nunc tincidunt laoreet.";

    // Split the text into words
    char *words[100];
    int num_words = 0;
    char *word = strtok(text, " ,.-\n");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ,.-\n");
    }

    // Create a hash table to store the word frequencies
    word_node *hash_table[100];
    for (int i = 0; i < 100; i++) {
        hash_table[i] = NULL;
    }

    // Add each word to the hash table
    for (int i = 0; i < num_words; i++) {
        // Calculate the hash value for the word
        int hash_value = 0;
        for (int j = 0; j < strlen(words[i]); j++) {
            hash_value += words[i][j];
        }
        hash_value = hash_value % 100;

        // Add the word to the hash table
        word_node *new_node = malloc(sizeof(word_node));
        new_node->word = words[i];
        new_node->count = 1;
        new_node->next = hash_table[hash_value];
        hash_table[hash_value] = new_node;
    }

    // Print the word frequencies
    for (int i = 0; i < 100; i++) {
        word_node *node = hash_table[i];
        while (node != NULL) {
            printf("%s: %d\n", node->word, node->count);
            node = node->next;
        }
    }

    // Free the memory used by the hash table
    for (int i = 0; i < 100; i++) {
        word_node *node = hash_table[i];
        while (node != NULL) {
            word_node *next = node->next;
            free(node);
            node = next;
        }
    }

    return 0;
}