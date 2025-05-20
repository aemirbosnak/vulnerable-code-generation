//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
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

void parse_resume(char* resume_text) {
  Candidate* head = NULL;
  Candidate* tail = NULL;

  // Extract candidate name, age, and salary from the resume text
  char* name = strstr(resume_text, "Name:");
  char* age_str = strstr(resume_text, "Age:");
  char* salary_str = strstr(resume_text, "Salary:");

  // Validate the extracted data
  if (name && age_str && salary_str) {
    // Allocate memory for the candidate
    Candidate* new_candidate = malloc(sizeof(Candidate));

    // Copy the candidate's name, age, and salary
    strncpy(new_candidate->name, name + 5, MAX_NAME_LENGTH - 1);
    new_candidate->age = atoi(age_str + 5);
    new_candidate->salary = atof(salary_str + 6);

    // Add the candidate to the list
    if (head == NULL) {
      head = new_candidate;
      tail = new_candidate;
    } else {
      tail->next = new_candidate;
      tail = new_candidate;
    }
  }

  // Print the candidate list
  Candidate* current = head;
  while (current) {
    printf("%s, %d, %.2f\n", current->name, current->age, current->salary);
    current = current->next;
  }
}

int main() {
  char resume_text[] = "Name: John Doe\nAge: 25\nSalary: $50,000\n\nName: Jane Doe\nAge: 30\nSalary: $60,000";

  parse_resume(resume_text);

  return 0;
}