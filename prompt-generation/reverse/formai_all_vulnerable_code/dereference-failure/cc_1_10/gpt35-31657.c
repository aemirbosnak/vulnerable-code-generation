//FormAI DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(struct node** head, int data) {
    struct node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* curr_node = *head;
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

void delete_node(struct node** head, int data) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == data) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct node* curr_node = *head;
    while (curr_node->next != NULL && curr_node->next->data != data) {
        curr_node = curr_node->next;
    }
    if (curr_node->next == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }
    struct node* temp = curr_node->next;
    curr_node->next = curr_node->next->next;
    free(temp);
}

void print_list(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct node* curr_node = head;
        printf("List: ");
        while (curr_node != NULL) {
            printf("%d ", curr_node->data);
            curr_node = curr_node->next;
        }
        printf("\n");
    }
}

int main() {
    struct node* head = NULL;
    insert_at_end(&head, 1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    print_list(head);
    delete_node(&head, 3);
    print_list(head);
    delete_node(&head, 5);
    print_list(head);
    return 0;
}