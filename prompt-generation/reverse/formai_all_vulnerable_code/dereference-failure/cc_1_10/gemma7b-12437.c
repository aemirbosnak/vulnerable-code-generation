//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
  char name[MAX_NAME_LENGTH];
  int age;
  float salary;
  struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
  Candidate* head = NULL;
  char* name = NULL;
  int age = -1;
  float salary = -1.0f;

  // Allocate memory for the candidate
  Candidate* new_candidate = malloc(sizeof(Candidate));

  // Extract candidate name
  name = strstr(resume_text, "Name:");
  if (name) {
    name += 5; // Skip "Name:" and whitespace
    strncpy(new_candidate->name, name, MAX_NAME_LENGTH - 1);
  }

  // Extract candidate age
  age = atoi(strstr(resume_text, "Age:"));
  if (age) {
    new_candidate->age = age;
  }

  // Extract candidate salary
  salary = atof(strstr(resume_text, "Salary:"));
  if (salary) {
    new_candidate->salary = salary;
  }

  // Link candidate to the head of the list
  if (head) {
    new_candidate->next = head;
  } else {
    head = new_candidate;
  }

  return head;
}

int main() {
  char resume_text[] = "Name: John Doe\nAge: 25\nSalary: 50000\n";

  Candidate* head = parse_resume(resume_text);

  // Print candidate information
  printf("Name: %s\n", head->name);
  printf("Age: %d\n", head->age);
  printf("Salary: %.2f\n", head->salary);

  return 0;
}