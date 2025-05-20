//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
  char name[50];
  char number[15];
};

struct phonebook {
  struct contact contacts[MAX_CONTACTS];
  int num_contacts;
};

struct phonebook *create_phonebook() {
  struct phonebook *phonebook = malloc(sizeof(struct phonebook));
  phonebook->num_contacts = 0;
  return phonebook;
}

void add_contact(struct phonebook *phonebook, char *name, char *number) {
  if (phonebook->num_contacts == MAX_CONTACTS) {
    printf("Phonebook is full! Can't add anymore contacts.\n");
    return;
  }

  strcpy(phonebook->contacts[phonebook->num_contacts].name, name);
  strcpy(phonebook->contacts[phonebook->num_contacts].number, number);
  phonebook->num_contacts++;
}

void print_phonebook(struct phonebook *phonebook) {
  printf("Phonebook:\n");
  for (int i = 0; i < phonebook->num_contacts; i++) {
    printf("%s: %s\n", phonebook->contacts[i].name, phonebook->contacts[i].number);
  }
}

void find_contact(struct phonebook *phonebook, char *name) {
  for (int i = 0; i < phonebook->num_contacts; i++) {
    if (strcmp(phonebook->contacts[i].name, name) == 0) {
      printf("Found contact: %s: %s\n", phonebook->contacts[i].name, phonebook->contacts[i].number);
      return;
    }
  }

  printf("Contact not found.\n");
}

void delete_contact(struct phonebook *phonebook, char *name) {
  for (int i = 0; i < phonebook->num_contacts; i++) {
    if (strcmp(phonebook->contacts[i].name, name) == 0) {
      for (int j = i; j < phonebook->num_contacts - 1; j++) {
        phonebook->contacts[j] = phonebook->contacts[j + 1];
      }
      phonebook->num_contacts--;
      printf("Contact deleted.\n");
      return;
    }
  }

  printf("Contact not found.\n");
}

void update_contact(struct phonebook *phonebook, char *name, char *new_number) {
  for (int i = 0; i < phonebook->num_contacts; i++) {
    if (strcmp(phonebook->contacts[i].name, name) == 0) {
      strcpy(phonebook->contacts[i].number, new_number);
      printf("Contact updated.\n");
      return;
    }
  }

  printf("Contact not found.\n");
}

int main() {
  struct phonebook *phonebook = create_phonebook();

  add_contact(phonebook, "John Doe", "555-123-4567");
  add_contact(phonebook, "Jane Doe", "555-234-5678");
  add_contact(phonebook, "Jack Frost", "555-345-6789");

  print_phonebook(phonebook);

  find_contact(phonebook, "John Doe");
  find_contact(phonebook, "Jack Frost");

  delete_contact(phonebook, "Jane Doe");
  print_phonebook(phonebook);

  update_contact(phonebook, "John Doe", "555-987-6543");
  print_phonebook(phonebook);

  return 0;
}