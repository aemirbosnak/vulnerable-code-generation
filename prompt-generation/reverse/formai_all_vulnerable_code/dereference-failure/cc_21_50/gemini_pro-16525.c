//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENT_LENGTH 256
#define MAX_ELEMENT_NAME_LENGTH 64

typedef struct Element {
  char name[MAX_ELEMENT_NAME_LENGTH];
  char value[MAX_ELEMENT_LENGTH];
  struct Element *next;
} Element;

typedef struct XMLParser {
  char *input;
  int input_length;
  int current_position;
  struct Element *root_element;
  struct Element *current_element;
} XMLParser;

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <XML file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  fseek(fp, 0, SEEK_END);
  int file_length = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *input = malloc(file_length + 1);
  if (input == NULL) {
    fprintf(stderr, "Error allocating memory for input\n");
    fclose(fp);
    return EXIT_FAILURE;
  }

  fread(input, file_length, 1, fp);
  fclose(fp);

  XMLParser parser;
  parser.input = input;
  parser.input_length = file_length;
  parser.current_position = 0;
  parser.root_element = NULL;
  parser.current_element = NULL;

  while (parser.current_position < parser.input_length) {
    char c = parser.input[parser.current_position];

    if (isspace(c)) {
      parser.current_position++;
      continue;
    }

    if (c == '<') {
      parser.current_position++;
      if (parser.input[parser.current_position] == '/') {
        parser.current_position++;
        if (parser.current_element != NULL) {
          parser.current_element = parser.current_element->next;
        }
      } else {
        Element *element = malloc(sizeof(Element));
        if (element == NULL) {
          fprintf(stderr, "Error allocating memory for element\n");
          free(input);
          return EXIT_FAILURE;
        }

        element->name[0] = '\0';
        element->value[0] = '\0';
        element->next = NULL;

        if (parser.current_element == NULL) {
          parser.root_element = element;
        } else {
          parser.current_element->next = element;
        }

        parser.current_element = element;

        while (parser.current_position < parser.input_length) {
          c = parser.input[parser.current_position];

          if (isspace(c)) {
            parser.current_position++;
            continue;
          }

          if (c == '>') {
            parser.current_position++;
            break;
          }

          if (element->name[0] == '\0') {
            if (c == '/') {
              fprintf(stderr, "Error: unexpected closing tag\n");
              free(input);
              free(element);
              return EXIT_FAILURE;
            }

            int i = 0;
            while (c != ' ' && c != '>' && c != '/') {
              if (i < MAX_ELEMENT_NAME_LENGTH - 1) {
                element->name[i] = c;
                i++;
              }
              parser.current_position++;
              c = parser.input[parser.current_position];
            }

            element->name[i] = '\0';
          } else {
            if (element->value[0] == '\0') {
              if (c == '=') {
                parser.current_position++;
                while (parser.current_position < parser.input_length) {
                  c = parser.input[parser.current_position];

                  if (isspace(c)) {
                    parser.current_position++;
                    continue;
                  }

                  if (c == '"') {
                    parser.current_position++;
                    int i = 0;
                    while (parser.current_position < parser.input_length) {
                      c = parser.input[parser.current_position];

                      if (c == '"') {
                        parser.current_position++;
                        element->value[i] = '\0';
                        break;
                      }

                      if (i < MAX_ELEMENT_LENGTH - 1) {
                        element->value[i] = c;
                        i++;
                      }
                      parser.current_position++;
                    }
                  } else {
                    int i = 0;
                    while (c != ' ' && c != '>' && c != '/') {
                      if (i < MAX_ELEMENT_LENGTH - 1) {
                        element->value[i] = c;
                        i++;
                      }
                      parser.current_position++;
                      c = parser.input[parser.current_position];
                    }

                    element->value[i] = '\0';
                  }

                  break;
                }
              }
            }
          }
        }
      }
    } else {
      parser.current_position++;
      continue;
    }
  }

  Element *element = parser.root_element;
  while (element != NULL) {
    printf("<%s", element->name);

    if (element->value[0] != '\0') {
      printf(" %s=\"%s\"", element->name, element->value);
    }

    printf(">");

    if (element->value[0] == '\0') {
      printf("\n");
    }

    element = element->next;
  }

  free(input);
  return EXIT_SUCCESS;
}