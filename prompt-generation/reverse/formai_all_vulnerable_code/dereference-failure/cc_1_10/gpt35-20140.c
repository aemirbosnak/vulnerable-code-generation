//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *next;
};

//Create a new node
struct node* createNode(int data) {
   struct node *temp= (struct node*)malloc(sizeof(struct node));
   temp->data = data;
   temp->next = NULL;
   return temp;
}

//Add Node to the end of the linked list
struct node* insertEnd(struct node *head, int data){
   struct node *temp, *p;
   temp = createNode(data);

   if(head == NULL){
      head = temp;
      return head;
   }

   p = head;
   while(p->next != NULL){
      p = p->next;
   }
   p->next = temp;
   return head;
}

//Displaying the Linked List
void display(struct node *head) {
   struct node *p;
   p = head;

   while(p != NULL){
      printf("%d ", p->data);
      p = p -> next;
   }
   printf("\n");
}

//Deleting a node from the linked list
struct node* deleteNode(struct node *head, int data) {
   struct node *p, *prev;
   p = head;
   if(head==NULL) {
      printf("List is Empty\n");
      return head;
   }
   if(head->data == data){
      head = head -> next;
      free(p);
      return head;
   }

   while(p!=NULL && p->data!=data){
      prev = p;
      p = p -> next;
   }

   if(p==NULL){
      printf("Data not present in the List\n");
      return head;
   }
   prev -> next = p -> next;
   free(p);
   return head;
}


int main() {

   struct node *head=NULL;

   head = insertEnd(head, 10);
   head = insertEnd(head, 20);
   head = insertEnd(head, 30);
   head = insertEnd(head, 40);

   printf("List after inserting 10, 20, 30, 40 : ");
   display(head);

   head = deleteNode(head, 20);
   printf("List after deleting 20 : ");
   display(head);

   head = deleteNode(head, 10);
   printf("List after deleting 10 : ");
   display(head);
   
   return 0;
}