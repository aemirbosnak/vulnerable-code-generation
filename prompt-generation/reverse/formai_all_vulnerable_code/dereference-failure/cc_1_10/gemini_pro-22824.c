//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
        char * word;
        int count;
        struct node *next;
}node_t;

node_t *insert(node_t *head, char *word) {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->word = strdup(word);
        new_node->count = 1;
        new_node->next = head;
        return new_node;
}

node_t *find(node_t *head, char *word) {
        node_t *current = head;
        while (current != NULL) {
                if (strcmp(current->word, word) == 0) {
                        return current;
                }
                current = current->next;
        }
        return NULL;
}

void print_list(node_t *head) {
        node_t *current = head;
        while (current != NULL) {
                printf("%s: %d\n", current->word, current->count);
                current = current->next;
        }
}

int main() {
        node_t *head = NULL;
        char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
        int num_words = sizeof(words) / sizeof(char *);
        for (int i = 0; i < num_words; i++) {
                node_t *node = find(head, words[i]);
                if (node == NULL) {
                        head = insert(head, words[i]);
                } else {
                        node->count++;
                }
        }
        print_list(head);
        return 0;
}