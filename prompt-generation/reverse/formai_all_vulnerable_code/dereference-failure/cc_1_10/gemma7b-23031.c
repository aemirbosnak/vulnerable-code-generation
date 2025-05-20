//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 255

void calculate(char **buffer, int *index);

int main()
{
  char **buffer = NULL;
  int index = 0;

  buffer = (char **)malloc(MAX_BUFFER_SIZE * sizeof(char *));

  for (int i = 0; i < MAX_BUFFER_SIZE; i++)
  {
    buffer[i] = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));
  }

  printf("Enter an expression: ");

  // Read the expression from the user
  char ch;
  while ((ch = getchar()) != '\n')
  {
    buffer[index][0] = ch;
    index++;
  }

  // Calculate the expression
  calculate(buffer, &index);

  // Print the result
  printf("The result is: %f\n", buffer[0][0]);

  // Free the memory
  for (int i = 0; i < MAX_BUFFER_SIZE; i++)
  {
    free(buffer[i]);
  }
  free(buffer);

  return 0;
}

void calculate(char **buffer, int *index)
{
  int i = 0;
  float result = 0.0f;
  char operator = '\0';

  // Iterate over the buffer
  for (i = 0; buffer[i][0] != '\0'; i++)
  {
    // Check if the character is an operator
    if (buffer[i][0] == '+' || buffer[i][0] == '-' || buffer[i][0] == '*' || buffer[i][0] == '/')
    {
      operator = buffer[i][0];
    }
    // Convert the number to an integer
    else
    {
      int number = atoi(buffer[i][0]);

      // Calculate the operation
      switch (operator)
      {
        case '+':
          result += number;
          break;
        case '-':
          result -= number;
          break;
        case '*':
          result *= number;
          break;
        case '/':
          result /= number;
          break;
      }
    }
  }

  // Store the result in the first element of the buffer
  buffer[0][0] = result;
}