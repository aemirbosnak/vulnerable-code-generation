//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: irregular
// Hey there, young programmer! Are you ready for a wild ride? 🎢
// Let's dive into the depths of C programming, shall we? 🐠

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Function to generate a random number between 1 and 10
int get_random_number() {
  return (rand() % 10) + 1;
}

// Function to print a message on the screen
void print_message(char *message) {
  printf("%s\n", message);
}

// Function to ask the user for their name
char *get_name() {
  char name[50];
  printf("What's your name? ");
  fgets(name, 50, stdin);
  return name;
}

// Function to print a greeting with the user's name
void print_greeting() {
  char *name = get_name();
  printf("Hello, %s! 😊\n", name);
}

// Function to ask the user for their favorite color
char *get_favorite_color() {
  char color[20];
  printf("What's your favorite color? ");
  fgets(color, 20, stdin);
  return color;
}

// Function to print a message based on the user's favorite color
void print_color_message() {
  char *color = get_favorite_color();
  if (strcmp(color, "red") == 0) {
    printf("You love the color red! 🔥\n");
  } else if (strcmp(color, "blue") == 0) {
    printf("You adore the color blue! 🌊\n");
  } else {
    printf("You're a fan of the color green! 🌿\n");
  }
}

int main() {
  srand(time(NULL)); // Seed the random number generator

  // Print a message to get started
  print_message("Let's get this party started! 🎉");

  // Ask the user for their name
  char *name = get_name();

  // Print a greeting with the user's name
  print_greeting();

  // Ask the user for their favorite color
  char *color = get_favorite_color();

  // Print a message based on the user's favorite color
  print_color_message();

  // Print a random number between 1 and 10
  int random_number = get_random_number();
  printf("You got a random number of %d! 🎉\n", random_number);

  return 0;
}