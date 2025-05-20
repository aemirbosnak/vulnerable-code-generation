//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the resume structure
typedef struct {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
} Resume;

// Define the parser function
Resume *parse_resume(FILE *fp) {
  // Allocate memory for the resume
  Resume *resume = malloc(sizeof(Resume));

  // Read the name
  char line[1024];
  fgets(line, sizeof(line), fp);
  resume->name = strdup(line);

  // Read the email
  fgets(line, sizeof(line), fp);
  resume->email = strdup(line);

  // Read the phone
  fgets(line, sizeof(line), fp);
  resume->phone = strdup(line);

  // Read the skills
  fgets(line, sizeof(line), fp);
  resume->skills = strdup(line);

  // Read the experience
  fgets(line, sizeof(line), fp);
  resume->experience = strdup(line);

  // Read the education
  fgets(line, sizeof(line), fp);
  resume->education = strdup(line);

  // Return the resume
  return resume;
}

// Define the main function
int main() {
  // Open the resume file
  FILE *fp = fopen("resume.txt", "r");
  if (fp == NULL) {
    perror("Error opening resume file");
    return 1;
  }

  // Parse the resume
  Resume *resume = parse_resume(fp);

  // Print the resume
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
  printf("Education: %s\n", resume->education);

  // Free the memory allocated for the resume
  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->skills);
  free(resume->experience);
  free(resume->education);
  free(resume);

  // Close the resume file
  fclose(fp);

  return 0;
}