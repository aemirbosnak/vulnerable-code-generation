//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_CASE_NUMBER 100

typedef struct Case {
  char name[MAX_NAME_LENGTH];
  int case_number;
  struct Case* next;
} Case;

Case* insert_case(Case* head, char* name, int case_number) {
  Case* new_case = malloc(sizeof(Case));
  strcpy(new_case->name, name);
  new_case->case_number = case_number;
  new_case->next = NULL;

  if (head == NULL) {
    return new_case;
  }

  head->next = new_case;
  return head;
}

Case* find_case(Case* head, int case_number) {
  while (head) {
    if (head->case_number == case_number) {
      return head;
    }
    head = head->next;
  }

  return NULL;
}

int main() {
  Case* cases = NULL;

  // Insert some cases
  insert_case(cases, "The Hound of the Baskervilles", 1);
  insert_case(cases, "The Adventure of the Speckled Band", 2);
  insert_case(cases, "The Case of the Missing Necklace", 3);

  // Find a case
  Case* case_found = find_case(cases, 2);

  // Print the case details
  if (case_found) {
    printf("Case name: %s\n", case_found->name);
    printf("Case number: %d\n", case_found->case_number);
  } else {
    printf("Case not found.\n");
  }

  return 0;
}