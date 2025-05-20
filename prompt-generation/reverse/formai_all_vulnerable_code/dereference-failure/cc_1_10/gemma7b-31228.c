//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VAR 10

double calculate(char **vars, int numVars, double value)
{
  double result = value;
  for (int i = 0; i < numVars; i++)
  {
    result = result * pow(atof(vars[i]), i);
  }
  return result;
}

int main()
{
  char **vars = (char **)malloc(MAX_VAR * sizeof(char *));
  for (int i = 0; i < MAX_VAR; i++)
  {
    vars[i] = (char *)malloc(20 * sizeof(char));
  }

  int numVars = 0;
  double value;

  printf("Enter the number of variables: ");
  scanf("%d", &numVars);

  printf("Enter the variable names: ");
  for (int i = 0; i < numVars; i++)
  {
    scanf("%s", vars[i]);
  }

  printf("Enter the value: ");
  scanf("%lf", &value);

  double result = calculate(vars, numVars, value);

  printf("The result is: %lf\n", result);

  for (int i = 0; i < MAX_VAR; i++)
  {
    free(vars[i]);
  }
  free(vars);

  return 0;
}