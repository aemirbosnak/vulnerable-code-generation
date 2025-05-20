//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define MAX_LEN 1024
#define MIN_LEN 10

typedef struct node {
    char *word;
    int count;
    struct node *next;
} Node;

void init_nodes(Node **head) {
    *head = NULL;
}

void add_node(Node **head, char *word) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->word = word;
    new_node->count = 1;
    new_node->next = *head;
    *head = new_node;
}

void print_nodes(Node *head) {
    while (head != NULL) {
        printf("%s: %d\n", head->word, head->count);
        head = head->next;
    }
}

int main() {
    Node *head = NULL;

    // Example usage:
    add_node(&head, "the");
    add_node(&head, "quick");
    add_node(&head, "brown");
    add_node(&head, "fox");
    add_node(&head, "jumps");
    add_node(&head, "over");
    add_node(&head, "the");
    add_node(&head, "lazy");
    add_node(&head, "dog");

    print_nodes(head);

    return 0;
}