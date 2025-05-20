//FormAI DATASET v1.0 Category: Data structures visualization ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

//structure for a node in the linked list
struct Node{
  int data;
  struct Node* next;
};

//function to insert a node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = (*headRef);
  (*headRef) = newNode;
}

//function to insert a node at the end of the linked list
void insertAtEnd(struct Node** headRef, int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  
  //if the linked list is empty, insert node at the beginning
  if(*headRef == NULL){
    *headRef = newNode;
    return;
  }
  
  //traversing to the end of the linked list and inserting node at the end
  struct Node* lastNode = *headRef;
  while(lastNode->next != NULL){
    lastNode = lastNode->next;
  }
  lastNode->next = newNode;
}

//function to delete a node with given key from the linked list
void deleteNode(struct Node** headRef, int key){
  //if the linked list is empty
  if(*headRef == NULL)
    return;
  
  //if the head node needs to be deleted
  if((*headRef)->data == key){
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
    return;
  }
  
  //traversing through the linked list to delete node with given key
  struct Node* currentNode = *headRef, *prev;
  while(currentNode != NULL && currentNode->data != key){
    prev = currentNode;
    currentNode = currentNode->next;
  }
  
  //if the key is not present
  if(currentNode == NULL)
    return;
  
  //deleting the node with given key
  prev->next = currentNode->next;
  free(currentNode);
}

//function to print the linked list
void printList(struct Node* head){
  while(head != NULL){
    printf("%d ", head->data);
    head = head->next;
  }
}

int main(){
  struct Node* head = NULL;
  
  //creating a linked list by inserting nodes at the beginning
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 15);
  insertAtBeginning(&head, 10);
  
  //inserting a node at the end of the linked list
  insertAtEnd(&head, 25);
  
  //deleting a node with key value 15
  deleteNode(&head, 15);
  
  //printing the linked list
  printList(head);
  
  return 0;
}