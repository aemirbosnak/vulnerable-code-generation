//FormAI DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Function to create a new Node */
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Function to recover lost data */
int dataRecovery(struct Node* head) {
    
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reversing the second half of the list
    struct Node* prev = NULL;
    struct Node* curr = slow;
    struct Node* next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Merging the two halves
    struct Node* first = head;
    struct Node* second = prev;
    while (second->next != NULL) {
        struct Node* temp = first->next;
        first->next = second;
        first = temp;
        
        temp = second->next;
        second->next = first;
        second = temp;
    }
    
    return head->data; // The lost data (which is in the first node) is now recovered!
}

/* Driver program to test above functions */
int main() {

    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    
    printf("Oh no! We have lost some data... Let me see if I can recover it...\n");
    printf("The lost data is: %d\n", dataRecovery(head));
    
    return 0;
}