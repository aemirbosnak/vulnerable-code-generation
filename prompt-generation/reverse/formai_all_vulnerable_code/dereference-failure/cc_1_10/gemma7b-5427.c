//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct Line {
  char *text;
  struct Line *next;
} Line;

void print_lines(Line *head) {
  Line *current = head;
  while (current) {
    printf("%s\n", current->text);
    current = current->next;
  }
}

int main() {
  Line *head = NULL;
  char line[MAX_LINES];

  // Allocate memory for the first line
  head = malloc(sizeof(Line));
  head->text = malloc(MAX_LINES);

  // Get the first line
  printf("Enter the first line: ");
  fgets(line, MAX_LINES, stdin);

  // Copy the line into the first line
  strcpy(head->text, line);

  // Add the first line to the head of the list
  head->next = NULL;

  // Allocate memory for the second line
  Line *second = malloc(sizeof(Line));
  second->text = malloc(MAX_LINES);

  // Get the second line
  printf("Enter the second line: ");
  fgets(line, MAX_LINES, stdin);

  // Copy the line into the second line
  strcpy(second->text, line);

  // Add the second line to the list
  head->next = second;

  // Print the lines
  print_lines(head);

  return 0;
}