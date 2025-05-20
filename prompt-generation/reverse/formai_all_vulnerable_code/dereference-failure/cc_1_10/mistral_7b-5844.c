//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 10000
typedef struct HashNode {
    char word[20];
    struct HashNode *next;
} HashNode;

HashNode *hash_table[TABLE_SIZE];

unsigned int hash_func(char *str) {
    unsigned int hash = 0;
    for (int i = 0; str[i]; i++) {
        hash = ((hash << 5) + hash) + str[i];
    }
    return hash % TABLE_SIZE;
}

void add_word(char *word) {
    unsigned int index = hash_func(word);
    HashNode *new_node = (HashNode *) malloc(sizeof(HashNode));
    strcpy(new_node->word, word);
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int check_word(char *word) {
    unsigned int index = hash_func(word);
    HashNode *current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    char line[100];
    char *token;
    int misspelled = 0;

    // Initialize dictionary
    add_word("apple");
    add_word("banana");
    add_word("cat");
    add_word("dog");
    add_word("elephant");

    printf("Enter a sentence to check for misspelled words: ");
    fgets(line, sizeof(line), stdin);
    line[strlen(line) - 1] = '\0'; // Remove newline character

    token = strtok(line, " ");
    while (token != NULL) {
        int is_misspelled = 1;
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        if (check_word(token)) {
            is_misspelled = 0;
        }
        if (is_misspelled) {
            misspelled++;
            printf("Misspelled word: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    if (misspelled > 0) {
        printf("%d misspelled word%s found.\n", misspelled, misspelled > 1 ? "s" : "");
    } else {
        printf("No misspelled words found.\n");
    }

    return 0;
}