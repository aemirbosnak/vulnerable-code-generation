//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *education;
  char *skills;
  char *experience;
  char *awards;
} resume;

// Function to parse resume from text file
resume *parse_resume(char *filename) {
  // Open the resume file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s", filename);
    return NULL;
  }

  // Allocate memory for the resume struct
  resume *r = malloc(sizeof(resume));
  if (r == NULL) {
    printf("Error allocating memory for resume");
    return NULL;
  }

  // Initialize the resume struct
  r->name = NULL;
  r->email = NULL;
  r->phone = NULL;
  r->address = NULL;
  r->education = NULL;
  r->skills = NULL;
  r->experience = NULL;
  r->awards = NULL;
  
  char line[500];

  // Parse the resume file line by line
  while (fgets(line, sizeof(line), file)) {
    // Check if the line contains the name
    if (strstr(line, "Name:") != NULL) {
      r->name = strdup(line + 6);
    }
    // Check if the line contains the email
    else if (strstr(line, "Email:") != NULL) {
      r->email = strdup(line + 7);
    }
    // Check if the line contains the phone
    else if (strstr(line, "Phone:") != NULL) {
      r->phone = strdup(line + 7);
    }
    // Check if the line contains the address
    else if (strstr(line, "Address:") != NULL) {
      r->address = strdup(line + 9);
    }
    // Check if the line contains the education
    else if (strstr(line, "Education:") != NULL) {
      r->education = strdup(line + 11);
    }
    // Check if the line contains the skills
    else if (strstr(line, "Skills:") != NULL) {
      r->skills = strdup(line + 7);
    }
    // Check if the line contains the experience
    else if (strstr(line, "Experience:") != NULL) {
      r->experience = strdup(line + 12);
    }
    // Check if the line contains the awards
    else if (strstr(line, "Awards:") != NULL) {
      r->awards = strdup(line + 8);
    }
  }

  // Close the resume file
  fclose(file);

  // Return the resume struct
  return r;
}

// Function to print resume
void print_resume(resume *r) {
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n", r->phone);
  printf("Address: %s\n", r->address);
  printf("Education: %s\n", r->education);
  printf("Skills: %s\n", r->skills);
  printf("Experience: %s\n", r->experience);
  printf("Awards: %s\n", r->awards);
}

// Main function
int main() {
  // Parse the resume file
  resume *r = parse_resume("resume.txt");

  // Print the resume
  print_resume(r);

  // Free the memory allocated for the resume struct
  free(r->name);
  free(r->email);
  free(r->phone);
  free(r->address);
  free(r->education);
  free(r->skills);
  free(r->experience);
  free(r->awards);
  free(r);

  return 0;
}