//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define MAX_NESTING 64
#define MAX_TAGS 32
#define MAX_ATTRIBUTES 16

typedef struct {
  char *name;
  char **attributes;
  int num_attributes;
  struct tag *parent;
  struct tag *children[MAX_TAGS];
  int num_children;
} tag;

typedef struct {
  char *text;
  struct tag *parent;
} text;

tag *root_tag;

void parse_xml(char *xml) {
  char *p = xml;
  tag *current_tag = NULL;
  text *current_text = NULL;

  while (*p != '\0') {
    if (*p == '<') {
      if (p[1] == '/') {
        // End tag
        current_tag = current_tag->parent;
        p += 2;
        while (*p != '>') {
          p++;
        }
      } else {
        // Start tag
        tag *new_tag = malloc(sizeof(tag));
        new_tag->name = malloc(strlen(p) + 1);
        strcpy(new_tag->name, p);
        new_tag->attributes = malloc(sizeof(char *) * MAX_ATTRIBUTES);
        new_tag->num_attributes = 0;
        new_tag->parent = current_tag;
        new_tag->num_children = 0;

        if (current_tag == NULL) {
          root_tag = new_tag;
        } else {
          current_tag->children[current_tag->num_children++] = new_tag;
        }

        current_tag = new_tag;

        p++;
        while (*p != '>') {
          // Parse attributes
          if (*p == ' ') {
            p++;
            char *attribute_name = malloc(strlen(p) + 1);
            strcpy(attribute_name, p);
            char *attribute_value = malloc(strlen(p) + 1);
            strcpy(attribute_value, p);
            current_tag->attributes[current_tag->num_attributes++] = attribute_name;
            current_tag->attributes[current_tag->num_attributes++] = attribute_value;
            p++;
          } else {
            p++;
          }
        }
      }
    } else if (*p == '>') {
      // End of tag
      p++;
    } else {
      // Text
      text *new_text = malloc(sizeof(text));
      new_text->text = malloc(strlen(p) + 1);
      strcpy(new_text->text, p);
      new_text->parent = current_tag;
      current_text = new_text;
      p++;
    }
  }
}

void print_xml(tag *tag) {
  printf("<%s", tag->name);
  for (int i = 0; i < tag->num_attributes; i += 2) {
    printf(" %s=\"%s\"", tag->attributes[i], tag->attributes[i + 1]);
  }
  printf(">");
  for (int i = 0; i < tag->num_children; i++) {
    print_xml(tag->children[i]);
  }
  printf("</%s>", tag->name);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <xml_file>\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *xml = malloc(file_size + 1);
  fread(xml, file_size, 1, file);
  xml[file_size] = '\0';

  parse_xml(xml);

  print_xml(root_tag);

  return 0;
}