//Gemma-7B DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a struct to store information about a dragon
typedef struct Dragon {
  char name[20];
  int age;
  double height;
  struct Dragon* next;
} Dragon;

// Function to insert a dragon into the linked list
void insertDragon(Dragon** head, char* name, int age, double height) {
  // Allocate memory for the new dragon
  Dragon* newDragon = malloc(sizeof(Dragon));

  // Copy the dragon's name, age, and height into the new dragon
  strcpy(newDragon->name, name);
  newDragon->age = age;
  newDragon->height = height;

  // If the head of the list is NULL, make the new dragon the head of the list
  if (*head == NULL) {
    *head = newDragon;
  } else {
    // Traverse the list until the last dragon is reached
    Dragon* currentDragon = *head;
    while (currentDragon->next != NULL) {
      currentDragon = currentDragon->next;
    }

    // Insert the new dragon at the end of the list
    currentDragon->next = newDragon;
  }
}

// Function to print the dragons in the list
void printDragons(Dragon* head) {
  // Traverse the list and print the dragons
  Dragon* currentDragon = head;
  while (currentDragon) {
    printf("Name: %s, Age: %d, Height: %.2lf\n", currentDragon->name, currentDragon->age, currentDragon->height);
    currentDragon = currentDragon->next;
  }
}

int main() {
  // Create a linked list of dragons
  Dragon* head = NULL;

  // Insert some dragons into the list
  insertDragon(&head, "Drogon", 15, 2.0);
  insertDragon(&head, "Viserion", 13, 1.8);
  insertDragon(&head, "Rhaegal", 12, 1.9);

  // Print the dragons in the list
  printDragons(head);

  return 0;
}