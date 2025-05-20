//FormAI DATASET v1.0 Category: Linked list operations ; Style: curious
#include<stdio.h>
#include<stdlib.h>

// defining the struct with the node name and its value
struct node {
    int val;
    struct node *next;
};

// defining the insert function to insert values into the linked list
void insert(struct node *head, int val) {
    struct node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    struct node *new_node = malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;
    temp->next = new_node;
}

// defining the delete function to remove a node from the linked list
void delete(struct node *head, int val) {
    struct node *temp1 = head;
    struct node *temp2 = head->next;
    while(temp2 != NULL) {
        if(temp2->val == val) {
            temp1->next = temp2->next;
            free(temp2);
            return;
        } 
        temp1 = temp2;
        temp2 = temp2->next;
    }
}

// defining the print function to print the linked list
void print(struct node *head) {
    struct node *temp = head->next;
    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// main function where our program starts
int main() {
    struct node *head = malloc(sizeof(struct node));
    head->val = -1;
    head->next = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    printf("Linked List: ");
    print(head);
    delete(head, 3);
    printf("Linked List after deleting node with value 3: ");
    print(head);
    return 0;
}