//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Knight {
    int data;
    struct Knight* next;
} Knight;

Knight* createKnight(int data) {
    Knight* knight = (Knight*)malloc(sizeof(Knight));
    knight->data = data;
    knight->next = NULL;
    return knight;
}

void addToQueue(Knight* head, int data) {
    Knight* newKnight = createKnight(data);
    if (head == NULL) {
        head = newKnight;
    } else {
        head->next = newKnight;
    }
    head = newKnight;
}

Knight* removeFromQueue(Knight* head) {
    Knight* tempKnight = head;
    Knight* prevKnight = NULL;
    if (head == NULL) {
        return NULL;
    }
    head = head->next;
    if (prevKnight == NULL) {
        free(tempKnight);
    } else {
        free(tempKnight);
        prevKnight->next = head;
    }
    return head;
}

int main() {
    Knight* head = NULL;
    addToQueue(head, 10);
    addToQueue(head, 20);
    addToQueue(head, 30);
    addToQueue(head, 40);
    addToQueue(head, 50);

    Knight* removedKnight = removeFromQueue(head);
    printf("Removed Knight: %d\n", removedKnight->data);

    removedKnight = removeFromQueue(head);
    printf("Removed Knight: %d\n", removedKnight->data);

    removedKnight = removeFromQueue(head);
    printf("Removed Knight: %d\n", removedKnight->data);

    return 0;
}