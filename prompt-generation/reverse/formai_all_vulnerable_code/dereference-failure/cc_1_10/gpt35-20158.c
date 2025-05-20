//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: surrealist
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct xml_element {
  char *name;
  char *value;
  struct xml_element *child;
  struct xml_element *next;
};

void display_xml_tree(struct xml_element *root, int depth) {
  if (root == NULL) {
    return;
  }

  for (int i = 0; i < depth; i++) {
    printf("  ");
  }

  printf("<%s>", root->name);

  if (root->child == NULL) {
    printf("%s", root->value);
  }

  printf("\n");

  display_xml_tree(root->child, depth + 1);

  for (struct xml_element *e = root->next; e != NULL; e = e->next) {
    display_xml_tree(e, depth);
  }

  for (int i = 0; i < depth; i++) {
    printf("  ");
  }

  printf("</%s>\n", root->name);
}

void free_xml_tree(struct xml_element *root) {
  if (root == NULL) {
    return;
  }

  free_xml_tree(root->child);
  free_xml_tree(root->next);
  free(root->name);
  free(root->value);
  free(root);
}

void parse_xml_element(char *xml, struct xml_element *el) {
  int tag_start = 1;

  // Find the element name
  for (int i = 1;; i++) {
    if (xml[i] == ' ' || xml[i] == '>') {
      el->name = malloc(i - 1);
      strncpy(el->name, xml + 1, i - 1);
      break;
    }
  }

  // Walk through the attributes
  for (int i = 1;; i++) {
    if (xml[i] == '>') {
      tag_start = i;
      break;
    }
  }

  for (int i = tag_start + 1;; i++) {
    if (xml[i] == '=') {
      int value_start = i + 2;

      while (xml[value_start] == ' ' || xml[value_start] == '"') {
        value_start++;
      }

      for (int j = value_start; j < strlen(xml); j++) {
        if (xml[j] == '"') {
          el->value = malloc(j - value_start);
          strncpy(el->value, xml + value_start, j - value_start);
          break;
        }
      }
    }

    if (xml[i] == '/' && xml[i + 1] == '>') {
      return;
    }

    if (xml[i] == '>') {
      if (xml[i - 1] == '/') {
        return;
      }

      int child_start = i + 1;
      while (xml[child_start] == ' ') {
        child_start++;
      }

      el->child = malloc(sizeof(struct xml_element));
      parse_xml_element(xml + child_start, el->child);
      struct xml_element *current = el->child;

      while (current != NULL) {
        if (current->next == NULL) {
          current->next = malloc(sizeof(struct xml_element));
          parse_xml_element(xml + i + 1, current->next);
          break;
        }

        current = current->next;
      }

      return;
    }
  }
}

int main() {
  char *xml = "<html><head><title>Welcome to Surrealist Programming</title></head><body><h1>Coding in Dreamland</h1><p>This is a surrealistic example of an XML Parser program.</p></body></html>";

  struct xml_element root;
  memset(&root, 0, sizeof(struct xml_element));

  parse_xml_element(xml, &root);
  display_xml_tree(&root, 0);
  free_xml_tree(&root);

  return 0;
}