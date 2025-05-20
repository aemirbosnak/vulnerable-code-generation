//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} node;

typedef struct queue {
    node *head;
    node *tail;
} queue;

queue *create_queue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(queue *q, char data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

char dequeue(queue *q) {
    if (q->head == NULL) {
        return '\0';
    } else {
        char data = q->head->data;
        node *new_head = q->head->next;
        free(q->head);
        q->head = new_head;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        return data;
    }
}

int main() {
    queue *q = create_queue();
    char *s = "Happy Birthday";
    for (int i = 0; i < strlen(s); i++) {
        enqueue(q, s[i]);
    }
    while (q->head != NULL) {
        printf("%c", dequeue(q));
    }
    printf("\n");
    return 0;
}