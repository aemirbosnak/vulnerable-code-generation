//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void beautify_html(Node* head) {
  int i = 0;
  char buffer[MAX_BUFFER_SIZE];
  buffer[0] = '\0';

  while (head) {
    switch (head->data) {
      case 'h':
      case 'H':
        strcat(buffer, "<h");
        break;
      case 'p':
      case 'P':
        strcat(buffer, "<p>");
        break;
      case 'b':
      case 'B':
        strcat(buffer, "<b>");
        break;
      case 'i':
      case 'I':
        strcat(buffer, "<i>");
        break;
      case 'u':
      case 'U':
        strcat(buffer, "<u>");
        break;
      default:
        strcat(buffer, "");
    }

    sprintf(buffer + strlen(buffer), " %c ", head->data);

    if (i) {
      strcat(buffer, ",");
    }

    i++;

    head = head->next;
  }

  printf("%s", buffer);
}

int main() {
  Node* head = NULL;

  // Create a sample linked list
  head = malloc(sizeof(Node));
  head->data = 'H';
  head->next = malloc(sizeof(Node));
  head->next->data = 'p';
  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 'b';
  head->next->next->next = malloc(sizeof(Node));
  head->next->next->next->data = 'i';

  beautify_html(head);

  return 0;
}