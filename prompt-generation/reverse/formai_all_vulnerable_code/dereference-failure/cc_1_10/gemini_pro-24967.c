//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Define the resume structure
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *experience;
  char *education;
} resume;

// Define the parser function
resume *parse_resume(char *filename) {
  // Open the resume file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Allocate memory for the resume struct
  resume *resume = malloc(sizeof(resume));

  // Read the resume file line by line
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    // Parse the line
    char *key = strtok(line, ":");
    char *value = strtok(NULL, ":");

    // Set the corresponding field in the resume struct
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
    } else if (strcmp(key, "Education") == 0) {
      resume->education = strdup(value);
    }
  }

  // Close the resume file
  fclose(file);

  // Return the resume struct
  return resume;
}

// Define the main function
int main() {
  // Parse the resume file
  resume *resume = parse_resume("resume.txt");

  // Print the resume
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Address: %s\n", resume->address);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
  printf("Education: %s\n", resume->education);

  // Free the memory allocated for the resume struct
  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->address);
  free(resume->skills);
  free(resume->experience);
  free(resume->education);
  free(resume);

  return 0;
}