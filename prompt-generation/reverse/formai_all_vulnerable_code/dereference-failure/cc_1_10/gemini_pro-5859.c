//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef enum {
  NUMBER = 0,
  OPERATOR,
  FUNCTION,
  LEFT_BRACKET,
  RIGHT_BRACKET
} token_type;

typedef struct {
  token_type type;
  char *value;
} token;

typedef struct {
  int capacity;
  int size;
  token *tokens;
} token_list;

#define TOKEN_LIST_INITIAL_CAPACITY 10

token_list *token_list_create() {
  token_list *list = malloc(sizeof(token_list));
  if (list == NULL) {
    return NULL;
  }
  list->capacity = TOKEN_LIST_INITIAL_CAPACITY;
  list->size = 0;
  list->tokens = malloc(list->capacity * sizeof(token));
  if (list->tokens == NULL) {
    free(list);
    return NULL;
  }
  return list;
}

void token_list_destroy(token_list *list) {
  for (int i = 0; i < list->size; i++) {
    free(list->tokens[i].value);
  }
  free(list->tokens);
  free(list);
}

int token_list_push(token_list *list, token *token) {
  if (list->size >= list->capacity) {
    list->capacity *= 2;
    list->tokens = realloc(list->tokens, list->capacity * sizeof(token));
    if (list->tokens == NULL) {
      return -1;
    }
  }
  list->tokens[list->size] = *token;
  list->size++;
  return 0;
}

token token_create(token_type type, char *value) {
  token token;
  token.type = type;
  token.value = value;
  return token;
}

int is_operator(char c) {
  return strchr("+-*/^", c) != NULL;
}

int is_function(char *str) {
  return strcmp(str, "sin") == 0 || strcmp(str, "cos") == 0 || strcmp(str, "tan") == 0;
}

token_list *tokenize(char *expr) {
  token_list *list = token_list_create();
  if (list == NULL) {
    return NULL;
  }
  char *token_start = expr;
  char *token_end = expr;
  while (*token_end != '\0') {
    if (isspace(*token_end)) {
      token_end++;
      token_start = token_end;
      continue;
    }
    if (is_operator(*token_end)) {
      token token = token_create(OPERATOR, strndup(token_start, token_end - token_start));
      if (token_list_push(list, &token) != 0) {
        token_list_destroy(list);
        return NULL;
      }
      token_start = token_end + 1;
    } else if (is_function(token_start)) {
      token token = token_create(FUNCTION, strndup(token_start, token_end - token_start));
      if (token_list_push(list, &token) != 0) {
        token_list_destroy(list);
        return NULL;
      }
      token_start = token_end + 1;
    } else if (*token_end == '(') {
      token token = token_create(LEFT_BRACKET, strdup("("));
      if (token_list_push(list, &token) != 0) {
        token_list_destroy(list);
        return NULL;
      }
      token_start = token_end + 1;
    } else if (*token_end == ')') {
      token token = token_create(RIGHT_BRACKET, strdup(")"));
      if (token_list_push(list, &token) != 0) {
        token_list_destroy(list);
        return NULL;
      }
      token_start = token_end + 1;
    } else {
      token_end++;
    }
  }
  if (token_start != token_end) {
    token token = token_create(NUMBER, strndup(token_start, token_end - token_start));
    if (token_list_push(list, &token) != 0) {
      token_list_destroy(list);
      return NULL;
    }
  }
  return list;
}

double evaluate(token_list *list) {
  double stack[100];
  int stack_size = 0;
  for (int i = 0; i < list->size; i++) {
    token token = list->tokens[i];
    switch (token.type) {
      case NUMBER:
        stack[stack_size++] = atof(token.value);
        break;
      case OPERATOR:
        if (stack_size < 2) {
          fprintf(stderr, "Error: Invalid expression\n");
          return NAN;
        }
        double op2 = stack[--stack_size];
        double op1 = stack[--stack_size];
        switch (token.value[0]) {
          case '+': stack[stack_size++] = op1 + op2; break;
          case '-': stack[stack_size++] = op1 - op2; break;
          case '*': stack[stack_size++] = op1 * op2; break;
          case '/': stack[stack_size++] = op1 / op2; break;
          case '^': stack[stack_size++] = pow(op1, op2); break;
          default: fprintf(stderr, "Error: Invalid operator '%s'\n", token.value); return NAN;
        }
        break;
      case FUNCTION:
        if (stack_size < 1) {
          fprintf(stderr, "Error: Invalid expression\n");
          return NAN;
        }
        double arg = stack[--stack_size];
        if (strcmp(token.value, "sin") == 0) { stack[stack_size++] = sin(arg); }
        else if (strcmp(token.value, "cos") == 0) { stack[stack_size++] = cos(arg); }
        else if (strcmp(token.value, "tan") == 0) { stack[stack_size++] = tan(arg); }
        else { fprintf(stderr, "Error: Invalid function '%s'\n", token.value); return NAN; }
        break;
      case LEFT_BRACKET:
        break;
      case RIGHT_BRACKET:
        if (stack_size < 1) {
          fprintf(stderr, "Error: Invalid expression\n");
          return NAN;
        }
        stack[stack_size - 1] = stack[--stack_size];
        break;
    }
  }
  if (stack_size != 1) {
    fprintf(stderr, "Error: Invalid expression\n");
    return NAN;
  }
  return stack[0];
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <expression>\n", argv[0]);
    return 1;
  }
  char *expr = argv[1];
  token_list *list = tokenize(expr);
  if (list == NULL) {
    fprintf(stderr, "Error: Invalid expression\n");
    return 1;
  }
  double result = evaluate(list);
  if (isnan(result)) {
    fprintf(stderr, "Error: Invalid expression\n");
    token_list_destroy(list);
    return 1;
  }
  printf("%f\n", result);
  token_list_destroy(list);
  return 0;
}