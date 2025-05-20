//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume {
  char name[MAX_NAME_LENGTH];
  int age;
  float salary;
  struct Resume* next;
} Resume;

void parse_resume(Resume* resume_head) {
  FILE* resume_file = fopen("resume.txt", "r");
  if (resume_file == NULL) {
    return;
  }

  char line[MAX_NAME_LENGTH];
  while (fgets(line, MAX_NAME_LENGTH, resume_file) != NULL) {
    // Parse name
    if (strstr(line, "Name:") != NULL) {
      char* name = strdup(strstr(line, "Name:") + 5);
      strcpy(resume_head->name, name);
    }

    // Parse age
    if (strstr(line, "Age:") != NULL) {
      char* age_str = strdup(strstr(line, "Age:") + 5);
      resume_head->age = atoi(age_str);
    }

    // Parse salary
    if (strstr(line, "Salary:") != NULL) {
      char* salary_str = strdup(strstr(line, "Salary:") + 8);
      resume_head->salary = atof(salary_str);
    }

    resume_head = resume_head->next;
  }

  fclose(resume_file);
}

int main() {
  Resume* resume_head = malloc(sizeof(Resume));
  resume_head->next = NULL;

  parse_resume(resume_head);

  printf("Name: %s\n", resume_head->name);
  printf("Age: %d\n", resume_head->age);
  printf("Salary: %.2f\n", resume_head->salary);

  return 0;
}