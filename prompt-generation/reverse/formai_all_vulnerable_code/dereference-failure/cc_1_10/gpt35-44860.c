//FormAI DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

// Declare a struct node
struct Node {
    int item;
    struct Node* next;
};

// Function to add a node to the beginning of the list
struct Node* addNodeToFront(struct Node* head, int item) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->item = item;
    new_node->next = head;
    head = new_node;
    printf("Oh noble list, I shall add to thy front\nWith %d, fair and square to the brunt\n", item);
    return head;
}

// Function to add a node to the end of the list
void addNodeToEnd(struct Node* head, int item) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->item = item;
    new_node->next = NULL;
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = new_node;
    printf("Of this list, I shall append\nA node to its end unspent\nWith %d, its breadth shall now extend\n", item);
}

// Function to remove a node from the list
struct Node* removeNode(struct Node* head, int item) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    if(temp != NULL && temp->item == item) {
        head = temp->next;
        free(temp);
        temp = NULL;
        printf("Oh list, I shall remove from thee\nThis node that matched with such glee\nWith %d, now it shall flee\n", item);
        return head;
    }
    while(temp != NULL && temp->item != item) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Oh list, I searched for thee in vain\nNo node matched, so none shall be slain\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    temp = NULL;
    printf("Oh list, I found and removed this node\n%s, oh %d, ne'er again shall thee roam\n", "Verily, it is gone!", item);
    return head;
}

// Function to print out the list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->item);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    head = addNodeToFront(head, 5);
    head = addNodeToFront(head, 4);
    addNodeToEnd(head, 6);
    addNodeToEnd(head, 7);
    addNodeToEnd(head, 8);
    removeNode(head, 4);
    removeNode(head, 6);
    removeNode(head, 9);
    printList(head);
    return 0;
}