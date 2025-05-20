//FormAI DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct Node {  // defining the structure of a node in linked list
    int data;
    struct Node *next; // pointer to next node
};

struct Node *head = NULL;

void insert(int val) { // function to insert a new value at the end of the linked list
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node)); //allocate memory for new node
    newNode->data = val; //store the value in the node
    newNode->next = NULL; //set the pointer to NULL for now

    if (head == NULL) { //if the linked list is empty, set the new node as the head node
        head = newNode;
        return;
    }

    struct Node *temp = head; //else traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode; //set pointer of last node to the new node
}

void display() { //function to display all the nodes in the linked list
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) { //loop until end of linked list is reached (last node points to NULL)
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(int val) { //function to delete a node with specific value from the linked list
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }

    struct Node *temp = head;

    if (temp->data == val) { //special case when deleting the head node
        head = head->next; //set head to next node
        free(temp); //free memory of deleted node
        printf("%d deleted\n", val);
        return;
    }

    while (temp->next != NULL && temp->next->data != val) { //traverse to node before the one to be deleted
        temp = temp->next;
    }

    if (temp->next == NULL) { //if the value is not present in the linked list
        printf("%d not found in the Linked List\n", val);
        return;
    }

    struct Node *deleteNode = temp->next; //set pointer to the node to be deleted
    temp->next = deleteNode->next; //set the node before it to point to the node after it
    free(deleteNode); //free memory of deleted node
    printf("%d deleted\n", val);
}

int main() {
    insert(1);
    insert(3);
    insert(5);
    insert(7);
    display();
    delete(3);
    display();
    delete(10);
    display();
    return 0;
}