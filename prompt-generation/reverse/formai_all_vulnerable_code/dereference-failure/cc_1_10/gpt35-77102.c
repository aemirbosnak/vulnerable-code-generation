//FormAI DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_EMAIL_LEN 30
#define MAX_PHONE_LEN 15

// Defining a structure for storing contact details
struct Contact {
  char name[MAX_NAME_LEN];
  char email[MAX_EMAIL_LEN];
  char phone[MAX_PHONE_LEN];
};

// Function to add a new contact to the database
void add_contact(struct Contact **contacts, int *num_contacts) {
  char name[MAX_NAME_LEN];
  char email[MAX_EMAIL_LEN];
  char phone[MAX_PHONE_LEN];

  // Prompt the user for the name, email and phone number
  printf("Enter the name: ");
  scanf("%s", name);

  printf("Enter the email: ");
  scanf("%s", email);

  printf("Enter the phone number: ");
  scanf("%s", phone);

  // Allocate memory for a new contact
  struct Contact *new_contact = (struct Contact*)malloc(sizeof(struct Contact));
  
  // Copy the data into the new contact
  strcpy(new_contact->name, name);
  strcpy(new_contact->email, email);
  strcpy(new_contact->phone, phone);

  // Increase the size of the contacts array
  (*num_contacts)++;
  *contacts = (struct Contact*)realloc(*contacts, (*num_contacts)*sizeof(struct Contact));

  // Add the new contact to the end of the array
  (*contacts)[(*num_contacts)-1] = *new_contact;

  printf("Contact added successfully!\n");
}

// Function to search for a contact by name
void search_contact(struct Contact *contacts, int num_contacts) {
  char name[MAX_NAME_LEN];

  printf("Enter the name of the contact: ");
  scanf("%s", name);

  int i;
  int found = 0;

  // Loop through the contacts array and look for a match
  for(i=0; i<num_contacts; i++) {
    if(strcmp(contacts[i].name, name) == 0) {
      printf("Name: %s\n", contacts[i].name);
      printf("Email: %s\n", contacts[i].email);
      printf("Phone: %s\n", contacts[i].phone);

      found = 1;
      break;
    }
  }

  if(!found) {
    printf("Contact not found!\n");
  }
}

// Function to print all contacts in the database
void print_contacts(struct Contact *contacts, int num_contacts) {
  printf("Name\tEmail\t\tPhone\n");

  int i;
  for(i=0; i<num_contacts; i++) {
    printf("%s\t%s\t%s\n", contacts[i].name, contacts[i].email, contacts[i].phone);
  }
}

// Main function
int main() {
  struct Contact *contacts = NULL;
  int num_contacts = 0;
  int choice;

  while(1) {
    printf("1. Add a new contact\n");
    printf("2. Search for a contact\n");
    printf("3. Print all contacts\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_contact(&contacts, &num_contacts);
        break;

      case 2:
        search_contact(contacts, num_contacts);
        break;

      case 3:
        print_contacts(contacts, num_contacts);
        break;

      case 4:
        exit(0);

      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}