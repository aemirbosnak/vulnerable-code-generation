//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the resume struct
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
} resume;

// Function to initialize a resume struct
resume *init_resume() {
  resume *r = malloc(sizeof(resume));
  r->name = NULL;
  r->email = NULL;
  r->phone = NULL;
  r->skills = NULL;
  r->experience = NULL;
  r->education = NULL;
  return r;
}

// Function to parse a resume from a file
resume *parse_resume(char *filename) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  resume *r = init_resume();

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the file line by line
  while ((read = getline(&line, &len, fp)) != -1) {
    // Parse the line and add the data to the resume struct
    if (strstr(line, "Name:")) {
      r->name = strdup(line + 6);
    } else if (strstr(line, "Email:")) {
      r->email = strdup(line + 7);
    } else if (strstr(line, "Phone:")) {
      r->phone = strdup(line + 7);
    } else if (strstr(line, "Skills:")) {
      r->skills = strdup(line + 8);
    } else if (strstr(line, "Experience:")) {
      r->experience = strdup(line + 12);
    } else if (strstr(line, "Education:")) {
      r->education = strdup(line + 11);
    }
  }

  // Close the file
  fclose(fp);

  // Return the resume struct
  return r;
}

// Function to print a resume
void print_resume(resume *r) {
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n", r->phone);
  printf("Skills: %s\n", r->skills);
  printf("Experience: %s\n", r->experience);
  printf("Education: %s\n", r->education);
}

// Main function
int main() {
  resume *r = parse_resume("resume.txt");
  if (r == NULL) {
    return 1;
  }

  print_resume(r);

  // Free the resume struct
  free(r->name);
  free(r->email);
  free(r->phone);
  free(r->skills);
  free(r->experience);
  free(r->education);
  free(r);

  return 0;
}