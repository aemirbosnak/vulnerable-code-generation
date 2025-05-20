//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *experience;
} Resume;

int main() {
  // Create a new resume
  Resume *resume = malloc(sizeof(Resume));

  // Parse the resume from a file
  FILE *file = fopen("resume.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  char buffer[1024];
  while (fgets(buffer, 1024, file) != NULL) {
    // Parse each line of the resume
    char *key = strtok(buffer, ":");
    char *value = strtok(NULL, "\n");

    // Set the appropriate field in the resume
    if (strcmp(key, "Name") == 0) {
      resume->name = strdup(value);
    } else if (strcmp(key, "Email") == 0) {
      resume->email = strdup(value);
    } else if (strcmp(key, "Phone") == 0) {
      resume->phone = strdup(value);
    } else if (strcmp(key, "Address") == 0) {
      resume->address = strdup(value);
    } else if (strcmp(key, "Skills") == 0) {
      resume->skills = strdup(value);
    } else if (strcmp(key, "Experience") == 0) {
      resume->experience = strdup(value);
    }
  }

  // Close the file
  fclose(file);

  // Print the resume
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Address: %s\n", resume->address);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);

  // Free the memory allocated for the resume
  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->address);
  free(resume->skills);
  free(resume->experience);
  free(resume);

  return 0;
}