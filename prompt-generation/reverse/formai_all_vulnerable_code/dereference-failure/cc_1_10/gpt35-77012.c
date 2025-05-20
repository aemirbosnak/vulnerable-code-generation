//FormAI DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// structure to represent a node in a linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// function to create a node with given value
struct ListNode* createNode(int val) {
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

// function to add a node at the end of a linked list
void append(struct ListNode** head_ref, int val) {
    struct ListNode* new_node = createNode(val);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct ListNode* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// function to add a node at the beginning of a linked list
void prepend(struct ListNode** head_ref, int val) {
    struct ListNode* new_node = createNode(val);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// function to print the elements of a linked list
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

// function to calculate the length of a linked list
int length(struct ListNode* node) {
    int len = 0;
    while (node != NULL) {
        len++;
        node = node->next;
    }
    return len;
}

// function to delete a node with given value from a linked list
void deleteNode(struct ListNode** head_ref, int val) {
    if (*head_ref == NULL) {
        return;
    }
    if ((*head_ref)->val == val) {
        *head_ref = (*head_ref)->next;
    } else {
        struct ListNode* temp = *head_ref;
        while (temp->next != NULL && temp->next->val != val) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            temp->next = temp->next->next;
        }
    }
}

// function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next_node = NULL;
    while (current != NULL) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}

int main() {
    struct ListNode* head = NULL;

    // adding elements to the linked list
    append(&head, 1);
    append(&head, 2);
    prepend(&head, 3);
    prepend(&head, 4);

    // printing the linked list
    printf("Linked list: ");
    printList(head);

    // calculating the length of the linked list
    printf("Length of the linked list: %d\n", length(head));

    // deleting an element from the linked list
    deleteNode(&head, 3);
    printf("Linked list after deleting an element: ");
    printList(head);

    // reversing the linked list
    head = reverseList(head);
    printf("Reversed linked list: ");
    printList(head);

    return 0;
}