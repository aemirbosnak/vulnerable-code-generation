//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: immersive
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
  Candidate* candidates = NULL;
  char* name_start = NULL;
  char* name_end = NULL;
  char* age_start = NULL;
  char* age_end = NULL;
  char* salary_start = NULL;
  char* salary_end = NULL;

  // Allocate memory for the first candidate
  candidates = malloc(sizeof(Candidate));
  candidates->next = NULL;

  // Search for the candidate's name
  name_start = strstr(resume_text, "Name:");
  if (name_start) {
    name_end = strchr(name_start, ':');
    strncpy(candidates->name, name_start + 1, name_end - name_start - 1);
  }

  // Search for the candidate's age
  age_start = strstr(resume_text, "Age:");
  if (age_start) {
    age_end = strchr(age_start, ':');
    candidates->age = atoi(age_start + 1);
  }

  // Search for the candidate's salary
  salary_start = strstr(resume_text, "Salary:");
  if (salary_start) {
    salary_end = strchr(salary_start, ':');
    candidates->salary = atof(salary_start + 1);
  }

  return candidates;
}

int main() {
  char* resume_text = "Name: John Doe\nAge: 25\nSalary: 50000";

  Candidate* candidates = parse_resume(resume_text);

  printf("Name: %s\n", candidates->name);
  printf("Age: %d\n", candidates->age);
  printf("Salary: %.2f\n", candidates->salary);

  return 0;
}