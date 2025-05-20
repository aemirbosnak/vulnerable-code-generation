//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

// Defining structure for a node
struct Node{
   int data;
   struct Node* next;
};

// Function to create a new node with given data
struct Node* newNode(int data){
   struct Node* node = (struct Node*)malloc(sizeof(struct Node));
   node->data = data;
   node->next = NULL;
   return node;
}

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data){
   struct Node* node = newNode(new_data);
   node->next = *head_ref;
   *head_ref = node;
}

// Function to add a node after a given position in the list
void insertAfter(struct Node* prev_node, int new_data){
   if(prev_node == NULL){
      printf("The given previous node cannot be NULL");
      return;
   }
   struct Node* node = newNode(new_data);
   node->next = prev_node->next;
   prev_node->next = node;
}

// Function to delete a node with given data
void deleteNode(struct Node** head_ref, int key){
   struct Node* temp = *head_ref;
   if(temp!= NULL && temp->data == key){
      *head_ref = temp->next;
      free(temp);
      return;
   }
   while(temp!= NULL && temp->data!= key){
      temp = temp->next;
   }
   if(temp == NULL){
      printf("The key is not present in the list");
      return;
   }
   struct Node* prev_node = temp->next;
   temp->next = prev_node->next;
   free(prev_node);
}

// Function to print the list
void printList(struct Node* node){
   while(node!= NULL){
      printf("%d ", node->data);
      node = node->next;
   }
}

int main(){
   struct Node* head = NULL;
   push(&head, 1);
   push(&head, 2);
   push(&head, 3);
   printList(head);
   insertAfter(head->next, 0);
   printList(head);
   deleteNode(&head, 1);
   printList(head);
   deleteNode(&head, 0);
   printList(head);
   return 0;
}