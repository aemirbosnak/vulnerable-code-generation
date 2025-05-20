//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct resume_entry {
  char name[MAX_NAME_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];
  struct resume_entry* next;
} resume_entry;

resume_entry* parse_resume(FILE* file) {
  resume_entry* head = NULL;
  resume_entry* current = NULL;

  // Read the file line by line
  char line[MAX_NAME_LENGTH];
  while (fgets(line, MAX_NAME_LENGTH, file) != NULL) {
    // Extract the name and experience from the line
    char* name = strchr(line, ':') + 1;
    char* experience = strstr(line, "Experience:");

    // Create a new resume entry
    resume_entry* new_entry = (resume_entry*)malloc(sizeof(resume_entry));
    strcpy(new_entry->name, name);
    strcpy(new_entry->experience, experience);

    // If there is no head, make it the head
    if (head == NULL) {
      head = new_entry;
    }

    // If there is a current, link it to the new entry
    if (current) {
      current->next = new_entry;
    }

    // Update the current pointer
    current = new_entry;
  }

  // Return the head of the resume entry list
  return head;
}

int main() {
  FILE* file = fopen("resume.txt", "r");
  resume_entry* head = parse_resume(file);

  // Print the resume entries
  for (resume_entry* current = head; current; current = current->next) {
    printf("Name: %s\n", current->name);
    printf("Experience: %s\n", current->experience);
    printf("\n");
  }

  fclose(file);

  return 0;
}