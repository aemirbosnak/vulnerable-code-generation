//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 5

struct Player {
  char name[20];
  int score;
  struct Player* next;
};

void addPlayer(struct Player** head) {
  struct Player* newNode = (struct Player*)malloc(sizeof(struct Player));
  strcpy(newNode->name, "Player");
  newNode->score = 0;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void readCSV(struct Player* head) {
  FILE* file = fopen("data.csv", "r");
  char line[1024];
  char* token;

  while (fgets(line, 1024, file) != NULL) {
    token = strtok(line, ",");
    while (token) {
      // Process each token (e.g., update player score)
      for (struct Player* current = head; current; current = current->next) {
        if (strcmp(token, current->name) == 0) {
          current->score = atoi(strtok(NULL, ","));
        }
      }
      token = strtok(NULL, ",");
    }
  }

  fclose(file);
}

int main() {
  struct Player* head = NULL;
  addPlayer(&head);
  addPlayer(&head);
  addPlayer(&head);

  readCSV(head);

  // Print updated player scores
  for (struct Player* current = head; current; current = current->next) {
    printf("%s: %d\n", current->name, current->score);
  }

  return 0;
}