//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

void createList(struct list *l) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = 1;
    temp->next = NULL;
    l->head = temp;
}

void addNode(struct list *l, int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = val;
    temp->next = NULL;
    if (l->head == NULL) {
        l->head = temp;
    } else {
        struct node *temp2 = l->head;
        while (temp2->next!= NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

void printList(struct list *l) {
    struct node *temp = l->head;
    while (temp!= NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct list l = {NULL};
    createList(&l);
    addNode(&l, 2);
    addNode(&l, 3);
    addNode(&l, 4);
    printList(&l);
    return 0;
}