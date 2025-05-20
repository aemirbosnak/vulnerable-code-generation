//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: imaginative
// Welcome to the realm of C, where syntax dances with imagination.

#include <stdio.h>
#include <stdlib.h>

// The Enchanted Forest of Syntax

struct Node {
    char *data;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
};

// The Wise Tree of Tokenization
int tokenize(char *input, struct Queue *queue) {
    char *token = strtok(input, " ");
    while (token != NULL) {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->data = token;
        node->next = NULL;
        if (queue->head == NULL) {
            queue->head = node;
            queue->tail = node;
        } else {
            queue->tail->next = node;
            queue->tail = node;
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

// The Majestic Castle of Parsing
void parse(struct Queue *queue, int *result) {
    struct Node *current = queue->head;
    while (current != NULL) {
        if (*current->data == '+') {
            *result += atoi(current->next->data);
        } else if (*current->data == '-') {
            *result -= atoi(current->next->data);
        } else {
            *result = atoi(current->data);
        }
        current = current->next;
    }
}

// The Enchanted Meadow of Main
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <expression>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    int result = 0;

    struct Queue queue;
    queue.head = NULL;
    queue.tail = NULL;

    tokenize(input, &queue);
    parse(&queue, &result);

    printf("Expression: %s", input);
    printf("\nResult: %d\n", result);

    return 0;
}