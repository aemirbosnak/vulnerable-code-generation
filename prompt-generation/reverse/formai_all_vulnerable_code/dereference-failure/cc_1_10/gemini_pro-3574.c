//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *word;
    int count;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void add_word(char *word) {
    struct node *new_node = malloc(sizeof(struct node));
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

void remove_word(char *word) {
    struct node *current_node = head;
    struct node *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            if (current_node == head) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }

            if (current_node == tail) {
                tail = previous_node;
            }

            free(current_node->word);
            free(current_node);
            return;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }
}

int get_word_count(char *word) {
    struct node *current_node = head;

    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return current_node->count;
        }

        current_node = current_node->next;
    }

    return 0;
}

void print_word_frequency() {
    struct node *current_node = head;

    while (current_node != NULL) {
        printf("%s: %d\n", current_node->word, current_node->count);
        current_node = current_node->next;
    }
}

int main() {
    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int num_words = sizeof(words) / sizeof(char *);

    for (int i = 0; i < num_words; i++) {
        add_word(words[i]);
    }

    remove_word("the");

    printf("Word Frequency:\n");
    print_word_frequency();

    return 0;
}