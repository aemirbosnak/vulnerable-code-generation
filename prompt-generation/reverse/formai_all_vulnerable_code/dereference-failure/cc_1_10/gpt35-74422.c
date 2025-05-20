//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 12

typedef struct {
  int id;
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct {
  Contact *data;
  int size;
  int capacity;
} ContactList;

void InitContactList(ContactList *list) {
  list->size = 0;
  list->capacity = 10;
  list->data = malloc(sizeof(Contact) * list->capacity);
}

void AddContact(ContactList *list) {
  // Resize if necessary
  if (list->size == list->capacity) {
    list->capacity *= 2;
    list->data = realloc(list->data, sizeof(Contact) * list->capacity);
  }

  Contact *newContact = &list->data[list->size++];
  newContact->id = list->size;

  // Read contact info from user
  printf("Enter contact name: ");
  fgets(newContact->name, MAX_NAME_LENGTH, stdin);
  newContact->name[strcspn(newContact->name, "\n")] = '\0';

  printf("Enter contact email: ");
  fgets(newContact->email, MAX_EMAIL_LENGTH, stdin);
  newContact->email[strcspn(newContact->email, "\n")] = '\0';

  printf("Enter contact phone number: ");
  fgets(newContact->phone, MAX_PHONE_LENGTH, stdin);
  newContact->phone[strcspn(newContact->phone, "\n")] = '\0';
}

void ListContacts(ContactList *list) {
  printf("%-5s%-20s%-30s%s\n", "ID", "Name", "Email", "Phone");
  printf("---------------------------------------------------------\n");
  for (int i = 0; i < list->size; i++) {
    Contact *contact = &list->data[i];
    printf("%-5d%-20s%-30s%s\n", contact->id, contact->name, contact->email, contact->phone);
  }
}

int main() {
  ContactList *list = malloc(sizeof(ContactList));
  InitContactList(list);

  while (1) {
    char cmd[10];
    printf("Enter command (add/list/exit): ");
    fgets(cmd, 10, stdin);
    cmd[strcspn(cmd, "\n")] = '\0';

    if (strcmp(cmd, "add") == 0) {
      AddContact(list);
    } else if (strcmp(cmd, "list") == 0) {
      ListContacts(list);
    } else if (strcmp(cmd, "exit") == 0) {
      break;
    } else {
      printf("Invalid command: %s\n", cmd);
    }
  }

  free(list->data);
  free(list);
  
  return 0;
}