//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: Claude Shannon
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

void print_list(struct node* head) {
    struct node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_list(struct node** head_ref) {
    struct node* temp = *head_ref;
    while (temp!= NULL) {
        struct node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head_ref = NULL;
}

int main() {
    struct node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);

    printf("Initial List: ");
    print_list(head);

    printf("\nDeleting the list: ");
    delete_list(&head);

    printf("\nFinal List: ");
    print_list(head);

    return 0;
}