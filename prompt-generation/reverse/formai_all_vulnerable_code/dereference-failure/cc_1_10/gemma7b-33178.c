//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct ResumeEntry {
  char name[MAX_NAME_LENGTH];
  int age;
  float salary;
  struct ResumeEntry* next;
} ResumeEntry;

void parse_resume(char* resume_text) {
  ResumeEntry* head = NULL;
  char* name_start = NULL;
  char* name_end = NULL;
  char* age_start = NULL;
  char* age_end = NULL;
  char* salary_start = NULL;
  char* salary_end = NULL;

  // Allocate memory for the first entry
  head = malloc(sizeof(ResumeEntry));

  // Find the name, age, and salary sections
  name_start = strstr(resume_text, "Name:");
  age_start = strstr(resume_text, "Age:");
  salary_start = strstr(resume_text, "Salary:");

  // Extract the name, age, and salary
  name_end = strchr(name_start, ':');
  age_end = strchr(age_start, ':');
  salary_end = strchr(salary_start, '$');

  // Copy the name, age, and salary into the entry
  strncpy(head->name, name_start + 1, name_end - name_start - 1);
  head->age = atoi(age_start + 1);
  head->salary = atof(salary_start + 1);

  // Link the first entry to the head of the list
  head->next = NULL;

  // Free the memory for the remaining entries
  free(head);
}

int main() {
  char* resume_text = "Name: John Doe\nAge: 30\nSalary: $50,000";

  parse_resume(resume_text);

  return 0;
}