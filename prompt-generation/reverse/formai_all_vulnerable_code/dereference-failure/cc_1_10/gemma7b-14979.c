//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: protected
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
  char buffer[MAX_BUFFER_SIZE];
  int index = 0;
  Node *head = NULL;

  while (xml_data[index] != '\0') {
    char tag[MAX_BUFFER_SIZE];
    int tag_length = 0;

    // Read the tag
    while (xml_data[index] != '<' && xml_data[index] != '\0') {
      tag[tag_length++] = xml_data[index];
      index++;
    }

    // Allocate memory for the node
    Node *node = newNode(tag);

    // Insert the node into the linked list
    if (head == NULL) {
      head = node;
    } else {
      node->next = head;
      head = node;
    }

    // Read the closing tag
    while (xml_data[index] != '>' && xml_data[index] != '\0') {
      index++;
    }

    // Increment the index
    index++;
  }

  // Print the nodes
  Node *current = head;
  while (current) {
    printf("%s\n", current->data);
    current = current->next;
  }
}

int main() {
  char xml_data[] = "<foo><bar>Hello, world!</bar></foo>";
  parseXML(xml_data);

  return 0;
}