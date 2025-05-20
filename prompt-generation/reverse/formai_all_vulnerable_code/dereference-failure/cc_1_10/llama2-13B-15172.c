//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 64
#define MAX_DISTANCE 16

struct node {
    uint32_t value;
    struct node* next[MAX_DISTANCE];
};

struct node* create_node(uint32_t value) {
    struct node* node = (struct node*)calloc(1, sizeof(struct node));
    node->value = value;
    return node;
}

void insert_node(struct node** head_ref, uint32_t value) {
    struct node* new_node = create_node(value);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct node* current = *head_ref;
        while (current->next[0] != NULL) {
            current = current->next[0];
        }
        current->next[0] = new_node;
    }
}

void compress(struct node** head_ref) {
    struct node* current = *head_ref;
    struct node* previous = NULL;
    uint32_t distance = 0;

    while (current != NULL) {
        if (distance == 0) {
            distance = current->value - previous->value;
        }
        if (distance > MAX_DISTANCE) {
            break;
        }
        previous = current;
        current = current->next[0];
    }

    if (current != NULL) {
        previous->next[distance] = current->next[0];
        current->next[0] = NULL;
    }
}

void decompress(struct node** head_ref) {
    struct node* current = *head_ref;
    struct node* previous = NULL;
    uint32_t distance = 0;

    while (current != NULL) {
        if (distance == 0) {
            distance = current->value - previous->value;
        }
        if (distance > MAX_DISTANCE) {
            break;
        }
        previous = current;
        current = previous->next[distance];
    }

    if (current != NULL) {
        previous->next[distance] = current->next[0];
        current->next[0] = NULL;
    }
}

int main() {
    struct node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    compress(&head);

    struct node* temp = head;
    head = NULL;

    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next[0];
    }
    printf("\n");

    decompress(&head);

    temp = head;
    head = NULL;

    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next[0];
    }
    printf("\n");

    return 0;
}