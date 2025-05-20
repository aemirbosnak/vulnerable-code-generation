//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 1000

typedef struct Resume {
  char name[MAX_NAME_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];
  struct Resume* next;
} Resume;

void parseResume(char* resumeText) {
  Resume* head = NULL;
  Resume* current = NULL;

  // Extract name and experience from resume text
  char* name = strstr(resumeText, "Name:");
  char* experience = strstr(resumeText, "Experience:");

  // Create a new resume node
  current = (Resume*)malloc(sizeof(Resume));
  current->next = NULL;

  // Populate name and experience fields
  strcpy(current->name, name + 5);
  strcpy(current->experience, experience + 9);

  // Add node to the head if it's the first node
  if (head == NULL) {
    head = current;
  } else {
    current->next = head;
    head = current;
  }

  // Repeat for remaining nodes until the end of the resume text is reached
  while (strstr(resumeText, "Name:") && strstr(resumeText, "Experience:") && current) {
    current = (Resume*)malloc(sizeof(Resume));
    current->next = NULL;

    name = strstr(resumeText, "Name:");
    experience = strstr(resumeText, "Experience:");

    strcpy(current->name, name + 5);
    strcpy(current->experience, experience + 9);

    current->next = head;
    head = current;

    resumeText = strstr(resumeText, "Name:") + 1;
  }

  // Print the resume data
  Resume* temp = head;
  while (temp) {
    printf("Name: %s\n", temp->name);
    printf("Experience: %s\n", temp->experience);
    printf("\n");
    temp = temp->next;
  }
}

int main() {
  char* resumeText = "Name: John Doe\nExperience: Software Engineer at Google\n\nName: Jane Doe\nExperience: Marketing Manager at Facebook\n";

  parseResume(resumeText);

  return 0;
}