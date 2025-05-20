//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

void create_node(node** head_ref, int new_data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        node* last = *head_ref;
        while (last->next!= *head_ref) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *head_ref;
    }
}

void print_list(node* node) {
    do {
        printf("%d ", node->data);
        node = node->next;
    } while (node!= node->next);
    printf("\n");
}

int main() {
    node* head = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                create_node(&head, data);
                break;
            case 2:
                printf("List: ");
                print_list(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (TRUE);

    return 0;
}