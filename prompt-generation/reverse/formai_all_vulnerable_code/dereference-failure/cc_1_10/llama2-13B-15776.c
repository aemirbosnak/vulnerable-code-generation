//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_NUMBER_LENGTH 15

// Function to generate a peaceful name
char *generate_peaceful_name() {
  char *name;
  int i, j;

  // Generate a random number of syllables (3-6)
  int syllable_count = rand() % 3 + 3;

  // Generate a random number of letters per syllable (2-4)
  int letter_count = rand() % 2 + 2;

  // Allocate memory for the name
  name = malloc(syllable_count * letter_count + 1);

  // Generate the name
  for (i = 0; i < syllable_count; i++) {
    for (j = 0; j < letter_count; j++) {
      // Generate a random letter
      char letter = 'a' + rand() % 26;

      // Add the letter to the name
      name[i * letter_count + j] = letter;
    }
  }

  return name;
}

// Function to generate a peaceful phone number
char *generate_peaceful_phone_number() {
  char *phone_number;
  int i, j;

  // Generate a random number of digits (6-10)
  int digit_count = rand() % 5 + 6;

  // Allocate memory for the phone number
  phone_number = malloc(digit_count + 1);

  // Generate the phone number
  for (i = 0; i < digit_count; i++) {
    for (j = 0; j < 3; j++) {
      // Generate a random digit
      char digit = '0' + rand() % 10;

      // Add the digit to the phone number
      phone_number[i * 3 + j] = digit;
    }
  }

  return phone_number;
}

int main() {
  // Generate a peaceful name
  char *name = generate_peaceful_name();

  // Print the name
  printf("Hello, my name is %s.\n", name);

  // Generate a peaceful phone number
  char *phone_number = generate_peaceful_phone_number();

  // Print the phone number
  printf("My phone number is %s.\n", phone_number);

  // Free memory
  free(name);
  free(phone_number);

  return 0;
}