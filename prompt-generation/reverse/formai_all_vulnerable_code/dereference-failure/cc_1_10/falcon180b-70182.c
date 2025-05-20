//Falcon-180B DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

// Node structure for linked list
struct Node{
    int data;
    struct Node* next;
};

// Function to insert node at the end of the list
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL){
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;

    while(last->next!= NULL){
        last = last->next;
    }

    last->next = new_node;
    return;
}

// Function to print the list
void printList(struct Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to sort the list using bubble sort
void bubbleSort(struct Node* head){
    struct Node* temp;
    int swapped;
    do{
        swapped = 0;
        temp = head;
        while(temp->next!= NULL){
            if(temp->data > temp->next->data){
                int temp_data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp_data;
                swapped = 1;
            }
            temp = temp->next;
        }
        temp = head;
    }while(swapped);
}

int main(){
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 2);
    push(&head, 9);
    push(&head, 3);
    push(&head, 7);

    printf("Before sorting: ");
    printList(head);

    bubbleSort(head);

    printf("\nAfter sorting: ");
    printList(head);

    return 0;
}