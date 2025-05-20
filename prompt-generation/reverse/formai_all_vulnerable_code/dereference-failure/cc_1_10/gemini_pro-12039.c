//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *education;
  char *experience;
};

struct resume *parse_resume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  struct resume *resume = malloc(sizeof(struct resume));
  if (resume == NULL) {
    fclose(fp);
    return NULL;
  }

  resume->name = NULL;
  resume->email = NULL;
  resume->phone = NULL;
  resume->address = NULL;
  resume->skills = NULL;
  resume->education = NULL;
  resume->experience = NULL;

  while ((read = getline(&line, &len, fp)) != -1) {
    if (strstr(line, "Name:")) {
      resume->name = strdup(strchr(line, ':') + 1);
    } else if (strstr(line, "Email:")) {
      resume->email = strdup(strchr(line, ':') + 1);
    } else if (strstr(line, "Phone:")) {
      resume->phone = strdup(strchr(line, ':') + 1);
    } else if (strstr(line, "Address:")) {
      resume->address = strdup(strchr(line, ':') + 1);
    } else if (strstr(line, "Skills:")) {
      resume->skills = strdup(strchr(line, ':') + 1);
    } else if (strstr(line, "Education:")) {
      resume->education = strdup(strchr(line, ':') + 1);
    } else if (strstr(line, "Experience:")) {
      resume->experience = strdup(strchr(line, ':') + 1);
    }
  }

  fclose(fp);
  free(line);

  return resume;
}

void print_resume(struct resume *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Address: %s\n", resume->address);
  printf("Skills: %s\n", resume->skills);
  printf("Education: %s\n", resume->education);
  printf("Experience: %s\n", resume->experience);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct resume *resume = parse_resume(argv[1]);
  if (resume == NULL) {
    fprintf(stderr, "Error: could not parse resume\n");
    return EXIT_FAILURE;
  }

  print_resume(resume);

  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->address);
  free(resume->skills);
  free(resume->education);
  free(resume->experience);
  free(resume);

  return EXIT_SUCCESS;
}