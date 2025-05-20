//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *education;
  char *experience;
} Resume;

Resume *parse_resume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    return NULL;
  }

  char *buffer = NULL;
  size_t buffer_size = 0;
  getline(&buffer, &buffer_size, fp);  // Read the first line (header)

  Resume *resume = malloc(sizeof(Resume));
  if (resume == NULL) {
    perror("malloc");
    free(buffer);
    fclose(fp);
    return NULL;
  }

  resume->name = NULL;
  resume->email = NULL;
  resume->phone = NULL;
  resume->skills = NULL;
  resume->education = NULL;
  resume->experience = NULL;

  char *ptr = buffer;
  while (*ptr != '\0') {
    if (*ptr == ':') {
      *ptr = '\0';
      ptr++;
      while (*ptr == ' ') {
        ptr++;
      }
      if (strcmp(buffer, "Name") == 0) {
        resume->name = strdup(ptr);
      } else if (strcmp(buffer, "Email") == 0) {
        resume->email = strdup(ptr);
      } else if (strcmp(buffer, "Phone") == 0) {
        resume->phone = strdup(ptr);
      } else if (strcmp(buffer, "Skills") == 0) {
        resume->skills = strdup(ptr);
      } else if (strcmp(buffer, "Education") == 0) {
        resume->education = strdup(ptr);
      } else if (strcmp(buffer, "Experience") == 0) {
        resume->experience = strdup(ptr);
      }
    }
    ptr++;
  }

  free(buffer);
  fclose(fp);

  return resume;
}

void print_resume(Resume *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills: %s\n", resume->skills);
  printf("Education: %s\n", resume->education);
  printf("Experience: %s\n", resume->experience);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  Resume *resume = parse_resume(argv[1]);
  if (resume == NULL) {
    return EXIT_FAILURE;
  }

  print_resume(resume);

  free(resume->name);
  free(resume->email);
  free(resume->phone);
  free(resume->skills);
  free(resume->education);
  free(resume->experience);
  free(resume);

  return EXIT_SUCCESS;
}