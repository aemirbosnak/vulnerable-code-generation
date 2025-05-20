//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 100

typedef struct {
  char *str;
  int len;
  int pos;
} String;

String *newString(char *str) {
  String *s = malloc(sizeof(String));
  s->str = str;
  s->len = strlen(str);
  s->pos = 0;
  return s;
}

void freeString(String *s) {
  free(s->str);
  free(s);
}

int nextChar(String *s) {
  if (s->pos < s->len) {
    return s->str[s->pos++];
  } else {
    return EOF;
  }
}

int isWhitespace(int c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int isAlpha(int c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isDigit(int c) {
  return c >= '0' && c <= '9';
}

int isPunctuation(int c) {
  return c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':' || c == '"' || c == '\'';
}

int isReserved(int c) {
  return c == '_' || c == '$' || c == '#';
}

int isOperator(int c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '>' || c == '<' || c == '=' || c == '&' || c == '|';
}

int isSymbol(int c) {
  return !isWhitespace(c) && !isAlpha(c) && !isDigit(c) && !isPunctuation(c) && !isReserved(c) && !isOperator(c);
}

int isIdentifier(String *s) {
  if (s->len == 0) {
    return 0;
  }
  if (!isAlpha(s->str[0]) && !isReserved(s->str[0])) {
    return 0;
  }
  for (int i = 1; i < s->len; i++) {
    if (!isAlpha(s->str[i]) && !isDigit(s->str[i]) && !isReserved(s->str[i])) {
      return 0;
    }
  }
  return 1;
}

int isNumber(String *s) {
  if (s->len == 0) {
    return 0;
  }
  if (s->str[0] == '-') {
    if (s->len == 1) {
      return 0;
    }
    for (int i = 1; i < s->len; i++) {
      if (!isDigit(s->str[i])) {
        return 0;
      }
    }
    return 1;
  } else {
    for (int i = 0; i < s->len; i++) {
      if (!isDigit(s->str[i])) {
        return 0;
      }
    }
    return 1;
  }
}

int isKeyword(String *s) {
  static char *keywords[] = {"if", "else", "while", "for", "return", "break", "continue", "int", "float", "char", "void", "main"};
  for (int i = 0; i < sizeof(keywords) / sizeof(char *); i++) {
    if (strcmp(s->str, keywords[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

int isLiteral(String *s) {
  if (s->len == 0) {
    return 0;
  }
  if (s->str[0] == '"' && s->str[s->len - 1] == '"') {
    return 1;
  } else if (s->str[0] == '\'' && s->str[s->len - 1] == '\'') {
    return 1;
  } else {
    return 0;
  }
}

int isComment(String *s) {
  if (s->len >= 2 && s->str[0] == '/' && s->str[1] == '/') {
    return 1;
  } else if (s->len >= 2 && s->str[0] == '/' && s->str[1] == '*') {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char *Romeo = "O Romeo, Romeo! Wherefore art thou Romeo?Deny thy father and refuse thy name;Or, if thou wilt not, be but sworn my love,And I'll no longer be a Capulet.";
  char *Juliet = "O Romeo, Romeo! Wherefore art thou Romeo?Deny thy father and refuse thy name;Or, if thou wilt not, be but sworn my love,And I'll no longer be a Montague.";

  String *romeo = newString(Romeo);
  String *juliet = newString(Juliet);

  int romeoScore = 0;
  int julietScore = 0;

  while (1) {
    int c1 = nextChar(romeo);
    int c2 = nextChar(juliet);
    if (c1 == EOF && c2 == EOF) {
      break;
    }

    // Skip whitespace
    while (isWhitespace(c1)) {
      c1 = nextChar(romeo);
    }
    while (isWhitespace(c2)) {
      c2 = nextChar(juliet);
    }

    // Check for comments
    if (isComment(romeo)) {
      while (nextChar(romeo) != '\n') {}
      continue;
    }
    if (isComment(juliet)) {
      while (nextChar(juliet) != '\n') {}
      continue;
    }

    // Check for identifiers
    if (isIdentifier(romeo)) {
      if (isKeyword(romeo)) {
        romeoScore += 1;
      } else {
        romeoScore += 2;
      }
    }
    if (isIdentifier(juliet)) {
      if (isKeyword(juliet)) {
        julietScore += 1;
      } else {
        julietScore += 2;
      }
    }

    // Check for numbers
    if (isNumber(romeo)) {
       romeoScore += 3;
    }
    if (isNumber(juliet)) {
      julietScore += 3;
    }

    // Check for literals
    if (isLiteral(romeo)) {
      romeoScore += 4;
    }
    if (isLiteral(juliet)) {
      julietScore += 4;
    }

    // Check for punctuation
    if (isPunctuation(c1)) {
      romeoScore += 1;
    }
    if (isPunctuation(c2)) {
      julietScore += 1;
    }

    // Check for symbols
    if (isSymbol(c1)) {
      romeoScore += 1;
    }
    if (isSymbol(c2)) {
      julietScore += 1;
    }
  }

  // Print the results
  printf("Romeo's score: %d\n", romeoScore);
  printf("Juliet's score: %d\n", julietScore);

  // Free the strings
  freeString(romeo);
  freeString(juliet);

  return 0;
}