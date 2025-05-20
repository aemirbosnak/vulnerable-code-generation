//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

void append_node(Node **head, char *data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

void beautify_html(Node *head) {
  char buffer[MAX_BUFFER_SIZE];
  int i = 0;

  for (Node *curr = head; curr; curr = curr->next) {
    char *data = curr->data;

    // Indent blocks
    if (data[0] == '{' && data[1] == '}') {
      int block_depth = 0;
      for (char *p = data; *p && *p != '}' && block_depth < 3; p++) {
        if (*p == '{') {
          block_depth++;
        } else if (*p == '}') {
          block_depth--;
        }
      }
      for (int j = 0; j < block_depth; j++) {
        snprintf(buffer, MAX_BUFFER_SIZE, "  ", i);
        fprintf(stdout, "%s", buffer);
      }
    }

    // Remove unnecessary whitespaces
    char *p = data;
    char *q = data;
    while (p && *p) {
      if (*q != ' ' || *p == ' ' && *(q - 1) == '{' && *(q - 2) == '}') {
        *p = *q;
      } else {
        q++;
      }
      p++;
    }

    // Add line breaks
    if (data[0] == '}' || data[0] == ')') {
      fprintf(stdout, "\n");
    }

    // Print data
    fprintf(stdout, "%s", data);
  }
}

int main() {
  Node *head = NULL;
  append_node(&head, "<h1>Hello, world!</h1>");
  append_node(&head, "<h2>This is a heading</h2>");
  append_node(&head, "<h4>And this is a subheading</h4>");
  append_node(&head, "<p>This is a paragraph of text.</p>");
  append_node(&head, "</p>");

  beautify_html(head);

  return 0;
}