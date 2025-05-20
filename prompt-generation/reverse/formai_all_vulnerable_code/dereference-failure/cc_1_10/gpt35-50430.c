//FormAI DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define HASH_SIZE 5000

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node* next;
} Node;

Node* hash_table[HASH_SIZE];

int hash(char* str) {
    int length = strlen(str);
    int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value = (31 * hash_value + tolower(str[i])) % HASH_SIZE;
    }
    return hash_value;
}

void insert_word(char* str) {
    int index = hash(str);
    Node* new_word = malloc(sizeof(Node));
    memcpy(new_word->word, str, MAX_WORD_LENGTH);
    new_word->next = hash_table[index];
    hash_table[index] = new_word;
}

void read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: unable to read file %s.\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, " %s", word) == 1) {
        insert_word(word);
    }
    fclose(file);
}

int check_word(char* word) {
    int index = hash(word);
    Node* curr = hash_table[index];
    while (curr) {
        if (strcmp(curr->word, word) == 0) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void lower_case(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error: incorrect number of arguments. Usage: ./spell_check [dictionary file] [text file]\n");
        exit(1);
    }

    read_file(argv[1]);

    FILE* file = fopen(argv[2], "r");
    if (!file) {
        printf("Error: unable to read file %s.\n", argv[2]);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, " %s", word) == 1) {
        lower_case(word);
        if (!check_word(word)) {
            printf("Misspelled word: %s\n", word);
        }
    }
    fclose(file);

    return 0;
}