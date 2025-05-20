//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A curious little struct to store a curious little linked list
struct curious_node {
    int data;
    struct curious_node *next;
};

// A function to create a curious little linked list
struct curious_node *create_curious_list(int n) {
    struct curious_node *head = NULL;
    struct curious_node *curr = NULL;
    for (int i = 0; i < n; i++) {
        struct curious_node *new_node = malloc(sizeof(struct curious_node));
        new_node->data = i;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            curr = new_node;
        } else {
            curr->next = new_node;
            curr = new_node;
        }
    }
    return head;
}

// A function to print a curious little linked list
void print_curious_list(struct curious_node *head) {
    struct curious_node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// A function to free a curious little linked list
void free_curious_list(struct curious_node *head) {
    struct curious_node *curr = head;
    while (curr != NULL) {
        struct curious_node *next = curr->next;
        free(curr);
        curr = next;
    }
}

int main() {
    // Create a curious little linked list
    struct curious_node *list = create_curious_list(10);

    // Print the curious little linked list
    print_curious_list(list);

    // Free the curious little linked list
    free_curious_list(list);

    return 0;
}