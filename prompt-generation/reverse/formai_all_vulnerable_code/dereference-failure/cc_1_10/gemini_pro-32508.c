//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct html_element {
  char *name;
  struct html_element *parent;
  struct html_element *first_child;
  struct html_element *next_sibling;
  char *text;
};

struct html_document {
  struct html_element *root;
};

struct html_beautifier {
  int indent_level;
  char *indent_string;
};

static void html_element_free(struct html_element *element) {
  free(element->name);
  free(element->text);
  free(element);
}

static void html_document_free(struct html_document *document) {
  struct html_element *element = document->root;
  while (element) {
    struct html_element *next = element->next_sibling;
    html_element_free(element);
    element = next;
  }
  free(document);
}

static struct html_element *html_element_create(const char *name, const char *text) {
  struct html_element *element = malloc(sizeof(struct html_element));
  if (!element) {
    return NULL;
  }
  element->name = strdup(name);
  if (!element->name) {
    free(element);
    return NULL;
  }
  element->parent = NULL;
  element->first_child = NULL;
  element->next_sibling = NULL;
  element->text = strdup(text);
  if (!element->text) {
    free(element->name);
    free(element);
    return NULL;
  }
  return element;
}

static struct html_document *html_document_create(const char *html) {
  struct html_document *document = malloc(sizeof(struct html_document));
  if (!document) {
    return NULL;
  }
  document->root = NULL;
  struct html_element *current_element = NULL;
  char *line = NULL;
  size_t line_length = 0;
  ssize_t line_read;
  while ((line_read = getline(&line, &line_length, stdin)) != -1) {
    if (line_read == 1 && line[0] == '\n') {
      continue;
    }
    line[strcspn(line, "\r\n")] = '\0';
    if (line[0] == '<') {
      char *end_tag = strchr(line, '>');
      if (!end_tag) {
        fprintf(stderr, "Error: Unterminated HTML tag: %s\n", line);
        free(line);
        html_document_free(document);
        return NULL;
      }
      *end_tag = '\0';
      char *tag_name = line + 1;
      if (tag_name[0] == '/') {
        if (!current_element) {
          fprintf(stderr, "Error: Closing tag without opening tag: %s\n", line);
          free(line);
          html_document_free(document);
          return NULL;
        }
        if (strcmp(tag_name + 1, current_element->name) != 0) {
          fprintf(stderr, "Error: Closing tag does not match opening tag: %s\n", line);
          free(line);
          html_document_free(document);
          return NULL;
        }
        current_element = current_element->parent;
      } else {
        struct html_element *element = html_element_create(tag_name, NULL);
        if (!element) {
          free(line);
          html_document_free(document);
          return NULL;
        }
        element->parent = current_element;
        if (!current_element) {
          document->root = element;
        } else {
          if (!current_element->first_child) {
            current_element->first_child = element;
          } else {
            struct html_element *last_child = current_element->first_child;
            while (last_child->next_sibling) {
              last_child = last_child->next_sibling;
            }
            last_child->next_sibling = element;
          }
        }
        current_element = element;
      }
    } else {
      if (!current_element) {
        fprintf(stderr, "Error: Text outside of HTML tags: %s\n", line);
        free(line);
        html_document_free(document);
        return NULL;
      }
      if (current_element->text) {
        free(current_element->text);
      }
      current_element->text = strdup(line);
      if (!current_element->text) {
        free(line);
        html_document_free(document);
        return NULL;
      }
    }
  }
  free(line);
  return document;
}

static void html_beautifier_init(struct html_beautifier *beautifier, int indent_level, const char *indent_string) {
  beautifier->indent_level = indent_level;
  beautifier->indent_string = indent_string;
}

static void html_beautifier_free(struct html_beautifier *beautifier) {
  free(beautifier->indent_string);
}

static void html_beautifier_print_indent(struct html_beautifier *beautifier, FILE *fp) {
  for (int i = 0; i < beautifier->indent_level; i++) {
    fprintf(fp, "%s", beautifier->indent_string);
  }
}

static void html_beautifier_print_element(struct html_beautifier *beautifier, FILE *fp, struct html_element *element) {
  html_beautifier_print_indent(beautifier, fp);
  fprintf(fp, "<%s", element->name);
  struct html_element *child = element->first_child;
  while (child) {
    html_beautifier_print_element(beautifier, fp, child);
    child = child->next_sibling;
  }
  if (!element->first_child) {
    fprintf(fp, "/>");
  } else {
    fprintf(fp, ">");
    if (element->text) {
      fprintf(fp, "\n");
      html_beautifier_print_indent(beautifier, fp);
      fprintf(fp, "%s", element->text);
      fprintf(fp, "\n");
    }
    child = element->first_child;
    while (child) {
      html_beautifier_print_element(beautifier, fp, child);
      child = child->next_sibling;
    }
    html_beautifier_print_indent(beautifier, fp);
    fprintf(fp, "</%s>", element->name);
  }
  fprintf(fp, "\n");
}

static void html_beautifier_print_document(struct html_beautifier *beautifier, FILE *fp, struct html_document *document) {
  html_beautifier_print_element(beautifier, fp, document->root);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
    return EXIT_FAILURE;
  }
  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    fprintf(stderr, "Error: Could not open file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  struct html_document *document = html_document_create(fp);
  fclose(fp);
  if (!document) {
    return EXIT_FAILURE;
  }
  struct html_beautifier beautifier;
  html_beautifier_init(&beautifier, 2, "  ");
  html_beautifier_print_document(&beautifier, stdout, document);
  html_beautifier_free(&beautifier);
  html_document_free(document);
  return EXIT_SUCCESS;
}