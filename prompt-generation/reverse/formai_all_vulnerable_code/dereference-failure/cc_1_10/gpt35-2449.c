//FormAI DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
   char email[50];
   struct node *next;
} node;

node *head = NULL;

void addEmail(char email[50]) {
   node *temp = (node*)malloc(sizeof(node));
   strcpy(temp->email, email);
   temp->next = NULL;

   if(head == NULL) {
      head = temp;
   } else {
      node *curr = head;
      while(curr->next != NULL) {
         curr = curr->next;
      }
      curr->next = temp;
   }
}

void removeEmail(char email[50]) {
   node *curr = head;
   node *prev = NULL;

   while(curr != NULL) {
      if(strcmp(curr->email, email) == 0) {
         if(prev == NULL) {
            head = curr->next;
         } else {
            prev->next = curr->next;
         }
         free(curr);
         printf("Email removed successfully.");
         return;
      }

      prev = curr;
      curr = curr->next;
   }

   printf("Email not found.");
}

void displayList() {
   node *curr = head;
   while(curr != NULL) {
      printf("%s\n", curr->email);
      curr = curr->next;
   }
}

int main() {
   int choice;
   char email[50];

   while(1) {
      printf("\n");
      printf("1. Add email to mailing list\n");
      printf("2. Remove email from mailing list\n");
      printf("3. Display mailing list\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            printf("Enter email to add: ");
            scanf("%s", email);
            addEmail(email);
            printf("Email added successfully.\n");
            break;

         case 2:
            printf("Enter email to remove: ");
            scanf("%s", email);
            removeEmail(email);
            break;

         case 3:
            printf("Mailing list:\n");
            displayList();
            break;

         case 4:
            exit(0);

         default:
            printf("Invalid choice.\n");
      }
   }
   return 0;
}