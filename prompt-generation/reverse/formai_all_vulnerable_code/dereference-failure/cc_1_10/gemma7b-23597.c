//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char item_name[20];
    int quantity;
    struct Node* next;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
};

void insert_node(struct Queue* queue, char* item_name, int quantity) {
    struct Node* new_node = malloc(sizeof(struct Node));
    strcpy(new_node->item_name, item_name);
    new_node->quantity = quantity;
    new_node->next = NULL;

    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

int search_node(struct Queue* queue, char* item_name) {
    struct Node* current_node = queue->head;

    while (current_node) {
        if (strcmp(current_node->item_name, item_name) == 0) {
            return current_node->quantity;
        }
        current_node = current_node->next;
    }

    return -1;
}

int main() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;

    insert_node(queue, "Apple", 10);
    insert_node(queue, "Banana", 20);
    insert_node(queue, "Orange", 30);

    int quantity = search_node(queue, "Apple");
    printf("Quantity of Apple: %d\n", quantity);

    return 0;
}