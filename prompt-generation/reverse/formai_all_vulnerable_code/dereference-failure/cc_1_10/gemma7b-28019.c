//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 50
#define NUM_SITES 2000

typedef struct Node {
  struct Node* next;
  int site;
  int state;
} Node;

void initialize_board(Node** head) {
  *head = malloc(sizeof(Node) * NUM_SITES);
  for (int i = 0; i < NUM_SITES; i++) {
    (*head)[i].next = NULL;
    (*head)[i].site = i;
    (*head)[i].state = 0;
  }
}

void simulate_percolation(Node** head) {
  for (int i = 0; i < NUM_SITES; i++) {
    if ((*head)[i].state == 0) {
      int num_neighbours = 0;
      for (Node* neighbor = (*head)[i].next; neighbor; neighbor++) {
        if (neighbor->state == 1) {
          num_neighbours++;
        }
      }
      if (num_neighbours >= 3) {
        (*head)[i].state = 1;
      }
    }
  }
}

int main() {
  Node** head = NULL;
  initialize_board(head);

  simulate_percolation(head);

  for (int i = 0; i < NUM_SITES; i++) {
    if ((*head)[i].state == 1) {
      printf("%d ", (*head)[i].site);
    }
  }
  printf("\n");

  return 0;
}