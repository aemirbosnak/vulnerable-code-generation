//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *experience;
  char *education;
} resume;

resume *parse_resume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  resume *r = malloc(sizeof(resume));
  r->name = NULL;
  r->email = NULL;
  r->phone = NULL;
  r->address = NULL;
  r->skills = NULL;
  r->experience = NULL;
  r->education = NULL;

  while ((read = getline(&line, &len, fp)) != -1) {
    if (strncmp(line, "Name:", 5) == 0) {
      r->name = strdup(line + 5);
    } else if (strncmp(line, "Email:", 6) == 0) {
      r->email = strdup(line + 6);
    } else if (strncmp(line, "Phone:", 6) == 0) {
      r->phone = strdup(line + 6);
    } else if (strncmp(line, "Address:", 8) == 0) {
      r->address = strdup(line + 8);
    } else if (strncmp(line, "Skills:", 7) == 0) {
      r->skills = strdup(line + 7);
    } else if (strncmp(line, "Experience:", 11) == 0) {
      r->experience = strdup(line + 11);
    } else if (strncmp(line, "Education:", 10) == 0) {
      r->education = strdup(line + 10);
    }
  }

  free(line);
  fclose(fp);

  return r;
}

void print_resume(resume *r) {
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n", r->phone);
  printf("Address: %s\n", r->address);
  printf("Skills: %s\n", r->skills);
  printf("Experience: %s\n", r->experience);
  printf("Education: %s\n", r->education);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  resume *r = parse_resume(argv[1]);
  if (r == NULL) {
    fprintf(stderr, "Error parsing resume\n");
    return EXIT_FAILURE;
  }

  print_resume(r);

  free(r->name);
  free(r->email);
  free(r->phone);
  free(r->address);
  free(r->skills);
  free(r->experience);
  free(r->education);
  free(r);

  return EXIT_SUCCESS;
}