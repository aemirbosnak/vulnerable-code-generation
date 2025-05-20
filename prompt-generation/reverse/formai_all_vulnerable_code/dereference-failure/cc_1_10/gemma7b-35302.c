//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 10

typedef struct Token {
  char *lexeme;
  int lineNumber;
  struct Token *next;
} Token;

Token *parseCSyntax(char *sourceCode) {
  Token *head = NULL;
  int lineNumber = 1;
  char *sourceCodePtr = sourceCode;
  char **tokens = malloc(MAX_TOKENS * sizeof(char *));

  // Eat the source code one line at a time
  while (*sourceCodePtr) {
    // Identify the end of the line
    char *lineEnd = strchr(sourceCodePtr, '\n');

    // Extract the line
    char *line = malloc(lineEnd - sourceCodePtr + 1);
    strncpy(line, sourceCodePtr, lineEnd - sourceCodePtr);

    // Create a token
    Token *token = malloc(sizeof(Token));
    token->lexeme = line;
    token->lineNumber = lineNumber;
    token->next = head;
    head = token;

    // Move to the next line
    sourceCodePtr = lineEnd + 1;
    lineNumber++;
  }

  // Return the head of the token list
  return head;
}

int main() {
  char *sourceCode = "int main() {\n  printf(\"Hello, world!\");\n}\n";
  Token *tokens = parseCSyntax(sourceCode);

  // Print the tokens
  for (Token *token = tokens; token; token = token->next) {
    printf("L%d: %s\n", token->lineNumber, token->lexeme);
  }

  return 0;
}