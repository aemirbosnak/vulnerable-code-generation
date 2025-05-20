//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cv {
  char name[20];
  int age;
  char occupation[20];
  struct Cv* next;
} Cv;

void parse_resume(Cv* cv) {
  FILE* fp;
  char line[1024];

  fp = fopen("resume.txt", "r");
  if (fp == NULL) {
    return;
  }

  while (fgets(line, 1024, fp) != NULL) {
    char* name = strstr(line, "Name:");
    char* age = strstr(line, "Age:");
    char* occupation = strstr(line, "Occupation:");

    if (name) {
      strcpy(cv->name, name + 5);
    }
    if (age) {
      cv->age = atoi(age + 4);
    }
    if (occupation) {
      strcpy(cv->occupation, occupation + 9);
    }

    cv = cv->next;
  }

  fclose(fp);
}

int main() {
  Cv* head = NULL;
  parse_resume(head);

  while (head) {
    printf("Name: %s, Age: %d, Occupation: %s\n", head->name, head->age, head->occupation);
    head = head->next;
  }

  return 0;
}