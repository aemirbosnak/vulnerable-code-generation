//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
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
  Candidate* tail = NULL;
  char* name_start = NULL;
  char* name_end = NULL;
  char* age_start = NULL;
  char* age_end = NULL;
  char* salary_start = NULL;
  char* salary_end = NULL;

  // Allocate memory for the candidate
  Candidate* new_candidate = (Candidate*)malloc(sizeof(Candidate));

  // Extract the candidate's name, age, and salary from the resume text
  name_start = strstr(resume_text, "Name:");
  if (name_start) {
    name_start += 5;
    name_end = strstr(name_start, "\n");
    strncpy(new_candidate->name, name_start, name_end - name_start);
  }

  age_start = strstr(resume_text, "Age:");
  if (age_start) {
    age_start += 5;
    age_end = strstr(age_start, "\n");
    new_candidate->age = atoi(age_start);
  }

  salary_start = strstr(resume_text, "Salary:");
  if (salary_start) {
    salary_start += 8;
    salary_end = strstr(salary_start, "\n");
    new_candidate->salary = atof(salary_start);
  }

  // Add the candidate to the linked list
  if (head) {
    tail->next = new_candidate;
    tail = new_candidate;
  } else {
    head = new_candidate;
    tail = new_candidate;
  }

  return head;
}

int main() {
  char resume_text[] = "Name: John Doe\nAge: 25\nSalary: $50,000\n";

  Candidate* head = parse_resume(resume_text);

  // Print the candidate's name, age, and salary
  printf("Name: %s\n", head->name);
  printf("Age: %d\n", head->age);
  printf("Salary: $%f\n", head->salary);

  return 0;
}