//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    Node* curr_node = head;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                if (head == NULL) {
                    head = create_node(data);
                } else {
                    Node* new_node = create_node(data);
                    new_node->next = head;
                    head = new_node;
                }
                break;
            case 2:
                if (head == NULL) {
                    printf("List is empty\n");
                } else {
                    printf("Enter the data to be deleted: ");
                    scanf("%d", &data);
                    Node* curr_node = head;
                    Node* prev_node = NULL;

                    while (curr_node!= NULL && curr_node->data!= data) {
                        prev_node = curr_node;
                        curr_node = curr_node->next;
                    }

                    if (curr_node == NULL) {
                        printf("Element not found\n");
                    } else {
                        if (prev_node == NULL) {
                            head = curr_node->next;
                        } else {
                            prev_node->next = curr_node->next;
                        }
                        free(curr_node);
                    }
                }
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}