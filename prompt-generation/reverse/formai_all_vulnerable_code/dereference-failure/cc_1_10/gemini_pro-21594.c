//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *education;
  char *experience;
} resume;

int main() {
  // Create a new resume
  resume *my_resume = malloc(sizeof(resume));

  // Parse the resume from a file
  FILE *file = fopen("resume.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    // Parse the line
    char *field = strtok(line, ":");
    char *value = strtok(NULL, "\n");

    // Set the appropriate field in the resume
    if (strcmp(field, "Name") == 0) {
      my_resume->name = malloc(strlen(value) + 1);
      strcpy(my_resume->name, value);
    } else if (strcmp(field, "Email") == 0) {
      my_resume->email = malloc(strlen(value) + 1);
      strcpy(my_resume->email, value);
    } else if (strcmp(field, "Phone") == 0) {
      my_resume->phone = malloc(strlen(value) + 1);
      strcpy(my_resume->phone, value);
    } else if (strcmp(field, "Address") == 0) {
      my_resume->address = malloc(strlen(value) + 1);
      strcpy(my_resume->address, value);
    } else if (strcmp(field, "Skills") == 0) {
      my_resume->skills = malloc(strlen(value) + 1);
      strcpy(my_resume->skills, value);
    } else if (strcmp(field, "Education") == 0) {
      my_resume->education = malloc(strlen(value) + 1);
      strcpy(my_resume->education, value);
    } else if (strcmp(field, "Experience") == 0) {
      my_resume->experience = malloc(strlen(value) + 1);
      strcpy(my_resume->experience, value);
    }
  }

  // Close the file
  fclose(file);

  // Print the resume
  printf("Name: %s\n", my_resume->name);
  printf("Email: %s\n", my_resume->email);
  printf("Phone: %s\n", my_resume->phone);
  printf("Address: %s\n", my_resume->address);
  printf("Skills: %s\n", my_resume->skills);
  printf("Education: %s\n", my_resume->education);
  printf("Experience: %s\n", my_resume->experience);

  // Free the memory allocated for the resume
  free(my_resume->name);
  free(my_resume->email);
  free(my_resume->phone);
  free(my_resume->address);
  free(my_resume->skills);
  free(my_resume->education);
  free(my_resume->experience);
  free(my_resume);

  return 0;
}