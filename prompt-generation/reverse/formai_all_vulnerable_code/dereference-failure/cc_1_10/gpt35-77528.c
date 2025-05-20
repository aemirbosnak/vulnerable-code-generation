//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char *key;
  char *value;
} KeyVal;

typedef struct xmlNode {
  char *name;
  char *content;
  KeyVal *attributes;
  struct xmlNode *children;
  struct xmlNode *sibling;
} xmlNode;

// function to trim whitespace from string
char *trim(char *str) {
  char *end;

  // trim leading space
  while (isspace((unsigned char)*str)) str++;

  if (*str == 0)  // all spaces?
    return str;

  // trim trailing space
  end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char)*end)) end--;

  // write new null terminator
  *(end + 1) = '\0';

  return str;
}

// function to parse XML attributes
KeyVal *parseAttributes(char *attrString) {
  if (!attrString) return NULL;

  KeyVal *attributes = malloc(sizeof(KeyVal));
  int attrCount = 1;

  char *token = strtok(attrString, " ");

  while (token != NULL) {
    char *key = strtok(token, "=");
    char *value = strtok(NULL, "=");

    key = trim(key);
    value = trim(value);

    attributes = realloc(attributes, (attrCount + 1) * sizeof(KeyVal));
    attributes[attrCount - 1].key = key;
    attributes[attrCount - 1].value = value;

    attrCount++;

    token = strtok(NULL, " ");
  }

  attributes = realloc(attributes, attrCount * sizeof(KeyVal));
  attributes[attrCount - 1].key = NULL;
  attributes[attrCount - 1].value = NULL;

  return attributes;
}

// function to parse XML nodes
xmlNode *parseNode(char *nodeString) {
  xmlNode *node = malloc(sizeof(xmlNode));
  node->name = NULL;
  node->content = NULL;
  node->attributes = NULL;
  node->children = NULL;
  node->sibling = NULL;

  if (nodeString[0] == '<' && nodeString[1] != '/') {
    char *token = strtok(nodeString, "<");
    token = strtok(NULL, ">");

    node->name = token;

    // check if node has attributes
    if (strchr(token, ' ') != NULL) {
      char *attrString = strchr(token, ' ') + 1;
      node->name = strtok(token, " ");
      node->attributes = parseAttributes(attrString);
    }

    if (nodeString[strlen(nodeString) - 1] != '/') {
      char *closingTag = malloc(sizeof(char) * (strlen(nodeString) + strlen(node->name) + 4));
      sprintf(closingTag, "</%s>", node->name);

      int contentLength = strlen(nodeString) - strlen(closingTag) - strlen(node->name) - 2;

      if (contentLength > 0) {
        char *content = malloc(sizeof(char) * (contentLength + 1));
        strncpy(content, nodeString + strlen(node->name) + 2, contentLength);
        content[contentLength] = '\0';
        node->content = content;
      }

      char *childString = malloc(sizeof(char) * (strlen(nodeString) - strlen(node->name) - 3));
      int childCount = 0;

      token = strtok(nodeString + strlen(node->name) + 2 + (node->attributes ? strlen(node->attributes[0].key) + strlen(node->attributes[0].value) + 3 : 0), "<");

      while (token != NULL) {
        if (token[0] != '/') {
          char *childNodeString = malloc(sizeof(char) * (strlen(token) + 3));
          sprintf(childNodeString, "<%s>", token);
          xmlNode *childNode = parseNode(childNodeString);

          if (childCount == 0) {
            node->children = childNode;
          } else {
            xmlNode *currentChild = node->children;
            while (currentChild->sibling != NULL) currentChild = currentChild->sibling;
            currentChild->sibling = childNode;
          }

          childCount++;
        }

        token = strtok(NULL, "<");
      }

      free(childString);
      free(closingTag);
    }
  }

  return node;
}

// function to print parsed XML node tree
void printNode(xmlNode *node, int depth) {
  for (int i = 0; i < depth; i++) printf(" ");
  printf("%s", node->name);

  if (node->attributes != NULL) {
    for (int i = 0; node->attributes[i].key != NULL; i++) {
      printf(" %s=\"%s\"", node->attributes[i].key, node->attributes[i].value);
    }
  }

  printf("\n");

  if (node->content != NULL) {
    for (int i = 0; i < depth + 2; i++) printf(" ");
    printf("%s\n", node->content);
  }

  if (node->children != NULL) {
    xmlNode *currentChild = node->children;
    while (currentChild != NULL) {
      printNode(currentChild, depth + 2);
      currentChild = currentChild->sibling;
    }
  }
}

int main() {
  char *xml = "<bookstore>\n"
              "  <book category=\"web\" cover=\"paperback\">\n"
              "    <title lang=\"en\">Everyday Italian</title>\n"
              "    <author>Giada De Laurentiis</author>\n"
              "    <year>2005</year>\n"
              "    <price>30.00</price>\n"
              "  </book>\n"
              "  <book category=\"web\" cover=\"paperback\">\n"
              "    <title lang=\"en\">Learning XML</title>\n"
              "    <author>Erik T. Ray</author>\n"
              "    <year>2003</year>\n"
              "    <price>39.95</price>\n"
              "  </book>\n"
              "</bookstore>\n";

  xmlNode *root = parseNode(xml);
  printNode(root, 0);

  return 0;
}