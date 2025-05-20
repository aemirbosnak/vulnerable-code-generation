//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SITES 5
#define NUM_AGENTS 10

typedef struct Agent {
  char name[20];
  int site;
  int secrets[NUM_SITES];
  struct Agent* next;
} Agent;

Agent* createAgent(char* name, int site) {
  Agent* newAgent = malloc(sizeof(Agent));
  strcpy(newAgent->name, name);
  newAgent->site = site;
  newAgent->secrets[0] = 1;
  newAgent->secrets[1] = 3;
  newAgent->secrets[2] = 5;
  newAgent->secrets[3] = 7;
  newAgent->secrets[4] = 9;
  newAgent->next = NULL;
  return newAgent;
}

void addToAgents(Agent* head, char* name, int site) {
  Agent* newAgent = createAgent(name, site);
  if (head == NULL) {
    head = newAgent;
  } else {
    newAgent->next = head;
    head = newAgent;
  }
}

int main() {
  srand(time(NULL));
  Agent* head = NULL;

  // Create a bunch of agents
  addToAgents(head, "Bob", 1);
  addToAgents(head, "Alice", 2);
  addToAgents(head, "Charlie", 3);
  addToAgents(head, "Dave", 4);
  addToAgents(head, "Eve", 5);

  // Secret sharing time
  for (int i = 0; i < NUM_SITES; i++) {
    for (Agent* agent = head; agent; agent = agent->next) {
      agent->secrets[i] = rand() % 10 + 1;
    }
  }

  // Let's see what secrets each agent knows
  for (Agent* agent = head; agent; agent = agent->next) {
    printf("%s knows secrets:", agent->name);
    for (int i = 0; i < NUM_SITES; i++) {
      printf(" %d", agent->secrets[i]);
    }
    printf("\n");
  }

  return 0;
}