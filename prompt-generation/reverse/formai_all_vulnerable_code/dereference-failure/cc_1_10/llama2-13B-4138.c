//LLAMA2-13B DATASET v1.0 Category: Game ; Style: Donald Knuth
/* This program will sort a list of integers using the "bubble sort" algorithm. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node *next;
};

struct node *sorted_list = NULL;
int num_elements = 0;

void insert_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (num_elements == 0) {
        sorted_list = new_node;
    } else {
        struct node *current = sorted_list;
        while (current->next != NULL) {
            if (current->next->data < data) {
                break;
            }
            current = current->next;
        }
        current->next = new_node;
    }

    num_elements++;
}

void bubble_sort() {
    int i, j;

    for (i = 0; i < num_elements - 1; i++) {
        for (j = 0; j < num_elements - i - 1; j++) {
            if (sorted_list->data < sorted_list->next->data) {
                struct node *temp = sorted_list;
                sorted_list = sorted_list->next;
                sorted_list->next = temp;
            }
        }
    }
}

int main() {
    insert_node(5);
    insert_node(2);
    insert_node(8);
    insert_node(3);
    insert_node(1);
    insert_node(6);
    insert_node(4);

    bubble_sort();

    struct node *current = sorted_list;
    printf("Sorted list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}