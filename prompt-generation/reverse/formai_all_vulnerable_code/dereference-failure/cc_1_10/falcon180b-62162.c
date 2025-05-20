//Falcon-180B DATASET v1.0 Category: Sorting ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

//node structure
typedef struct Node{
    int data;
    struct Node* next;
}node;

//function to create a new node
node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to insert a node at the end of the list
void insertAtEnd(node** head, int data){
    node* newNode = createNode(data);
    node* temp = *head;

    //if the list is empty, set the new node as the head
    if(*head == NULL){
        *head = newNode;
        return;
    }

    //traverse to the end of the list
    while(temp->next!= NULL){
        temp = temp->next;
    }

    //insert the new node at the end
    temp->next = newNode;
}

//function to display the list
void displayList(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//function to sort the list using bubble sort
void bubbleSort(node** head){
    node* curr = *head;
    node* next;
    int swapped = 1;

    //continue sorting until no swaps are needed
    while(swapped){
        swapped = 0;
        curr = *head;

        //traverse through the list
        while(curr->next!= NULL){
            if(curr->data > curr->next->data){
                //swap the nodes
                int tempData = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tempData;
                swapped = 1;
            }
            curr = curr->next;
        }
    }
}

//main function
int main(){
    node* head = NULL;

    //insert nodes
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 2);

    //display the unsorted list
    printf("Unsorted List:\n");
    displayList(head);

    //sort the list
    bubbleSort(&head);

    //display the sorted list
    printf("Sorted List:\n");
    displayList(head);

    return 0;
}