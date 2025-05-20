//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Ada Lovelace
// Ada Lovelace's XML Parser

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the XML element types
typedef enum {
  ELEMENT_START,
  ELEMENT_END,
  ELEMENT_TEXT
} ElementType;

// Define the XML element structure
typedef struct {
  ElementType type;
  char *name;
  char *value;
} Element;

// Create a new XML element
Element *new_element(ElementType type, char *name, char *value) {
  Element *element = malloc(sizeof(Element));
  element->type = type;
  element->name = strdup(name);
  element->value = strdup(value);
  return element;
}

// Parse an XML string into a list of elements
Element **parse_xml(char *xml) {
  // Initialize the list of elements
  Element **elements = malloc(sizeof(Element *) * 100);
  int num_elements = 0;

  // Iterate over the XML string
  char *current = xml;
  while (*current != '\0') {
    // Skip whitespace
    while (*current == ' ' || *current == '\t' || *current == '\n' || *current == '\r') {
      current++;
    }

    // Check for the start of an element
    if (*current == '<') {
      // Get the element name
      char *name = current + 1;
      while (*current != '>' && *current != '\0') {
        current++;
      }
      *current = '\0';

      // Get the element value
      char *value = NULL;
      if (*current == '>') {
        current++;
        value = current;
        while (*current != '<' && *current != '\0') {
          current++;
        }
        *current = '\0';
      }

      // Create the element
      Element *element = new_element(ELEMENT_START, name, value);

      // Add the element to the list
      elements[num_elements++] = element;
    }

    // Check for the end of an element
    else if (*current == '/') {
      // Get the element name
      char *name = current + 1;
      while (*current != '>' && *current != '\0') {
        current++;
      }
      *current = '\0';

      // Create the element
      Element *element = new_element(ELEMENT_END, name, NULL);

      // Add the element to the list
      elements[num_elements++] = element;
    }

    // Skip to the next character
    current++;
  }

  // Return the list of elements
  return elements;
}

// Print the XML elements
void print_elements(Element **elements) {
  int i;
  for (i = 0; elements[i] != NULL; i++) {
    Element *element = elements[i];
    switch (element->type) {
      case ELEMENT_START:
        printf("<%s>", element->name);
        break;
      case ELEMENT_END:
        printf("</%s>", element->name);
        break;
      case ELEMENT_TEXT:
        printf("%s", element->value);
        break;
    }
  }
}

// Free the XML elements
void free_elements(Element **elements) {
  int i;
  for (i = 0; elements[i] != NULL; i++) {
    Element *element = elements[i];
    free(element->name);
    free(element->value);
    free(element);
  }
  free(elements);
}

// Main function
int main() {
  // Parse the XML string
  char *xml = "<root><child>Hello world!</child></root>";
  Element **elements = parse_xml(xml);

  // Print the XML elements
  print_elements(elements);

  // Free the XML elements
  free_elements(elements);

  return 0;
}