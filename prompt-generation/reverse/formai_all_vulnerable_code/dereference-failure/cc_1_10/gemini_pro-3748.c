//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char word[100];
    struct node *next;
} node_t;

node_t *head = NULL;

void insert(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    new_node->next = head;
    head = new_node;
}

int search(char *word) {
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        insert(word);
    }

    fclose(fp);
}

int check_spelling(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    return search(word);
}

int main() {
    load_dictionary("dictionary.txt");

    char word[100];
    while (1) {
        printf("Enter a word (or 'q' to quit): ");
        scanf("%s", word);

        if (strcmp(word, "q") == 0) {
            break;
        }

        if (check_spelling(word)) {
            printf("Valid word.\n");
        } else {
            printf("Invalid word.\n");
        }
    }

    return 0;
}