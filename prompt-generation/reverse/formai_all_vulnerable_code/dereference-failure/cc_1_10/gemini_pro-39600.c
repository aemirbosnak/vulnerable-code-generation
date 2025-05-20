//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 4096

typedef struct {
  char *name;
  char **attrs;
  int nattrs;
  char **children;
  int nchildren;
} xml_node;

xml_node *xml_parse(const char *buf) {
  xml_node *node = malloc(sizeof(xml_node));
  if (!node) return NULL;

  char *tok = strtok((char *)buf, "<>");
  if (!tok) return node;

  node->name = strdup(tok);
  if (!node->name) {
    free(node);
    return NULL;
  }

  while (tok = strtok(NULL, "<>")) {
    if (*tok == '/') {
      return node;
    } else if (*tok == '!') {
      // skip comments
      while (*tok && *tok != '>') tok++;
    } else {
      char **attrs = NULL;
      int nattrs = 0;

      char *attr = strtok(tok, " ");
      while (attr) {
        char *eq = strchr(attr, '=');
        if (eq) {
          *eq++ = '\0';
          attrs = realloc(attrs, (nattrs + 1) * sizeof(char *));
          attrs[nattrs++] = strdup(attr);
          attrs = realloc(attrs, (nattrs + 1) * sizeof(char *));
          attrs[nattrs++] = strdup(eq);
        } else {
          attrs = realloc(attrs, (nattrs + 1) * sizeof(char *));
          attrs[nattrs++] = strdup(attr);
        }
        attr = strtok(NULL, " ");
      }

      xml_node *child = xml_parse(tok);
      if (!child) {
        free(node->name);
        free(node);
        for (int i = 0; i < nattrs; i++) free(attrs[i]);
        free(attrs);
        return NULL;
      }

      node->children = realloc(node->children, (node->nchildren + 1) * sizeof(char *));
      node->children[node->nchildren++] = child;

      while (*tok && *tok != '>') tok++;
    }
  }

  return node;
}

void xml_free(xml_node *node) {
  if (!node) return;
  free(node->name);
  for (int i = 0; i < node->nattrs; i++) free(node->attrs[i]);
  free(node->attrs);
  for (int i = 0; i < node->nchildren; i++) xml_free(node->children[i]);
  free(node->children);
  free(node);
}

int main() {
  char buf[MAX_BUF];
  FILE *fp = fopen("test.xml", "r");
  if (!fp) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (fgets(buf, MAX_BUF, fp)) {
    xml_node *node = xml_parse(buf);
    if (!node) {
      perror("xml_parse");
      return EXIT_FAILURE;
    }

    printf("Node: %s\n", node->name);
    for (int i = 0; i < node->nattrs; i++) {
      printf("Attribute: %s = %s\n", node->attrs[i * 2], node->attrs[i * 2 + 1]);
    }
    for (int i = 0; i < node->nchildren; i++) {
      printf("Child: ");
      xml_free(node->children[i]);
    }

    xml_free(node);
  }

  fclose(fp);
  return EXIT_SUCCESS;
}