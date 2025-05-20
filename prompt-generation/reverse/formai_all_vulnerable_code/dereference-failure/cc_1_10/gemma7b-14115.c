//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Candidate {
  char name[MAX_NAME_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];
  struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
  Candidate* head = NULL;
  Candidate* tail = NULL;

  // Extract candidate name and experience from resume text
  char* name = strstr(resume_text, "Name:");
  char* experience = strstr(resume_text, "Experience:");

  // Create a new candidate node
  Candidate* new_candidate = malloc(sizeof(Candidate));
  new_candidate->next = NULL;

  // Copy candidate name and experience into the node
  strcpy(new_candidate->name, name + 5);
  strcpy(new_candidate->experience, experience - 1);

  // If the head of the list is NULL, make it the head
  if (head == NULL) {
    head = new_candidate;
  } else {
    tail->next = new_candidate;
  }

  // Update the tail of the list
  tail = new_candidate;

  // Return the head of the list
  return head;
}

int main() {
  char* resume_text = "Name: John Doe\nExperience: Software Engineer at Google";

  Candidate* head = parse_resume(resume_text);

  // Print candidate name and experience
  printf("Name: %s\n", head->name);
  printf("Experience: %s\n", head->experience);

  return 0;
}