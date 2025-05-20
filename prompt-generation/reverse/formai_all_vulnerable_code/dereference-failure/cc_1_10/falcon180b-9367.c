//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void init(LinkedList *list) {
    list->head = NULL;
}

void add(LinkedList *list, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print(LinkedList *list) {
    Node *temp = list->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse(LinkedList *list) {
    Node *prev = NULL;
    Node *next = NULL;
    Node *head = list->head;
    while (head!= NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    list->head = prev;
}

int main() {
    LinkedList list;
    init(&list);
    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 5);
    printf("Original Linked List: ");
    print(&list);
    reverse(&list);
    printf("Reversed Linked List: ");
    print(&list);
    return 0;
}