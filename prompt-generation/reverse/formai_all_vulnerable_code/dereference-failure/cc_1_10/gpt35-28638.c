//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

/* Custom data structure to hold parsed XML information */
typedef struct {
  char* element_name;
  char* element_value;
} XML_ELEMENT;

/* Function to parse a single element from the XML string */
bool parse_xml_element(char* element_string, XML_ELEMENT* parsed_element) {
  char* name_start = strchr(element_string, '<') + 1;
  char* name_end = strchr(name_start, '>');
  if (name_end == NULL) {
    return false;
  }
  
  parsed_element->element_name = malloc((name_end - name_start) + 1);
  strncpy(parsed_element->element_name, name_start, (name_end - name_start));
  parsed_element->element_name[(name_end - name_start)] = '\0';
  
  char* value_start = name_end + 1;
  char* value_end = strchr(value_start, '<');
  
  if (value_end == NULL) {
    return false;
  }
  
  parsed_element->element_value = malloc((value_end - value_start) + 1);
  strncpy(parsed_element->element_value, value_start, (value_end - value_start));
  parsed_element->element_value[(value_end - value_start)] = '\0';
  
  return true;
}

/* Main function to parse an entire XML string */
int main() {
  char xml_string[BUFFER_SIZE] = "<root><name>John</name><age>32</age></root>";
  
  XML_ELEMENT elements[10]; // Limiting to 10 elements for this example
  int num_elements = 0;
  
  char* current_element = xml_string;
  while (true) {
    current_element = strchr(current_element, '<');
    if (current_element == NULL) {
      break;
    }
    
    XML_ELEMENT current_parsed_element;
    if (parse_xml_element(current_element, &current_parsed_element)) {
      elements[num_elements] = current_parsed_element;
      num_elements++;
    }
    
    current_element++;
  }
  
  for (int i = 0; i < num_elements; i++) {
    printf("Element %d\n", i+1);
    printf("  Name: %s\n", elements[i].element_name);
    printf("  Value: %s\n", elements[i].element_value);
  }
  
  return 0;
}