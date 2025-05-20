//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct data_node_ {
  int data;
  struct data_node_ *next;
} data_node;

data_node* create_data_node(int data){
  data_node* new_node = (data_node*) malloc(sizeof(data_node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

data_node* recover_data(data_node *head){
  if(head == NULL){
    printf("ERROR: Empty list!\n");
    return NULL;
  }
  data_node *prev_node = NULL;
  data_node *curr_node = head;
  data_node *next_node = curr_node->next;
  while(curr_node != NULL){
    curr_node->next = prev_node;
    prev_node = curr_node;
    curr_node = next_node;
    if(next_node != NULL){
        next_node = next_node->next;
    }
  }
  return prev_node;
}

int main(){
  data_node *a = create_data_node(1);
  data_node *b = create_data_node(2);
  data_node *c = create_data_node(3);
  data_node *d = create_data_node(4);
  
  a->next = b;
  b->next = c;
  c->next = d;
  
  printf("Before recovering:\n");
  data_node *curr_node = a;
  while(curr_node != NULL){
    printf("%d ", curr_node->data);
    curr_node = curr_node->next;
  }
  printf("\n");
  
  data_node *recovered = recover_data(a);
  
  printf("After recovering:\n");
  curr_node = recovered;
  while(curr_node != NULL){
    printf("%d ", curr_node->data);
    curr_node = curr_node->next;
  }
  printf("\n");
  
  return 0;
}