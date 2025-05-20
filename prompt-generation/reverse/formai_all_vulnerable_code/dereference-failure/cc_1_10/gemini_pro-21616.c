//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A linked list to store the tokens
typedef struct Token {
  char *value;
  struct Token *next;
} Token;

// A linked list to store the statements
typedef struct Statement {
  int type; // 0 = expression, 1 = declaration
  char *value;
  struct Statement *next;
} Statement;

// Parse a string into a linked list of tokens
Token *tokenize(char *input) {
  Token *head = NULL;
  Token *tail = NULL;

  char *token = strtok(input, " ");
  while (token != NULL) {
    Token *newToken = malloc(sizeof(Token));
    newToken->value = token;
    newToken->next = NULL;

    if (head == NULL) {
      head = newToken;
      tail = newToken;
    } else {
      tail->next = newToken;
      tail = newToken;
    }

    token = strtok(NULL, " ");
  }

  return head;
}

// Parse a linked list of tokens into a linked list of statements
Statement *parse(Token *tokens) {
  Statement *head = NULL;
  Statement *tail = NULL;

  Token *token = tokens;
  while (token != NULL) {
    Statement *newStatement = malloc(sizeof(Statement));

    // Check if the token is a keyword
    if (strcmp(token->value, "int") == 0) {
      newStatement->type = 1; // Declaration
      newStatement->value = token->value;
    } else {
      newStatement->type = 0; // Expression
      newStatement->value = token->value;
    }

    newStatement->next = NULL;

    if (head == NULL) {
      head = newStatement;
      tail = newStatement;
    } else {
      tail->next = newStatement;
      tail = newStatement;
    }

    token = token->next;
  }

  return head;
}

// Print a linked list of statements
void printStatements(Statement *statements) {
  Statement *statement = statements;
  while (statement != NULL) {
    printf("%s ", statement->value);
    statement = statement->next;
  }

  printf("\n");
}

int main() {
  // Get the input string from the user
  char input[1024];
  printf("Enter a C expression or declaration: ");
  fgets(input, 1024, stdin);

  // Tokenize the input string
  Token *tokens = tokenize(input);

  // Parse the linked list of tokens into a linked list of statements
  Statement *statements = parse(tokens);

  // Print the linked list of statements
  printStatements(statements);

  return 0;
}