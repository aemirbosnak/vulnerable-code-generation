//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linkedlist {
    Node* head;
} LinkedList;

LinkedList* create_linkedlist() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        printf("Memory error\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}

Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory error\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(LinkedList* list, int data) {
    Node* node = create_node(data);
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void print_linkedlist(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % 10 + 1;
    LinkedList* list = create_linkedlist();
    for (int i = 0; i < n; i++) {
        int data = rand() % 100;
        add_node(list, data);
    }
    printf("Linked List: ");
    print_linkedlist(list);
    return 0;
}