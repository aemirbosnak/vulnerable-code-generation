//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
  char *name;
  char *email;
  char *phone;
  char *skills[10];
  char *education[5];
  char *experience[10];
} Applicant;

Applicant *create_new_applicant() {
  Applicant *new_applicant = malloc(sizeof(Applicant));
  new_applicant->name = NULL;
  new_applicant->email = NULL;
  new_applicant->phone = NULL;
  for (int i = 0; i < 10; i++) {
    new_applicant->skills[i] = NULL;
  }
  for (int i = 0; i < 5; i++) {
    new_applicant->education[i] = NULL;
  }
  for (int i = 0; i < 10; i++) {
    new_applicant->experience[i] = NULL;
  }
  return new_applicant;
}

void parse_text(char *text, Applicant *applicant) {
  char *token = strtok(text, "\n");
  while (token != NULL) {
    if (strstr(token, "Name:")) {
      applicant->name = strtok(token + 5, "\n");
    } else if (strstr(token, "Email:")) {
      applicant->email = strtok(token + 6, "\n");
    } else if (strstr(token, "Phone:")) {
      applicant->phone = strtok(token + 6, "\n");
    } else if (strstr(token, "Skills:")) {
      token = strtok(NULL, "\n");
      int i = 0;
      while (strstr(token, "\t")) {
        applicant->skills[i++] = strtok(token + 1, "\n");
        token = strtok(NULL, "\n");
      }
    } else if (strstr(token, "Education:")) {
      token = strtok(NULL, "\n");
      int i = 0;
      while (strstr(token, "\t")) {
        applicant->education[i++] = strtok(token + 1, "\n");
        token = strtok(NULL, "\n");
      }
    } else if (strstr(token, "Experience:")) {
      token = strtok(NULL, "\n");
      int i = 0;
      while (strstr(token, "\t")) {
        applicant->experience[i++] = strtok(token + 1, "\n");
        token = strtok(NULL, "\n");
      }
    }
    token = strtok(NULL, "\n");
  }
}

void print_applicant_info(Applicant *applicant) {
  printf("Applicant Name: %s\n", applicant->name);
  printf("Applicant E-mail: %s\n", applicant->email);
  printf("Applicant Phone: %s\n", applicant->phone);
  printf("Applicant Skills:\n");
  for (int i = 0; applicant->skills[i] != NULL; i++) {
    printf("%s\n", applicant->skills[i]);
  }
  printf("Applicant Education:\n");
  for (int i = 0; applicant->education[i] != NULL; i++) {
    printf("%s\n", applicant->education[i]);
  }
  printf("Applicant Experience:\n");
  for (int i = 0; applicant->experience[i] != NULL; i++) {
    printf("%s\n", applicant->experience[i]);
  }
}

int main() {
  char resume_text[MAX_BUFFER_SIZE];
  fgets(resume_text, MAX_BUFFER_SIZE, stdin);

  Applicant *applicant = create_new_applicant();
  parse_text(resume_text, applicant);
  print_applicant_info(applicant);

  free(applicant);
  return 0;
}