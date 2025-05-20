//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Candidate {
  char name[MAX_NAME_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];
  int age;
  struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* resume_text) {
  Candidate* head = NULL;
  Candidate* current = NULL;

  // Extract candidate name
  char* name = strstr(resume_text, "Name:");
  if (name) {
    name += 5; // Skip "Name:" and space
    current = malloc(sizeof(Candidate));
    strcpy(current->name, name);
    current->age = atoi(strtok(NULL, ","));
    current->next = NULL;

    if (head) {
      head->next = current;
    } else {
      head = current;
    }
  }

  // Extract candidate experience
  char* experience = strstr(resume_text, "Experience:");
  if (experience) {
    experience += 9; // Skip "Experience:" and space
    current = malloc(sizeof(Candidate));
    strcpy(current->experience, experience);
    current->next = NULL;

    if (head) {
      head->next = current;
    } else {
      head = current;
    }
  }

  return head;
}

int main() {
  char resume_text[] = "Name: John Doe\n"
    "Age: 25\n"
    "Experience:\n"
    "Software Engineer at Google\n"
    "2018-2022\n"
    "Bachelor's degree in Computer Science\n";

  Candidate* head = parse_resume(resume_text);

  // Print candidate name and experience
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Experience: %s\n", head->experience);
    printf("\n");
    head = head->next;
  }

  return 0;
}