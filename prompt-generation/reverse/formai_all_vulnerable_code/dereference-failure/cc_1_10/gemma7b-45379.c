//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1024

struct Character
{
  char name[MAX_CHAR];
  int level;
  float health;
  float strength;
  float agility;
  float intelligence;
  struct Character* next;
};

void character_init(struct Character* character)
{
  character->name[0] = '\0';
  character->level = 0;
  character->health = 100.0f;
  character->strength = 0.0f;
  character->agility = 0.0f;
  character->intelligence = 0.0f;
  character->next = NULL;
}

int main()
{
  struct Character* head = NULL;

  // Create a new character
  struct Character* character = malloc(sizeof(struct Character));
  character_init(character);

  // Add character to the head of the list
  if (head == NULL)
  {
    head = character;
  }
  else
  {
    head->next = character;
  }

  // Print character information
  printf("Name: %s\n", head->name);
  printf("Level: %d\n", head->level);
  printf("Health: %.2f%\n", head->health);

  return 0;
}