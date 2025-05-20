//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    int data;
    struct node *next;
} node;

node *head = NULL;

void generate_random_numbers(int size) {
    int i;
    node *new_node;

    srand(time(NULL));

    for (i = 0; i < size; i++) {
        new_node = (node *)malloc(sizeof(node));
        new_node->data = rand() % MAX;
        new_node->next = head;
        head = new_node;
    }
}

void print_linked_list() {
    node *temp;

    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int size;

    printf("Enter the size of the linked list: ");
    scanf("%d", &size);

    generate_random_numbers(size);
    print_linked_list();

    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    printf("Linked list freed.\n");

    return 0;
}