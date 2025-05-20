//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A word is a contiguous sequence of alphabetic characters.
#define IS_ALPHA(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

// A node in the hash table.
typedef struct node {
    char *word;
    int count;
    struct node *next;
} node_t;

// The hash table.
#define HASHTABLE_SIZE 10000
node_t **hashtable;

// Hash a string.
unsigned int hash(char *str) {
    unsigned int h = 0;
    while (*str) {
        h = h * 31 + *str++;
    }
    return h % HASHTABLE_SIZE;
}

// Insert a word into the hash table.
void insert(char *word) {
    unsigned int h = hash(word);
    node_t *n = hashtable[h];
    while (n) {
        if (strcmp(n->word, word) == 0) {
            n->count++;
            return;
        }
        n = n->next;
    }
    n = malloc(sizeof(node_t));
    n->word = strdup(word);
    n->count = 1;
    n->next = hashtable[h];
    hashtable[h] = n;
}

// Free the hash table.
void free_hashtable() {
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        node_t *n = hashtable[i];
        while (n) {
            node_t *next = n->next;
            free(n->word);
            free(n);
            n = next;
        }
    }
    free(hashtable);
}

// Count the words in a file.
int count_words(FILE *fp) {
    char buf[1024];
    int count = 0;
    while (fgets(buf, sizeof(buf), fp)) {
        char *word = strtok(buf, " ");
        while (word) {
            if (IS_ALPHA(*word)) {
                insert(word);
            }
            word = strtok(NULL, " ");
            count++;
        }
    }
    return count;
}

// Print the words in the hash table.
void print_hashtable() {
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        node_t *n = hashtable[i];
        while (n) {
            printf("%s: %d\n", n->word, n->count);
            n = n->next;
        }
    }
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Initialize the hash table.
    hashtable = calloc(HASHTABLE_SIZE, sizeof(node_t *));
    if (!hashtable) {
        perror("calloc");
        return EXIT_FAILURE;
    }

    // Count the words in the file.
    int count = count_words(fp);
    printf("Counted %d words.\n", count);

    // Print the words in the hash table.
    print_hashtable();

    // Free the hash table.
    free_hashtable();

    // Close the file.
    fclose(fp);

    return EXIT_SUCCESS;
}