//FormAI DATASET v1.0 Category: Linked list operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert_at_beginning(struct node** head, int data) {
    struct node* newNode = create_node(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

void insert_at_end(struct node** head, int data) {
    struct node* newNode = create_node(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insert_at_position(struct node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
    } else if (position == 1) {
        insert_at_beginning(head, data);
    } else {
        struct node* newNode = create_node(data);
        struct node* temp = *head;
        while (position > 2 && temp != NULL) {
            temp = temp->next;
            position--;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void delete_first_node(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void delete_last_node(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        struct node* temp = *head;
        if (temp->next == NULL) {
            *head = NULL;
            free(temp);
        } else {
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            struct node* toDelete = temp->next;
            temp->next = NULL;
            free(toDelete);
        }
    }
}

void delete_node_at_position(struct node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    } else if (position < 1) {
        printf("Invalid position\n");
        return;
    } else if (position == 1) {
        delete_first_node(head);
    } else {
        struct node* temp = *head;
        while (position > 2 && temp->next != NULL) {
            temp = temp->next;
            position--;
        }
        if (temp->next == NULL) {
            printf("Invalid position\n");
        } else {
            struct node* toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
        }
    }
}

void display_list(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct node* temp = head;
        printf("List elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct node* head = NULL;
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);

    printf("Before deletion:\n");
    display_list(head);

    printf("Deleting first node:\n");
    delete_first_node(&head);
    display_list(head);

    printf("Deleting last node:\n");
    delete_last_node(&head);
    display_list(head);

    printf("Deleting node at position 2:\n");
    delete_node_at_position(&head, 2);
    display_list(head);

    printf("Inserting 60 at beginning:\n");
    insert_at_beginning(&head, 60);
    display_list(head);

    printf("Inserting 70 at position 3:\n");
    insert_at_position(&head, 70, 3);
    display_list(head);

    printf("Inserting 80 at position 6:\n");
    insert_at_position(&head, 80, 6);
    display_list(head);

    return 0;
}