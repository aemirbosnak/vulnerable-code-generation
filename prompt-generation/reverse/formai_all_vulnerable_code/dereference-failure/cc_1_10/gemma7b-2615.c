//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define BAG_SIZE 20

typedef struct Bag
{
  int weight;
  char *content;
  struct Bag *next;
} Bag;

void simulate_baggage_handling(Bag *head)
{
  int i, total_weight = 0;
  for (i = 0; head && i < MAX_BAGS; i++)
  {
    total_weight += head->weight;
    printf("Bag %d: Content - %s, Weight - %d\n", i + 1, head->content, head->weight);
    head = head->next;
  }
  printf("Total Weight: %d\n", total_weight);
}

int main()
{
  Bag *head = NULL;
  int num_bags = 0;

  // Simulate baggage handling for a number of bags
  for (int i = 0; i < MAX_BAGS; i++)
  {
    // Create a new bag
    Bag *new_bag = malloc(sizeof(Bag));
    new_bag->weight = rand() % BAG_SIZE;
    new_bag->content = malloc(rand() % 20) ? "Stuff" : "";
    new_bag->next = NULL;

    // Add the new bag to the head of the list
    if (head == NULL)
    {
      head = new_bag;
    }
    else
    {
      head->next = new_bag;
      head = new_bag;
    }
    num_bags++;
  }

  // Simulate baggage handling
  simulate_baggage_handling(head);

  return 0;
}