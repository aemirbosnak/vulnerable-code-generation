//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node_t;

node_t* add_node_to_list(node_t* head, int value) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    return head;
}

node_t* delete_node_from_list(node_t* head, int value) {
    node_t* current = head;
    node_t* previous = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    return head;
}

void print_list(node_t* head) {
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

int main() {
    node_t* head = NULL;
    char op;
    int val;
    while (1) {
        printf(">");
        scanf("%c", &op);
        if (op == 'a') {
            scanf("%d", &val);
            head = add_node_to_list(head, val);
        } else if (op == 'd') {
            scanf("%d", &val);
            head = delete_node_from_list(head, val);
        } else if (op == 'p') {
            print_list(head);
        } else if (op == 'q') {
            break;
        }
    }
    return 0;
}