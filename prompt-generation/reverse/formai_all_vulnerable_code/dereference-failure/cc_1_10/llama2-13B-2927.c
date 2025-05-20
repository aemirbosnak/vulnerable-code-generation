//LLAMA2-13B DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 42

struct node {
    char *word;
    int frequency;
    struct node *next;
};

struct dictionary {
    struct node *head;
    struct node *tail;
};

void init_dictionary(struct dictionary *dict) {
    dict->head = NULL;
    dict->tail = NULL;
}

void add_word(struct dictionary *dict, char *word) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = word;
    new_node->frequency = 1;
    new_node->next = NULL;

    if (dict->head == NULL) {
        dict->head = new_node;
    } else {
        dict->tail->next = new_node;
    }
    dict->tail = new_node;
}

int find_frequency(struct dictionary *dict, char *word) {
    struct node *current = dict->head;
    int frequency = 0;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            frequency = current->frequency;
            break;
        }
        current = current->next;
    }

    return frequency;
}

void print_dictionary(struct dictionary *dict) {
    struct node *current = dict->head;

    while (current != NULL) {
        printf("%s: %d\n", current->word, current->frequency);
        current = current->next;
    }
}

int main() {
    srand(time(NULL));

    struct dictionary dict;
    init_dictionary(&dict);

    char word[MAX_LENGTH];
    int i;

    for (i = 0; i < 100; i++) {
        // Generate a random word
        snprintf(word, MAX_LENGTH, "word%d", i);

        // Add the word to the dictionary
        add_word(&dict, word);
    }

    // Print the dictionary
    print_dictionary(&dict);

    // Find the frequency of a random word
    char *random_word = "word42";
    int frequency = find_frequency(&dict, random_word);

    printf("Frequency of %s: %d\n", random_word, frequency);

    return 0;
}