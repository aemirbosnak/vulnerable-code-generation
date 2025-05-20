//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

struct HappyNode {
    int key;
    struct HappyNode *next;
};

struct HappyList {
    struct HappyNode *head;
};

void initHappyList(struct HappyList *list) {
    list->head = NULL;
}

void addHappyNode(struct HappyList *list, int key) {
    struct HappyNode *newNode = malloc(sizeof(struct HappyNode));
    newNode->key = key;
    newNode->next = list->head;
    list->head = newNode;
}

int findHappyNode(struct HappyList *list, int key) {
    struct HappyNode *current = list->head;
    while (current != NULL && current->key != key) {
        current = current->next;
    }
    return current;
}

void printHappyList(struct HappyList *list) {
    struct HappyNode *current = list->head;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct HappyList list;
    initHappyList(&list);

    addHappyNode(&list, 1);
    addHappyNode(&list, 2);
    addHappyNode(&list, 3);
    addHappyNode(&list, 4);
    addHappyNode(&list, 5);

    struct HappyNode *happyNode = findHappyNode(&list, MAGIC_NUMBER);
    if (happyNode != NULL) {
        printf("Found happy node with key %d!\n", happyNode->key);
    } else {
        printf("No happy node found :(");
    }

    printHappyList(&list);

    return 0;
}