//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
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

ResumeEntry* parseResume(char* resumeText) {
  ResumeEntry* head = NULL;
  char* name = NULL;
  int age = 0;
  float salary = 0.0f;

  // Allocate memory for the first entry
  head = malloc(sizeof(ResumeEntry));
  head->next = NULL;

  // Parse the resume text
  name = strstr(resumeText, "Name:");
  if (name) {
    name += 5;
    strncpy(head->name, name, MAX_NAME_LENGTH - 1);
  }

  age = atoi(strstr(resumeText, "Age:"));
  if (age) {
    head->age = age;
  }

  salary = atof(strstr(resumeText, "Salary:"));
  if (salary) {
    head->salary = salary;
  }

  return head;
}

int main() {
  char* resumeText = "Name: John Doe\nAge: 30\nSalary: 50000";

  ResumeEntry* head = parseResume(resumeText);

  printf("Name: %s\n", head->name);
  printf("Age: %d\n", head->age);
  printf("Salary: %.2f\n", head->salary);

  return 0;
}