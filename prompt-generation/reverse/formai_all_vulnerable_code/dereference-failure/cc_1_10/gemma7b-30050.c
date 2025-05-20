//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct calculator {
  char buffer[MAX_BUFFER_SIZE];
  int pos;
  double result;
  double num1;
  double num2;
  char operator;
} calculator;

calculator* create_calculator() {
  calculator* calc = (calculator*)malloc(sizeof(calculator));
  calc->pos = 0;
  calc->result = 0;
  calc->num1 = 0;
  calc->num2 = 0;
  calc->operator = '\0';
  return calc;
}

void destroy_calculator(calculator* calc) {
  free(calc);
}

void clear_calculator(calculator* calc) {
  calc->pos = 0;
  calc->result = 0;
  calc->num1 = 0;
  calc->num2 = 0;
  calc->operator = '\0';
}

void set_num1(calculator* calc, double num) {
  calc->num1 = num;
}

void set_num2(calculator* calc, double num) {
  calc->num2 = num;
}

void set_operator(calculator* calc, char operator) {
  calc->operator = operator;
}

double get_result(calculator* calc) {
  switch (calc->operator) {
    case '+':
      return calc->num1 + calc->num2;
    case '-':
      return calc->num1 - calc->num2;
    case '*':
      return calc->num1 * calc->num2;
    case '/':
      return calc->num1 / calc->num2;
    default:
      return 0;
  }
}

int main() {
  calculator* calc = create_calculator();
  clear_calculator(calc);

  // Perform calculations
  set_num1(calc, 10.0);
  set_num2(calc, 20.0);
  set_operator(calc, '+');
  calc->result = get_result(calc);
  printf("The result is: %.2lf\n", calc->result);

  destroy_calculator(calc);

  return 0;
}