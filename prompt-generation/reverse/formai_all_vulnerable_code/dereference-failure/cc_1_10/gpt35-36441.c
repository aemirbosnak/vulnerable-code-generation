//FormAI DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 1000

typedef struct node {
    char word[50];
    struct node* next;
} node;

node* hash_table[TABLE_SIZE];

int hash(char* word) {
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        sum += tolower(word[i]);
    }
    return ((sum % TABLE_SIZE) + TABLE_SIZE) % TABLE_SIZE; // prevent negative index
}

void insert(char* word) {
    int index = hash(word);
    node* new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int check(char* word) {
    int index = hash(word);
    node* current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1; // word exists in hash table (i.e. is spelled correctly)
        }
        current = current->next;
    }
    return 0; // word does not exist in hash table (i.e. is spelled incorrectly)
}

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char word[50];
    while (fscanf(file, "%s", word) != EOF) {
        insert(word);
    }
    fclose(file);
}

int main() {
    load_dictionary("dictionary.txt");
    char input[100];
    printf("Enter some text to spell check:\n");
    scanf("%[^\n]", input);
    char* word = strtok(input, " ,.!?");
    while (word != NULL) {
        if (!check(word)) {
            printf("Misspelled word: %s\n", word);
        }
        word = strtok(NULL, " ,.!?");
    }
    return 0;
}