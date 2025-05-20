//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

Node *newNode(char *data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = strdup(data);
  node->next = NULL;
  return node;
}

void parseXML(char *xml_data) {
  char *buffer = malloc(MAX_BUFFER_SIZE);
  int i = 0;
  Node *head = NULL;

  while (xml_data[i] != '\0') {
    char tag[256];
    int j = 0;

    // Extract tag
    for (j = i; xml_data[j] != '<' && xml_data[j] != '\0'; j++) {
      tag[j] = xml_data[j];
    }
    tag[j] = '\0';

    // Create a new node
    Node *node = newNode(tag);

    // Insert the node into the head
    if (head == NULL) {
      head = node;
    } else {
      node->next = head;
      head = node;
    }

    // Skip the tag and its contents
    i += 2;

    // Free the buffer
    free(buffer);
  }

  // Print the nodes
  Node *current = head;
  while (current) {
    printf("%s\n", current->data);
    current = current->next;
  }

  // Free the nodes
  free(head);
}

int main() {
  char xml_data[] = "<root><person><name>John Doe</name><age>30</age></person></root>";
  parseXML(xml_data);
  return 0;
}