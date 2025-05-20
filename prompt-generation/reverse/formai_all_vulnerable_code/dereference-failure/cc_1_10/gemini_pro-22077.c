//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet Mailing List Manager

// Romeo and Juliet data structure
typedef struct romeo_juliet {
  char name[50];
  char email[50];
} rj;

// Mailing list data structure
typedef struct mailing_list {
  rj *members;
  int num_members;
} ml;

// Create a new mailing list
ml *create_mailing_list() {
  ml *list = malloc(sizeof(ml));
  list->members = NULL;
  list->num_members = 0;
  return list;
}

// Add a member to the mailing list
void add_member(ml *list, rj member) {
  list->members = realloc(list->members, (list->num_members + 1) * sizeof(rj));
  list->members[list->num_members++] = member;
}

// Remove a member from the mailing list
void remove_member(ml *list, char *name) {
  int i;
  for (i = 0; i < list->num_members; i++) {
    if (strcmp(list->members[i].name, name) == 0) {
      list->num_members--;
      list->members[i] = list->members[list->num_members];
      list->members = realloc(list->members, list->num_members * sizeof(rj));
      break;
    }
  }
}

// Print the mailing list
void print_mailing_list(ml *list) {
  int i;
  for (i = 0; i < list->num_members; i++) {
    printf("%s <%s>\n", list->members[i].name, list->members[i].email);
  }
}

// Free the mailing list
void free_mailing_list(ml *list) {
  free(list->members);
  free(list);
}

int main() {
  // Create a new mailing list
  ml *list = create_mailing_list();

  // Add some members to the mailing list
  rj romeo = {"Romeo", "romeo@example.com"};
  rj juliet = {"Juliet", "juliet@example.com"};
  rj mercutio = {"Mercutio", "mercutio@example.com"};
  rj tybalt = {"Tybalt", "tybalt@example.com"};
  add_member(list, romeo);
  add_member(list, juliet);
  add_member(list, mercutio);
  add_member(list, tybalt);

  // Print the mailing list
  printf("Original mailing list:\n");
  print_mailing_list(list);

  // Remove a member from the mailing list
  remove_member(list, "Tybalt");

  // Print the mailing list
  printf("Mailing list after removing Tybalt:\n");
  print_mailing_list(list);

  // Free the mailing list
  free_mailing_list(list);

  return 0;
}