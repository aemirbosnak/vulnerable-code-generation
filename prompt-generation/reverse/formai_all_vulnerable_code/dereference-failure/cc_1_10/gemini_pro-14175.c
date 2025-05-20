//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to represent a cat
typedef struct Cat {
  char *name;
  int age;
  char *breed;
  char *color;
} Cat;

// Create a function to print a cat's information
void print_cat(Cat *cat) {
  printf("Name: %s\n", cat->name);
  printf("Age: %d\n", cat->age);
  printf("Breed: %s\n", cat->breed);
  printf("Color: %s\n", cat->color);
}

// Create a function to create a new cat
Cat *create_cat(char *name, int age, char *breed, char *color) {
  // Allocate memory for the cat
  Cat *cat = (Cat *)malloc(sizeof(Cat));

  // Set the cat's properties
  cat->name = name;
  cat->age = age;
  cat->breed = breed;
  cat->color = color;

  // Return the cat
  return cat;
}

// Create a function to free the memory allocated for a cat
void destroy_cat(Cat *cat) {
  // Free the memory allocated for the cat's name
  free(cat->name);

  // Free the memory allocated for the cat
  free(cat);
}

// Main function
int main() {
  // Create a new cat
  Cat *cat = create_cat("Mittens", 5, "Domestic Shorthair", "Calico");

  // Print the cat's information
  print_cat(cat);

  // Free the memory allocated for the cat
  destroy_cat(cat);

  return 0;
}