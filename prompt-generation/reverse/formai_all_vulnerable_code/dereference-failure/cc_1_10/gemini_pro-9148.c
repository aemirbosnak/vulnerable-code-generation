//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *word;
    int count;
    struct node *next;
};

struct node *head = NULL;

void insert(char *word) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->count = 1;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_summary(int n) {
    if (head == NULL) {
        printf("No words to summarize.\n");
    } else {
        struct node *current = head;
        while (current != NULL) {
            if (current->count >= n) {
                printf("%s: %d\n", current->word, current->count);
            }
            free(current->word);
            current = current->next;
        }
        free(head);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <n> <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    char *text = argv[2];

    char *token = strtok(text, " ");
    while (token != NULL) {
        insert(token);
        token = strtok(NULL, " ");
    }

    print_summary(n);

    return EXIT_SUCCESS;
}