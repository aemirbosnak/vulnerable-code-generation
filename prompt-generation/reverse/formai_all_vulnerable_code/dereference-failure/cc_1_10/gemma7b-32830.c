//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main()
{
  system("clear");
  printf("Here is a unique C Periodic Table Quiz:\n\n");

  // Create a table of elements
  char **elements = malloc(sizeof(char *) * 11);
  elements[0] = "Hydrogen";
  elements[1] = "Helium";
  elements[2] = "Lithium";
  elements[3] = "Sodium";
  elements[4] = "Potassium";
  elements[5] = "Calcium";
  elements[6] = "Iron";
  elements[7] = "Gold";
  elements[8] = "Silver";
  elements[9] = "Copper";
  elements[10] = "Uranium";

  // Create a list of properties
  int **properties = malloc(sizeof(int *) * 11);
  properties[0] = 1;
  properties[1] = 2;
  properties[2] = 3;
  properties[3] = 5;
  properties[4] = 7;
  properties[5] = 20;
  properties[6] = 26;
  properties[7] = 69;
  properties[8] = 47;
  properties[9] = 29;
  properties[10] = 92;

  // Print the table
  printf("Element | Properties\n");
  printf("----- |--------\n");
  for (int i = 0; i < 11; i++)
  {
    printf("%s | %d\n", elements[i], properties[i]);
  }

  // Free the memory
  free(elements);
  free(properties);

  return 0;
}