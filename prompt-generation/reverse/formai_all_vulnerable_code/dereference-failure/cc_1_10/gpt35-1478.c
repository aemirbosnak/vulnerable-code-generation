//FormAI DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    int size;
    Node* head;
    Node* tail;
} LinkedList;

void init(LinkedList* l) {
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
}

void add(LinkedList* l, int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;

    if(l->size == 0) {
        l->head = n;
        l->tail = n;
    }
    else {
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
}

int pop(LinkedList* l) {
    if(l->size == 0) return -1;
    Node* head = l->head;
    int data = head->data;
    l->head = head->next;
    free(head);
    l->size--;
    return data;
}

void display(LinkedList* l) {
    printf("Size: %d -> ", l->size);
    Node* n = l->head;
    while(n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList l;
    init(&l);

    srand(time(NULL));
    for(int i=0; i<10; i++) {
        int n = rand() % 100;
        add(&l, n);
    }

    display(&l);
    int popped = pop(&l);
    printf("Popped: %d\n", popped);
    display(&l);

    return 0;
}