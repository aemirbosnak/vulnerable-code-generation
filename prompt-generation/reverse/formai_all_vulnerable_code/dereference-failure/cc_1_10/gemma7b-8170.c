//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EXPERIENCE_LENGTH 200

typedef struct resume_node {
  char name[MAX_NAME_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];
  struct resume_node* next;
} resume_node;

resume_node* parse_resume(FILE* resume_file) {
  resume_node* head = NULL;
  char line[MAX_NAME_LENGTH];
  char* name;
  char* experience;

  // Read the resume file line by line
  while (fgets(line, MAX_NAME_LENGTH, resume_file) != NULL) {
    // Extract the name and experience from the line
    name = strchr(line, ':') + 1;
    experience = strchr(name, ';') - name;

    // Allocate a new resume node
    resume_node* new_node = malloc(sizeof(resume_node));

    // Copy the name and experience into the node
    strcpy(new_node->name, name);
    strcpy(new_node->experience, experience);

    // Add the node to the head of the list
    if (head == NULL) {
      head = new_node;
    } else {
      new_node->next = head;
      head = new_node;
    }
  }

  return head;
}

int main() {
  FILE* resume_file = fopen("resume.txt", "r");
  resume_node* head = parse_resume(resume_file);

  // Print the name and experience of each node
  for (resume_node* node = head; node != NULL; node = node->next) {
    printf("Name: %s\n", node->name);
    printf("Experience: %s\n", node->experience);
    printf("\n");
  }

  fclose(resume_file);

  return 0;
}