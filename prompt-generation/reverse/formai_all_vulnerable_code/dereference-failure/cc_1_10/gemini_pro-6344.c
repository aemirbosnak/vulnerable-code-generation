//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a resume
#define MAX_RESUME_SIZE 1024

// Define the maximum number of skills
#define MAX_SKILLS 10

// Define the maximum number of experiences
#define MAX_EXPERIENCES 10

// Define the resume struct
typedef struct {
  char name[50];
  char email[50];
  char phone[20];
  char skills[MAX_SKILLS][20];
  char experiences[MAX_EXPERIENCES][50];
} resume;

// Function to parse a resume
void parse_resume(resume *r, char *filename) {
  // Open the resume file
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Error opening resume file\n");
    return;
  }

  // Read the resume into a buffer
  char buffer[MAX_RESUME_SIZE];
  fread(buffer, 1, MAX_RESUME_SIZE, f);

  // Close the resume file
  fclose(f);

  // Parse the name
  char *name = strtok(buffer, "\n");
  strcpy(r->name, name);

  // Parse the email
  char *email = strtok(NULL, "\n");
  strcpy(r->email, email);

  // Parse the phone
  char *phone = strtok(NULL, "\n");
  strcpy(r->phone, phone);

  // Parse the skills
  int i = 0;
  char *skill = strtok(NULL, "\n");
  while (skill != NULL && i < MAX_SKILLS) {
    strcpy(r->skills[i], skill);
    i++;
    skill = strtok(NULL, "\n");
  }

  // Parse the experiences
  i = 0;
  char *experience = strtok(NULL, "\n");
  while (experience != NULL && i < MAX_EXPERIENCES) {
    strcpy(r->experiences[i], experience);
    i++;
    experience = strtok(NULL, "\n");
  }
}

// Function to print a resume
void print_resume(resume *r) {
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n\n", r->phone);

  printf("Skills:\n");
  for (int i = 0; i < MAX_SKILLS; i++) {
    if (strlen(r->skills[i]) > 0) {
      printf("  - %s\n", r->skills[i]);
    }
  }

  printf("\nExperiences:\n");
  for (int i = 0; i < MAX_EXPERIENCES; i++) {
    if (strlen(r->experiences[i]) > 0) {
      printf("  - %s\n", r->experiences[i]);
    }
  }
}

// Main function
int main() {
  // Create a new resume
  resume r;

  // Parse the resume
  parse_resume(&r, "resume.txt");

  // Print the resume
  print_resume(&r);

  return 0;
}