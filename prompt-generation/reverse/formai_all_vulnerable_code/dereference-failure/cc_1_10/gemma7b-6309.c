//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume {
  char name[MAX_NAME_LENGTH];
  int experience_years;
  float salary;
  struct Resume *next;
} Resume;

void parse_resume(char *resume_text) {
  Resume *head = NULL;
  Resume *tail = NULL;

  // Split the resume text into sections
  char *section_start = strtok(resume_text, "Section:");
  while (section_start) {
    // Extract the name, experience years, and salary
    char *name_start = strstr(section_start, "Name:");
    char *name_end = strstr(name_start, ",");
    char *experience_years_start = strstr(name_end, "Experience Years:");
    char *experience_years_end = strstr(experience_years_start, "Salary:");
    char *salary_start = strstr(experience_years_end, "$");
    char *salary_end = strstr(salary_start, "\n");

    // Allocate a new resume node
    Resume *new_resume = malloc(sizeof(Resume));
    new_resume->next = NULL;

    // Copy the name, experience years, and salary
    strncpy(new_resume->name, name_start + 5, name_end - name_start - 5);
    new_resume->experience_years = atoi(experience_years_start + 16);
    new_resume->salary = atof(salary_start + 1);

    // Add the new resume node to the list
    if (head == NULL) {
      head = new_resume;
      tail = new_resume;
    } else {
      tail->next = new_resume;
      tail = new_resume;
    }
    section_start = strtok(NULL, "Section:");
  }

  // Print the resume data
  for (Resume *current = head; current; current = current->next) {
    printf("Name: %s, Experience Years: %d, Salary: $%.2f\n", current->name, current->experience_years, current->salary);
  }
}

int main() {
  char *resume_text = "Section: Personal\nName: John Doe, Experience Years: 5, Salary: $50,000\n\nSection: Professional Experience\nPosition: Software Engineer, Company: ACME Inc., City: New York\n\nSection: Education\nDegree: Bachelor of Science in Computer Science, University: Harvard University, City: Cambridge";

  parse_resume(resume_text);

  return 0;
}