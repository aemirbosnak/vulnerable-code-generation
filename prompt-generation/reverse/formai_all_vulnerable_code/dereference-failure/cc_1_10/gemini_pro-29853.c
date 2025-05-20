//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating categories
#define G "G"
#define PG "PG"
#define PG13 "PG-13"
#define R "R"
#define NC17 "NC-17"

// Define the age limit for each rating category
#define G_AGE_LIMIT 0
#define PG_AGE_LIMIT 8
#define PG13_AGE_LIMIT 13
#define R_AGE_LIMIT 17
#define NC17_AGE_LIMIT 18

// Get the user's age
int getAge() {
  int age;
  printf("Enter your age: ");
  scanf("%d", &age);
  return age;
}

// Get the movie rating
char* getRating() {
  char* rating;
  printf("Enter the movie rating (G, PG, PG-13, R, NC-17): ");
  scanf("%s", rating);
  return rating;
}

// Check if the user is old enough to see the movie
int checkAge(int age, char* rating) {
  int isOldEnough;
  if (strcmp(rating, G) == 0) {
    isOldEnough = 1;
  } else if (strcmp(rating, PG) == 0) {
    isOldEnough = age >= PG_AGE_LIMIT;
  } else if (strcmp(rating, PG13) == 0) {
    isOldEnough = age >= PG13_AGE_LIMIT;
  } else if (strcmp(rating, R) == 0) {
    isOldEnough = age >= R_AGE_LIMIT;
  } else if (strcmp(rating, NC17) == 0) {
    isOldEnough = age >= NC17_AGE_LIMIT;
  } else {
    isOldEnough = 0;
  }
  return isOldEnough;
}

// Print the result
void printResult(int isOldEnough) {
  if (isOldEnough) {
    printf("You are old enough to see this movie.\n");
  } else {
    printf("You are not old enough to see this movie.\n");
  }
}

// Main function
int main() {
  int age = getAge();
  char* rating = getRating();
  int isOldEnough = checkAge(age, rating);
  printResult(isOldEnough);
  return 0;
}