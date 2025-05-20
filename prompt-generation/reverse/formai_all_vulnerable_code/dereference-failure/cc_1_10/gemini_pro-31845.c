//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
} Resume;

Resume *parse_resume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  Resume *resume = malloc(sizeof(Resume));
  if (resume == NULL) {
    fclose(fp);
    return NULL;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, fp)) != -1) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }

    if (strstr(line, "Name:") != NULL) {
      resume->name = strdup(line + 6);
    } else if (strstr(line, "Email:") != NULL) {
      resume->email = strdup(line + 7);
    } else if (strstr(line, "Phone:") != NULL) {
      resume->phone = strdup(line + 7);
    } else if (strstr(line, "Skills:") != NULL) {
      resume->skills = strdup(line + 8);
    } else if (strstr(line, "Experience:") != NULL) {
      resume->experience = strdup(line + 12);
    } else if (strstr(line, "Education:") != NULL) {
      resume->education = strdup(line + 11);
    }
  }

  fclose(fp);
  free(line);

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

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  Resume *resume = parse_resume(argv[1]);
  if (resume == NULL) {
    printf("Error parsing resume\n");
    return 1;
  }

  print_resume(resume);

  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->skills);
  free(resume->experience);
  free(resume->education);
  free(resume);

  return 0;
}