//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 //Maximum length of a name or email

typedef struct contact {
  char name[MAX_LEN];
  char email[MAX_LEN];
  struct contact* next;
} Contact; //Linked list structure for each contact

void add_contact(Contact** head, char name[], char email[]) { //Add a new contact to the list
  Contact* new_contact = (Contact*)malloc(sizeof(Contact));
  strcpy(new_contact->name, name);
  strcpy(new_contact->email, email);
  new_contact->next = *head;
  *head = new_contact;
}

void delete_contact(Contact** head, char name[]) { //Delete a contact from the list
  Contact* curr_contact = *head;
  Contact* prev_contact = NULL;

  while(curr_contact != NULL) {
    if(strcmp(curr_contact->name, name) == 0) {
      if(prev_contact == NULL) {
        *head = curr_contact->next;
      } else {
        prev_contact->next = curr_contact->next;
      }
      free(curr_contact);
      return;
    }
    prev_contact = curr_contact;
    curr_contact = curr_contact->next;
  }
}

void lookup_contact(Contact** head, char name[]) { //Lookup contact by name and print their email
  Contact* curr_contact = *head;

  while(curr_contact != NULL) {
    if(strcmp(curr_contact->name, name) == 0) {
      printf("%s: %s\n", curr_contact->name, curr_contact->email);
      return;
    }
    curr_contact = curr_contact->next;
  }
  printf("Contact not found\n");
}

void print_contacts(Contact** head) { //Print all contacts in the list
  Contact* curr_contact = *head;

  while(curr_contact != NULL) {
    printf("%s: %s\n", curr_contact->name, curr_contact->email);
    curr_contact = curr_contact->next;
  }
}

int main() {
  Contact* head = NULL; //Initialize empty list
  int choice;
  char name[MAX_LEN];
  char email[MAX_LEN];

  do {
    printf("1. Add contact\n");
    printf("2. Delete contact\n");
    printf("3. Lookup contact\n");
    printf("4. Print all contacts\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter email: ");
        scanf("%s", email);
        add_contact(&head, name, email);
        printf("Contact added successfully!\n");
        break;
      case 2:
        printf("Enter name: ");
        scanf("%s", name);
        delete_contact(&head, name);
        printf("Contact deleted successfully!\n");
        break;
      case 3:
        printf("Enter name: ");
        scanf("%s", name);
        lookup_contact(&head, name);
        break;
      case 4:
        print_contacts(&head);
        break;
      case 0:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  } while(choice != 0);

  return 0;
}