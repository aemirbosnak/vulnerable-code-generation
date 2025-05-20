//FormAI DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node** head_ref, int data) {
    node* new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        node* current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(node* head) {
    printf("List: ");
    node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    printf("Welcome to my Happy Linked List program!\n");
    printf("Let's insert some nodes:\n");
    insert_node(&head, 5);
    insert_node(&head, 10);
    insert_node(&head, 15);
    print_list(head);
    printf("Wow, we have a list now!\n");
    printf("Now, let's remove the second node:\n");
    node* current = head;
    int count = 1;
    while (count < 2) {
        current = current->next;
        count++;
    }
    current->next = current->next->next;
    print_list(head);
    printf("Amazing, the second node has been removed!\n");
    printf("Let's insert some more nodes:\n");
    insert_node(&head, 20);
    insert_node(&head, 25);
    insert_node(&head, 30);
    print_list(head);
    printf("This list is getting longer and longer, but it's still so happy!\n");
    printf("Let's search for a node:\n");
    int search_value = 25;
    current = head;
    int search_index = 0;
    while (current != NULL) {
        if (current->data == search_value) {
            printf("Found %d at index %d\n", search_value, search_index);
            break;
        } else {
            current = current->next;
            search_index++;
        }
    }
    if (current == NULL) {
        printf("%d not found in the list\n", search_value);
    }
    printf("Thanks for using my Happy Linked List program!\n");

    return 0;
}