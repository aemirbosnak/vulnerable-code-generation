//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

node* add_to_list(node* head, int data) {
    node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    return head;
}

void print_list(node* head) {
    node* temp = head;
    printf("The magic numbers are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int num, choice;

    do {
        printf("\nWelcome, my dear numerologist, to the enchanted realm of magical numbers!\n");
        printf("Please choose an option:\n");
        printf("1. Add a new number to the list\n");
        printf("2. Print the list of magical numbers\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the magical number to be added: ");
                scanf("%d", &num);
                head = add_to_list(head, num);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                printf("Farewell, dear numerologist! May your journey be filled with endless wonders and magical numbers.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}