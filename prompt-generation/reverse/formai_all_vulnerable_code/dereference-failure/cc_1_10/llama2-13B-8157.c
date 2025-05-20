//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 100
#define MIN_LENGTH 5
#define MAX_LENGTH 50

// Function to generate a random number between MIN_NUMBER and MAX_NUMBER
int getRandomNumber() {
  return (rand() % (MAX_NUMBER - MIN_NUMBER)) + MIN_NUMBER;
}

// Function to generate a random string of length MIN_LENGTH to MAX_LENGTH
char* getRandomString() {
  int length = getRandomNumber() % (MAX_LENGTH - MIN_LENGTH) + MIN_LENGTH;
  char* string = malloc(length * sizeof(char));
  for (int i = 0; i < length; i++) {
    string[i] = 'a' + getRandomNumber() % 26;
  }
  return string;
}

// Function to check if two strings are equal
int isEqual(char* str1, char* str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  if (len1 != len2) {
    return 0;
  }
  for (int i = 0; i < len1; i++) {
    if (str1[i] != str2[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  // Generate a random string of length MIN_LENGTH to MAX_LENGTH
  char* str = getRandomString();

  // Generate a random number between MIN_NUMBER and MAX_NUMBER
  int number = getRandomNumber();

  // Check if the string is equal to the number
  if (isEqual(str, (char*)&number)) {
    printf("The string %s is equal to the number %d\n", str, number);
  } else {
    printf("The string %s is not equal to the number %d\n", str, number);
  }

  // Free the memory allocated for the string
  free(str);

  return 0;
}