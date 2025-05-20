//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define NULL ((void*)0)

typedef struct node {
    char data[10];
    struct node* next;
} node_t;

void print_list(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void push(node_t** head_ref, const char* new_data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    strcpy(new_node->data, new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void pop(node_t** head_ref) {
    node_t* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

int main() {
    srand(time(NULL));
    node_t* head = NULL;

    while (1) {
        int choice;
        printf("\nMysterious Linked List\n");
        printf("------------------------\n");
        printf("1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char data[10];
                printf("Enter data to push: ");
                scanf("%s", data);
                push(&head, data);
                break;
            }
            case 2: {
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    pop(&head);
                }
                break;
            }
            case 3: {
                print_list(head);
                break;
            }
            case 4: {
                node_t* temp;
                while (head != NULL) {
                    temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(EXIT_SUCCESS);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }

        if (head != NULL) {
            sleep(1 + (rand() % 3));
        }
    }

    return 0;
}