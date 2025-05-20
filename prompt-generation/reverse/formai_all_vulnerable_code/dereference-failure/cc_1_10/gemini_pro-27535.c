//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the resume struct
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *experience;
  char *education;
} resume_t;

// Define the resume parser function
int parse_resume(resume_t *resume, char *filename) {
  // Open the resume file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening resume file");
    return -1;
  }

  // Read the resume file into a string
  char *buffer = NULL;
  size_t len = 0;
  ssize_t read;
  while ((read = getline(&buffer, &len, file)) != -1) {
    // Parse the resume string
    char *line = strtok(buffer, "\n");
    while (line != NULL) {
      // Parse the name
      if (strstr(line, "Name:") != NULL) {
        resume->name = strdup(strtok(line, ":"));
      }

      // Parse the email
      else if (strstr(line, "Email:") != NULL) {
        resume->email = strdup(strtok(line, ":"));
      }

      // Parse the phone
      else if (strstr(line, "Phone:") != NULL) {
        resume->phone = strdup(strtok(line, ":"));
      }

      // Parse the address
      else if (strstr(line, "Address:") != NULL) {
        resume->address = strdup(strtok(line, ":"));
      }

      // Parse the skills
      else if (strstr(line, "Skills:") != NULL) {
        resume->skills = strdup(strtok(line, ":"));
      }

      // Parse the experience
      else if (strstr(line, "Experience:") != NULL) {
        resume->experience = strdup(strtok(line, ":"));
      }

      // Parse the education
      else if (strstr(line, "Education:") != NULL) {
        resume->education = strdup(strtok(line, ":"));
      }

      // Move to the next line
      line = strtok(NULL, "\n");
    }
  }

  // Close the resume file
  fclose(file);

  // Return 0 if the resume was parsed successfully
  return 0;
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user provided a resume file
  if (argc < 2) {
    printf("Usage: %s <resume_file>\n", argv[0]);
    return -1;
  }

  // Parse the resume file
  resume_t resume;
  int error = parse_resume(&resume, argv[1]);
  if (error != 0) {
    return error;
  }

  // Print the resume
  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Address: %s\n", resume.address);
  printf("Skills: %s\n", resume.skills);
  printf("Experience: %s\n", resume.experience);
  printf("Education: %s\n", resume.education);

  // Free the resume memory
  free(resume.name);
  free(resume.email);
  free(resume.phone);
  free(resume.address);
  free(resume.skills);
  free(resume.experience);
  free(resume.education);

  // Return 0 if the program exited successfully
  return 0;
}