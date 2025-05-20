//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int pos;
  int history[100];
  int historyPos;
  char operator;
  float result;
} Calculator;

Calculator* createCalculator() {
  Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
  calculator->pos = 0;
  calculator->historyPos = 0;
  return calculator;
}

void addToHistory(Calculator* calculator, float value) {
  calculator->history[calculator->historyPos++] = value;
}

void calculate(Calculator* calculator) {
  switch (calculator->operator) {
    case '+':
      calculator->result = calculator->history[0] + calculator->history[1];
      break;
    case '-':
      calculator->result = calculator->history[0] - calculator->history[1];
      break;
    case '*':
      calculator->result = calculator->history[0] * calculator->history[1];
      break;
    case '/':
      calculator->result = calculator->history[0] / calculator->history[1];
      break;
  }
  addToHistory(calculator, calculator->result);
}

int main() {
  Calculator* calculator = createCalculator();

  // Get calculator input
  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  scanf("%s", input);

  // Parse input and calculate
  int i = 0;
  float operand1 = 0.0f;
  float operand2 = 0.0f;
  calculator->operator = '\0';
  for (i = 0; input[i] != '\0'; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      calculator->operator = input[i];
    } else if (input[i] >= '0' && input[i] <= '9') {
      operand2 = operand2 * 10 + input[i] - '0';
    } else if (input[i] == '.') {
      operand2 = operand2 * 10 + input[i] - '0';
      operand2 /= 10.0f;
    }
  }

  // Calculate result
  calculate(calculator);

  // Display result
  printf("Result: %.2f\n", calculator->result);

  return 0;
}