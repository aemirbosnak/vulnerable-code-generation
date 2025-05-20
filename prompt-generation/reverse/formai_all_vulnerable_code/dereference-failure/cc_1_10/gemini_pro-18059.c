//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
} resume;

int parse_resume(char *filename, resume *r) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  char *buffer = malloc(1024);
  while (fgets(buffer, 1024, fp) != NULL) {
    if (strstr(buffer, "Name:") != NULL) {
      r->name = strdup(buffer + 5);
    } else if (strstr(buffer, "Email:") != NULL) {
      r->email = strdup(buffer + 6);
    } else if (strstr(buffer, "Phone:") != NULL) {
      r->phone = strdup(buffer + 6);
    } else if (strstr(buffer, "Skills:") != NULL) {
      r->skills = strdup(buffer + 7);
    }
  }

  free(buffer);
  fclose(fp);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  resume r;
  if (parse_resume(argv[1], &r) != 0) {
    return -1;
  }

  printf("Name: %s\n", r.name);
  printf("Email: %s\n", r.email);
  printf("Phone: %s\n", r.phone);
  printf("Skills: %s\n", r.skills);

  free(r.name);
  free(r.email);
  free(r.phone);
  free(r.skills);

  return 0;
}