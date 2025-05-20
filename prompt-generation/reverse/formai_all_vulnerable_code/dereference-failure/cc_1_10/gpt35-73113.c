//FormAI DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node* insert_at_beginning(node* head, int data) {
    node* new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

node* insert_at_end(node* head, int data) {
    node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        node* temp_node = head;
        while (temp_node->next != NULL) {
            temp_node = temp_node->next;
        }
        temp_node->next = new_node;
    }
    return head;
}

node* delete(node* head, int data) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
    } else if (head->data == data) {
        node* temp_node = head;
        head = head->next;
        free(temp_node);
    } else {
        node* current_node = head->next;
        node* previous_node = head;
        while (current_node != NULL) {
            if (current_node->data == data) {
                previous_node->next = current_node->next;
                free(current_node);
                return head;
            }
            current_node = current_node->next;
            previous_node = previous_node->next;
        }
        printf("%d not found in the Linked list\n", data);
    }
    return head;
}

void display(node* head) {
    if (head == NULL) {
        printf("Linked list is empty!\n");
    } else {
        node* temp_node = head;
        while (temp_node != NULL) {
            printf("%d ", temp_node->data);
            temp_node = temp_node->next;
        }
        printf("\n");
    }
}

int main() {
    node* head = NULL;
    int choice, element;

    while (1) {
        printf("Enter a choice:\n1. Insert at beginning\n2. Insert at end\n3. Delete\n4. Display\n5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element you want to insert: ");
                scanf("%d", &element);
                head = insert_at_beginning(head, element);
                break;
            case 2:
                printf("Enter the element you want to insert: ");
                scanf("%d", &element);
                head = insert_at_end(head, element);
                break;
            case 3:
                printf("Enter the element you want to delete: ");
                scanf("%d", &element);
                head = delete(head, element);
                break;
            case 4:
                printf("Linked list: ");
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}