//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    struct node *next;
} node;

node *head = NULL;

void insert(char *word) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->next = head;
    head = new_node;
}

int search(char *word) {
    node *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int check_spelling(char *word) {
    return search(word);
}

int main() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        return EXIT_FAILURE;
    }

    char buffer[100];
    while (fgets(buffer, 100, fp) != NULL) {
        char *word = strtok(buffer, "\n");
        insert(word);
    }

    fclose(fp);

    char input[100];
    printf("Enter a word to check spelling: ");
    scanf("%s", input);

    if (check_spelling(input)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is misspelled.\n");
    }

    return EXIT_SUCCESS;
}