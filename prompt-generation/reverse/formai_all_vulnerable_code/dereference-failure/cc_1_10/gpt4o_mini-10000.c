//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node* next;
} Node;

Node* dictionary[DICTIONARY_SIZE];

unsigned long hash(char* word) {
    unsigned long hash_value = 5381;
    int c;
    while ((c = *word++)) {
        hash_value = ((hash_value << 5) + hash_value) + c; // hash * 33 + c
    }
    return hash_value % DICTIONARY_SIZE;
}

void insert_word(char* word) {
    unsigned long index = hash(word);
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = dictionary[index];
    dictionary[index] = new_node;
}

int check_word(char* word) {
    unsigned long index = hash(word);
    Node* node = dictionary[index];
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return 1; // Word found
        }
        node = node->next;
    }
    return 0; // Word not found
}

void free_dictionary() {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        Node* node = dictionary[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
}

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        insert_word(word);
    }
    fclose(file);
}

void spell_check(char* text) {
    char* token = strtok(text, " \n");
    
    while (token != NULL) {
        char* word = token;

        // Strip punctuation from word
        while (*word && (ispunct(*word))) word++;
        char* end = word + strlen(word) - 1;
        while (end > word && ispunct(*end)) end--;
        end[1] = '\0';

        // Check if the word is empty after stripping
        if (*word != '\0') {
            if (!check_word(word)) {
                printf("Misspelled: %s\n", word);
            }
        }

        token = strtok(NULL, " \n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    load_dictionary(argv[1]);
    
    FILE* text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        printf("Cannot open text file: %s\n", argv[2]);
        free_dictionary();
        return EXIT_FAILURE;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), text_file) != NULL) {
        spell_check(buffer);
    }
    
    fclose(text_file);
    free_dictionary();
    
    return EXIT_SUCCESS;
}