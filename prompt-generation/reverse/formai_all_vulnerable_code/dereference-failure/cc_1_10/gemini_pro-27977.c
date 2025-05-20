//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node_t;

node_t *create_list(int n) {
    node_t *head = NULL;
    node_t *current = NULL;

    for (int i = 0; i < n; i++) {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->data = i;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }

    return head;
}

void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

node_t *insert_at_beginning(node_t *head, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;

    return new_node;
}

node_t *insert_at_end(node_t *head, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current = head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }

    return head;
}

node_t *insert_at_position(node_t *head, int data, int position) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;

    if (position == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        node_t *current = head;

        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    return head;
}

node_t *delete_at_beginning(node_t *head) {
    if (head == NULL) {
        return NULL;
    } else {
        node_t *temp = head;
        head = head->next;
        free(temp);

        return head;
    }
}

node_t *delete_at_end(node_t *head) {
    if (head == NULL) {
        return NULL;
    } else {
        node_t *current = head;

        while (current->next->next != NULL) {
            current = current->next;
        }

        free(current->next);
        current->next = NULL;

        return head;
    }
}

node_t *delete_at_position(node_t *head, int position) {
    if (head == NULL) {
        return NULL;
    } else if (position == 0) {
        node_t *temp = head;
        head = head->next;
        free(temp);
    } else {
        node_t *current = head;

        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }

        node_t *temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return head;
}

int main() {
    node_t *list = create_list(5);

    print_list(list);

    list = insert_at_beginning(list, 10);

    print_list(list);

    list = insert_at_end(list, 20);

    print_list(list);

    list = insert_at_position(list, 15, 2);

    print_list(list);

    list = delete_at_beginning(list);

    print_list(list);

    list = delete_at_end(list);

    print_list(list);

    list = delete_at_position(list, 2);

    print_list(list);

    return 0;
}