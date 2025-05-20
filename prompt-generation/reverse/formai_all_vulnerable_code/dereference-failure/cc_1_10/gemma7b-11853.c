//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct _C_Fitness_Tracker
{
  char name[MAX_CHAR];
  int age;
  float height;
  float weight;
  float target_heart_rate;
  int steps_taken;
  int calories_burned;
  struct _C_Fitness_Tracker *next;
} C_Fitness_Tracker;

void initialize_fitness_tracker(C_Fitness_Tracker *tracker)
{
  tracker->name[0] = '\0';
  tracker->age = 0;
  tracker->height = 0.0f;
  tracker->weight = 0.0f;
  tracker->target_heart_rate = 0.0f;
  tracker->steps_taken = 0;
  tracker->calories_burned = 0;
  tracker->next = NULL;
}

void add_fitness_tracker(C_Fitness_Tracker **tracker_head)
{
  C_Fitness_Tracker *new_tracker = (C_Fitness_Tracker *)malloc(sizeof(C_Fitness_Tracker));
  initialize_fitness_tracker(new_tracker);

  if (*tracker_head)
  {
    (*tracker_head)->next = new_tracker;
    *tracker_head = new_tracker;
  }
  else
  {
    *tracker_head = new_tracker;
  }
}

void display_fitness_tracker(C_Fitness_Tracker *tracker)
{
  printf("Name: %s\n", tracker->name);
  printf("Age: %d\n", tracker->age);
  printf("Height: %.2f meters\n", tracker->height);
  printf("Weight: %.2f kilograms\n", tracker->weight);
  printf("Target Heart Rate: %.2f beats per minute\n", tracker->target_heart_rate);
  printf("Steps Taken: %d\n", tracker->steps_taken);
  printf("Calories Burned: %d\n", tracker->calories_burned);
}

int main()
{
  C_Fitness_Tracker *head = NULL;

  add_fitness_tracker(&head);
  add_fitness_tracker(&head);
  add_fitness_tracker(&head);

  display_fitness_tracker(head);

  return 0;
}