//GEMINI-pro DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_list(int n) {
    struct node *head = NULL;
    struct node *current = NULL;

    for (int i = 0; i < n; i++) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = rand() % 100;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    return head;
}

void print_list(struct node *head) {
    struct node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

struct node *reverse_list(struct node *head) {
    struct node *current = head;
    struct node *previous = NULL;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

struct node *merge_lists(struct node *head1, struct node *head2) {
    struct node *current1 = head1;
    struct node *current2 = head2;
    struct node *new_head = NULL;
    struct node *current_new = NULL;

    while (current1 != NULL || current2 != NULL) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->next = NULL;

        if (current1 == NULL) {
            new_node->data = current2->data;
            current2 = current2->next;
        } else if (current2 == NULL) {
            new_node->data = current1->data;
            current1 = current1->next;
        } else {
            if (current1->data <= current2->data) {
                new_node->data = current1->data;
                current1 = current1->next;
            } else {
                new_node->data = current2->data;
                current2 = current2->next;
            }
        }

        if (new_head == NULL) {
            new_head = new_node;
            current_new = new_head;
        } else {
            current_new->next = new_node;
            current_new = current_new->next;
        }
    }

    return new_head;
}

int main() {
    // Create two random lists of length 10
    struct node *head1 = create_list(10);
    struct node *head2 = create_list(10);

    // Print the original lists
    printf("Original List 1: ");
    print_list(head1);

    printf("Original List 2: ");
    print_list(head2);

    // Reverse the first list
    head1 = reverse_list(head1);

    // Merge the two lists
    struct node *merged_head = merge_lists(head1, head2);

    // Print the merged list
    printf("Merged List: ");
    print_list(merged_head);

    return 0;
}