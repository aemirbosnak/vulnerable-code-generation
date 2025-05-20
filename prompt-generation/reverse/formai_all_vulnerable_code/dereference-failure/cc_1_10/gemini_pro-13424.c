//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _c_syntax_parser {
  char *input;
  int index;
  char current;
} c_syntax_parser;

void c_syntax_parser_init(c_syntax_parser *parser, char *input) {
  parser->input = input;
  parser->index = 0;
  parser->current = input[parser->index];
}

void c_syntax_parser_next(c_syntax_parser *parser) {
  parser->index++;
  parser->current = parser->input[parser->index];
}

int c_syntax_parser_is_end(c_syntax_parser *parser) {
  return parser->current == '\0';
}

int c_syntax_parser_is_whitespace(c_syntax_parser *parser) {
  return parser->current == ' ' || parser->current == '\t' || parser->current == '\n' || parser->current == '\r';
}

int c_syntax_parser_is_digit(c_syntax_parser *parser) {
  return parser->current >= '0' && parser->current <= '9';
}

int c_syntax_parser_is_letter(c_syntax_parser *parser) {
  return (parser->current >= 'a' && parser->current <= 'z') || (parser->current >= 'A' && parser->current <= 'Z');
}

int c_syntax_parser_is_identifier(c_syntax_parser *parser) {
  return c_syntax_parser_is_letter(parser) || c_syntax_parser_is_digit(parser) || parser->current == '_';
}

int c_syntax_parser_parse_number(c_syntax_parser *parser) {
  int number = 0;
  while (c_syntax_parser_is_digit(parser)) {
    number *= 10;
    number += parser->current - '0';
    c_syntax_parser_next(parser);
  }
  return number;
}

char *c_syntax_parser_parse_identifier(c_syntax_parser *parser) {
  char *identifier = malloc(100);
  int index = 0;
  while (c_syntax_parser_is_identifier(parser)) {
    identifier[index++] = parser->current;
    c_syntax_parser_next(parser);
  }
  identifier[index] = '\0';
  return identifier;
}

int c_syntax_parser_parse_expression(c_syntax_parser *parser) {
  int left = c_syntax_parser_parse_term(parser);
  while (parser->current == '+' || parser->current == '-') {
    char operator = parser->current;
    c_syntax_parser_next(parser);
    int right = c_syntax_parser_parse_term(parser);
    if (operator == '+') {
      left += right;
    } else {
      left -= right;
    }
  }
  return left;
}

int c_syntax_parser_parse_term(c_syntax_parser *parser) {
  int left = c_syntax_parser_parse_factor(parser);
  while (parser->current == '*' || parser->current == '/') {
    char operator = parser->current;
    c_syntax_parser_next(parser);
    int right = c_syntax_parser_parse_factor(parser);
    if (operator == '*') {
      left *= right;
    } else {
      left /= right;
    }
  }
  return left;
}

int c_syntax_parser_parse_factor(c_syntax_parser *parser) {
  if (parser->current == '(') {
    c_syntax_parser_next(parser);
    int expression = c_syntax_parser_parse_expression(parser);
    if (parser->current != ')') {
      printf("Parse error: expected ')' after expression\n");
      exit(1);
    }
    c_syntax_parser_next(parser);
    return expression;
  } else if (c_syntax_parser_is_digit(parser)) {
    return c_syntax_parser_parse_number(parser);
  } else if (c_syntax_parser_is_letter(parser)) {
    return c_syntax_parser_parse_identifier(parser);
  } else {
    printf("Parse error: expected number, identifier, or '(' after factor\n");
    exit(1);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <expression>\n", argv[0]);
    return 1;
  }
  c_syntax_parser parser;
  c_syntax_parser_init(&parser, argv[1]);
  int result = c_syntax_parser_parse_expression(&parser);
  if (!c_syntax_parser_is_end(&parser)) {
    printf("Parse error: unexpected input after expression\n");
    return 1;
  }
  printf("Result: %d\n", result);
  return 0;
}