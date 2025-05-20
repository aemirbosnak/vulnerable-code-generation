//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 1000

typedef struct resume_entry {
  char name[MAX_NAME_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];
  struct resume_entry* next;
} resume_entry;

resume_entry* parse_resume(char* resume_text) {
  resume_entry* head = NULL;
  char* name_start = NULL;
  char* experience_start = NULL;
  char* current_line = NULL;

  // Iterate over the resume text line by line
  current_line = strtok(resume_text, "\n");
  while (current_line) {
    // Find the start of the name and experience sections
    if (name_start == NULL && strstr(current_line, "Name:") != NULL) {
      name_start = strstr(current_line, "Name:") + strlen("Name:");
    }
    if (experience_start == NULL && strstr(current_line, "Experience:") != NULL) {
      experience_start = strstr(current_line, "Experience:") + strlen("Experience:");
    }

    // Create a new resume entry
    if (name_start && experience_start) {
      resume_entry* new_entry = malloc(sizeof(resume_entry));
      strcpy(new_entry->name, name_start);
      strcpy(new_entry->experience, experience_start);
      new_entry->next = head;
      head = new_entry;
    }

    current_line = strtok(NULL, "\n");
  }

  return head;
}

int main() {
  char* resume_text = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Apple";

  resume_entry* head = parse_resume(resume_text);

  // Print the resume entries
  for (resume_entry* current = head; current; current = current->next) {
    printf("Name: %s\n", current->name);
    printf("Experience: %s\n", current->experience);
    printf("\n");
  }

  return 0;
}