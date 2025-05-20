//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Candidate {
  char name[MAX_NAME_LENGTH];
  int age;
  char experience[MAX_EXPERIENCE_LENGTH];
  struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
  Candidate* head = NULL;
  char* line = strtok(resume_text, "\n");
  while (line) {
    char* name = strstr(line, "Name:");
    char* experience = strstr(line, "Experience:");
    if (name && experience) {
      Candidate* new_candidate = malloc(sizeof(Candidate));
      strcpy(new_candidate->name, name + 5);
      new_candidate->age = atoi(strtok(experience, ":")[1]);
      strcpy(new_candidate->experience, experience + 10);
      new_candidate->next = head;
      head = new_candidate;
    }
    line = strtok(NULL, "\n");
  }
  return head;
}

int main() {
  char* resume_text = "Name: John Doe\n"
    "Age: 25\n"
    "Experience:\n"
    "Software Engineer at Google\n"
    "Worked on projects using Java, Python, and C++\n"
    "Senior Engineer at IBM\n"
    "Led a team of developers in building a mobile app\n";

  Candidate* head = parse_resume(resume_text);
  Candidate* current = head;
  while (current) {
    printf("Name: %s\n", current->name);
    printf("Age: %d\n", current->age);
    printf("Experience: %s\n", current->experience);
    printf("\n");
    current = current->next;
  }

  return 0;
}