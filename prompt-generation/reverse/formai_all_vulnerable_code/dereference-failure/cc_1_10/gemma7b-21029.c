//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

void parse_xml(char *xml_data) {
  Node *head = NULL;
  char *buffer = NULL;
  char *start_tag = NULL;
  char *end_tag = NULL;
  int buffer_size = 0;
  int i = 0;

  buffer = malloc(MAX_BUFFER_SIZE);
  buffer_size = MAX_BUFFER_SIZE;

  while (xml_data[i] != '\0') {
    if (buffer_size - 1 < i) {
      buffer_size *= 2;
      buffer = realloc(buffer, buffer_size);
    }

    if (xml_data[i] == '<') {
      start_tag = xml_data + i;
      end_tag = strstr(start_tag, ">");
      if (end_tag) {
        char *node_data = malloc(end_tag - start_tag - 1);
        memcpy(node_data, start_tag + 1, end_tag - start_tag - 1);
        Node *node = malloc(sizeof(Node));
        node->data = node_data;
        node->next = head;
        head = node;
      }
    }

    i++;
  }

  printf("Parsed XML data:\n");
  for (Node *node = head; node; node = node->next) {
    printf("  %s\n", node->data);
  }

  free(buffer);
  free(head);
}

int main() {
  char xml_data[] = "<root><child>Hello, world!</child></root>";
  parse_xml(xml_data);

  return 0;
}