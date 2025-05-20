//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume_t {
  char *name;
  char *position;
  char *summary;
  struct resume_t *next;
} resume_t;

resume_t *parse_resume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  resume_t *head = NULL;
  resume_t *curr = NULL;

  char line[1024];
  while (fgets(line, 1024, fp) != NULL) {
    // Remove formatting and normalize line
    char *stripped_line = strdup(line);
    stripped_line = strstr(stripped_line, ":") ? strstr(stripped_line, ":") : stripped_line;
    stripped_line = strstr(stripped_line, "-") ? strstr(stripped_line, "-") : stripped_line;
    stripped_line = strstr(stripped_line, " ") ? strstr(stripped_line, " ") : stripped_line;
    stripped_line = strstr(stripped_line, "\n") ? strstr(stripped_line, "\n") : stripped_line;

    // Extract information based on line content
    if (strstr(stripped_line, "Name:") != NULL) {
      curr = malloc(sizeof(resume_t));
      curr->name = strdup(stripped_line + 5);
      curr->position = NULL;
      curr->summary = NULL;
      if (head == NULL) {
        head = curr;
      } else {
        curr->next = head;
        head = curr;
      }
    } else if (strstr(stripped_line, "Position:") != NULL) {
      curr->position = strdup(stripped_line + 9);
    } else if (strstr(stripped_line, "Summary:") != NULL) {
      curr->summary = strdup(stripped_line + 9);
    }
  }

  fclose(fp);
  return head;
}

int main() {
  resume_t *head = parse_resume("resume.txt");

  if (head) {
    printf("Name: %s\n", head->name);
    printf("Position: %s\n", head->position);
    printf("Summary: %s\n", head->summary);
  } else {
    printf("Error parsing resume.\n");
  }

  return 0;
}