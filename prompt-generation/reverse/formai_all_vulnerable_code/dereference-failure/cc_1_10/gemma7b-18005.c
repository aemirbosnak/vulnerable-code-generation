//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char **resume_text) {
  // Declare variables
  char *name, *position, *summary, *skills;
  int i = 0;

  // Allocate memory for the variables
  name = malloc(100);
  position = malloc(100);
  summary = malloc(200);
  skills = malloc(200);

  // Search for the name, position, summary, and skills sections
  while (*resume_text[i] != '\0') {
    // Name section
    if (strstr(resume_text[i], "Name:") != NULL) {
      name = strtok(resume_text[i], ":");
      name = strchr(name, '\n') ? strchr(name, '\n') : name;
    }

    // Position section
    if (strstr(resume_text[i], "Position:") != NULL) {
      position = strtok(resume_text[i], ":");
      position = strchr(position, '\n') ? strchr(position, '\n') : position;
    }

    // Summary section
    if (strstr(resume_text[i], "Summary:") != NULL) {
      summary = strtok(resume_text[i], ":");
      summary = strchr(summary, '\n') ? strchr(summary, '\n') : summary;
    }

    // Skills section
    if (strstr(resume_text[i], "Skills:") != NULL) {
      skills = strtok(resume_text[i], ":");
      skills = strchr(skills, '\n') ? strchr(skills, '\n') : skills;
    }

    i++;
  }

  // Print the parsed information
  printf("Name: %s\n", name);
  printf("Position: %s\n", position);
  printf("Summary: %s\n", summary);
  printf("Skills: %s\n", skills);

  // Free the allocated memory
  free(name);
  free(position);
  free(summary);
  free(skills);
}

int main() {
  // Get the resume text from the user
  char *resume_text = malloc(1000);
  printf("Enter the resume text: ");
  fgets(resume_text, 1000, stdin);

  // Parse the resume
  parse_resume(&resume_text);

  // Free the allocated memory
  free(resume_text);

  return 0;
}