//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: energetic
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

void insert_node(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct Node* current = *head_ref;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_node(struct Node** head_ref, int data) {
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current!= NULL) {
        prev->next = current->next;
        free(current);
    }
}

void print_list(struct Node* head) {
    struct Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    print_list(head);
    delete_node(&head, 2);
    print_list(head);
    return 0;
}