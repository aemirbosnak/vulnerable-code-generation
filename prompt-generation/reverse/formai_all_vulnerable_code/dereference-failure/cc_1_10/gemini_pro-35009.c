//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

typedef struct node {
    char word[MAX_WORD_LENGTH + 1];
    struct node *next;
} node;

node *head = NULL;

void insert(char *word) {
    node *new_node = malloc(sizeof(node));
    strcpy(new_node->word, word);
    new_node->next = head;
    head = new_node;
}

int search(char *word) {
    node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(dictionary, "%s", word) != EOF) {
        insert(word);
    }
    fclose(dictionary);

    FILE *text = fopen("text.txt", "r");
    if (text == NULL) {
        printf("Error opening text file.\n");
        return 1;
    }

    while (fscanf(text, "%s", word) != EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        if (!search(word)) {
            printf("%s is not in the dictionary.\n", word);
        }
    }
    fclose(text);

    return 0;
}