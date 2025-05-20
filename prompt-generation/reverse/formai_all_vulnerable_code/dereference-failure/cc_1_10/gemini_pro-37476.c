//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node *insert_front(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

Node *insert_back(Node *head, int data) {
    if (head == NULL) {
        return insert_front(head, data);
    }

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    Node *new_node = create_node(data);
    current->next = new_node;
    return head;
}

Node *insert_after(Node *head, int target_data, int data) {
    if (head == NULL) {
        return NULL;
    }

    Node *current = head;
    while (current != NULL) {
        if (current->data == target_data) {
            Node *new_node = create_node(data);
            new_node->next = current->next;
            current->next = new_node;
            return head;
        }
        current = current->next;
    }

    return head;
}

Node *delete_node(Node *head, int data) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == data) {
        head = head->next;
        return head;
    }

    Node *current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            current->next = current->next->next;
            return head;
        }
        current = current->next;
    }

    return head;
}

Node *reverse_list(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *new_head = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

Node *sort_list(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *sorted_head = NULL;
    Node *current = head;
    while (current != NULL) {
        Node *next_node = current->next;
        Node *prev_node = NULL;
        Node *temp = sorted_head;
        while (temp != NULL && current->data > temp->data) {
            prev_node = temp;
            temp = temp->next;
        }

        if (prev_node == NULL) {
            current->next = sorted_head;
            sorted_head = current;
        } else {
            prev_node->next = current;
            current->next = temp;
        }
        current = next_node;
    }

    return sorted_head;
}

int main() {
    Node *head = NULL;
    head = insert_back(head, 1);
    head = insert_back(head, 3);
    head = insert_back(head, 2);
    head = insert_back(head, 5);
    head = insert_back(head, 4);

    print_list(head);

    head = sort_list(head);

    print_list(head);

    return 0;
}