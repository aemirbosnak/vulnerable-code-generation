//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the resume data structure
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
} resume;

// Define the resume parser function
resume *parse_resume(char *filename) {
  // Open the resume file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Read the resume file into memory
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *file_contents = malloc(file_size + 1);
  fread(file_contents, file_size, 1, file);
  fclose(file);

  // Parse the resume file
  resume *r = malloc(sizeof(resume));
  char *line = strtok(file_contents, "\n");
  while (line != NULL) {
    // Parse the name
    if (strstr(line, "Name:") != NULL) {
      r->name = strdup(strtok(NULL, "\n"));
    }

    // Parse the email
    if (strstr(line, "Email:") != NULL) {
      r->email = strdup(strtok(NULL, "\n"));
    }

    // Parse the phone
    if (strstr(line, "Phone:") != NULL) {
      r->phone = strdup(strtok(NULL, "\n"));
    }

    // Parse the skills
    if (strstr(line, "Skills:") != NULL) {
      r->skills = strdup(strtok(NULL, "\n"));
    }

    // Parse the experience
    if (strstr(line, "Experience:") != NULL) {
      r->experience = strdup(strtok(NULL, "\n"));
    }

    // Parse the education
    if (strstr(line, "Education:") != NULL) {
      r->education = strdup(strtok(NULL, "\n"));
    }

    // Get the next line
    line = strtok(NULL, "\n");
  }

  // Free the memory allocated for the file contents
  free(file_contents);

  // Return the resume
  return r;
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user specified a resume file
  if (argc < 2) {
    printf("Usage: %s <resume file>\n", argv[0]);
    return 1;
  }

  // Parse the resume file
  resume *r = parse_resume(argv[1]);

  // Print the resume
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n", r->phone);
  printf("Skills: %s\n", r->skills);
  printf("Experience: %s\n", r->experience);
  printf("Education: %s\n", r->education);

  // Free the memory allocated for the resume
  free(r->name);
  free(r->email);
  free(r->phone);
  free(r->skills);
  free(r->experience);
  free(r->education);
  free(r);

  return 0;
}