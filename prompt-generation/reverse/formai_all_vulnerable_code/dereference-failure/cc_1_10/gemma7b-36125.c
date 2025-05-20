//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Candidate {
  char name[20];
  int age;
  float salary;
  struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
  Candidate* head = NULL;
  Candidate* tail = NULL;

  // Extract candidate's name, age, and salary from the resume text
  char* name = strstr(resume_text, "Name:");
  char* age_str = strstr(resume_text, "Age:");
  char* salary_str = strstr(resume_text, "Salary:");

  if (name && age_str && salary_str) {
    // Allocate memory for the candidate
    Candidate* new_candidate = (Candidate*)malloc(sizeof(Candidate));

    // Copy candidate's name, age, and salary
    strcpy(new_candidate->name, name + 5);
    new_candidate->age = atoi(age_str + 5);
    new_candidate->salary = atof(salary_str + 6);

    // Link the new candidate to the head of the list
    if (head == NULL) {
      head = new_candidate;
      tail = new_candidate;
    } else {
      tail->next = new_candidate;
      tail = new_candidate;
    }
  }

  return head;
}

int main() {
  char* resume_text = "Name: John Doe\nAge: 25\nSalary: $50,000";

  Candidate* head = parse_resume(resume_text);

  // Print candidate's name, age, and salary
  printf("Name: %s\n", head->name);
  printf("Age: %d\n", head->age);
  printf("Salary: $%f\n", head->salary);

  return 0;
}