//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_YEARS 10

typedef struct Resume {
  char name[MAX_NAME_LENGTH];
  int experience_years;
  struct Resume* next;
} Resume;

void parse_resume(char* resume_text) {
  Resume* head = NULL;
  Resume* current = NULL;

  // Extract the name and experience years from the resume text
  char* name = strstr(resume_text, "Name:");
  if (name) {
    name += 5; // Skip "Name:" and space
    current = malloc(sizeof(Resume));
    strcpy(current->name, name);

    // Extract the experience years
    char* experience_years_str = strstr(resume_text, "Experience Years:");
    if (experience_years_str) {
      experience_years_str += 15; // Skip "Experience Years:" and space
      current->experience_years = atoi(experience_years_str);
    }

    // Link the resume node to the head if it is the first node
    if (head == NULL) {
      head = current;
    } else {
      current->next = head;
      head = current;
    }
  }

  // Print the resume data
  current = head;
  while (current) {
    printf("Name: %s\n", current->name);
    printf("Experience Years: %d\n", current->experience_years);
    printf("\n");
    current = current->next;
  }
}

int main() {
  char* resume_text = "Name: John Doe\nExperience Years: 5\n\nName: Jane Doe\nExperience Years: 3\n";

  parse_resume(resume_text);

  return 0;
}