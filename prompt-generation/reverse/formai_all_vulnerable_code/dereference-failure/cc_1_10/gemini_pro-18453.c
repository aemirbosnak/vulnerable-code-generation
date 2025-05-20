//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
} resume;

resume *parse_resume(char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("Couldn't open file %s\n", filename);
    return NULL;
  }

  resume *r = malloc(sizeof(resume));
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    if (strstr(line, "Name:")) {
      r->name = strdup(line + 6);
    } else if (strstr(line, "Email:")) {
      r->email = strdup(line + 7);
    } else if (strstr(line, "Phone:")) {
      r->phone = strdup(line + 7);
    } else if (strstr(line, "Skills:")) {
      r->skills = strdup(line + 8);
    } else if (strstr(line, "Experience:")) {
      r->experience = strdup(line + 12);
    }
  }

  fclose(file);
  return r;
}

void print_resume(resume *r) {
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n", r->phone);
  printf("Skills: %s\n", r->skills);
  printf("Experience: %s\n", r->experience);
}

int main() {
  resume *r = parse_resume("resume.txt");
  print_resume(r);
  free(r->name);
  free(r->email);
  free(r->phone);
  free(r->skills);
  free(r->experience);
  free(r);
  return 0;
}