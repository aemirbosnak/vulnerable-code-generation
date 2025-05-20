//FormAI DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

//Defining the structure for a doubly linked list node
struct node {
   int data;
   struct node* next;
   struct node* prev;
};

//Function to create a new node and return its address
struct node* create_node(int data) {
   struct node* new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data = data;
   new_node->next = NULL;
   new_node->prev = NULL;
   return new_node;
}

//Function to insert a node at the beginning of the doubly linked list
struct node* insert_at_beginning(struct node* head, int data) {
   struct node* new_node = create_node(data);
   if(head == NULL) {
      head = new_node;
   } else {
      new_node->next = head;
      head->prev = new_node;
      head = new_node;
   }
   return head;
}

//Function to insert a node at the end of the doubly linked list
struct node* insert_at_end(struct node* head, int data) {
   struct node* new_node = create_node(data);
   if(head == NULL) {
      head = new_node;
   } else {
      struct node* temp = head;
      while(temp->next != NULL) {
         temp = temp->next;
      }
      temp->next = new_node;
      new_node->prev = temp;
   }
   return head;
}

//Function to delete a node from the doubly linked list
struct node* delete_node(struct node* head, int data) {
   if(head == NULL) {
      printf("List is empty");
   } else if(head->data == data) {
      head = head->next;
      free(head->prev);
      head->prev = NULL;
   } else {
      struct node* temp = head->next;
      while(temp != NULL && temp->data != data) {
         temp = temp->next;
      }
      if(temp == NULL) {
         printf("Element not found");
      } else {
         temp->prev->next = temp->next;
         if(temp->next != NULL) {
            temp->next->prev = temp->prev;
         }
         free(temp);
      }
   }
   return head;
}

//Function to display the doubly linked list
void display_list(struct node* head) {
   struct node* temp = head;
   printf("Doubly Linked List:\n");
   while(temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
   }
   printf("NULL");
}

int main() {
   struct node* head = NULL;
   head = insert_at_beginning(head, 5);
   head = insert_at_beginning(head, 10);
   head = insert_at_end(head, 15);
   display_list(head);
   head = delete_node(head, 10);
   display_list(head);
   return 0;
}