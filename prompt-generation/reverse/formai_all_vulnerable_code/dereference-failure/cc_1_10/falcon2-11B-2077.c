//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node* next;
} node;

void print_list(node* head) {
    node* current = head;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

node* create_node(int value) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void add_to_list(node** head, int value) {
    node* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void remove_from_list(node** head, int value) {
    node* current = *head;
    node* prev = NULL;
    while (current!= NULL) {
        if (current->value == value) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void shuffle_list(node** head) {
    srand(time(NULL));
    node* temp = *head;
    while (temp->next!= NULL) {
        int rand_index = rand() % (temp->value - 1) + 1;
        node* temp_next = temp->next;
        int temp_value = temp->value;
        int temp_next_value = temp_next->value;
        temp->value = temp_next_value;
        temp_next->value = temp_value;
        temp->next = temp_next->next;
        temp_next->next = temp;
    }
}

int main() {
    int num_cards = 8;
    node* head = NULL;
    node* current = NULL;
    for (int i = 1; i <= num_cards; i++) {
        add_to_list(&head, i);
    }
    print_list(head);
    shuffle_list(&head);
    print_list(head);
    remove_from_list(&head, 3);
    print_list(head);
    return 0;
}