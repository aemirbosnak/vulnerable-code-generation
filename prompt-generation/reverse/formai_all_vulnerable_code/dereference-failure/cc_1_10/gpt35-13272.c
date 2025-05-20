//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TAG_LENGTH 256
#define MAX_ATTR_LENGTH 256
#define MAX_ATTR_VALUE_LENGTH 1024
#define MAX_STRING_LENGTH 8192

typedef struct {
  char tag[MAX_TAG_LENGTH];
  int attr_count;
  char attr_names[MAX_ATTR_LENGTH][MAX_ATTR_LENGTH];
  char attr_values[MAX_ATTR_LENGTH][MAX_ATTR_VALUE_LENGTH];
  char string[MAX_STRING_LENGTH];
} xml_element_t;

typedef struct {
  int element_count;
  xml_element_t *elements;
} xml_document_t;

void xml_parse_node(char *string, xml_element_t *element);
void xml_parse_attribute(char *string, xml_element_t *element);

xml_document_t *xml_parse_document(char *string) {
  xml_document_t *doc = (xml_document_t *) malloc(sizeof(xml_document_t));
  doc->element_count = 0;
  doc->elements = NULL;

  char *token = strtok(string, "<");
  while (token != NULL) {
    if (strncmp(token, "/", 1) == 0) {
      // End tag
      doc->element_count--;
      doc->elements = (xml_element_t *) realloc(doc->elements, sizeof(xml_element_t) * doc->element_count);
    } else {
      // Start tag
      doc->element_count++;
      doc->elements = (xml_element_t *) realloc(doc->elements, sizeof(xml_element_t) * doc->element_count);
      memset(&doc->elements[doc->element_count - 1], 0, sizeof(xml_element_t));
      xml_parse_node(token, &doc->elements[doc->element_count - 1]);
    }
    token = strtok(NULL, "<");
  }

  return doc;
}

void xml_parse_node(char *string, xml_element_t *element) {
  char *token = strtok(string, " \t\r\n>");
  if (token == NULL) {
    return;
  }
  strncpy(element->tag, token, MAX_TAG_LENGTH);

  while (token != NULL) {
    if (strncmp(token, "/", 1) == 0 || strncmp(token, ">", 1) == 0) {
      // End of attributes
      break;
    } else {
      xml_parse_attribute(token, element);
      token = strtok(NULL, " \t\r\n>");
    }
  }

  if (strncmp(token, "/", 1) == 0) {
    // End tag
    return;
  }

  // Parse string
  int length = strlen(token);
  if (length > 0) {
    token[length - 1] = '\0';
    strncpy(element->string, token, MAX_STRING_LENGTH);
  }

  // Parse children nodes
  char *ptr = NULL;
  while ((ptr = strstr(token, "<")) != NULL) {
    xml_parse_node(ptr + 1, element);
    token = ptr + 1;
  }
}

void xml_parse_attribute(char *string, xml_element_t *element) {
  // Get attribute name
  char *name_ptr = string;
  while (isalnum(*name_ptr) || *name_ptr == '_') {
    name_ptr++;
  }
  *name_ptr = '\0';
  strncpy(element->attr_names[element->attr_count], string, MAX_ATTR_LENGTH);

  // Get attribute value
  char *value_ptr = name_ptr + 1;
  while (*value_ptr == ' ' || *value_ptr == '\t' || *value_ptr == '=') {
    value_ptr++;
  }
  if (*value_ptr == '\"' || *value_ptr == '\'') {
    value_ptr++;
  }
  char *end_ptr = value_ptr;
  while (*end_ptr != '\0' && *end_ptr != '\"' && *end_ptr != '\'') {
    end_ptr++;
  }
  *end_ptr = '\0';
  strncpy(element->attr_values[element->attr_count], value_ptr, MAX_ATTR_VALUE_LENGTH);

  element->attr_count++;
}

int main() {
  char *xml_string = "<fruit name=\"banana\">\n"
                     "  <color>yellow</color>\n"
                     "  <size>medium</size>\n"
                     "</fruit>\n"
                     "<fruit name=\"apple\">\n"
                     "  <color>red</color>\n"
                     "  <size>s</size>\n"
                     "</fruit>";
  xml_document_t *doc = xml_parse_document(xml_string);
  for (int i = 0; i < doc->element_count; i++) {
    printf("Tag: %s\n", doc->elements[i].tag);
    for (int j = 0; j < doc->elements[i].attr_count; j++) {
      printf("%s=\"%s\"\n", doc->elements[i].attr_names[j], doc->elements[i].attr_values[j]);
    }
    printf("String: %s\n", doc->elements[i].string);
    printf("\n");
  }
  free(doc->elements);
  free(doc);
  return 0;
}