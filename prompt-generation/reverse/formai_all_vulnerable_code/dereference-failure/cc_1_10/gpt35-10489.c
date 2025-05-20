//FormAI DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_SIZE 10

struct node {
    int value;
    struct node *next;
};

void print_sequence(struct node *head) {
    printf("Current sequence: [ ");
    while(head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("]\n");
}

void swap(struct node* a, struct node* b, struct node** head) {
    if(a == b) return; // Elements cannot be swapped with themselves

    // Locate the previous node to access the "next" pointers
    struct node *prev_a = NULL, *prev_b = NULL, *current = *head;
    while(current != NULL) {
        if(current->next == a) prev_a = current;
        if(current->next == b) prev_b = current;

        current = current->next;

        if(prev_a != NULL && prev_b != NULL) break;
    }

    if(prev_a == NULL) {
        // Update the head if a is the first element
        *head = b;
    } else {
        prev_a->next = b;
    }

    if(prev_b == NULL) {
        // Update the head if b is the first element
        *head = a;
    } else {
        prev_b->next = a;
    }

    struct node *next_a = a->next;
    a->next = b->next;
    b->next = next_a;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Generate a random sequence of values and store them in a linked list
    printf("Generating a random sequence with %d elements...\n", SEQUENCE_SIZE);
    struct node *head = NULL, *current = NULL;
    for(int i = 0; i < SEQUENCE_SIZE; i++) {
        int value = rand() % 100;
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->value = value;
        new_node->next = NULL;

        if(head == NULL) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    // Print the original sequence
    print_sequence(head);

    // Bubble sort the sequence (and visualize the process)
    printf("Sorting the sequence with bubble sort...\n");
    int swapped;
    struct node *last_element = NULL;
    do {
        swapped = 0;
        current = head;
        while(current->next != last_element) {
            if(current->value > current->next->value) {
                swap(current, current->next, &head);
                swapped = 1;
                print_sequence(head);
            }
            current = current->next;
        }
        last_element = current;
    } while(swapped);

    // Free the memory allocated for the linked list
    while(head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }

    return 0; // Done!
}