//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
  char *phone;
  char **skills;
  int num_skills;
} candidate;

candidate *parse_resume(char *filename) {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  candidate *c = malloc(sizeof(candidate));

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    return NULL;
  }

  while (getline(&line, &len, fp) != -1) {
    char *token;
    token = strtok(line, ":");
    if (strcmp(token, "Name") == 0) {
      token = strtok(NULL, "\n");
      c->name = strdup(token);
    } else if (strcmp(token, "Email") == 0) {
      token = strtok(NULL, "\n");
      c->email = strdup(token);
    } else if (strcmp(token, "Phone") == 0) {
      token = strtok(NULL, "\n");
      c->phone = strdup(token);
    } else if (strcmp(token, "Skills") == 0) {
      int num_skills = 0;
      char **skills = NULL;
      token = strtok(NULL, "\n");
      while (token) {
        num_skills++;
        skills = realloc(skills, sizeof(char *) * num_skills);
        skills[num_skills - 1] = strdup(token);
        token = strtok(NULL, ", ");
      }
      c->skills = skills;
      c->num_skills = num_skills;
    }
  }

  fclose(fp);
  return c;
}

void print_candidate(candidate *c) {
  printf("Name: %s\n", c->name);
  printf("Email: %s\n", c->email);
  printf("Phone: %s\n", c->phone);
  printf("Skills: ");
  for (int i = 0; i < c->num_skills; i++) {
    printf("%s ", c->skills[i]);
  }
  printf("\n");
}

int main() {
  candidate *c = parse_resume("resume.txt");
  if (c == NULL) {
    return 1;
  }

  print_candidate(c);

  free(c->name);
  free(c->email);
  free(c->phone);
  for (int i = 0; i < c->num_skills; i++) {
    free(c->skills[i]);
  }
  free(c->skills);
  free(c);

  return 0;
}