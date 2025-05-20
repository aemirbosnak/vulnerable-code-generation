//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 1000

typedef struct Resume {
  char name[MAX_NAME_LENGTH];
  char email[MAX_NAME_LENGTH];
  char phone[MAX_NAME_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];
  struct Resume* next;
} Resume;

void parse_resume(char* resume_text) {
  Resume* head = NULL;
  Resume* current = NULL;

  // Extract name, email, and phone
  char* name = strstr(resume_text, "Name:");
  char* email = strstr(resume_text, "Email:");
  char* phone = strstr(resume_text, "Phone:");

  // Create a new resume node
  current = malloc(sizeof(Resume));
  current->next = NULL;

  // Fill in the node data
  strcpy(current->name, name + 5);
  strcpy(current->email, email + 6);
  strcpy(current->phone, phone + 7);

  // Add the node to the linked list
  if (head == NULL) {
    head = current;
  } else {
    current->next = head;
    head = current;
  }

  // Extract experience
  char* experience = strstr(resume_text, "Experience:");
  experience = experience + 9;

  // Iterate over the experience sections and add them to the node's experience field
  while (experience && *experience) {
    char* line = strstr(experience, ".");
    if (line) {
      *line = '\0';
      strcat(current->experience, experience);
      experience = line + 1;
    } else {
      strcat(current->experience, experience);
      experience = NULL;
    }
  }

  // Print the resume data
  current = head;
  while (current) {
    printf("Name: %s\n", current->name);
    printf("Email: %s\n", current->email);
    printf("Phone: %s\n", current->phone);
    printf("Experience:\n%s\n", current->experience);
    printf("\n");
    current = current->next;
  }
}

int main() {
  char* resume_text = "Name: John Doe\nEmail: john.doe@example.com\nPhone: (123) 456-7890\n\nExperience:\nSoftware Engineer, ACM Corporation, New York, NY, 2018-2022\n\nResponsibilities:\n- Designed and implemented software systems.\n- Managed project timelines and budgets.\n- Collaborated with teams of engineers.\n\n";

  parse_resume(resume_text);

  return 0;
}