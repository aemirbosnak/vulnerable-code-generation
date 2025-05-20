//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 256
#define MAX_ATTRIBUTE_NAME_LENGTH 128
#define MAX_ATTRIBUTE_VALUE_LENGTH 1024

typedef struct {
  char name[MAX_TAG_NAME_LENGTH];
  int num_attributes;
  struct attribute {
    char name[MAX_ATTRIBUTE_NAME_LENGTH];
    char value[MAX_ATTRIBUTE_VALUE_LENGTH];
  } attributes[16];
} tag;

typedef struct {
  int num_tags;
  tag tags[1024];
} xml_document;

xml_document *parse_xml(char *xml) {
  xml_document *document = malloc(sizeof(xml_document));
  document->num_tags = 0;

  char *tag_start = xml;
  while (*tag_start != '\0') {
    // Find the end of the tag name
    char *tag_end = tag_start;
    while (*tag_end != '>' && *tag_end != '\0') {
      tag_end++;
    }

    // Copy the tag name into the document
    strncpy(document->tags[document->num_tags].name, tag_start, tag_end - tag_start);
    document->tags[document->num_tags].name[tag_end - tag_start] = '\0';

    // Parse the attributes
    char *attribute_start = tag_end + 1;
    while (*attribute_start != '>' && *attribute_start != '\0') {
      // Find the end of the attribute name
      char *attribute_end = attribute_start;
      while (*attribute_end != '=' && *attribute_end != '\0') {
        attribute_end++;
      }

      // Copy the attribute name into the document
      strncpy(document->tags[document->num_tags].attributes[document->tags[document->num_tags].num_attributes].name, attribute_start, attribute_end - attribute_start);
      document->tags[document->num_tags].attributes[document->tags[document->num_tags].num_attributes].name[attribute_end - attribute_start] = '\0';

      // Find the end of the attribute value
      attribute_start = attribute_end + 1;
      while (*attribute_start != '"' && *attribute_start != '\0') {
        attribute_start++;
      }

      // Copy the attribute value into the document
      strncpy(document->tags[document->num_tags].attributes[document->tags[document->num_tags].num_attributes].value, attribute_start + 1, attribute_end - attribute_start - 2);
      document->tags[document->num_tags].attributes[document->tags[document->num_tags].num_attributes].value[attribute_end - attribute_start - 2] = '\0';

      document->tags[document->num_tags].num_attributes++;
    }

    document->num_tags++;

    tag_start = tag_end + 1;
  }

  return document;
}

void print_xml_document(xml_document *document) {
  for (int i = 0; i < document->num_tags; i++) {
    printf("<%s", document->tags[i].name);

    for (int j = 0; j < document->tags[i].num_attributes; j++) {
      printf(" %s=\"%s\"", document->tags[i].attributes[j].name, document->tags[i].attributes[j].value);
    }

    printf(">");
  }
}

int main() {
  char *xml = "<root><child1 attr1=\"value1\" attr2=\"value2\"/><child2 attr3=\"value3\"/><child3/></root>";

  xml_document *document = parse_xml(xml);

  print_xml_document(document);

  return 0;
}