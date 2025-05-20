//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the resume structure
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
} resume;

// Declare the function to parse a resume
resume *parse_resume(char *filename) {
  // Open the resume file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Create a new resume struct
  resume *r = malloc(sizeof(resume));

  // Read the name from the file
  char line[1024];
  if (fgets(line, sizeof(line), file) != NULL) {
    r->name = strdup(strtok(line, "\n"));
  }

  // Read the email from the file
  if (fgets(line, sizeof(line), file) != NULL) {
    r->email = strdup(strtok(line, "\n"));
  }

  // Read the phone from the file
  if (fgets(line, sizeof(line), file) != NULL) {
    r->phone = strdup(strtok(line, "\n"));
  }

  // Read the skills from the file
  if (fgets(line, sizeof(line), file) != NULL) {
    r->skills = strdup(strtok(line, "\n"));
  }

  // Read the experience from the file
  if (fgets(line, sizeof(line), file) != NULL) {
    r->experience = strdup(strtok(line, "\n"));
  }

  // Read the education from the file
  if (fgets(line, sizeof(line), file) != NULL) {
    r->education = strdup(strtok(line, "\n"));
  }

  // Close the resume file
  fclose(file);

  // Return the resume struct
  return r;
}

// Declare the function to print a resume
void print_resume(resume *r) {
  // Print the name
  printf("Name: %s\n", r->name);

  // Print the email
  printf("Email: %s\n", r->email);

  // Print the phone
  printf("Phone: %s\n", r->phone);

  // Print the skills
  printf("Skills: %s\n", r->skills);

  // Print the experience
  printf("Experience: %s\n", r->experience);

  // Print the education
  printf("Education: %s\n", r->education);
}

// Declare the main function
int main() {
  // Parse the resume
  resume *r = parse_resume("resume.txt");

  // Print the resume
  print_resume(r);

  // Free the resume struct
  free(r);

  return 0;
}