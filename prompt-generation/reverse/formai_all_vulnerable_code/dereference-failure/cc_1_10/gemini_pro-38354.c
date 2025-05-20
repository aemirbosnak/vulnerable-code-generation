//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a resume
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
} resume_t;

// Define a function to parse a resume from a file
resume_t *parse_resume(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the file into a buffer
  char *buffer = NULL;
  size_t buffer_size = 0;
  ssize_t bytes_read = getline(&buffer, &buffer_size, file);
  if (bytes_read == -1) {
    perror("Error reading file");
    free(buffer);
    fclose(file);
    return NULL;
  }

  // Parse the buffer into a resume struct
  resume_t *resume = malloc(sizeof(resume_t));
  if (resume == NULL) {
    perror("Error allocating memory");
    free(buffer);
    fclose(file);
    return NULL;
  }

  // Parse the name
  char *name = strtok(buffer, "\n");
  if (name != NULL) {
    resume->name = strdup(name);
  }

  // Parse the email
  char *email = strtok(NULL, "\n");
  if (email != NULL) {
    resume->email = strdup(email);
  }

  // Parse the phone
  char *phone = strtok(NULL, "\n");
  if (phone != NULL) {
    resume->phone = strdup(phone);
  }

  // Parse the skills
  char *skills = strtok(NULL, "\n");
  if (skills != NULL) {
    resume->skills = strdup(skills);
  }

  // Parse the experience
  char *experience = strtok(NULL, "\n");
  if (experience != NULL) {
    resume->experience = strdup(experience);
  }

  // Close the file
  fclose(file);

  // Free the buffer
  free(buffer);

  // Return the resume
  return resume;
}

// Define a function to print a resume
void print_resume(resume_t *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
}

// Define a function to free a resume struct
void free_resume(resume_t *resume) {
  if (resume == NULL) {
    return;
  }

  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->skills);
  free(resume->experience);
  free(resume);
}

// Define a main function
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the resume
  resume_t *resume = parse_resume(argv[1]);
  if (resume == NULL) {
    return EXIT_FAILURE;
  }

  // Print the resume
  print_resume(resume);

  // Free the resume
  free_resume(resume);

  return EXIT_SUCCESS;
}