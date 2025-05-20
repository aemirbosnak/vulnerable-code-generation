//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert_node(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    return (*head_ref);
}

struct Node* delete_node(struct Node** head_ref, int data) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return *head_ref;
    if (prev == NULL)
        *head_ref = temp->next;
    else
        prev->next = temp->next;
    free(temp);
    return *head_ref;
}

void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int data;

    while (1) {
        printf("Enter data (-1 to quit): ");
        scanf("%d", &data);
        if (data == -1)
            break;
        head = insert_node(&head, data);
    }
    print_list(head);

    while (1) {
        printf("Enter data to delete (-1 to quit): ");
        scanf("%d", &data);
        if (data == -1)
            break;
        head = delete_node(&head, data);
    }
    print_list(head);

    return 0;
}