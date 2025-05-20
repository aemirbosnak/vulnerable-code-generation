//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node and add it to the linked list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    struct Node* temp = node;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
        free(temp);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Function to find the length of the linked list
int findLength(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to find the middle node of the linked list
struct Node* findMiddle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast!= NULL && fast->next!= NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to find the kth node from the end of the linked list
struct Node* findKthFromEnd(struct Node* head, int k) {
    struct Node* slow = head;
    struct Node* fast = head;
    int count = 0;
    while (fast!= NULL && count < k) {
        fast = fast->next;
        count++;
    }
    if (fast == NULL) {
        return NULL;
    }
    while (fast!= NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
void mergeLists(struct Node** head1, struct Node** head2) {
    struct Node* dummy = *head1;
    struct Node* curr = dummy;
    struct Node* prev = NULL;
    while (*head1!= NULL && *head2!= NULL) {
        if ((*head1)->data < (*head2)->data) {
            prev->next = *head1;
            prev = prev->next;
            *head1 = (*head1)->next;
        } else {
            prev->next = *head2;
            prev = prev->next;
            *head2 = (*head2)->next;
        }
    }
    while (*head1!= NULL) {
        prev->next = *head1;
        prev = prev->next;
        *head1 = (*head1)->next;
    }
    while (*head2!= NULL) {
        prev->next = *head2;
        prev = prev->next;
        *head2 = (*head2)->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* second_head = NULL;

    // Create two singly linked lists
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    insertAtBeginning(&second_head, 7);
    insertAtBeginning(&second_head, 8);
    insertAtEnd(&second_head, 9);
    insertAtEnd(&second_head, 10);
    insertAtEnd(&second_head, 11);

    // Merge the two lists
    mergeLists(&head, &second_head);

    // Print the merged linked list
    printf("Merged list: ");
    printList(head);

    // Reverse the linked list
    reverseList(&head);

    // Print the reversed linked list
    printf("Reversed list: ");
    printList(head);

    // Find the length of the linked list
    int length = findLength(head);
    printf("Length of the list: %d\n", length);

    // Find the middle node of the linked list
    struct Node* middle = findMiddle(head);
    printf("Middle node: %d\n", middle->data);

    // Find the kth node from the end of the linked list
    int k = 3;
    struct Node* kth_node = findKthFromEnd(head, k);
    if (kth_node!= NULL) {
        printf("Kth node from the end: %d\n", kth_node->data);
    } else {
        printf("Kth node not found\n");
    }

    return 0;
}