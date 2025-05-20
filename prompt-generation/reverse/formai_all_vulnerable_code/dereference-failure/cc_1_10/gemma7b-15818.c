//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void beautify_html(char* str) {
  Node* head = NULL;
  Node* tail = NULL;
  int i = 0;

  for (i = 0; str[i] != '\0'; i++) {
    char current_char = str[i];
    if (head == NULL) {
      head = tail = malloc(sizeof(Node));
      head->data = current_char;
      head->next = NULL;
    } else {
      tail->next = malloc(sizeof(Node));
      tail = tail->next;
      tail->data = current_char;
      tail->next = NULL;
    }
  }

  int line_number = 1;
  char* new_str = malloc(MAX_BUFFER_SIZE);
  tail = head;

  while (tail) {
    switch (tail->data) {
      case '<':
        sprintf(new_str, "<%d %c>\n", line_number, tail->data);
        break;
      case '(':
        sprintf(new_str, "(%d %c)\n", line_number, tail->data);
        break;
      default:
        sprintf(new_str, "%d %c\n", line_number, tail->data);
        break;
    }

    line_number++;
    tail = tail->next;
  }

  free(str);
  free(head);
  free(new_str);

  return;
}

int main() {
  char str[] = "<div><b>Hello, world!</b></div>";
  beautify_html(str);
  printf("%s", str);

  return 0;
}