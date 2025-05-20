//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
};

struct resume *parse_resume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  struct resume *resume = malloc(sizeof(struct resume));
  if (resume == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return NULL;
  }

  while ((read = getline(&line, &len, fp)) != -1) {
    if (strstr(line, "Name:")) {
      resume->name = strdup(line + 6);
    } else if (strstr(line, "Email:")) {
      resume->email = strdup(line + 7);
    } else if (strstr(line, "Phone:")) {
      resume->phone = strdup(line + 7);
    } else if (strstr(line, "Skills:")) {
      resume->skills = strdup(line + 8);
    } else if (strstr(line, "Experience:")) {
      resume->experience = strdup(line + 12);
    } else if (strstr(line, "Education:")) {
      resume->education = strdup(line + 11);
    }
  }

  fclose(fp);
  return resume;
}

void print_resume(struct resume *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
  printf("Education: %s\n", resume->education);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct resume *resume = parse_resume(argv[1]);
  if (resume == NULL) {
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

  return EXIT_SUCCESS;
}