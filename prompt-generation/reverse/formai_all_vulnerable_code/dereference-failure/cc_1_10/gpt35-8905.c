//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

// Define a node for our linked list
struct Node{
  int data;
  struct Node* next;
};

/**
 * Create a new node with the given data. 
 * Returns a pointer to the newly created node.
 */
struct Node* createNode(int val){
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

/** 
 * Traverse the linked list starting from the given node.
 * Prints the data in each node as it goes.
 */
void traverse(struct Node* node){
  while(node != NULL){
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

/**
 * Add a new node to the end of the linked list.
 * Takes a pointer to the head of the list and the value to be added.
 */
void append(struct Node** head, int val){
  struct Node* newNode = createNode(val);
  if(*head == NULL){
    *head = newNode;
  } else {
    struct Node* current = *head;
    while(current->next != NULL){
      current = current->next;
    }
    current->next = newNode;
  }
}

/**
 * Add a new node to the beginning of the linked list.
 * Takes a pointer to the head of the list and the value to be added.
 */
void prepend(struct Node** head, int val){
  struct Node* newNode = createNode(val);
  newNode->next = *head;
  *head = newNode;
}

/**
 * Insert a new node at the given position in the linked list.
 * Takes a pointer to the head of the list, the value to be added,
 * and the position to add the new node (index starts at 0).
 */
void insert(struct Node** head, int val, int pos){
  struct Node* newNode = createNode(val);
  if(pos == 0){
    newNode->next = *head;
    *head = newNode;
  } else {
    struct Node* current = *head;
    for(int i = 0; i < pos-1; i++){
      if(current->next == NULL){
        printf("Error: attempted to insert beyond end of list.\n");
        return;
      }
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

/**
 * Delete the node at the given position in the linked list.
 * Takes a pointer to the head of the list and the position to delete
 * (index starts at 0).
 */
void delete(struct Node** head, int pos){
  if(*head == NULL){
    printf("Error: attempted to delete from empty list.\n");
    return;
  }
  if(pos == 0){
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
  } else {
    struct Node* current = *head;
    for(int i = 0; i < pos-1; i++){
      if(current->next == NULL){
        printf("Error: attempted to delete beyond end of list.\n");
        return;
      }
      current = current->next;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
  }
}

int main(){
  // Declare and initialize our linked list
  struct Node* head = NULL;
  
  // Append some nodes to the end of the list
  append(&head, 5);
  append(&head, 10);
  append(&head, 15);
  printf("After appending 5, 10, 15 to the end of the list:\n");
  traverse(head);
  
  // Insert a node at position 1
  insert(&head, 7, 1);
  printf("After inserting 7 at position 1:\n");
  traverse(head);
  
  // Prepend a node to the beginning of the list
  prepend(&head, 3);
  printf("After prepending 3 to the beginning of the list:\n");
  traverse(head);
  
  // Delete the node at position 2
  delete(&head, 2);
  printf("After deleting the node at position 2:\n");
  traverse(head);
  
  // Delete the node at position 0
  delete(&head, 0);
  printf("After deleting the node at position 0:\n");
  traverse(head);
  
  return 0;
}