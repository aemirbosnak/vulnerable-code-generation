//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
  char name[MAX_NAME_LENGTH];
  int age;
  double salary;
  struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
  Candidate* head = NULL;
  Candidate* current = NULL;

  // Extract candidate name
  char* name = strstr(resume_text, "Name:");
  if (name) {
    name += 5; // Skip "Name:" and spaces
    current = malloc(sizeof(Candidate));
    strcpy(current->name, name);
    current->age = atoi(strstr(name, ","));
    current->salary = atof(strstr(name, "$"));

    // Insert candidate into linked list
    if (head) {
      current->next = head;
    } else {
      head = current;
    }
  }

  return head;
}

int main() {
  char resume_text[] = "Name: John Doe, Age: 25, Salary: $50,000\n"
                          "Name: Jane Doe, Age: 30, Salary: $60,000\n";

  Candidate* head = parse_resume(resume_text);

  // Print candidate information
  for (Candidate* current = head; current; current = current->next) {
    printf("Name: %s, Age: %d, Salary: $%f\n", current->name, current->age, current->salary);
  }

  return 0;
}