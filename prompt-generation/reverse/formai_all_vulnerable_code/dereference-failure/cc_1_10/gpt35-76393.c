//FormAI DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* node_ptr;

node_ptr create_node() {
    node_ptr node = malloc(sizeof(struct Node));
    node->data = 0;
    node->next = NULL;
    return node;
}

node_ptr add_to_list(node_ptr head, int data) {
    node_ptr new_node = create_node();
    new_node->data = data;
    if (head == NULL) {
        head = new_node;
    } else {
        node_ptr current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    printf("Added %d to the list\n", data);
    return head;
}

node_ptr remove_from_list(node_ptr head, int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->data == data) {
        node_ptr tmp = head->next;
        free(head);
        printf("Removed %d from the list\n", data);
        return tmp;
    }
    node_ptr prev = head;
    node_ptr current = head->next;
    while (current != NULL) {
        if (current->data == data) {
            prev->next = current->next;
            free(current);
            printf("Removed %d from the list\n", data);
            return head;
        } else {
            prev = current;
            current = current->next;
        }
    }
    printf("%d not found in the list\n", data);
    return head;
}

void display_list(node_ptr head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node_ptr current = head;
    printf("Current list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node_ptr head = NULL;
    display_list(head);
    head = add_to_list(head, 1);
    head = add_to_list(head, 2);
    head = add_to_list(head, 3);
    head = add_to_list(head, 4);
    display_list(head);
    head = remove_from_list(head, 2);
    head = remove_from_list(head, 3);
    display_list(head);
    head = remove_from_list(head, 5);
    return 0;
}