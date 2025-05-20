//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100

typedef struct {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
} Resume;

Resume *parse_resume(FILE *fp) {
  Resume *resume = malloc(sizeof(Resume));
  if (resume == NULL) {
    return NULL;
  }

  char line[MAX_LINE_LENGTH];
  int line_count = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    line_count++;

    if (line_count == 1) {
      // Parse name
      resume->name = strdup(line);
    } else if (line_count == 2) {
      // Parse email
      resume->email = strdup(line);
    } else if (line_count == 3) {
      // Parse phone
      resume->phone = strdup(line);
    } else if (line_count == 4) {
      // Parse skills
      resume->skills = strdup(line);
    } else if (line_count == 5) {
      // Parse experience
      resume->experience = strdup(line);
    } else if (line_count == 6) {
      // Parse education
      resume->education = strdup(line);
    }
  }

  return resume;
}

void print_resume(Resume *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
  printf("Education: %s\n", resume->education);
}

int main() {
  FILE *fp = fopen("resume.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  Resume *resume = parse_resume(fp);
  if (resume == NULL) {
    perror("Error parsing resume");
    return EXIT_FAILURE;
  }

  print_resume(resume);

  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->skills);
  free(resume->experience);
  free(resume->education);
  free(resume);

  fclose(fp);

  return EXIT_SUCCESS;
}