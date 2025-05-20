//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct parser_t {
  FILE *in;
  char buf[1024];
  int idx;
};
static void parser_init(struct parser_t *parser, FILE *in) {
  parser->in = in;
  parser->idx = 0;
}
static int parser_getc(struct parser_t *parser) {
  return parser->buf[parser->idx++];
}
static void parser_ungetc(struct parser_t *parser, int c) {
  parser->idx--;
}
static char *parser_get_tag(struct parser_t *parser) {
  char *tag = NULL;
  int c;
  parser->buf[parser->idx] = 0;
  if (isalpha(c = parser_getc(parser))) {
    size_t len = 0;
    tag = malloc(len + 2);
    while (isalpha(c) || isdigit(c)) {
      tag[len++] = c;
      parser->buf[parser->idx] = 0;
      c = parser_getc(parser);
    }
    parser_ungetc(parser, c);
    tag[len] = 0;
  }
  return tag;
}
static char *parser_get_attr(struct parser_t *parser) {
  char *attr = NULL;
  int c;
  parser->buf[parser->idx] = 0;
  while (isspace(c = parser_getc(parser)))
    ;
  if (isalpha(c)) {
    size_t len = 0;
    attr = malloc(len + 2);
    while (isalpha(c) || isdigit(c) || c == '_') {
      attr[len++] = c;
      parser->buf[parser->idx] = 0;
      c = parser_getc(parser);
    }
    parser_ungetc(parser, c);
    attr[len] = 0;
  }
  return attr;
}
static char *parser_get_value(struct parser_t *parser) {
  char *value = NULL;
  int c;
  parser->buf[parser->idx] = 0;
  while (isspace(c = parser_getc(parser)))
    ;
  if (c == '"') {
    size_t len = 0;
    value = malloc(len + 2);
    while ((c = parser_getc(parser)) != '"') {
      value[len++] = c;
      parser->buf[parser->idx] = 0;
    }
    value[len] = 0;
  }
  return value;
}
void parser_parse(struct parser_t *parser) {
  int c;
  char *name = NULL, *attr = NULL, *value = NULL;
  while ((c = parser_getc(parser)) != EOF) {
    switch (c) {
    case '<':
      name = parser_get_tag(parser);
      if (name) {
        printf("<%s>", name);
        free(name);
      }
      while ((attr = parser_get_attr(parser)) &&
             (value = parser_get_value(parser))) {
        printf(" %s=\"%s\"", attr, value);
        free(attr);
        free(value);
      }
      if (parser_getc(parser) == '/') {
        printf("/>");
        parser_getc(parser);
      }
      break;
    case '>':
      printf(">");
      break;
    case '/':
      if ((name = parser_get_tag(parser))) {
        printf("</%s>", name);
        free(name);
      }
      break;
    default:
      putchar(c);
      break;
    }
  }
}
int main(int argc, char **argv) {
  struct parser_t parser;
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <xml file>\n", argv[0]);
    return EXIT_FAILURE;
  }
  parser_init(&parser, fopen(argv[1], "r"));
  parser_parse(&parser);
  return EXIT_SUCCESS;
}