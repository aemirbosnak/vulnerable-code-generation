//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Define the node structure.
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Create a new node.
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the beginning of the list.
void insert_at_beginning(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node at the end of the list.
void insert_at_end(node_t **head, int data) {
    node_t *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Insert a new node after a given node.
void insert_after(node_t *node, int data) {
    if (node == NULL) {
        fprintf(stderr, "Error: cannot insert after a NULL node.\n");
        exit(1);
    }
    node_t *new_node = create_node(data);
    new_node->next = node->next;
    node->next = new_node;
}

// Delete a node from the list.
void delete_node(node_t **head, node_t *node) {
    if (*head == node) {
        *head = node->next;
    } else {
        node_t *current = *head;
        while (current->next != node) {
            current = current->next;
        }
        current->next = node->next;
    }
    free(node);
}

// Print the list.
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free the list.
void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

// Reverse the list.
node_t *reverse_list(node_t *head) {
    node_t *prev = NULL;
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Find the middle node of the list.
node_t *find_middle_node(node_t *head) {
    node_t *slow = head;
    node_t *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Check if the list is a palindrome.
bool is_palindrome(node_t *head) {
    node_t *slow = head;
    node_t *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != NULL) {
        slow = slow->next;
    }
    slow = reverse_list(slow);
    while (slow != NULL) {
        if (slow->data != head->data) {
            return false;
        }
        slow = slow->next;
        head = head->next;
    }
    return true;
}

// Merge two sorted lists.
node_t *merge_sorted_lists(node_t *head1, node_t *head2) {
    node_t *dummy_head = create_node(0);
    node_t *current = dummy_head;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }
    if (head1 != NULL) {
        current->next = head1;
    } else if (head2 != NULL) {
        current->next = head2;
    }
    return dummy_head->next;
}

// Remove duplicates from a sorted list.
void remove_duplicates(node_t *head) {
    node_t *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            node_t *next = current->next->next;
            free(current->next);
            current->next = next;
        } else {
            current = current->next;
        }
    }
}

// Find the nth node from the end of the list.
node_t *find_nth_node_from_end(node_t *head, int n) {
    node_t *slow = head;
    node_t *fast = head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// Rotate the list to the right by k nodes.
node_t *rotate_list_right(node_t *head, int k) {
    int len = 0;
    node_t *current = head;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    k %= len;
    if (k == 0) {
        return head;
    }
    current = head;
    for (int i = 0; i < len - k - 1; i++) {
        current = current->next;
    }
    node_t *new_head = current->next;
    current->next = NULL;
    current = new_head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head;
    return new_head;
}

// Main function.
int main() {
    // Create a linked list.
    node_t *head = NULL;
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 2);
    insert_at_end(&head, 3);
    insert_at_end(&head, 4);
    insert_after(head->next, 5);

    // Print the list.
    printf("Original list: ");
    print_list(head);

    // Reverse the list.
    node_t *reversed_head = reverse_list(head);

    // Print the reversed list.
    printf("Reversed list: ");
    print_list(reversed_head);

    // Free the original list.
    free_list(head);

    // Free the reversed list.
    free_list(reversed_head);

    return 0;
}