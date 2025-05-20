//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} node;

void print_list(node* head) {
    node* current = head;
    printf("Reversing linked list: \n");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");

    // Visualize the linked list by printing the nodes in reverse order
    current = head;
    while (current != NULL) {
        node* temp = current->next;
        printf("%d <- ", current->value);
        current->next = NULL;
        current = temp;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int arr[] = {1, 2, 3};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->value = arr[i];
        new_node->next = head;
        head = new_node;
    }

    printf("Original linked list: \n");
    print_list(head);

    sleep(1);
    system("clear"); // or 'cls' on Windows

    printf("Reversed linked list: \n");
    print_list(head);

    return 0;
}