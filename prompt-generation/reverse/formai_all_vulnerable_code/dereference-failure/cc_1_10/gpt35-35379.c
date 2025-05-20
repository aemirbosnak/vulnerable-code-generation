//FormAI DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
  char fname[20];
  char lname[20];
  char email[50];
  struct mailing_list* next;
} *head = NULL, *tail = NULL; // Linked list head and tail pointers

void add_contact() {
  // Function to add new contact to linked list
  struct mailing_list* new_contact = (struct mailing_list*) malloc(sizeof(struct mailing_list));

  printf("Enter first name: ");
  scanf("%s", new_contact->fname);

  printf("Enter last name: ");
  scanf("%s", new_contact->lname);

  printf("Enter email address: ");
  scanf("%s", new_contact->email);

  new_contact->next = NULL;

  if (head == NULL) {
    head = new_contact;
    tail = new_contact;
  } else {
    tail->next = new_contact;
    tail = new_contact;
  }
}

void print_list() {
  // Function to display entire linked list
  struct mailing_list* current_contact = head;

  while (current_contact != NULL) {
    printf("%s %s, %s\n", current_contact->fname, current_contact->lname, current_contact->email);
    current_contact = current_contact->next;
  }
}

int search_contact(char* email) {
  // Function to search linked list for contact by email
  struct mailing_list* current_contact = head;

  while (current_contact != NULL) {
    if (strcmp(current_contact->email, email) == 0) {
      printf("%s %s, %s\n", current_contact->fname, current_contact->lname, current_contact->email);
      return 1;
    }
    current_contact = current_contact->next;
  }
  printf("Contact not found.\n");
  return 0;
}

void remove_contact(char* email) {
  // Function to remove contact from linked list
  struct mailing_list *current_contact = head, *previous_contact = NULL;

  while (current_contact != NULL) {
    if (strcmp(current_contact->email, email) == 0) {
      if (current_contact == head) {
        head = current_contact->next;
      } else if (current_contact == tail) {
        tail = previous_contact;
        tail->next = NULL;
      } else {
        previous_contact->next = current_contact->next;
      }

      printf("Contact removed.\n");
      free(current_contact);
      return;
    }
    previous_contact = current_contact;
    current_contact = current_contact->next;
  }
  printf("Contact not found.\n");
}

int main() {
  int choice;
  char search_email[50], remove_email[50];

  while (1) {
    printf("\n--Menu--\n");
    printf("1. Add contact\n");
    printf("2. View entire mailing list\n");
    printf("3. Search for contact\n");
    printf("4. Remove contact\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_contact();
        break;
      case 2:
        printf("\nMailing List:\n");
        print_list();
        break;
      case 3:
        printf("Enter email to search for: ");
        scanf("%s", search_email);
        search_contact(search_email);
        break;
      case 4:
        printf("Enter email to remove: ");
        scanf("%s", remove_email);
        remove_contact(remove_email);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
  return 0;
}