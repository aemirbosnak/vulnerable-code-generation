//FormAI DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node *next;
};

typedef struct Node node;
node *head=NULL;

void insert(node **head, int new_data){
   node *new_node = (node*) malloc(sizeof(node));
   
   new_node->data = new_data;
   new_node->next = (*head);
   (*head) = new_node;
}

void delete(node **head, int key){
   node *temp = *head, *prev;

   if(temp != NULL && temp->data == key){
       *head = temp->next;
       free(temp);
       return;
   }

   while (temp != NULL && temp->data != key){
       prev = temp;
       temp = temp->next;
   }

   if(temp == NULL) return;
   
   prev->next = temp->next;

   free(temp);
}

void display(node *node){
   while (node != NULL){
       printf("%d ", node->data);
       node = node->next;
   }
   printf("\n");
}

int main(){
   int opt, data, key;

   while(1){
       printf("\nLinked List Operations\n");
       printf("1. Insert\n");
       printf("2. Delete\n");
       printf("3. Display\n");
       printf("4. Exit\n");

       printf("\nEnter your choice: ");
       scanf("%d", &opt);

       switch(opt){
           case 1:
               printf("Enter the data to insert: ");
               scanf("%d", &data);
               insert(&head, data);
               printf("%d inserted!\n", data);
               break;
           case 2:
               printf("Enter the data to delete: ");
               scanf("%d", &key);
               delete(&head, key);
               printf("%d deleted!\n", key);
               break;
           case 3:
               printf("Linked List: ");
               display(head);
               break;
           case 4:
               printf("\nExiting...");
               exit(0);
               break;
           default:
               printf("\nInvalid input!");
       }
   }

   return 0;
}