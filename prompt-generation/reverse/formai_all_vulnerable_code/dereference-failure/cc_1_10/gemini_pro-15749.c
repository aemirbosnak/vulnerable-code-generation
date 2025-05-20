//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100
#define MAX_INPUT_LENGTH 100

typedef enum {
  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV,
  OP_MOD,
  OP_POW,
  OP_SQRT,
  OP_SIN,
  OP_COS,
  OP_TAN,
  OP_LN,
  OP_LOG,
  OP_EXIT
} Operator;

typedef struct {
  double value;
  char *str;
} Token;

typedef struct {
  Token *tokens;
  int top;
} Stack;

Stack *stack;

void init_stack() {
  stack = malloc(sizeof(Stack));
  stack->tokens = malloc(MAX_STACK_SIZE * sizeof(Token));
  stack->top = -1;
}

void push(double value, char *str) {
  stack->top++;
  stack->tokens[stack->top].value = value;
  stack->tokens[stack->top].str = str;
}

double pop() {
  return stack->tokens[stack->top--].value;
}

char *pop_str() {
  return stack->tokens[stack->top--].str;
}

int is_empty() {
  return stack->top == -1;
}

int get_operator(char *str) {
  if (strcmp(str, "+") == 0) {
    return OP_ADD;
  } else if (strcmp(str, "-") == 0) {
    return OP_SUB;
  } else if (strcmp(str, "*") == 0) {
    return OP_MUL;
  } else if (strcmp(str, "/") == 0) {
    return OP_DIV;
  } else if (strcmp(str, "%") == 0) {
    return OP_MOD;
  } else if (strcmp(str, "^") == 0) {
    return OP_POW;
  } else if (strcmp(str, "sqrt") == 0) {
    return OP_SQRT;
  } else if (strcmp(str, "sin") == 0) {
    return OP_SIN;
  } else if (strcmp(str, "cos") == 0) {
    return OP_COS;
  } else if (strcmp(str, "tan") == 0) {
    return OP_TAN;
  } else if (strcmp(str, "ln") == 0) {
    return OP_LN;
  } else if (strcmp(str, "log") == 0) {
    return OP_LOG;
  } else if (strcmp(str, "exit") == 0) {
    return OP_EXIT;
  } else {
    return -1;
  }
}

double evaluate(Operator op, double a, double b) {
  switch (op) {
    case OP_ADD:
      return a + b;
    case OP_SUB:
      return a - b;
    case OP_MUL:
      return a * b;
    case OP_DIV:
      return a / b;
    case OP_MOD:
      return fmod(a, b);
    case OP_POW:
      return pow(a, b);
    case OP_SQRT:
      return sqrt(a);
    case OP_SIN:
      return sin(a);
    case OP_COS:
      return cos(a);
    case OP_TAN:
      return tan(a);
    case OP_LN:
      return log(a);
    case OP_LOG:
      return log10(a);
    default:
      return 0;
  }
}

void process_input(char *input) {
  char *token;
  char *end;
  while ((token = strtok(input, " ")) != NULL) {
    double value = strtod(token, &end);
    if (end == token) {
      int op = get_operator(token);
      if (op == OP_EXIT) {
        exit(0);
      } else {
        if (is_empty()) {
          printf("Error: Not enough operands\n");
        } else {
          double b = pop();
          double a = pop();
          double result = evaluate(op, a, b);
          push(result, "");
        }
      }
    } else {
      push(value, token);
    }
    input = NULL;
  }
}

int main() {
  init_stack();

  printf("Welcome to the Claude Shannon Scientific Calculator\n");
  printf("Enter an expression or 'exit' to quit\n");

  char input[MAX_INPUT_LENGTH];
  while (1) {
    printf("> ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    process_input(input);

    if (is_empty()) {
      printf("0\n");
    } else {
      printf("%s\n", pop_str());
    }
  }

  return 0;
}