//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHOICES 5

typedef struct Choice {
  char *name;
  struct Choice *next;
} Choice;

Choice *createChoice(char *name, Choice *next) {
  Choice *choice = malloc(sizeof(Choice));
  choice->name = strdup(name);
  choice->next = next;
  return choice;
}

void playGame() {
  Choice *choices = createChoice("Go to the library", NULL);
  choices = createChoice("Go to the park", choices);
  choices = createChoice("Go to the museum", choices);
  choices = createChoice("Go home", choices);

  printf("You are at a crossroads.\n");
  for (Choice *choice = choices; choice; choice = choice->next) {
    printf("  %s\n", choice->name);
  }

  char input;
  scanf("Enter your choice: ", &input);

  switch (input) {
    case 'a':
      printf("You went to the library.\n");
      break;
    case 'b':
      printf("You went to the park.\n");
      break;
    case 'c':
      printf("You went to the museum.\n");
      break;
    case 'd':
      printf("You went home.\n");
      break;
    default:
      printf("Invalid input.\n");
  }
}

int main() {
  playGame();
  return 0;
}