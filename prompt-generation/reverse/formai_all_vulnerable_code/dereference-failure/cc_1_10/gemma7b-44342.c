//Gemma-7B DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
  // Define the data structure for storing survivor information
  typedef struct Survivor
  {
    char name[MAX_SIZE];
    int age;
    char occupation[MAX_SIZE];
    struct Survivor* next;
  } Survivor;

  // Create a linked list of survivors
  Survivor* head = NULL;

  // Simulate the post-apocalyptic environment
  char environment[] = "The ruins of what was once a city lie before you. You are the only survivor in this desolate wasteland.";

  // Display the environment
  printf("%s", environment);

  // Get survivor information from the user
  printf("Enter your name: ");
  scanf("%s", head->name);

  // Get the survivor's age
  printf("Enter your age: ");
  scanf("%d", &head->age);

  // Get the survivor's occupation
  printf("Enter your occupation: ");
  scanf("%s", head->occupation);

  // Insert the survivor into the linked list
  head = (Survivor*)malloc(sizeof(Survivor));
  head->next = NULL;
  head = head;

  // Print the survivor's information
  printf("Name: %s", head->name);
  printf("\nAge: %d", head->age);
  printf("\nOccupation: %s", head->occupation);

  return 0;
}