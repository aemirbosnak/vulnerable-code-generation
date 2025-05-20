//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare a struct to store the resume information
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *experience;
  char *education;
  char *awards;
} resume_t;

// Declare a function to read a resume from a file
resume_t *read_resume(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Allocate memory for the resume
  resume_t *resume = malloc(sizeof(resume_t));
  if (resume == NULL) {
    fclose(file);
    return NULL;
  }

  // Read the resume from the file
  char *line = NULL;
  size_t len = 0;
  while (getline(&line, &len, file) != -1) {
    // Parse the line
    char *key = strtok(line, ":");
    char *value = strtok(NULL, "\n");
    if (key == NULL || value == NULL) {
      continue;
    }

    // Store the value in the resume struct
    if (strcmp(key, "name") == 0) {
      resume->name = strdup(value);
    } else if (strcmp(key, "email") == 0) {
      resume->email = strdup(value);
    } else if (strcmp(key, "phone") == 0) {
      resume->phone = strdup(value);
    } else if (strcmp(key, "address") == 0) {
      resume->address = strdup(value);
    } else if (strcmp(key, "skills") == 0) {
      resume->skills = strdup(value);
    } else if (strcmp(key, "experience") == 0) {
      resume->experience = strdup(value);
    } else if (strcmp(key, "education") == 0) {
      resume->education = strdup(value);
    } else if (strcmp(key, "awards") == 0) {
      resume->awards = strdup(value);
    }
  }

  // Close the file
  fclose(file);

  // Return the resume
  return resume;
}

// Declare a function to print a resume
void print_resume(resume_t *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Address: %s\n", resume->address);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
  printf("Education: %s\n", resume->education);
  printf("Awards: %s\n", resume->awards);
}

// Declare a function to free the memory allocated for a resume
void free_resume(resume_t *resume) {
  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->address);
  free(resume->skills);
  free(resume->experience);
  free(resume->education);
  free(resume->awards);
  free(resume);
}

// Declare a function to compare two resumes
int compare_resumes(resume_t *resume1, resume_t *resume2) {
  int result = strcmp(resume1->name, resume2->name);
  if (result == 0) {
    result = strcmp(resume1->email, resume2->email);
  }
  if (result == 0) {
    result = strcmp(resume1->phone, resume2->phone);
  }
  if (result == 0) {
    result = strcmp(resume1->address, resume2->address);
  }
  if (result == 0) {
    result = strcmp(resume1->skills, resume2->skills);
  }
  if (result == 0) {
    result = strcmp(resume1->experience, resume2->experience);
  }
  if (result == 0) {
    result = strcmp(resume1->education, resume2->education);
  }
  if (result == 0) {
    result = strcmp(resume1->awards, resume2->awards);
  }
  return result;
}

// Declare a function to search for a resume in a list of resumes
resume_t *search_resumes(resume_t *resumes, int num_resumes, char *name) {
  for (int i = 0; i < num_resumes; i++) {
    if (strcmp(resumes[i].name, name) == 0) {
      return &resumes[i];
    }
  }
  return NULL;
}

// Declare a function to sort a list of resumes
void sort_resumes(resume_t *resumes, int num_resumes) {
  for (int i = 0; i < num_resumes; i++) {
    for (int j = i + 1; j < num_resumes; j++) {
      if (compare_resumes(&resumes[i], &resumes[j]) > 0) {
        resume_t temp = resumes[i];
        resumes[i] = resumes[j];
        resumes[j] = temp;
      }
    }
  }
}

// Declare a function to print a list of resumes
void print_resumes(resume_t *resumes, int num_resumes) {
  for (int i = 0; i < num_resumes; i++) {
    print_resume(&resumes[i]);
    printf("\n");
  }
}

// Declare a function to main
int main() {
  // Read the resumes from the files
  resume_t *resumes[4];
  resumes[0] = read_resume("resume1.txt");
  resumes[1] = read_resume("resume2.txt");
  resumes[2] = read_resume("resume3.txt");
  resumes[3] = read_resume("resume4.txt");

  // Print the resumes
  printf("Original Resumes:\n");
  print_resumes(resumes, 4);

  // Sort the resumes
  sort_resumes(resumes, 4);

  // Print the sorted resumes
  printf("Sorted Resumes:\n");
  print_resumes(resumes, 4);

  // Search for a resume
  resume_t *resume = search_resumes(resumes, 4, "John Doe");
  if (resume != NULL) {
    printf("Found Resume:\n");
    print_resume(resume);
  } else {
    printf("Resume not found.\n");
  }

  // Free the memory allocated for the resumes
  for (int i = 0; i < 4; i++) {
    free_resume(resumes[i]);
  }

  return 0;
}