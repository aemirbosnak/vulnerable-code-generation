//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *experience;
  char *education;
  struct resume *next;
} resume;

resume *parse_resume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    return NULL;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  resume *head = NULL;
  resume *current = NULL;

  while ((read = getline(&line, &len, fp)) != -1) {
    if (line[read - 1] == '\n') {
      line[read - 1] = '\0';
    }

    if (current == NULL) {
      current = malloc(sizeof(resume));
      if (current == NULL) {
        perror("malloc");
        return NULL;
      }
      memset(current, 0, sizeof(resume));
      head = current;
    } else {
      current->next = malloc(sizeof(resume));
      if (current->next == NULL) {
        perror("malloc");
        return NULL;
      }
      memset(current->next, 0, sizeof(resume));
      current = current->next;
    }

    if (strncmp(line, "Name:", 5) == 0) {
      current->name = strdup(line + 5);
    } else if (strncmp(line, "Email:", 6) == 0) {
      current->email = strdup(line + 6);
    } else if (strncmp(line, "Phone:", 6) == 0) {
      current->phone = strdup(line + 6);
    } else if (strncmp(line, "Address:", 8) == 0) {
      current->address = strdup(line + 8);
    } else if (strncmp(line, "Skills:", 7) == 0) {
      current->skills = strdup(line + 7);
    } else if (strncmp(line, "Experience:", 11) == 0) {
      current->experience = strdup(line + 11);
    } else if (strncmp(line, "Education:", 10) == 0) {
      current->education = strdup(line + 10);
    }
  }

  free(line);
  fclose(fp);

  return head;
}

void print_resume(resume *head) {
  resume *current = head;
  while (current != NULL) {
    printf("Name: %s\n", current->name);
    printf("Email: %s\n", current->email);
    printf("Phone: %s\n", current->phone);
    printf("Address: %s\n", current->address);
    printf("Skills: %s\n", current->skills);
    printf("Experience: %s\n", current->experience);
    printf("Education: %s\n\n", current->education);
    current = current->next;
  }
}

void free_resume(resume *head) {
  resume *current = head;
  while (current != NULL) {
    resume *next = current->next;
    free(current->name);
    free(current->email);
    free(current->phone);
    free(current->address);
    free(current->skills);
    free(current->experience);
    free(current->education);
    free(current);
    current = next;
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  resume *head = parse_resume(argv[1]);
  if (head == NULL) {
    perror("parse_resume");
    return EXIT_FAILURE;
  }

  print_resume(head);
  free_resume(head);

  return EXIT_SUCCESS;
}