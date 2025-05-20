//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct baggage_tag {
  char tag[5];
  int weight;
  struct baggage_tag* next;
} baggage_tag;

baggage_tag* create_baggage(char* tag, int weight) {
  baggage_tag* new_baggage = malloc(sizeof(baggage_tag));
  strcpy(new_baggage->tag, tag);
  new_baggage->weight = weight;
  new_baggage->next = NULL;
  return new_baggage;
}

void print_baggage(baggage_tag* baggage) {
  while (baggage) {
    printf("Tag: %s, Weight: %d\n", baggage->tag, baggage->weight);
    baggage = baggage->next;
  }
}

int main() {
  // Create a baggage list
  baggage_tag* baggage_list = create_baggage("ABC", 20);
  baggage_list = create_baggage("XYZ", 10);
  baggage_list = create_baggage("123", 30);

  // Print the baggage list
  print_baggage(baggage_list);

  // Randomly select a baggage tag
  srand(time(NULL));
  int random_index = rand() % 3;

  // Get the baggage tag associated with the random index
  baggage_tag* selected_baggage = baggage_list;
  for (int i = 0; i < random_index; i++) {
    selected_baggage = selected_baggage->next;
  }

  // Print the selected baggage tag
  printf("Selected baggage tag: %s\n", selected_baggage->tag);

  return 0;
}