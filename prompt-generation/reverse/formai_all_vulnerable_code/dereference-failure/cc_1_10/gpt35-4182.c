//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to hold the resume data
typedef struct {
  char *name;
  char *email;
  char *phone;
  char *education;
  char *experience;
  char *skills;
} Resume;

// Define a function to parse the resume
void parseResume(char *resumeText, Resume *res) {

  // Split the text into lines
  char *line = strtok(resumeText, "\n");

  // Start parsing the resume line by line
  while (line != NULL) {

    // Look for keywords and extract data
    if (strstr(line, "NAME:")) {
      res->name = strtok(line, "NAME:");
    }
    if (strstr(line, "EMAIL:")) {
      res->email = strtok(line, "EMAIL:");
    }
    if (strstr(line, "PHONE:")) {
      res->phone = strtok(line, "PHONE:");
    }
    if (strstr(line, "EDUCATION:")) {
      res->education = strtok(line, "EDUCATION:");
    }
    if (strstr(line, "EXPERIENCE:")) {
      res->experience = strtok(line, "EXPERIENCE:");
    }
    if (strstr(line, "SKILLS:")) {
      res->skills = strtok(line, "SKILLS:");
    }

    // Move on to the next line
    line = strtok(NULL, "\n");
  }
}

// Define the main function
int main() {

  // Define the resume input
  char *input = "NAME: John Doe\n"
                "EMAIL: john.doe@example.com\n"
                "PHONE: 555-1234\n"
                "EDUCATION: BS in Computer Science\n"
                "EXPERIENCE: 2 years of experience in software development\n"
                "SKILLS: C, Python, SQL\n";

  // Parse the resume
  Resume *res = malloc(sizeof(Resume));
  parseResume(input, res);

  // Print out the parsed data
  printf("NAME: %s\n", res->name);
  printf("EMAIL: %s\n", res->email);
  printf("PHONE: %s\n", res->phone);
  printf("EDUCATION: %s\n", res->education);
  printf("EXPERIENCE: %s\n", res->experience);
  printf("SKILLS: %s\n", res->skills);

  // Free the allocated memory
  free(res);

  // Return 0 as a sign of success
  return 0;
}