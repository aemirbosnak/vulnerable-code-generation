//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mystical token, a key to the XML realm
typedef enum {
  TAG_START, TAG_END, TEXT, NONE
} Token;

// The mighty XML parser, ready to conquer the beast
typedef struct {
  char *data;
  int length;
  int pos;
  Token token;
  char *name;
  char *value;
} Parser;

// Summon the parser, the gateway to the XML world
Parser *parser_create(char *data, int length) {
  Parser *parser = malloc(sizeof(Parser));
  parser->data = data;
  parser->length = length;
  parser->pos = 0;
  parser->token = NONE;
  parser->name = NULL;
  parser->value = NULL;
  return parser;
}

// Tear down the parser, freeing its memory
void parser_destroy(Parser *parser) {
  free(parser->name);
  free(parser->value);
  free(parser);
}

// The main loop, traversing the XML labyrinth
int parser_loop(Parser *parser) {
  while (parser->pos < parser->length) {
    switch (parser->token) {
      case NONE:
        if (parser->data[parser->pos] == '<') {
          parser->token = TAG_START;
          parser->pos++;
        } else {
          parser->token = TEXT;
        }
        break;
      case TAG_START:
        if (parser->data[parser->pos] == '/') {
          parser->pos++;
          parser->token = TAG_END;
        } else {
          parser->name = malloc(1);
          parser->name[0] = '\0';
          while (parser->data[parser->pos] != '>' && parser->data[parser->pos] != ' ' && parser->pos < parser->length) {
            parser->name = realloc(parser->name, strlen(parser->name) + 2);
            parser->name[strlen(parser->name)] = parser->data[parser->pos];
            parser->name[strlen(parser->name) + 1] = '\0';
            parser->pos++;
          }
          parser->token = NONE;
        }
        break;
      case TAG_END:
        if (parser->data[parser->pos] == '>') {
          parser->pos++;
          parser->token = NONE;
        }
        break;
      case TEXT:
        if (parser->data[parser->pos] == '<') {
          parser->value = malloc(1);
          parser->value[0] = '\0';
          while (parser->data[parser->pos] != '<' && parser->pos < parser->length) {
            parser->value = realloc(parser->value, strlen(parser->value) + 2);
            parser->value[strlen(parser->value)] = parser->data[parser->pos];
            parser->value[strlen(parser->value) + 1] = '\0';
            parser->pos++;
          }
          printf("Text: %s\n", parser->value);
          parser->token = NONE;
        } else {
          parser->pos++;
        }
        break;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <xml_file>\n", argv[0]);
    return 1;
  }

  // Load the XML file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }
  fseek(fp, 0, SEEK_END);
  int length = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *data = malloc(length + 1);
  fread(data, 1, length, fp);
  data[length] = '\0';
  fclose(fp);

  // Create the parser
  Parser *parser = parser_create(data, length);

  // Parse the XML file
  parser_loop(parser);

  // Destroy the parser
  parser_destroy(parser);

  return 0;
}