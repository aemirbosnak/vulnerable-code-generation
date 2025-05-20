//FormAI DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

//structure to represent a node in the linked list
struct Node{
  int data;
  struct Node* next;
};

//function to add a new node at the end of the linked list
void append(struct Node** head_ref, int new_data){
  struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  struct Node* last = *head_ref;
  
  new_node->data = new_data;
  new_node->next = NULL;
  
  if(*head_ref == NULL){
    *head_ref = new_node;
    return;
  }
  
  while(last->next != NULL){
    last = last->next;
  }
  
  last->next = new_node;
}

//function to display the linked list as a chart
void display_chart(struct Node** head_ref){
  struct Node* current = *head_ref;
  int counter = 1;
  
  printf("\n\n");
  printf("************************************************************\n");
  printf("                          Linked List Chart                         \n");
  printf("************************************************************\n");

  while(current != NULL){
    printf("| Node %2d | %10d |",counter, current->data);
    printf("------------>\n");
    current = current->next;
    counter++;
  }
}

int main(){
  struct Node* head = NULL;
  
  //appending nodes to the linked list
  append(&head, 10);
  append(&head, 20);
  append(&head, 30);
  append(&head, 40);
  append(&head, 50);
  
  //displaying the linked list as a chart
  display_chart(&head);
  
  return 0;
}