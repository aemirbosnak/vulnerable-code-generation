//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: brave
// Dance with the Syntax, Embrace the Brave

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom token type
enum TokenType {
  TOKEN_EOF,
  TOKEN_IDEN,
  TOKEN_INUM,
  TOKEN_CNUM,
  TOKEN_STR,
  TOKEN_PUNCT,
  TOKEN_OP
};

// Define the token structure
struct Token {
  enum TokenType type;
  char *value;
};

// Create a linked list node for the token
struct Node {
  struct Token token;
  struct Node *next;
};

// Create a linked list for the tokens
struct List {
  struct Node *head;
  struct Node *tail;
};

// Initialize the token list
void list_init(struct List *list) {
  list->head = NULL;
  list->tail = NULL;
}

// Add a token to the list
void list_add(struct List *list, struct Token token) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->token = token;
  node->next = NULL;

  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
}

// Free the token list
void list_free(struct List *list) {
  struct Node *node = list->head;
  while (node != NULL) {
    struct Node *next = node->next;
    free(node->token.value);
    free(node);
    node = next;
  }

  list->head = NULL;
  list->tail = NULL;
}

// Get the next token from the input stream
struct Token get_token(char **input) {
  struct Token token;

  // Skip whitespace
  while (**input && isspace(**input)) {
    (*input)++;
  }

  // Check for end of input
  if (**input == '\0') {
    token.type = TOKEN_EOF;
    token.value = NULL;
    return token;
  }

  // Check for identifiers
  if (isalpha(**input) || **input == '_') {
    char *start = *input;
    while (isalnum(**input) || **input == '_') {
      (*input)++;
    }

    int len = *input - start;
    token.type = TOKEN_IDEN;
    token.value = (char *)malloc(len + 1);
    memcpy(token.value, start, len);
    token.value[len] = '\0';
    return token;
  }

  // Check for integer literals
  if (isdigit(**input)) {
    char *start = *input;
    while (isdigit(**input)) {
      (*input)++;
    }

    int len = *input - start;
    token.type = TOKEN_INUM;
    token.value = (char *)malloc(len + 1);
    memcpy(token.value, start, len);
    token.value[len] = '\0';
    return token;
  }

  // Check for character literals
  if (**input == '\'') {
    (*input)++;
    char c = **input;
    (*input)++;

    if (**input == '\'') {
      token.type = TOKEN_CNUM;
      token.value = (char *)malloc(2);
      token.value[0] = c;
      token.value[1] = '\0';
      return token;
    } else {
      fprintf(stderr, "Invalid character literal\n");
      exit(EXIT_FAILURE);
    }
  }

  // Check for string literals
  if (**input == '"') {
    (*input)++;
    char *start = *input;
    while (**input && **input != '"') {
      (*input)++;
    }

    int len = *input - start;
    token.type = TOKEN_STR;
    token.value = (char *)malloc(len + 1);
    memcpy(token.value, start, len);
    token.value[len] = '\0';
    return token;
  }

  // Check for punctuation
  if (ispunct(**input)) {
    char c = **input;
    (*input)++;

    token.type = TOKEN_PUNCT;
    token.value = (char *)malloc(2);
    token.value[0] = c;
    token.value[1] = '\0';
    return token;
  }

  // Check for operators
  if (**input == '+' || **input == '-' || **input == '*' || **input == '/' || **input == '%') {
    char c = **input;
    (*input)++;

    token.type = TOKEN_OP;
    token.value = (char *)malloc(2);
    token.value[0] = c;
    token.value[1] = '\0';
    return token;
  }

  // Unknown character
  fprintf(stderr, "Unknown character '%c'\n", **input);
  exit(EXIT_FAILURE);
}

// Display the token list
void print_list(struct List *list) {
  struct Node *node = list->head;
  while (node != NULL) {
    switch (node->token.type) {
      case TOKEN_EOF:
        printf("EOF\n");
        break;
      case TOKEN_IDEN:
        printf("IDEN: %s\n", node->token.value);
        break;
      case TOKEN_INUM:
        printf("INUM: %s\n", node->token.value);
        break;
      case TOKEN_CNUM:
        printf("CNUM: %s\n", node->token.value);
        break;
      case TOKEN_STR:
        printf("STR: %s\n", node->token.value);
        break;
      case TOKEN_PUNCT:
        printf("PUNCT: %s\n", node->token.value);
        break;
      case TOKEN_OP:
        printf("OP: %s\n", node->token.value);
        break;
    }

    node = node->next;
  }
}

// Parse the input stream
struct List *parse(char *input) {
  struct List *list = (struct List *)malloc(sizeof(struct List));
  list_init(list);

  while (*input != '\0') {
    struct Token token = get_token(&input);
    list_add(list, token);
  }

  return list;
}

// Free the parsed input stream
void free_list(struct List *list) {
  list_free(list);
  free(list);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  fseek(fp, 0, SEEK_END);
  long filesize = ftell(fp);
  rewind(fp);

  char *input = (char *)malloc(filesize + 1);
  fread(input, 1, filesize, fp);
  fclose(fp);

  input[filesize] = '\0';

  struct List *list = parse(input);

  print_list(list);

  free_list(list);
  free(input);

  return 0;
}