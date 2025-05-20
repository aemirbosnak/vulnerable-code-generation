//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to store resume data
typedef struct Resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
} Resume;

// Function to parse a resume file and extract data
Resume *parse_resume(char *filename) {
  // Open the resume file for reading
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening resume file\n");
    return NULL;
  }

  // Read the contents of the file into a buffer
  char *buffer = NULL;
  size_t size = 0;
  getline(&buffer, &size, file);

  // Create a new resume object
  Resume *resume = malloc(sizeof(Resume));

  // Extract the resume data from the buffer
  char *line = strtok(buffer, "\n");
  while (line != NULL) {
    if (strstr(line, "Name:")) {
      resume->name = strdup(line + 6);
    } else if (strstr(line, "Email:")) {
      resume->email = strdup(line + 7);
    } else if (strstr(line, "Phone:")) {
      resume->phone = strdup(line + 7);
    } else if (strstr(line, "Skills:")) {
      resume->skills = strdup(line + 8);
    } else if (strstr(line, "Experience:")) {
      resume->experience = strdup(line + 12);
    } else if (strstr(line, "Education:")) {
      resume->education = strdup(line + 11);
    }
    line = strtok(NULL, "\n");
  }

  // Close the file
  fclose(file);

  // Return the parsed resume
  return resume;
}

// Function to print the resume data
void print_resume(Resume *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
  printf("Education: %s\n", resume->education);
}

int main() {
  // Parse a resume file
  Resume *resume = parse_resume("resume.txt");

  // Print the parsed resume
  print_resume(resume);

  // Free the allocated memory
  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->skills);
  free(resume->experience);
  free(resume->education);
  free(resume);

  return 0;
}