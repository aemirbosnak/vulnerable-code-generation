//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
} resume;

// Function to parse a resume file
resume *parse_resume(char *filename) {
  // Open the resume file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  // Allocate memory for the resume struct
  resume *res = malloc(sizeof(resume));

  // Read the resume data from the file
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    // Parse the line for the name
    if (strstr(line, "Name:")) {
      res->name = strdup(strtok(line, ":"));
    }

    // Parse the line for the email
    else if (strstr(line, "Email:")) {
      res->email = strdup(strtok(line, ":"));
    }

    // Parse the line for the phone
    else if (strstr(line, "Phone:")) {
      res->phone = strdup(strtok(line, ":"));
    }

    // Parse the line for the skills
    else if (strstr(line, "Skills:")) {
      res->skills = strdup(strtok(line, ":"));
    }

    // Parse the line for the experience
    else if (strstr(line, "Experience:")) {
      res->experience = strdup(strtok(line, ":"));
    }

    // Parse the line for the education
    else if (strstr(line, "Education:")) {
      res->education = strdup(strtok(line, ":"));
    }
  }

  // Close the resume file
  fclose(fp);

  // Return the resume struct
  return res;
}

// Function to print the resume data
void print_resume(resume *res) {
  // Print the name
  printf("Name: %s\n", res->name);

  // Print the email
  printf("Email: %s\n", res->email);

  // Print the phone
  printf("Phone: %s\n", res->phone);

  // Print the skills
  printf("Skills: %s\n", res->skills);

  // Print the experience
  printf("Experience: %s\n", res->experience);

  // Print the education
  printf("Education: %s\n", res->education);
}

// Main function
int main() {
  // Parse the resume file
  resume *res = parse_resume("resume.txt");

  // Print the resume data
  print_resume(res);

  // Free the resume struct
  free(res);

  return 0;
}