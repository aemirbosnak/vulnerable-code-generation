//LLAMA2-13B DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Global variables
int num_people = 0;
char **names = NULL;
int *ages = NULL;

// Function prototypes
void add_person(char *name, int age);
void display_people();
void calculate_avg_age();

// Main function
int main() {
  // Initialize global variables
  num_people = 0;
  names = malloc(MAX_NAME_LEN * sizeof(char *));
  ages = malloc(MAX_NAME_LEN * sizeof(int));

  // Add people to the list
  add_person("Alice", 25);
  add_person("Bob", 30);
  add_person("Charlie", 35);
  add_person("David", 20);

  // Display the list of people
  display_people();

  // Calculate the average age
  calculate_avg_age();

  // Free memory
  free(names);
  free(ages);

  return 0;
}

// Function to add a person to the list
void add_person(char *name, int age) {
  // Check if the name is too long
  if (strlen(name) > MAX_NAME_LEN) {
    printf("Error: Name too long\n");
    return;
  }

  // Check if the age is valid
  if (age < 0 || age > MAX_AGE) {
    printf("Error: Invalid age\n");
    return;
  }

  // Allocate memory for the name and age
  char *new_name = malloc(strlen(name) + 1);
  int new_age = age;

  // Copy the name and age to the new memory
  strcpy(new_name, name);
  new_age = age;

  // Add the person to the list
  names[num_people] = new_name;
  ages[num_people] = new_age;

  // Increment the number of people
  num_people++;
}

// Function to display the list of people
void display_people() {
  printf("List of people:\n");
  for (int i = 0; i < num_people; i++) {
    printf("%d. %s (%d years old)\n", i + 1, names[i], ages[i]);
  }
}

// Function to calculate the average age
void calculate_avg_age() {
  int sum = 0;
  for (int i = 0; i < num_people; i++) {
    sum += ages[i];
  }
  int avg = sum / num_people;
  printf("Average age: %d\n", avg);
}