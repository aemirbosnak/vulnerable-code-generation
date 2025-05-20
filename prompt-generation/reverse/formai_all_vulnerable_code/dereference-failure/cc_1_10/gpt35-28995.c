//FormAI DATASET v1.0 Category: Linked list operations ; Style: modular
#include<stdio.h>
#include<stdlib.h>

/* Definition of Node for Doubly Linked List */
struct Node {
    int data;
    struct Node* previous;
    struct Node* next;
};

/* Function to display the elements of Linked List */
void display(struct Node* start) {
    if (start == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    struct Node* itr = start;
    while (itr != NULL) {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

/* Function to insert an element at the beginning of Linked List */
struct Node* insertAtBeginning(struct Node* start, int element) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = element;
    new_node->previous = NULL;
    new_node->next = start;
    if (start!=NULL) {
        start->previous = new_node;
    }
    start = new_node;
    printf("Element %d inserted at the beginning\n", element);
    return start;
}

/* Function to insert an element at the end of Linked List */
struct Node* insertAtEnd(struct Node* start, int element) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = element;
    new_node->next = NULL;
    struct Node* itr = start;
    if (start == NULL) {
        start = new_node;
        new_node->previous = NULL;
        printf("Element %d inserted at the end\n", element);
        return start;
    }
    while (itr->next != NULL) {
        itr = itr->next;
    }
    itr->next = new_node;
    new_node->previous = itr;
    printf("Element %d inserted at the end\n", element);
    return start;
}

/* Function to delete an element from the beginning of Linked List */
struct Node* deleteFromBeginning(struct Node* start) {
    if (start == NULL) {
        printf("Linked List is empty\n");
        return start;
    }
    struct Node* temp = start;
    start = start->next;
    if(start!=NULL){
        start->previous = NULL;
    }
    printf("Element %d deleted from the beginning\n", temp->data);
    free(temp);
    return start;
}

/* Function to delete an element from the end of Linked List */
struct Node* deleteFromEnd(struct Node* start) {
    if (start == NULL) {
        printf("Linked List is empty\n");
        return start;
    }
    struct Node* itr = start;
    if (itr->next == NULL) {
        printf("Element %d deleted from the end\n", itr->data);
        free(itr);
        start = NULL;
        return start;
    }
    while (itr->next != NULL) {
        itr = itr->next;
    }
    itr->previous->next = NULL;
    printf("Element %d deleted from the end\n", itr->data);
    free(itr);
    return start;
}

/* Main Function */
int main(){
    struct Node* start=NULL;
    int choice=0, element=0;
    do{
        printf("Enter your choice(1-5):\n1. Insert at Beginning\n2. Insert at End\n3. Delete from Beginning\n4. Delete from End\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d",&element);
            start=insertAtBeginning(start,element);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d",&element);
            start=insertAtEnd(start,element);
            break;
        case 3:
            start=deleteFromBeginning(start);
            break;
        case 4:
            start=deleteFromEnd(start);
            break;
        case 5:
            display(start);
            break;
        case 6:
            printf("Thank You");
            break;
        default:
            printf("Invalid Choice");
        }
    }while(choice!=6);
    return 0;
}