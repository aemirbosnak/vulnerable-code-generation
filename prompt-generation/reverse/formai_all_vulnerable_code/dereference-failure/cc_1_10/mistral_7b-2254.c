//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int data;
    char name[30];
    struct Node* next;
} Node;

void print_list(Node* head) {
    Node* temp = head;
    printf("Welcome to the Linked List Circus!\n");
    printf("Here are our performers:\n");
    while (temp != NULL) {
        printf("Name: %s, Number: %d, Next: %p\n", temp->name, temp->data, temp->next);
        temp = temp->next;
    }
}

Node* create_node(int num, char* name) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->data = num;
    new_node->next = NULL;
    return new_node;
}

Node* add_node(Node* head, Node* new_node) {
    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

int main() {
    srand(time(NULL));
    Node* head = NULL;
    int i;

    printf("Let's create some performers for our Linked List Circus!\n");

    for (i = 0; i < 10; i++) {
        int num = rand() % 100 + 1;
        char name[30];
        sprintf(name, "Performer %d", i + 1);
        Node* new_node = create_node(num, name);
        head = add_node(head, new_node);
    }

    print_list(head);

    free(head);

    return 0;
}