//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare data structures for Resume Parsing
struct Resume {
   char name[25];
   char email[50];
   char skills[150];
   char experience[200];
};

struct Node {
   struct Resume r;
   struct Node* next;
};

// Declare function prototypes
bool is_valid_email(char email[]);
void add_resume(struct Node** head, struct Resume r);
void parse_resumes(struct Node* head);

// Function to check if email is valid
bool is_valid_email(char email[]) {
   // Do some surreal validation here
   if (email[0] == '@' || email[0] == '.') {
      printf("Forget it! This email is invalid.\n");
      return false;
   }
   return true;
}

// Function that adds a resume to the linked list
void add_resume(struct Node** head, struct Resume r) {

   // Check email validity
   if (!is_valid_email(r.email)) {
      return;
   }

   // Create a new node
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->r = r;
   new_node->next = NULL;

   // Add node to the end of the list
   if (*head == NULL) {
      *head = new_node;
      return;
   }

   struct Node* last = *head;
   while (last->next != NULL) {
      last = last->next;
   }

   last->next = new_node;
}

// Function that parses all resumes in the linked list
void parse_resumes(struct Node* head) {
   struct Node *current = head;

   // Do some surreal parsing
   while (current != NULL) {
      printf("%s\n", current->r.name);
      printf("%s\n", current->r.email);
      printf("%s\n", current->r.skills);
      printf("%s\n", current->r.experience);
      current = current->next;
   }
}

// Main function that tests the Resume Parsing System
int main() {

   // Create a linked list
   struct Node* head = NULL;

   // Create some surreal resumes
   struct Resume r1 = {"Alice", "alice@wonderland.org", "Rabbit Hunting", "Adventurer at Wonderland"};
   struct Resume r2 = {"Bob", "bob@inception.com", "Dreaming", "Professional Thief"};

   // Add the resumes to the linked list
   add_resume(&head, r1);
   add_resume(&head, r2);

   // Parse all resumes in the linked list
   parse_resumes(head);

   return 0;
}