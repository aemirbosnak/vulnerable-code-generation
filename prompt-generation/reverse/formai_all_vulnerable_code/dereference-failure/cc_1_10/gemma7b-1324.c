//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 255

typedef struct Cv {
  char name[MAX_NAME_LEN];
  int age;
  struct Cv* next;
} Cv;

void parse_resume(Cv** head, char* resume_text) {
  Cv* new_cv = malloc(sizeof(Cv));
  new_cv->name[0] = '\0';
  new_cv->age = -1;

  char* name_start = strstr(resume_text, "Name:");
  char* name_end = strstr(name_start, "Age:");

  if (name_start && name_end) {
    int name_len = name_end - name_start - 1;
    memcpy(new_cv->name, name_start + 5, name_len);
    new_cv->name[name_len] = '\0';

    char* age_start = strstr(name_end, "Age:");
    char* age_end = strstr(age_start, ":");

    if (age_start && age_end) {
      new_cv->age = atoi(age_start + 5);
    }
  }

  new_cv->next = *head;
  *head = new_cv;
}

int main() {
  Cv* head = NULL;
  char* resume_text = "Name: John Doe\nAge: 25\nEducation: Bachelor's degree in Computer Science\n";

  parse_resume(&head, resume_text);

  Cv* current = head;
  while (current) {
    printf("Name: %s, Age: %d\n", current->name, current->age);
    current = current->next;
  }

  return 0;
}