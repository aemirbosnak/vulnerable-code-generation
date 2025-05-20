//FormAI DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKEN_LENGTH 100

char token[MAX_TOKEN_LENGTH];
int token_index = 0;
char look_ahead = ' ';
FILE *fp;

void parse_error(char *msg);
void next_token();
void program();
void decl_list();
void decl();
void var_list();
void type_spec();
void var();
void params();
void param_list();
void param();
void stmt();
void stmt_list();
void expr();
void term();
void factor();
void identifier();
void number();

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("Please provide the input file as an argument.\n");
    return 1;
  }
  fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Unable to open file.\n");
    return 1;
  }
  program();
  return 0;
}

void parse_error(char *msg) {
  printf("%s\n", msg);
  exit(1);
}

void next_token() {
  int c;

  while ((c = fgetc(fp)) != EOF) {
    if (isspace(c))
      continue;
    else if (isalpha(c) || c == '_') {
      token[token_index++] = c;
      while (isalpha(c = fgetc(fp)) || c == '_')
        token[token_index++] = c;
      token[token_index] = '\0';
      ungetc(c, fp);
      return;
    } else if (isdigit(c)) {
      token[token_index++] = c;
      while (isdigit(c = fgetc(fp)))
        token[token_index++] = c;
      token[token_index] = '\0';
      ungetc(c, fp);
      return;
    } else if (c == '=') {
      c = fgetc(fp);
      if (c == '=') {
        token[0] = token[1] = '=';
        token_index = 2;
        return;
      }
      ungetc(c, fp);
      token[0] = '=';
      token_index = 1;
      return;
    } else if (c == '<') {
      c = fgetc(fp);
      if (c == '=') {
        token[0] = '<';
        token[1] = '=';
        token_index = 2;
        return;
      }
      ungetc(c, fp);
      token[0] = '<';
      token_index = 1;
      return;
    } else if (c == '>') {
      c = fgetc(fp);
      if (c == '=') {
        token[0] = '>';
        token[1] = '=';
        token_index = 2;
        return;
      }
      ungetc(c, fp);
      token[0] = '>';
      token_index = 1;
      return;
    } else if (c == '!') {
      c = fgetc(fp);
      if (c == '=') {
        token[0] = '!';
        token[1] = '=';
        token_index = 2;
        return;
      }
      ungetc(c, fp);
      token[0] = '!';
      token_index = 1;
      return;
    } else if (c == ';') {
      token[0] = ';';
      token_index = 1;
      return;
    } else if (c == '(') {
      token[0] = '(';
      token_index = 1;
      return;
    } else if (c == ')') {
      token[0] = ')';
      token_index = 1;
      return;
    } else if (c == ',') {
      token[0] = ',';
      token_index = 1;
      return;
    } else if (c == '{') {
      token[0] = '{';
      token_index = 1;
      return;
    } else if (c == '}') {
      token[0] = '}';
      token_index = 1;
      return;
    } else if (c == '+') {
      token[0] = '+';
      token_index = 1;
      return;
    } else if (c == '-') {
      token[0] = '-';
      token_index = 1;
      return;
    } else if (c == '*') {
      token[0] = '*';
      token_index = 1;
      return;
    } else if (c == '/') {
      token[0] = '/';
      token_index = 1;
      return;
    } else if (c == '%') {
      token[0] = '%';
      token_index = 1;
      return;
    } else {
      parse_error("Error: Invalid character.");
    }
  }
}

void program() {
  next_token();
  decl_list();
}

void decl_list() {
  while (token[0]) {
    decl();
  }
}

void decl() {
  type_spec();
  var_list();
  if (token[0] != ';')
    parse_error("Error: Expected semicolon.");
  next_token();
}

void var_list() {
  var();
  while (token[0] == ',') {
    next_token();
    var();
  }
}

void type_spec() {
  if (strcmp(token, "int") == 0) {
    next_token();
  } else {
    parse_error("Error: Expected integer type.");
  }
}

void var() {
  if (token[0]) {
    identifier();
    if (token[0] == '[') {
      next_token();
      if (isdigit(token[0])) {
        number();
      } else {
        parse_error("Error: Expected array size.");
      }
      if (token[0] != ']')
        parse_error("Error: Expected closing bracket.");
      next_token();
    }
  } else {
    parse_error("Error: Expected variable name.");
  }
}

void params() {
  if (strcmp(token, "void") == 0) {
    next_token();
    return;
  }
  param_list();
}

void param_list() {
  param();
  while (token[0] == ',') {
    next_token();
    param();
  }
}

void param() {
  type_spec();
  identifier();
  if (token[0] == '[') {
    next_token();
    if (token[0] != ']') {
      parse_error("Error: Expected closing bracket.");
    }
    next_token();
  }
}

void stmt() {
  if (token[0] == '{') {
    next_token();
    stmt_list();
    if (token[0] == '}') {
      next_token();
      return;
    } else {
      parse_error("Error: Expected closing brace.");
    }
  } else if (strcmp(token, "if") == 0) {
    next_token();
    if (token[0] == '(') {
      next_token();
      expr();
      if (token[0] == ')') {
        next_token();
        stmt();
        if (strcmp(token, "else") == 0) {
          next_token();
          stmt();
        }
        return;
      } else {
        parse_error("Error: Expected closing parenthesis.");
      }
    } else {
      parse_error("Error: Expected opening parenthesis.");
    }
  } else if (strcmp(token, "while") == 0) {
    next_token();
    if (token[0] == '(') {
      next_token();
      expr();
      if (token[0] == ')') {
        next_token();
        stmt();
        return;
      } else {
        parse_error("Error: Expected closing parenthesis.");
      }
    } else {
      parse_error("Error: Expected opening parenthesis.");
    }
  } else if (strcmp(token, "return") == 0) {
    next_token();
    if (token[0] != ';') {
      expr();
    }
    if (token[0] != ';') {
      parse_error("Error: Expected semicolon.");
    }
    next_token();
    return;
  } else {
    expr();
    if (token[0] != ';') {
      parse_error("Error: Expected semicolon");
    }
    next_token();
    return;
  }
}

void stmt_list() {
  while (token[0] && token[0] != '}') {
    stmt();
  }
}

void expr() {
  term();
  while (token[0] == '+' || token[0] == '-') {
    next_token();
    term();
  }
}

void term() {
  factor();
  while (token[0] == '*' || token[0] == '/' || token[0] == '%') {
    next_token();
    factor();
  }
}

void factor() {
  if (token[0] == '(') {
    next_token();
    expr();
    if (token[0] != ')') {
      parse_error("Error: Expected closing parenthesis.");
    }
    next_token();
  } else if (isdigit(token[0])) {
    number();
  } else {
    identifier();
    if (token[0] == '(') {
      next_token();
      if (token[0] == ')') {
        next_token();
      } else {
        expr();
        while (token[0] == ',') {
          next_token();
          expr();
        }
        if (token[0] != ')') {
          parse_error("Error: Expected closing parenthesis.");
        }
        next_token();
      }
    } else if (token[0] == '[') {
      next_token();
      expr();
      if (token[0] != ']') {
        parse_error("Error: Expected closing bracket.");
      }
      next_token();
    }
  }
}

void identifier() {
  if (isalpha(token[0]) || token[0] == '_') {
    next_token();
  } else {
    parse_error("Error: Expected identifier.");
  }
}

void number() {
  if (isdigit(token[0])) {
    next_token();
  } else {
    parse_error("Error: Expected number.");
  }
}