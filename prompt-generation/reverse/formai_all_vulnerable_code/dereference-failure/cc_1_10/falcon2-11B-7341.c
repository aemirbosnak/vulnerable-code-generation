//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_head(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_list(struct Node** head) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current!= NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    insert_at_head(&head, 5);
    insert_at_head(&head, 10);
    insert_at_head(&head, 15);
    insert_at_head(&head, 20);

    print_list(head);

    delete_list(&head);

    return 0;
}