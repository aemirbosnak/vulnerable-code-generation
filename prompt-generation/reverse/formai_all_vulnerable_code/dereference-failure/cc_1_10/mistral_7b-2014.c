//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

HashNode *table[TABLE_SIZE];

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void add_word(char *word) {
    unsigned long index = hash(word);

    HashNode *new_node = (HashNode *)calloc(1, sizeof(HashNode));
    new_node->key = strdup(word);
    new_node->value = 1;

    if (table[index] == NULL) {
        table[index] = new_node;
    } else {
        HashNode *current = table[index];

        while (current->next != NULL)
            current = current->next;

        current->next = new_node;
    }
}

void process_text_file(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file.");
        return;
    }

    char word[256];

    while (fscanf(file, "%s", word) != EOF) {
        for (int i = 0; word[i]; i++)
            word[i] = tolower(word[i]);

        add_word(word);
    }

    fclose(file);
}

void print_word_frequency() {
    printf("%-20s %s\n", "Word", "Frequency");

    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *current = table[i];

        while (current != NULL) {
            printf("%-20s %d\n", current->key, current->value);
            current = current->next;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    process_text_file(argv[1]);
    print_word_frequency();

    return 0;
}