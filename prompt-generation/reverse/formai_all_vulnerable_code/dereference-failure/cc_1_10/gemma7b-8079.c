//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

Node *append(Node *head, char *data) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = strdup(data);
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    head->next = new_node;
  }

  return head;
}

void xml_parser(char *xml_data) {
  Node *head = NULL;
  char *current_element = NULL;

  for (int i = 0; xml_data[i] != '\0'; i++) {
    char element_start = xml_data[i];

    if (element_start == '<') {
      current_element = xml_data + i + 1;
    } else if (element_start == '>') {
      append(head, current_element);
      current_element = NULL;
    }
  }

  printf("Elements:");
  for (Node *node = head; node != NULL; node = node->next) {
    printf(" %s", node->data);
  }

  printf("\n");
}

int main() {
  char xml_data[] = "<foo><bar>baz</bar></foo>";
  xml_parser(xml_data);

  return 0;
}