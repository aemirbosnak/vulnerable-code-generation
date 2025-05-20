//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

struct word_node {
    char *word;
    struct word_node *next;
};

void insert_word(struct word_node **head, char *word) {
    struct word_node *new_node = malloc(sizeof(struct word_node));
    new_node->word = strdup(word);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

int count_words(struct word_node *head) {
    int count = 0;

    while (head) {
        count++;
        head = head->next;
    }

    return count;
}

int main() {
    struct word_node *head = NULL;

    char text[] = "This is a sample text with many words. The quick brown fox jumps over the lazy dog. The cat sat on the mat.";

    insert_word(&head, "the");
    insert_word(&head, "is");
    insert_word(&head, "a");
    insert_word(&head, "sample");
    insert_word(&head, "text");
    insert_word(&head, "many");
    insert_word(&head, "words");
    insert_word(&head, "quick");
    insert_word(&head, "brown");
    insert_word(&head, "fox");
    insert_word(&head, "jumps");
    insert_word(&head, "over");
    insert_word(&head, "lazy");
    insert_word(&head, "dog");
    insert_word(&head, "cat");
    insert_word(&head, "sat");
    insert_word(&head, "on");
    insert_word(&head, "mat");

    int word_count = count_words(head);

    printf("Total number of words: %d\n", word_count);

    return 0;
}