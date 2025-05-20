//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *word;
    int count;
    struct node *next;
};

struct hashtable {
    int size;
    struct node **table;
};

struct hashtable *create_hashtable(int size) {
    struct hashtable *ht = malloc(sizeof(struct hashtable));
    ht->size = size;
    ht->table = malloc(sizeof(struct node *) * size);
    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insert_hashtable(struct hashtable *ht, char *word) {
    int index = hash(word, ht->size);
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = word;
    new_node->count = 1;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
}

int hash(char *word, int size) {
    int hash_value = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_value += word[i];
    }
    return hash_value % size;
}

int check_hashtable(struct hashtable *ht, char *word) {
    int index = hash(word, ht->size);
    struct node *current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

void destroy_hashtable(struct hashtable *ht) {
    for (int i = 0; i < ht->size; i++) {
        struct node *current = ht->table[i];
        while (current != NULL) {
            struct node *next = current->next;
            free(current->word);
            free(current);
            current = next;
        }
    }
    free(ht->table);
    free(ht);
}

int main() {
    struct hashtable *ht = create_hashtable(100);

    // Insert words into the hashtable
    char *words[] = {"spam", "viagra", "rolex", "free", "money"};
    for (int i = 0; i < 5; i++) {
        insert_hashtable(ht, words[i]);
    }

    // Check if a word is spam
    char *input = "I want to buy a rolex";
    int count = check_hashtable(ht, "rolex");
    if (count > 0) {
        printf("The input is spam (%s: %d)\n", "rolex", count);
    } else {
        printf("The input is not spam\n");
    }

    // Destroy the hashtable
    destroy_hashtable(ht);

    return 0;
}