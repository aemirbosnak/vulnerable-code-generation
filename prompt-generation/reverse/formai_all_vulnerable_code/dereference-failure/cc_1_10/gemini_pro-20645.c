//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct phonebook {
  char name[32];
  char number[16];
  char email[64];
  char address[128];
};

struct phonebook *pb;
int pb_size = 0;

void add_entry(char *name, char *number, char *email, char *address) {
  pb = realloc(pb, (pb_size + 1) * sizeof(struct phonebook));
  strcpy(pb[pb_size].name, name);
  strcpy(pb[pb_size].number, number);
  strcpy(pb[pb_size].email, email);
  strcpy(pb[pb_size].address, address);
  pb_size++;
}

void print_entry(int index) {
  printf("Name: %s\n", pb[index].name);
  printf("Number: %s\n", pb[index].number);
  printf("Email: %s\n", pb[index].email);
  printf("Address: %s\n", pb[index].address);
}

void print_all_entries() {
  for (int i = 0; i < pb_size; i++) {
    print_entry(i);
  }
}

void search_by_name(char *name) {
  for (int i = 0; i < pb_size; i++) {
    if (strcmp(pb[i].name, name) == 0) {
      print_entry(i);
    }
  }
}

void search_by_number(char *number) {
  for (int i = 0; i < pb_size; i++) {
    if (strcmp(pb[i].number, number) == 0) {
      print_entry(i);
    }
  }
}

void search_by_email(char *email) {
  for (int i = 0; i < pb_size; i++) {
    if (strcmp(pb[i].email, email) == 0) {
      print_entry(i);
    }
  }
}

void search_by_address(char *address) {
  for (int i = 0; i < pb_size; i++) {
    if (strcmp(pb[i].address, address) == 0) {
      print_entry(i);
    }
  }
}

void delete_entry(int index) {
  for (int i = index; i < pb_size; i++) {
    strcpy(pb[i].name, pb[i + 1].name);
    strcpy(pb[i].number, pb[i + 1].number);
    strcpy(pb[i].email, pb[i + 1].email);
    strcpy(pb[i].address, pb[i + 1].address);
  }
  pb_size--;
}

int main() {
  add_entry("John Doe", "555-123-4567", "john.doe@example.com", "123 Main Street");
  add_entry("Jane Doe", "555-234-5678", "jane.doe@example.com", "456 Elm Street");
  add_entry("John Smith", "555-345-6789", "john.smith@example.com", "789 Oak Street");

  print_all_entries();

  search_by_name("John Doe");

  search_by_number("555-234-5678");

  search_by_email("jane.doe@example.com");

  search_by_address("456 Elm Street");

  delete_entry(1);

  print_all_entries();

  return 0;
}