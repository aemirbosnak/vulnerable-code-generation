//FormAI DATASET v1.0 Category: Data mining ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}node;

void create_list(node **head, int data){
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  *head = new_node;
}

void insert(node **head, int data){
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  node *current = *head;
  if(*head == NULL){
    *head = new_node;
  }else{
    while(current->next != NULL){
      current = current->next;
    }
    current->next = new_node;
  }
}

void display(node **head){
  node *current = *head;
  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void remove_duplicates(node **head){
  node *current = *head;
  node *previous = NULL;
  node *temp = NULL;
  while(current != NULL){
    temp = current->next;
    previous = current;
    while(temp != NULL){
      if(current->data == temp->data){
        previous->next = temp->next;
        free(temp);
        temp = previous->next;
      }else{
        previous = temp;
        temp = temp->next;
      }
    }
    current = current->next;
  }
}

int main(){
  node *head = NULL;
  create_list(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 2);
  insert(&head, 4);
  insert(&head, 1);
  printf("Original List: ");
  display(&head);
  remove_duplicates(&head);
  printf("List after removing duplicates: ");
  display(&head);
  return 0;
}