//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

// Structure to store an email address
typedef struct {
  char email[100];
} Email;

// Structure to store a mailing list
typedef struct {
  char name[100];
  int num_emails;
  Email emails[MAX_EMAILS];
} MailingList;

// Create a new mailing list
MailingList *create_mailing_list(char *name) {
  MailingList *list = (MailingList *)malloc(sizeof(MailingList));
  strcpy(list->name, name);
  list->num_emails = 0;
  return list;
}

// Add an email address to a mailing list
void add_email(MailingList *list, char *email) {
  if (list->num_emails < MAX_EMAILS) {
    strcpy(list->emails[list->num_emails].email, email);
    list->num_emails++;
  }
}

// Print the contents of a mailing list
void print_mailing_list(MailingList *list) {
  printf("Mailing list: %s\n", list->name);
  printf("Number of emails: %d\n", list->num_emails);
  for (int i = 0; i < list->num_emails; i++) {
    printf("%s\n", list->emails[i].email);
  }
}

// Free the memory allocated for a mailing list
void destroy_mailing_list(MailingList *list) {
  free(list);
}

// Main function
int main() {
  // Create a new mailing list
  MailingList *list = create_mailing_list("My Mailing List");

  // Add some email addresses to the mailing list
  add_email(list, "john@example.com");
  add_email(list, "jane@example.com");
  add_email(list, "bob@example.com");

  // Print the contents of the mailing list
  print_mailing_list(list);

  // Free the memory allocated for the mailing list
  destroy_mailing_list(list);

  return 0;
}