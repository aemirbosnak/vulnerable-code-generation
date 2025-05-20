//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a resume
typedef struct {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *experience;
  char *education;
} resume;

// Define the function to parse a resume
int parse_resume(resume *res, char *filename) {
  // Open the resume file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return -1;
  }

  // Read the resume file line by line
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    // Parse the line
    char *key = strtok(line, ":");
    char *value = strtok(NULL, "\n");

    // Store the parsed data in the resume structure
    if (strcmp(key, "name") == 0) {
      res->name = strdup(value);
    } else if (strcmp(key, "email") == 0) {
      res->email = strdup(value);
    } else if (strcmp(key, "phone") == 0) {
      res->phone = strdup(value);
    } else if (strcmp(key, "address") == 0) {
      res->address = strdup(value);
    } else if (strcmp(key, "skills") == 0) {
      res->skills = strdup(value);
    } else if (strcmp(key, "experience") == 0) {
      res->experience = strdup(value);
    } else if (strcmp(key, "education") == 0) {
      res->education = strdup(value);
    }
  }

  // Close the resume file
  fclose(file);

  return 0;
}

// Define the function to print a resume
void print_resume(resume *res) {
  // Print the resume
  printf("Name: %s\n", res->name);
  printf("Email: %s\n", res->email);
  printf("Phone: %s\n", res->phone);
  printf("Address: %s\n", res->address);
  printf("Skills: %s\n", res->skills);
  printf("Experience: %s\n", res->experience);
  printf("Education: %s\n", res->education);
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if a resume file was specified
  if (argc < 2) {
    fprintf(stderr, "Usage: %s resume.txt\n", argv[0]);
    return -1;
  }

  // Parse the resume file
  resume res;
  int result = parse_resume(&res, argv[1]);
  if (result != 0) {
    fprintf(stderr, "Error parsing resume file\n");
    return -1;
  }

  // Print the resume
  print_resume(&res);

  // Free the memory allocated for the resume
  free(res.name);
  free(res.email);
  free(res.phone);
  free(res.address);
  free(res.skills);
  free(res.experience);
  free(res.education);

  return 0;
}