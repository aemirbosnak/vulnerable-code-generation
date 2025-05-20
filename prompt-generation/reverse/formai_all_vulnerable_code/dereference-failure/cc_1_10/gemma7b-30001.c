//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void baggage_handling_simulation()
{
  int baggage_count = 0;
  char **baggage_list = NULL;

  // Allocate memory for baggage list
  baggage_list = (char**)malloc(sizeof(char*) * 10);
  for (int i = 0; i < 10; i++)
  {
    baggage_list[i] = (char*)malloc(sizeof(char) * 20);
  }

  // Simulate baggage check-in
  while (baggage_count < 10)
  {
    printf("Enter baggage weight: ");
    int weight = atoi(fgets(baggage_list[baggage_count], 20, stdin));

    // Check if baggage weight is valid
    if (weight < 20 && weight > 50)
    {
      printf("Error: baggage weight is invalid.\n");
    }
    else
    {
      baggage_count++;
    }
  }

  // Print baggage list
  printf("Baggage list:\n");
  for (int i = 0; i < baggage_count; i++)
  {
    printf("Baggage %d: %d kg\n", i + 1, atoi(baggage_list[i]));
  }

  // Free memory
  for (int i = 0; i < 10; i++)
  {
    free(baggage_list[i]);
  }
  free(baggage_list);
}

int main()
{
  baggage_handling_simulation();

  return 0;
}