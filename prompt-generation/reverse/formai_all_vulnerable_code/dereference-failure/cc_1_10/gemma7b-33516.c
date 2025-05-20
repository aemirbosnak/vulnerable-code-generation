//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct resume_node {
  char name[MAX_NAME_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];
  struct resume_node* next;
} resume_node;

void parse_resume(char* resume_text) {
  resume_node* head = NULL;
  resume_node* tail = NULL;

  // Extract name and experience from the resume text
  char* name = strstr(resume_text, "Name:");
  char* experience = strstr(resume_text, "Experience:");

  // Create a new resume node
  resume_node* new_node = malloc(sizeof(resume_node));
  new_node->next = NULL;

  // Copy name and experience into the new node
  strncpy(new_node->name, name, MAX_NAME_LENGTH);
  strncpy(new_node->experience, experience, MAX_EXPERIENCE_LENGTH);

  // If the head of the list is NULL, make it the head
  if (head == NULL) {
    head = new_node;
  }

  // If the tail of the list is not NULL, append the new node to the tail
  if (tail) {
    tail->next = new_node;
  }

  // Update the tail of the list
  tail = new_node;

  // Print the name and experience of the new node
  printf("Name: %s\n", new_node->name);
  printf("Experience: %s\n", new_node->experience);
}

int main() {
  char* resume_text = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Microsoft";

  parse_resume(resume_text);

  return 0;
}