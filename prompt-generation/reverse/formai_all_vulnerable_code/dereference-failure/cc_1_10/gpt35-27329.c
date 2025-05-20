//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* name;
  char* email;
  char* skills[10];
} Resume;

int main() {
  printf("Welcome to my C Resume Parsing System!\n");

  // Let's create a sample resume to test the system
  Resume sample = {
    .name = "John Doe",
    .email = "jdoe@email.com",
    .skills = { "C", "Python", "Data Analysis" }
  };

  // Let's print the sample resume
  printf("\n\nPrinting Sample Resume:\n");
  printf("Name: %s\n", sample.name);
  printf("Email: %s\n", sample.email);
  printf("Skills: ");
  for (int i = 0; i < 3; i++) {
    printf("%s, ", sample.skills[i]);
  }

  // Let's ask the user for their resume
  printf("\n\nPlease enter your resume:\n");

  char* input = malloc(1000 * sizeof(char));
  fgets(input, 1000, stdin);

  // Let's parse the information from the user's resume
  char* name_start = strstr(input, "name: ");
  char* name_end = strstr(name_start, "\n");
  char* email_start = strstr(input, "email: ");
  char* email_end = strstr(email_start, "\n");
  char* skills_start = strstr(input, "skills: ");
  char* skills_end = strstr(skills_start, "\n");

  char* name = malloc((name_end - name_start) * sizeof(char));
  strncpy(name, name_start + 6, name_end - name_start - 6);
  char* email = malloc((email_end - email_start) * sizeof(char));
  strncpy(email, email_start + 7, email_end - email_start - 7);
  char* skills_temp = malloc((skills_end - skills_start) * sizeof(char));
  strncpy(skills_temp, skills_start + 8, skills_end - skills_start - 8);

  // Let's tokenize the skills input
  char delimiters[] = ", ";
  char* token = strtok(skills_temp, delimiters);
  char* skills[10];
  int skill_count = 0;

  while (token != NULL) {
    skills[skill_count] = token;
    skill_count++;
    token = strtok(NULL, delimiters);
  }

  free(skills_temp);

  // Let's create the user's resume struct
  Resume user_resume = {
    .name = name,
    .email = email,
    .skills = {0}
  };

  for (int i = 0; i < skill_count; i++) {
    user_resume.skills[i] = skills[i];
  }

  // Let's print the user's resume
  printf("\n\nPrinting User's Resume:\n");
  printf("Name: %s\n", user_resume.name);
  printf("Email: %s\n", user_resume.email);
  printf("Skills: ");
  for (int i = 0; i < skill_count; i++) {
    printf("%s, ", user_resume.skills[i]);
  }

  // Let's free the memory we allocated
  free(name);
  free(email);
  free(input);

  return 0;
}