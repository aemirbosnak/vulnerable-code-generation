//LLAMA2-13B DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT 1024
#define MAX_LEVEL 10

struct Node {
    char name[50];
    int score;
    struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
};

void initQueue(struct Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(struct Queue *q, char *name, int score) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    strcpy(node->name, name);
    node->score = score;
    if (q->head == NULL) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
    q->tail = node;
}

void dequeue(struct Queue *q) {
    if (q->head == NULL) {
        return;
    }
    struct Node *node = q->head;
    q->head = node->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(node);
}

int getHighestScore(struct Queue *q) {
    int highest = -1;
    struct Node *node = q->head;
    while (node != NULL) {
        if (node->score > highest) {
            highest = node->score;
        }
        node = node->next;
    }
    return highest;
}

void printQueue(struct Queue *q) {
    struct Node *node = q->head;
    while (node != NULL) {
        printf("%s: %d\n", node->name, node->score);
        node = node->next;
    }
}

int main() {
    srand(time(NULL));
    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
    initQueue(q);

    for (int i = 0; i < 10; i++) {
        char name[50];
        int score = rand() % 100 + 1;
        printf("Player %d: ", i + 1);
        fgets(name, sizeof(name), stdin);
        enqueue(q, name, score);
    }

    while (q->head != NULL) {
        dequeue(q);
    }

    printf("Highest score: %d\n", getHighestScore(q));
    printQueue(q);

    return 0;
}