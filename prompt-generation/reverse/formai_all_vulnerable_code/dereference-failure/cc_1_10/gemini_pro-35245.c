//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a futuristic-looking data structure to represent a contact
typedef struct {
  char *name;
  char *number;
  char *email;
  char *location;
  int age;
  char *bio;
  char *photo;
} Contact;

// Define a futuristic-looking function to create a new contact
Contact *create_contact(char *name, char *number, char *email, char *location, int age, char *bio, char *photo) {
  Contact *contact = malloc(sizeof(Contact));
  contact->name = strdup(name);
  contact->number = strdup(number);
  contact->email = strdup(email);
  contact->location = strdup(location);
  contact->age = age;
  contact->bio = strdup(bio);
  contact->photo = strdup(photo);
  return contact;
}

// Define a futuristic-looking function to add a contact to a phone book
void add_contact(Contact **phone_book, int *num_contacts, Contact *contact) {
  phone_book[*num_contacts] = contact;
  (*num_contacts)++;
}

// Define a futuristic-looking function to print a contact
void print_contact(Contact *contact) {
  printf("Name: %s\n", contact->name);
  printf("Number: %s\n", contact->number);
  printf("Email: %s\n", contact->email);
  printf("Location: %s\n", contact->location);
  printf("Age: %d\n", contact->age);
  printf("Bio: %s\n", contact->bio);
  printf("Photo: %s\n", contact->photo);
}

// Define a futuristic-looking function to search for a contact by name
Contact *search_contact(Contact **phone_book, int num_contacts, char *name) {
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(phone_book[i]->name, name) == 0) {
      return phone_book[i];
    }
  }
  return NULL;
}

// Define a futuristic-looking function to delete a contact by name
void delete_contact(Contact **phone_book, int *num_contacts, char *name) {
  int index = -1;
  for (int i = 0; i < *num_contacts; i++) {
    if (strcmp(phone_book[i]->name, name) == 0) {
      index = i;
      break;
    }
  }
  if (index != -1) {
    free(phone_book[index]->name);
    free(phone_book[index]->number);
    free(phone_book[index]->email);
    free(phone_book[index]->location);
    free(phone_book[index]->bio);
    free(phone_book[index]->photo);
    free(phone_book[index]);
    for (int i = index; i < *num_contacts - 1; i++) {
      phone_book[i] = phone_book[i + 1];
    }
    (*num_contacts)--;
  }
}

// Define a futuristic-looking function to print the phone book
void print_phone_book(Contact **phone_book, int num_contacts) {
  for (int i = 0; i < num_contacts; i++) {
    print_contact(phone_book[i]);
    printf("\n");
  }
}

// Define a futuristic-looking function to run the phone book program
void run_phone_book() {
  // Create a new phone book
  Contact **phone_book = malloc(sizeof(Contact *) * 100);
  int num_contacts = 0;

  // Add some contacts to the phone book
  add_contact(phone_book, &num_contacts, create_contact("Alice", "555-1234", "alice@example.com", "123 Main Street", 25, "Alice is a software engineer.", "alice.jpg"));
  add_contact(phone_book, &num_contacts, create_contact("Bob", "555-5678", "bob@example.com", "456 Elm Street", 30, "Bob is a doctor.", "bob.jpg"));
  add_contact(phone_book, &num_contacts, create_contact("Carol", "555-9012", "carol@example.com", "789 Oak Street", 35, "Carol is a teacher.", "carol.jpg"));

  // Print the phone book
  print_phone_book(phone_book, num_contacts);

  // Search for a contact by name
  Contact *contact = search_contact(phone_book, num_contacts, "Bob");
  if (contact != NULL) {
    printf("Found contact: %s\n", contact->name);
  } else {
    printf("Contact not found.\n");
  }

  // Delete a contact by name
  delete_contact(phone_book, &num_contacts, "Carol");

  // Print the phone book again
  print_phone_book(phone_book, num_contacts);

  // Free the phone book
  for (int i = 0; i < num_contacts; i++) {
    free(phone_book[i]->name);
    free(phone_book[i]->number);
    free(phone_book[i]->email);
    free(phone_book[i]->location);
    free(phone_book[i]->bio);
    free(phone_book[i]->photo);
    free(phone_book[i]);
  }
  free(phone_book);
}

int main() {
  run_phone_book();
  return 0;
}