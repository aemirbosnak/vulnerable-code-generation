//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XmlElement {
  char* name;
  char* content;
  struct XmlAttribute* attributes;
  struct XmlElement* children;
  struct XmlElement* next;
} XmlElement;

typedef struct XmlAttribute {
  char* name;
  char* value;
  struct XmlAttribute* next;
} XmlAttribute;

void parseElement(char* input, XmlElement** currentNode) {
  char* tagName = strtok(input, "<>/ ");
  int hasClosingTag = 0, hasContent = 0;
  if (tagName[0] == '/') {
    hasClosingTag = 1;
    tagName = strtok(NULL, "<>/ ");
  }
  if (strchr(input, '>') != NULL) {
    hasContent = 1;
  }
  XmlElement* newElement = (XmlElement*) malloc(sizeof(XmlElement));
  newElement->name = (char*) malloc(strlen(tagName) + 1);
  strcpy(newElement->name, tagName);
  newElement->content = NULL;
  newElement->attributes = NULL;
  newElement->children = NULL;
  newElement->next = NULL;
  if (*currentNode == NULL) {
    *currentNode = newElement;
  } else {
    XmlElement* currentNodeCopy = *currentNode;
    while (currentNodeCopy->next != NULL) {
      currentNodeCopy = currentNodeCopy->next;
    }
    currentNodeCopy->next = newElement;
  }
  char* attributeName = NULL;
  char* attributeValue = NULL;
  char* attributeToken = strtok(NULL, "<>\"'=/ ");
  while (attributeToken != NULL) {
    if (attributeName == NULL) {
      attributeName = (char*) malloc(strlen(attributeToken) + 1);
      strcpy(attributeName, attributeToken);
    } else if (attributeValue == NULL) {
      attributeValue = (char*) malloc(strlen(attributeToken) + 1);
      strcpy(attributeValue, attributeToken);
      XmlAttribute* newAttribute = (XmlAttribute*) malloc(sizeof(XmlAttribute));
      newAttribute->name = attributeName;
      newAttribute->value = attributeValue;
      newAttribute->next = NULL;
      if (newElement->attributes == NULL) {
        newElement->attributes = newAttribute;
      } else {
        XmlAttribute* attributeCopy = newElement->attributes;
        while (attributeCopy->next != NULL) {
          attributeCopy = attributeCopy->next;
        }
        attributeCopy->next = newAttribute;
      }
      attributeName = NULL;
      attributeValue = NULL;
    }
    attributeToken = strtok(NULL, "<>\"'=/ ");
  }
  if (!hasClosingTag && !hasContent) {
    parseElement(input + strlen(tagName) + 1, &(newElement->children));
  } else if (hasContent) {
    char* contentStart = strchr(input, '>') + 1;
    char* contentEnd = strstr(contentStart, "</");
    int contentLength = contentEnd - contentStart;
    newElement->content = (char*) malloc(contentLength + 1);
    memset(newElement->content, 0, contentLength + 1);
    strncpy(newElement->content, contentStart, contentLength);
  }
}

int main() {
  XmlElement* root = NULL;
  char* input = "<root><element1 attribute1='value1'>content1</element1><element2>content2</element2></root>";
  parseElement(input, &root);
  XmlElement* currentElement = root;
  while (currentElement != NULL) {
    printf("Element Name: %s\n", currentElement->name);
    if (currentElement->attributes != NULL) {
      XmlAttribute* currentAttribute = currentElement->attributes;
      printf("Attributes:\n");
      while (currentAttribute != NULL) {
        printf("%s: %s\n", currentAttribute->name, currentAttribute->value);
        currentAttribute = currentAttribute->next;
      }
    }
    if (currentElement->content != NULL) {
      printf("Content: %s\n", currentElement->content);
    } else if (currentElement->children != NULL) {
      printf("Children:\n");
      XmlElement* currentChild = currentElement->children;
      while (currentChild != NULL) {
        printf("- %s\n", currentChild->name);
        currentChild = currentChild->next;
      }
    }
    currentElement = currentElement->next;
  }
  return 0;
}