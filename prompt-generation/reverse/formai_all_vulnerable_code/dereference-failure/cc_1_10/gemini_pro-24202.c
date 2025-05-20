//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void add_word(char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int get_count(char *word) {
    node *current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->count;
        }
        current = current->next;
    }

    return 0;
}

void increment_count(char *word) {
    node *current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }

    add_word(word);
}

void print_list() {
    node *current = head;

    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int num_words = sizeof(words) / sizeof(char *);

    for (int i = 0; i < num_words; i++) {
        increment_count(words[i]);
    }

    print_list();

    return 0;
}