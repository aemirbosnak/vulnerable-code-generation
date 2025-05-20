//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

int main() {
  // Declare variables to store user input
  int age, height, weight;
  char name[MAX_LENGTH];

  // Print a happy message to start
  printf("Welcome to the Happy Arithmetic Program! \n");

  // Get the user's name
  printf("What's your name? ");
  fgets(name, MAX_LENGTH, stdin);

  // Check if the user's name is too long
  if (strlen(name) > MAX_LENGTH) {
    printf("Oops! Your name is too long. Let's try again.\n");
    return 1;
  }

  // Get the user's age
  printf("How old are you? ");
  scanf("%d", &age);

  // Check if the user's age is negative
  if (age < 0) {
    printf("Hey, watch it! Age can't be negative. Let's try again.\n");
    return 1;
  }

  // Get the user's height
  printf("How tall are you? ");
  scanf("%d", &height);

  // Check if the user's height is negative
  if (height < 0) {
    printf("Oops! Height can't be negative. Let's try again.\n");
    return 1;
  }

  // Get the user's weight
  printf("How much do you weigh? ");
  scanf("%d", &weight);

  // Check if the user's weight is negative
  if (weight < 0) {
    printf("Uh-oh! Weight can't be negative. Let's try again.\n");
    return 1;
  }

  // Calculate the user's BMI
  double bmi = (weight / (height * height)) * 10000;

  // Check if the user's BMI is too high
  if (bmi > 30) {
    printf("Whoa! You're a bit on the heavy side. Maybe try some exercise? \n");
  } else {
    printf("You're just right! Keep on keepin' on! \n");
  }

  // Print a happy message to end
  printf("Thanks for playing the Happy Arithmetic Program! \n");

  return 0;
}