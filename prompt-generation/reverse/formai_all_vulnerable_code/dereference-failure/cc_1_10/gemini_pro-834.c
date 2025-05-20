//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the resume structure
typedef struct resume {
  char* name;
  char* email;
  char* phone;
  char* address;
  char* skills;
  char* experience;
  char* education;
} resume;

// Parse the resume from a file
resume* parse_resume(char* filename) {
  // Open the file
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Read the file into a buffer
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);
  char* buffer = malloc(size + 1);
  fread(buffer, size, 1, file);
  buffer[size] = '\0';

  // Close the file
  fclose(file);

  // Parse the buffer into a resume struct
  resume* resume = malloc(sizeof(resume));
  resume->name = strtok(buffer, "\n");
  resume->email = strtok(NULL, "\n");
  resume->phone = strtok(NULL, "\n");
  resume->address = strtok(NULL, "\n");
  resume->skills = strtok(NULL, "\n");
  resume->experience = strtok(NULL, "\n");
  resume->education = strtok(NULL, "\n");

  // Return the resume struct
  return resume;
}

// Print the resume to the console
void print_resume(resume* resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Address: %s\n", resume->address);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
  printf("Education: %s\n", resume->education);
}

// Free the memory allocated for the resume
void free_resume(resume* resume) {
  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->address);
  free(resume->skills);
  free(resume->experience);
  free(resume->education);
  free(resume);
}

// Main function
int main() {
  // Parse the resume from a file
  resume* resume = parse_resume("resume.txt");

  // Print the resume to the console
  print_resume(resume);

  // Free the memory allocated for the resume
  free_resume(resume);

  return 0;
}