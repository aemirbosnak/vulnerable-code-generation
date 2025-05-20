//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

void parseXML(char *xml_data) {
  Node *head = NULL;
  char *buffer = malloc(MAX_BUFFER_SIZE);
  int i = 0;
  int state = 0; // 0 - neutral, 1 - inside tag, 2 - attribute

  for (; xml_data[i] != '\0'; i++) {
    switch (state) {
      case 0:
        if (xml_data[i] == '<') {
          state = 1;
          buffer = realloc(buffer, MAX_BUFFER_SIZE * 2);
          buffer[0] = xml_data[i];
          buffer[1] = '\0';
          head = malloc(sizeof(Node));
          head->data = buffer;
          head->next = NULL;
          buffer = buffer + MAX_BUFFER_SIZE;
        }
        break;
      case 1:
        if (xml_data[i] == '>' && buffer[0] == '<') {
          state = 0;
          head->next = malloc(sizeof(Node));
          head = head->next;
          head->data = malloc(MAX_BUFFER_SIZE);
          buffer = head->data;
          buffer[0] = '\0';
        } else {
          buffer = realloc(buffer, MAX_BUFFER_SIZE * 2);
          buffer[0] = xml_data[i];
          buffer[1] = '\0';
        }
        break;
      case 2:
        if (xml_data[i] == '>' && buffer[0] == '<') {
          state = 0;
          head->next = malloc(sizeof(Node));
          head = head->next;
          head->data = malloc(MAX_BUFFER_SIZE);
          buffer = head->data;
          buffer[0] = '\0';
        } else {
          buffer = realloc(buffer, MAX_BUFFER_SIZE * 2);
          buffer[0] = xml_data[i];
          buffer[1] = '\0';
        }
        break;
    }
  }

  free(buffer);
  free(head);
}

int main() {
  char *xml_data = "<foo bar=\"baz\">Hello, world!</foo>";
  parseXML(xml_data);

  return 0;
}