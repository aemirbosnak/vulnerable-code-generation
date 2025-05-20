//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define TABLE_SIZE 101
#define MAX_WORD_LENGTH 50

typedef struct HashNode {
    char word[MAX_WORD_LENGTH];
    int count;
    struct HashNode *next;
} HashNode;

HashNode* create_node(const char *word) {
    HashNode *new_node = (HashNode*) malloc(sizeof(HashNode));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->next = NULL;
    return new_node;
}

int hash_func(const char *word) {
    int hash = 0;
    for (int i = 0; i < strlen(word); i++)
        hash += tolower(word[i]) * (i % 3);
    return hash % TABLE_SIZE;
}

HashNode* hash_table[TABLE_SIZE];

void print_ascii_art() {
    printf("_______________________________________________________________\n");
    printf("|                 Welcome to the Word Frequency Analyzer!       |\n");
    printf("|                --------------------------------------------||\n");
    printf("|                Enter the text file name and press Enter.    |\n");
    printf("|____________________________________________________________||\n");
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char word[MAX_WORD_LENGTH];
    int len;
    while ((len = fscanf(file, "%s%*[^%[%n]]%*c", word)) != EOF) {
        int index = hash_func(word);
        HashNode *current = hash_table[index];
        HashNode *new_node = create_node(word);

        while (current != NULL && strcmp(current->word, word) != 0)
            current = current->next;

        if (current == NULL) {
            new_node->next = hash_table[index];
            hash_table[index] = new_node;
        } else {
            current->count += new_node->count;
            free(new_node);
        }
    }

    fclose(file);
}

void print_results() {
    printf("\nWord\tFrequency\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            HashNode *current = hash_table[i];
            while (current != NULL) {
                printf("%s\t%d\n", current->word, current->count);
                current = current->next;
            }
        }
    }
}

int main() {
    print_ascii_art();

    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);

    process_file(filename);
    print_results();

    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *current = hash_table[i];
        while (current != NULL) {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}