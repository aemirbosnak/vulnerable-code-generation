//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int baggage_count = 0;
  char **baggage_list = NULL;

  // Create a baggage list
  baggage_list = malloc(sizeof(char *) * 10);
  for (int i = 0; i < 10; i++)
  {
    baggage_list[i] = malloc(sizeof(char) * 20);
  }

  // Simulate baggage check-in
  printf("Welcome to the C Airport Baggage Handling System!\n");
  printf("Please enter the number of bags you have:");
  int num_bags = 0;
  scanf("%d", &num_bags);

  for (int i = 0; i < num_bags; i++)
  {
    printf("Enter the name of your bag:");
    scanf("%s", baggage_list[i]);
    baggage_count++;
  }

  // Print baggage list
  printf("Your baggage list:");
  for (int i = 0; i < baggage_count; i++)
  {
    printf("%s ", baggage_list[i]);
  }

  // Calculate baggage fees
  int total_fees = 0;
  for (int i = 0; i < baggage_count; i++)
  {
    if (strlen(baggage_list[i]) > 10)
    {
      total_fees++;
    }
  }

  // Print total fees
  printf("\nTotal fees: %d", total_fees);

  // Free memory
  for (int i = 0; i < 10; i++)
  {
    free(baggage_list[i]);
  }
  free(baggage_list);

  return 0;
}