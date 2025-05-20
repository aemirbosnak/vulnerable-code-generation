//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char **resume_text) {
  // Allocate memory for the parsed resume text
  char *parsed_text = malloc(strlen(*resume_text) * 2);
  if (parsed_text == NULL) {
    return;
  }

  // Remove all formatting and punctuation from the resume text
  char *p = strchr(*resume_text, ':');
  while (p) {
    *p = ' ';
    p = strchr(p, ':');
  }

  // Split the resume text into sections
  char **sections = malloc(10 * sizeof(char *));
  int section_count = 0;
  char *section_start = strstr(*resume_text, "Summary");
  while (section_start) {
    sections[section_count++] = malloc(strlen(section_start) + 1);
    strcpy(sections[section_count - 1], section_start);
    section_start = strstr(section_start, "Skills");
  }

  // Print the parsed sections
  for (int i = 0; i < section_count; i++) {
    printf("Section %d:\n", i + 1);
    printf("%s\n", sections[i]);
  }

  // Free the allocated memory
  free(parsed_text);
  free(sections);
}

int main() {
  // Get the resume text from the user
  char *resume_text = malloc(1024);
  printf("Enter the resume text: ");
  getline(resume_text, 1024, stdin);

  // Parse the resume text
  parse_resume(&resume_text);

  // Free the allocated memory
  free(resume_text);

  return 0;
}