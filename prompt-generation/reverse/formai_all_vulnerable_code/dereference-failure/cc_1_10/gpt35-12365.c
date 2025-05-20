//FormAI DATASET v1.0 Category: Data structures visualization ; Style: creative
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data; 
   struct node *next; 
};

void display(struct node *start) {
   struct node *ptr;
   ptr=start;

   while(ptr!=NULL) {
      printf("%d -> ", ptr->data);
      ptr=ptr->next;
   }
   printf("NULL\n");
} 

void insertAtEnd(struct node *start, int val) {
   struct node *new_node;
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=val;
   new_node->next=NULL; 

   while(start->next!=NULL)
      start=start->next;

   start->next=new_node; 
} 

void insertAtHead(struct node **start_ref, int val) {
   struct node *new_node=*start_ref;
   new_node=(struct node*)malloc(sizeof(struct node));
   new_node->data=val;
   new_node->next=*start_ref;
   *start_ref=new_node; 
}

void deleteNode(struct node **start_ref, int key) {
   struct node *tmp=*start_ref, *prev;
   if(tmp!=NULL && tmp->data==key) {
      *start_ref=tmp->next;
      free(tmp); return;
   }

   while(tmp!=NULL && tmp->data!=key) {
      prev=tmp;
      tmp=tmp->next;
   }

   if(tmp==NULL) return;
   prev->next=tmp->next;
   free(tmp); 
}

int main() {
   struct node *start=NULL;
   start=(struct node*)malloc(sizeof(struct node));
   start->data=5;
   start->next=NULL;

   insertAtEnd(start, 10);
   insertAtEnd(start, 15);
   insertAtEnd(start, 20);
   insertAtEnd(start, 25);

   printf("Initial Linked List:\n");
   display(start);

   insertAtHead(&start, 1);
   printf("\nLinked List after insertion at head:\n");
   display(start);

   deleteNode(&start, 10);
   printf("\nLinked List after deletion of node with value 10:\n");
   display(start);

   return 0;
}