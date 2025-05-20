//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct resume_entry {
  char name[MAX_NAME_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];
  struct resume_entry* next;
} resume_entry;

resume_entry* parse_resume(char* resume_text) {
  resume_entry* head = NULL;
  resume_entry* current = NULL;

  // Extract name and experience from the resume text
  char* name = strstr(resume_text, "Name:");
  if (name) {
    name += 5;
    current = malloc(sizeof(resume_entry));
    strcpy(current->name, name);

    // Extract experience from the resume text
    char* experience = strstr(resume_text, "Experience:");
    if (experience) {
      experience += 9;
      strcpy(current->experience, experience);

      // Link the current entry to the head of the list
      if (head) {
        current->next = head;
      } else {
        head = current;
      }
    }
  }

  return head;
}

int main() {
  char resume_text[] = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Amazon";

  resume_entry* head = parse_resume(resume_text);

  // Print the name and experience of each entry
  for (resume_entry* current = head; current; current = current->next) {
    printf("Name: %s\n", current->name);
    printf("Experience: %s\n", current->experience);
    printf("\n");
  }

  return 0;
}