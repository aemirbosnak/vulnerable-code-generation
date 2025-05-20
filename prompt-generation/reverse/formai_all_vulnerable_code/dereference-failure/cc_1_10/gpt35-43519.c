//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node node_t;

struct Node {
    int value;
    node_t* next;
};

node_t* create_node(int value) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

node_t* insert_node_at_beginning(node_t* head, int value) {
    node_t* new_node = create_node(value);
    new_node->next = head;
    head = new_node;
    return head;
}

node_t* insert_node_at_end(node_t* head, int value) {
    node_t* new_node = create_node(value);
    if (!head) {
        head = new_node;
        return head;
    }
    node_t* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

void print_linked_list(node_t* head) {
    if (!head) {
        printf("Linked list is empty.\n");
        return;
    }
    node_t* temp = head;
    while (temp) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node_t* delete_node_at_beginning(node_t* head) {
    if (!head) {
        printf("Linked list is empty.\n");
        return head;
    }
    node_t* temp = head;
    head = temp->next;
    free(temp);
    return head;
}

node_t* delete_node_at_end(node_t* head) {
    if (!head) {
        printf("Linked list is empty.\n");
        return head;
    }
    if (!head->next) {
        free(head);
        return NULL;
    }
    node_t* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

node_t* delete_node_by_value(node_t* head, int value) {
    if (!head) {
        printf("Linked list is empty.\n");
        return head;
    }
    if (head->value == value) {
        node_t* temp = head;
        head = temp->next;
        free(temp);
        return head;
    }
    node_t* temp = head;
    while (temp->next) {
        if (temp->next->value == value) {
            node_t* del_node = temp->next;
            temp->next = del_node->next;
            free(del_node);
            return head;
        }
        temp = temp->next;
    }
    printf("Node not found in linked list.\n");
    return head;
}

int main() {
    node_t* head = NULL;
    head = insert_node_at_end(head, 10);
    head = insert_node_at_end(head, 100);
    head = insert_node_at_end(head, 1000);
    head = insert_node_at_beginning(head, 1);
    print_linked_list(head);
    head = delete_node_at_beginning(head);
    head = delete_node_at_end(head);
    head = delete_node_by_value(head, 100);
    print_linked_list(head);
    return 0;
}