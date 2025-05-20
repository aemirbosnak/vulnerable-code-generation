//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

void init(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

int isEmpty(LinkedList* list) {
    return list->head == NULL;
}

int size(LinkedList* list) {
    return list->size;
}

void add(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(list)) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    list->size++;
}

void delete(LinkedList* list, int data) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }

    if (list->head->data == data) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }

    Node* prev = list->head;
    Node* curr = prev->next;

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
    list->size--;
}

void print(LinkedList* list) {
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }

    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    init(&list);

    add(&list, 10);
    add(&list, 20);
    add(&list, 30);
    add(&list, 40);
    add(&list, 50);

    printf("Size of list: %d\n", size(&list));
    print(&list);

    delete(&list, 20);
    delete(&list, 40);

    printf("Size of list after deletion: %d\n", size(&list));
    print(&list);

    return 0;
}