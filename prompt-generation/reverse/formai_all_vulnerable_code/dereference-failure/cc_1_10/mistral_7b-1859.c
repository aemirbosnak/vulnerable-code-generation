//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

typedef struct Node {
    char word[MAX_WORD_LENGTH + 1];
    struct Node *next;
} Node;

Node *head = NULL;

void load_dictionary() {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    char line[MAX_WORD_LENGTH + 1];
    Node *new_node;

    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)) {
        size_t len = strlen(line);
        if (len > MAX_WORD_LENGTH) {
            continue;
        }

        new_node = (Node *)malloc(sizeof(Node));
        strcpy(new_node->word, line);
        new_node->next = head;
        head = new_node;
    }

    fclose(file);
}

bool is_valid_word(char *word) {
    Node *current = head;

    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void check_spell(char *input_string) {
    char *token = strtok(input_string, " ");
    bool valid_word;

    while (token != NULL) {
        for (int i = 0; token[i] != '\0'; i++) {
            token[i] = tolower(token[i]);
        }
        valid_word = is_valid_word(token);

        if (!valid_word) {
            printf("Error: '%s' is not a valid word.\n", token);
        }

        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    load_dictionary();

    if (argc < 2) {
        printf("Usage: %s <string to check>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    check_spell(argv[1]);

    return EXIT_SUCCESS;
}