//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* word;
    int count;
    struct node* next;
} node_t;

node_t* create_node(char* word) {
    node_t* node = malloc(sizeof(node_t));
    node->word = strdup(word);
    node->count = 1;
    node->next = NULL;
    return node;
}

void insert_node(node_t** head, char* word) {
    node_t* new_node = create_node(word);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

int count_words(node_t* head) {
    int count = 0;
    node_t* current = head;
    while (current != NULL) {
        count += current->count;
        current = current->next;
    }
    return count;
}

void print_words(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void free_list(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        node_t* next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

int main() {
    node_t* head = NULL;
    char* words[] = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
    int num_words = sizeof(words) / sizeof(char*);
    for (int i = 0; i < num_words; i++) {
        insert_node(&head, words[i]);
    }
    printf("Total number of words: %d\n", count_words(head));
    print_words(head);
    free_list(head);
    return 0;
}