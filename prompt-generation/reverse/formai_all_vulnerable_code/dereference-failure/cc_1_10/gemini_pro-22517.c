//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Happy car colors
char* colors[] = {"Sunshine Yellow", "Emerald Green", "Bubblegum Pink", "Cotton Candy Blue", "Twinkle Star Silver"};

// Happy car sounds
char* sounds[] = {"Beep Beep!", "Honk Honk!", "Vroom Vroom!", "Beep Boop!", "Toot Toot!"};

// Create a happy car
typedef struct car {
  char* color;
  char* sound;
  int speed;
  int direction;
} car;

// Create a new happy car
car* create_car() {
  // Allocate memory for the car
  car* c = malloc(sizeof(car));

  // Set the car's color to a random happy color
  c->color = colors[rand() % 5];

  // Set the car's sound to a random happy sound
  c->sound = sounds[rand() % 5];

  // Set the car's speed to a random speed
  c->speed = rand() % 100;

  // Set the car's direction to a random direction
  c->direction = rand() % 360;

  // Return the car
  return c;
}

// Drive the happy car
void drive_car(car* c) {
  // Print the car's happy status
  printf("The %s car is driving at %d mph in the %d direction and making the %s sound!\n", c->color, c->speed, c->direction, c->sound);
}

// Destroy the happy car
void destroy_car(car* c) {
  // Free the memory allocated for the car
  free(c);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Create a happy car
  car* c = create_car();

  // Drive the happy car
  drive_car(c);

  // Destroy the happy car
  destroy_car(c);

  return 0;
}