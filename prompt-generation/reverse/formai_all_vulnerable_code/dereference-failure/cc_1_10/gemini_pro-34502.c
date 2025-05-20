//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *word;
    struct node *next;
} node;

node *head = NULL;

void insert(char *word) {
    node *new = malloc(sizeof(node));
    new->word = strdup(word);
    new->next = head;
    head = new;
}

int check(char *word) {
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
    FILE *f = fopen("words.txt", "r");
    char buf[1024];
    while (fgets(buf, sizeof(buf), f)) {
        char *word = strtok(buf, "\n");
        insert(word);
    }
    fclose(f);

    char input[1024];
    while (1) {
        printf("Enter a word: ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        if (check(input)) {
            printf("The word is spelled correctly.\n");
        } else {
            printf("The word is spelled incorrectly.\n");
        }
    }

    return 0;
}