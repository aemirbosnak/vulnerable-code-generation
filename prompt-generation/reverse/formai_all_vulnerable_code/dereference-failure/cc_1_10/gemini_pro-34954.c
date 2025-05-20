//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_index(node **head, int data, int index) {
    if (index == 0) {
        insert_at_head(head, data);
    } else {
        node *new_node = create_node(data);
        node *current = *head;
        int i = 0;
        while (current != NULL && i < index) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            printf("Error: Index out of bounds.\n");
            exit(1);
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_at_head(node **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_tail(node **head) {
    if (*head == NULL) {
        printf("Error: List is empty.\n");
        exit(1);
    }
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void delete_at_index(node **head, int index) {
    if (index == 0) {
        delete_at_head(head);
    } else {
        node *current = *head;
        int i = 0;
        while (current != NULL && i < index) {
            current = current->next;
            i++;
        }
        if (current == NULL) {
            printf("Error: Index out of bounds.\n");
            exit(1);
        }
        node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

void reverse_list(node **head) {
    node *prev = NULL;
    node *current = *head;
    node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    insert_at_head(&head, 1);
    insert_at_head(&head, 2);
    insert_at_head(&head, 3);
    insert_at_tail(&head, 4);
    insert_at_index(&head, 5, 2);
    print_list(head);
    reverse_list(&head);
    print_list(head);
    delete_at_head(&head);
    delete_at_tail(&head);
    delete_at_index(&head, 1);
    print_list(head);
    return 0;
}