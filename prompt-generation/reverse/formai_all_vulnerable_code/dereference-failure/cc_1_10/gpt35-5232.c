//FormAI DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_MISSPELLED 1000
#define HASH_TABLE_SIZE 500

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

Node* hash_table[HASH_TABLE_SIZE];

int hash(char* word) {
    int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash_value = (hash_value + tolower(word[i])) * 31;
    }
    return hash_value % HASH_TABLE_SIZE;
}

void add_word(char* word) {
    int index = hash(word);
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int check_word(char* word) {
    if (strlen(word) >= MAX_WORD_LENGTH) {
        return -1;
    }

    for (int i = 0; word[i] != '\0'; i++) {
        if (!isalpha(word[i])) {
            return -1;
        }
    }

    int index = hash(word);
    Node* current_node = hash_table[index];

    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return 0;
        }
        current_node = current_node->next;
    }

    return 1;
}

int check_file(FILE* fp, char* misspelled[]) {
    int num_misspelled = 0;
    char word[MAX_WORD_LENGTH + 1];
    int pos = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            word[pos++] = tolower(c);
            if (pos > MAX_WORD_LENGTH) {
                pos = 0;
                while ((c = fgetc(fp)) != EOF && isalpha(c));
            }
        }
        else if (pos > 0) {
            word[pos] = '\0';
            if (check_word(word) == 1) {
                misspelled[num_misspelled++] = strdup(word);
                if (num_misspelled >= MAX_MISSPELLED) {
                    return num_misspelled;
                }
            }
            pos = 0;
        }
    }

    if (pos > 0) {
        word[pos] = '\0';
        if (check_word(word) == 1) {
            misspelled[num_misspelled++] = strdup(word);
        }
    }

    return num_misspelled;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char* misspelled[MAX_MISSPELLED];
    int num_misspelled = check_file(fp, misspelled);

    printf("Misspelled words:\n");
    for (int i = 0; i < num_misspelled; i++) {
        printf("%s\n", misspelled[i]);
    }

    fclose(fp);
    return 0;
}