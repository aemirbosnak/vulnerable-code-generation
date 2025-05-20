//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void create_list(node **head, int n) {
    int i;
    node *temp, *p;

    *head = NULL;
    for (i = 0; i < n; i++) {
        temp = malloc(sizeof(node));
        temp->data = rand() % 100;
        temp->next = NULL;

        if (*head == NULL) {
            *head = temp;
        } else {
            p = *head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = temp;
        }
    }
}

void display_list(node *head) {
    node *p;

    p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insert_at_beginning(node **head, int data) {
    node *temp;

    temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insert_at_end(node **head, int data) {
    node *temp, *p;

    temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void insert_at_position(node **head, int data, int position) {
    node *temp, *p;
    int i;

    temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (position == 1) {
        insert_at_beginning(head, data);
    } else {
        p = *head;
        for (i = 1; i < position - 1; i++) {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void delete_at_beginning(node **head) {
    node *temp;

    if (*head == NULL) {
        return;
    } else {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void delete_at_end(node **head) {
    node *temp, *p;

    if (*head == NULL) {
        return;
    } else if ((*head)->next == NULL) {
        delete_at_beginning(head);
    } else {
        p = *head;
        while (p->next->next != NULL) {
            p = p->next;
        }
        temp = p->next;
        p->next = NULL;
        free(temp);
    }
}

void delete_at_position(node **head, int position) {
    node *temp, *p;
    int i;

    if (position == 1) {
        delete_at_beginning(head);
    } else {
        p = *head;
        for (i = 1; i < position - 1; i++) {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

void reverse_list(node **head) {
    node *p, *q, *r;

    p = *head;
    q = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *head = q;
}

int main() {
    node *head = NULL;
    int n, choice, data, position;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    create_list(&head, n);

    while (1) {
        printf("\n1. Display the list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at position\n");
        printf("5. Delete at beginning\n");
        printf("6. Delete at end\n");
        printf("7. Delete at position\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_list(head);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
            case 3:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 4:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position at which the data is to be inserted: ");
                scanf("%d", &position);
                insert_at_position(&head, data, position);
                break;
            case 5:
                delete_at_beginning(&head);
                break;
            case 6:
                delete_at_end(&head);
                break;
            case 7:
                printf("Enter the position at which the data is to be deleted: ");
                scanf("%d", &position);
                delete_at_position(&head, position);
                break;
            case 8:
                reverse_list(&head);
                break;
            case 9:
                exit(0);
        }
    }

    return 0;
}