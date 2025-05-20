//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_ITEMS 10

typedef struct item {
    int index;
    struct item* next;
} item_t;

item_t* insert_item(item_t* head, int index) {
    item_t* new_item = malloc(sizeof(item_t));
    new_item->index = index;
    new_item->next = NULL;

    if (head == NULL) {
        head = new_item;
    } else {
        item_t* traverse = head;
        while (traverse->next) {
            traverse = traverse->next;
        }
        traverse->next = new_item;
    }

    return head;
}

void Greedy_Algorithms(item_t* head) {
    item_t* traverse = head;
    item_t* current = NULL;
    int total_cost = 0;

    while (traverse) {
        if (current == NULL || traverse->index < current->index) {
            current = traverse;
        }
        total_cost++;
        traverse = traverse->next;
    }

    printf("Total cost: %d\n", total_cost);
}

int main() {
    item_t* head = NULL;

    head = insert_item(head, 5);
    head = insert_item(head, 2);
    head = insert_item(head, 8);
    head = insert_item(head, 3);
    head = insert_item(head, 9);
    head = insert_item(head, 1);

    Greedy_Algorithms(head);

    return 0;
}