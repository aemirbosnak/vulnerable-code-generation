//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a node after a given node
void insert_after(struct node *prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct node *new_node = create_node(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning(struct node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the linked list
void delete_from_end(struct node **head) {
    if (*head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node *temp = *head;
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        *head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);
}

// Function to delete a node after a given node
void delete_after(struct node *prev_node) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    if (prev_node->next == NULL) {
        printf("Node to be deleted does not exist\n");
        return;
    }
    struct node *temp = prev_node->next;
    prev_node->next = temp->next;
    free(temp);
}

// Function to search for a node in the linked list
struct node *search(struct node *head, int data) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the linked list
void print_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to get the length of the linked list
int get_length(struct node *head) {
    int length = 0;
    struct node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Function to reverse the linked list
struct node *reverse_list(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to merge two sorted linked lists
struct node *merge_lists(struct node *head1, struct node *head2) {
    struct node *new_head = NULL;
    struct node *new_tail = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            if (new_head == NULL) {
                new_head = head1;
                new_tail = head1;
            } else {
                new_tail->next = head1;
                new_tail = head1;
            }
            head1 = head1->next;
        } else {
            if (new_head == NULL) {
                new_head = head2;
                new_tail = head2;
            } else {
                new_tail->next = head2;
                new_tail = head2;
            }
            head2 = head2->next;
        }
    }
    if (head1 != NULL) {
        new_tail->next = head1;
    }
    if (head2 != NULL) {
        new_tail->next = head2;
    }
    return new_head;
}

int main() {
    struct node *head = NULL;

    // Insert some nodes into the linked list
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);
    insert_after(head->next, 25);

    // Print the linked list
    printf("Linked list: ");
    print_list(head);

    // Get the length of the linked list
    int length = get_length(head);
    printf("Length of the linked list: %d\n", length);

    // Search for a node in the linked list
    struct node *found_node = search(head, 25);
    if (found_node != NULL) {
        printf("Node found: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    // Reverse the linked list
    head = reverse_list(head);

    // Print the reversed linked list
    printf("Reversed linked list: ");
    print_list(head);

    // Merge two sorted linked lists
    struct node *head1 = create_node(1);
    insert_at_end(&head1, 3);
    insert_at_end(&head1, 5);
    struct node *head2 = create_node(2);
    insert_at_end(&head2, 4);
    insert_at_end(&head2, 6);
    struct node *merged_head = merge_lists(head1, head2);

    // Print the merged linked list
    printf("Merged linked list: ");
    print_list(merged_head);

    // Delete a node from the beginning of the linked list
    delete_from_beginning(&head);

    // Print the linked list after deleting a node from the beginning
    printf("Linked list after deleting a node from the beginning: ");
    print_list(head);

    // Delete a node from the end of the linked list
    delete_from_end(&head);

    // Print the linked list after deleting a node from the end
    printf("Linked list after deleting a node from the end: ");
    print_list(head);

    // Delete a node after a given node
    delete_after(head);

    // Print the linked list after deleting a node after a given node
    printf("Linked list after deleting a node after a given node: ");
    print_list(head);

    return 0;
}