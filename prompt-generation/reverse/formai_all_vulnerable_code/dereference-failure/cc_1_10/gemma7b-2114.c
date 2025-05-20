//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_WAIT_TIME 5

typedef struct baggage {
  char* name;
  int weight;
  struct baggage* next;
} baggage;

void simulate_baggage_handling(baggage** head) {
  int i = 0;
  time_t start_time, end_time;

  start_time = time(NULL);

  for (i = 0; i < MAX_BAGS; i++) {
    if ((*head)->name == NULL) {
      break;
    }
    printf("Baggage name: %s, weight: %d kg\n", (*head)->name, (*head)->weight);
    (*head) = (*head)->next;
  }

  end_time = time(NULL);

  printf("Total time taken: %ld seconds\n", end_time - start_time);
}

int main() {
  baggage* head = NULL;
  int i;

  for (i = 0; i < MAX_BAGS; i++) {
    head = malloc(sizeof(baggage));
    head->name = malloc(20);
    head->name = "Baggage No. " + i;
    head->weight = rand() % MAX_WAIT_TIME;
    head->next = NULL;

    if (head->next != NULL) {
      break;
    }

    head = head->next;
  }

  simulate_baggage_handling(&head);

  return 0;
}