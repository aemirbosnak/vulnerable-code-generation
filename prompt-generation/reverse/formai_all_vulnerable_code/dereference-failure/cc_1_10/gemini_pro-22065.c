//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the resume structure
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *education;
  char *experience;
} resume;

// Define the parser function
resume *parse_resume(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Allocate memory for the resume
  resume *r = malloc(sizeof(resume));
  if (r == NULL) {
    fclose(file);
    return NULL;
  }

  // Read the file
  char line[1024];
  while (fgets(line, sizeof(line), file) != NULL) {
    // Parse the line
    char *key = strtok(line, ":");
    char *value = strtok(NULL, "\n");

    // Store the value in the resume
    if (strcmp(key, "name") == 0) {
      r->name = strdup(value);
    } else if (strcmp(key, "email") == 0) {
      r->email = strdup(value);
    } else if (strcmp(key, "phone") == 0) {
      r->phone = strdup(value);
    } else if (strcmp(key, "address") == 0) {
      r->address = strdup(value);
    } else if (strcmp(key, "skills") == 0) {
      r->skills = strdup(value);
    } else if (strcmp(key, "education") == 0) {
      r->education = strdup(value);
    } else if (strcmp(key, "experience") == 0) {
      r->experience = strdup(value);
    }
  }

  // Close the file
  fclose(file);

  // Return the resume
  return r;
}

// Define the main function
int main(int argc, char **argv) {
  // Check the arguments
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Parse the resume
  resume *r = parse_resume(argv[1]);
  if (r == NULL) {
    printf("Error parsing resume\n");
    return 1;
  }

  // Print the resume
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n", r->phone);
  printf("Address: %s\n", r->address);
  printf("Skills: %s\n", r->skills);
  printf("Education: %s\n", r->education);
  printf("Experience: %s\n", r->experience);

  // Free the memory
  free(r->name);
  free(r->email);
  free(r->phone);
  free(r->address);
  free(r->skills);
  free(r->education);
  free(r->experience);
  free(r);

  return 0;
}