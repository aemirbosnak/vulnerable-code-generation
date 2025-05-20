//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

typedef struct {
  char *name;
  char *email;
  char *phone;
  char *skills;
} Candidate;

int main() {
  // Open the resume file
  FILE *file = fopen("resume.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Read the resume into an array of strings
  char *lines[MAX_LINES];
  int line_count = 0;
  while (fgets(lines[line_count], MAX_LINE_LENGTH, file) != NULL) {
    line_count++;
  }
  fclose(file);

  // Parse the resume to extract the candidate's information
  Candidate candidate;
  candidate.name = NULL;
  candidate.email = NULL;
  candidate.phone = NULL;
  candidate.skills = NULL;
  for (int i = 0; i < line_count; i++) {
    char *line = lines[i];

    // Extract the candidate's name
    if (strstr(line, "Name:") != NULL) {
      candidate.name = strdup(line + 6);
    }

    // Extract the candidate's email address
    else if (strstr(line, "Email:") != NULL) {
      candidate.email = strdup(line + 7);
    }

    // Extract the candidate's phone number
    else if (strstr(line, "Phone:") != NULL) {
      candidate.phone = strdup(line + 7);
    }

    // Extract the candidate's skills
    else if (strstr(line, "Skills:") != NULL) {
      candidate.skills = strdup(line + 8);
    }
  }

  // Print the candidate's information
  printf("Name: %s\n", candidate.name);
  printf("Email: %s\n", candidate.email);
  printf("Phone: %s\n", candidate.phone);
  printf("Skills: %s\n", candidate.skills);

  // Free the memory allocated for the candidate's information
  free(candidate.name);
  free(candidate.email);
  free(candidate.phone);
  free(candidate.skills);

  return EXIT_SUCCESS;
}