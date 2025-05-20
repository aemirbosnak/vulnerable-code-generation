//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
  srand(time(NULL));

  int conspiracy_level = rand() % 10 + 1;
  int num_agents = rand() % 20 + 1;

  char **agent_names = malloc(num_agents * sizeof(char *));
  for (int i = 0; i < num_agents; i++)
  {
    agent_names[i] = malloc(20 * sizeof(char));
  }

  for (int i = 0; i < num_agents; i++)
  {
    sprintf(agent_names[i], "Agent %d", i + 1);
  }

  int **mission_objectives = malloc(conspiracy_level * sizeof(int *));
  for (int i = 0; i < conspiracy_level; i++)
  {
    mission_objectives[i] = malloc(20 * sizeof(int));
  }

  for (int i = 0; i < conspiracy_level; i++)
  {
    for (int j = 0; j < num_agents; j++)
    {
      mission_objectives[i][j] = rand() % 1000;
    }
  }

  printf("Conspiracy Level: %d\n", conspiracy_level);
  printf("Number of Agents: %d\n", num_agents);
  printf("Agent Names:\n");
  for (int i = 0; i < num_agents; i++)
  {
    printf("%s\n", agent_names[i]);
  }
  printf("Mission Objectives:\n");
  for (int i = 0; i < conspiracy_level; i++)
  {
    printf("Objective %d:\n", i + 1);
    for (int j = 0; j < num_agents; j++)
    {
      printf("%d\n", mission_objectives[i][j]);
    }
  }

  free(agent_names);
  free(mission_objectives);

  return 0;
}