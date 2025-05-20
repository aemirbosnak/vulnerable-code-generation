//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
  char name[50];
  char experience[100];
  char education[100];
  char skills[500];
};

void print_resume(struct Resume *resume) {
  printf("Name: %s\n", resume->name);
  printf("Experience: %s\n", resume->experience);
  printf("Education: %s\n", resume->education);
  printf("Skills: %s\n", resume->skills);
}

int parse_resume(char *filename, struct Resume *resume) {
  FILE *fp;
  char buffer[1000];
  char *token;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Unable to open file %s\n", filename);
    return 0;
  }

  while (fgets(buffer, 1000, fp)) {
    token = strtok(buffer, " :");
    if (strcmp(token, "Name") == 0) {
      token = strtok(NULL, "\n");
      strcpy(resume->name, token);
    } else if (strcmp(token, "Experience") == 0) {
      token = strtok(NULL, "\n");
      strcpy(resume->experience, token);
    } else if (strcmp(token, "Education") == 0) {
      token = strtok(NULL, "\n");
      strcpy(resume->education, token);
    } else if (strcmp(token, "Skills") == 0) {
      token = strtok(NULL, "\n");
      strcpy(resume->skills, token);
    }
  }

  fclose(fp);
  return 1;
}

int main() {
  struct Resume my_resume;

  if (parse_resume("myresume.txt", &my_resume)) {
    print_resume(&my_resume);
  }

  return 0;
}