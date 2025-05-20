//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct node {
    int number;
    struct node* next;
} node;

void add_node(node** head, int number) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->number = number;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_linked_list(node* head) {
    node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
}

void shuffle(node** head) {
    node* temp = *head;
    srand(time(NULL));
    while (temp!= NULL) {
        int random_index = rand() % temp->number;
        node* temp_node = temp->next;
        temp->number = temp_node->number;
        temp_node->number = random_index;
        temp = temp_node;
    }
}

int main() {
    node* head = NULL;
    for (int i = 1; i <= 9; i++) {
        add_node(&head, i);
    }
    print_linked_list(head);
    shuffle(&head);
    print_linked_list(head);
    return 0;
}