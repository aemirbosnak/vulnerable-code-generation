//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_RESUMES 100
#define MAX_FIELDS 10

// Data structures
typedef struct {
  char *name;
  char *email;
  char *phone;
  char *skills[MAX_FIELDS];
  int num_skills;
} Resume;

// Global variables
Resume resumes[MAX_RESUMES];
int num_resumes = 0;

// Function prototypes
void parse_resume(char *filename);
void print_resume(Resume *resume);
void print_summary();

// Main function
int main() {
  // Parse the resumes
  parse_resume("resumes.txt");

  // Print the resumes
  for (int i = 0; i < num_resumes; i++) {
    print_resume(&resumes[i]);
  }

  // Print the summary
  print_summary();

  return 0;
}

// Parse a resume from a file
void parse_resume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Parse the line
    char *name = strtok(line, ",");
    char *email = strtok(NULL, ",");
    char *phone = strtok(NULL, ",");

    // Create a new resume
    Resume resume;
    resume.name = strdup(name);
    resume.email = strdup(email);
    resume.phone = strdup(phone);
    resume.num_skills = 0;

    // Parse the skills
    char *skill;
    while ((skill = strtok(NULL, ",")) != NULL) {
      resume.skills[resume.num_skills] = strdup(skill);
      resume.num_skills++;
    }

    // Add the resume to the list
    resumes[num_resumes] = resume;
    num_resumes++;
  }

  fclose(fp);
}

// Print a resume
void print_resume(Resume *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills:\n");
  for (int i = 0; i < resume->num_skills; i++) {
    printf("  %s\n", resume->skills[i]);
  }
  printf("\n");
}

// Print a summary of the resumes
void print_summary() {
  // Count the number of skills
  int num_skills = 0;
  for (int i = 0; i < num_resumes; i++) {
    num_skills += resumes[i].num_skills;
  }

  // Find the most common skill
  char *most_common_skill = NULL;
  int max_count = 0;
  for (int i = 0; i < num_resumes; i++) {
    for (int j = 0; j < resumes[i].num_skills; j++) {
      int count = 0;
      for (int k = 0; k < num_resumes; k++) {
        for (int l = 0; l < resumes[k].num_skills; l++) {
          if (strcmp(resumes[i].skills[j], resumes[k].skills[l]) == 0) {
            count++;
          }
        }
      }
      if (count > max_count) {
        max_count = count;
        most_common_skill = resumes[i].skills[j];
      }
    }
  }

  // Print the summary
  printf("Number of resumes: %d\n", num_resumes);
  printf("Number of skills: %d\n", num_skills);
  printf("Most common skill: %s\n", most_common_skill);
}