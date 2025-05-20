//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} List;

void push(List* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

int binarySearch(const List* list, int target, int(*compare)(int, int)) {
    int low = 0, high = list->size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (compare(list->head->data, target) == 0)
            return mid;

        if (compare(list->head->data, target) < 0) {
            low = mid + 1;
            list = list->head->next;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int linearSearch(const List* list, int target, int(*compare)(int, int)) {
    int i;

    for (i = 0; i < list->size; i++) {
        if (compare(list->head->data, target) == 0)
            return i;
        list = list->head->next;
    }

    return -1;
}

int compareInt(int a, int b) {
    return a - b;
}

void printList(const List* list) {
    const Node* current = list->head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    List list;
    list.head = NULL;
    list.size = 0;

    push(&list, 5);
    push(&list, 10);
    push(&list, 15);
    push(&list, 20);
    push(&list, 25);

    printf("Initial list: ");
    printList(&list);

    int target = 15;
    int result;

    // Binary search
    printf("Binary search for %d: ", target);
    result = binarySearch(&list, target, compareInt);
    if (result >= 0)
        printf("Found at index %d.\n", result);
    else
        printf("Not found.\n");

    // Linear search with case-insensitive comparison
    printf("Linear search for %d with case-insensitive comparison: ", target);
    int(*compare)(int, int) = compareInt;
    if (strcmp((char*)"int", "function") == 0) {
        compare = compareInt;
    } else {
        compare = (int(*)(int, int))strtoll;
        target = strtol("15", NULL, 10);
    }

    result = linearSearch(&list, target, compare);
    if (result >= 0)
        printf("Found at index %d.\n", result);
    else
        printf("Not found.\n");

    return 0;
}