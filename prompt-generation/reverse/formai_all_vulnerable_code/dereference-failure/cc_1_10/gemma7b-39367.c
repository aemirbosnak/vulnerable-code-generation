//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume {
  char name[MAX_NAME_LENGTH];
  int age;
  float salary;
  struct Resume *next;
} Resume;

void parse_resume(char *resume_text) {
  Resume *head = NULL;
  char *name_start = NULL;
  char *name_end = NULL;
  char *age_start = NULL;
  char *age_end = NULL;
  char *salary_start = NULL;
  char *salary_end = NULL;

  // Find the name, age, and salary sections in the resume text
  name_start = strstr(resume_text, "Name:");
  name_end = strstr(name_start, "\n");

  age_start = strstr(name_end, "Age:");
  age_end = strstr(age_start, "\n");

  salary_start = strstr(age_end, "Salary:");
  salary_end = strstr(salary_start, "\n");

  // Allocate memory for the resume node
  Resume *new_resume = malloc(sizeof(Resume));

  // Copy the name, age, and salary from the resume text
  strncpy(new_resume->name, name_start + 5, name_end - name_start - 5);
  new_resume->age = atoi(age_start + 5);
  new_resume->salary = atof(salary_start + 8);

  // Link the new resume node to the head of the list
  if (head) {
    new_resume->next = head;
  } else {
    head = new_resume;
  }

  // Free the memory allocated for the resume node
  free(new_resume);
}

int main() {
  char resume_text[] = "Name: John Doe\nAge: 25\nSalary: $50,000\n";

  parse_resume(resume_text);

  return 0;
}