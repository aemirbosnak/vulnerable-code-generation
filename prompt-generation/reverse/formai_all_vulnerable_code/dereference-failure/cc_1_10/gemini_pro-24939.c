//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert_first(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_last(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_after(int after, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node *temp = head;
        while (temp->data != after) {
            temp = temp->next;
            if (temp == NULL) {
                return;
            }
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_first() {
    if (head == NULL) {
        return;
    }
    node *temp = head;
    head = head->next;
    free(temp);
}

void delete_last() {
    if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void delete_after(int after) {
    if (head == NULL) {
        return;
    }

    node *temp = head;
    while (temp->data != after) {
        temp = temp->next;
        if (temp == NULL) {
            return;
        }
    }

    if (temp->next != NULL) {
        node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

void print_list() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert_last(x);
    }

    for (int i = 0; i < m; i++) {
        int op, x;
        scanf("%d %d", &op, &x);

        switch (op) {
            case 1:
                insert_first(x);
                break;
            case 2:
                insert_last(x);
                break;
            case 3:
                insert_after(x, k);
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                delete_after(x);
                break;
        }
    }

    print_list();

    return 0;
}