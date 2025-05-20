//LLAMA2-13B DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_GIBBERISH_LENGTH 50

int main() {
  int sentence_length = 0;
  char sentence[MAX_SENTENCE_LENGTH];
  char gibberish[MAX_GIBBERISH_LENGTH];
  int gibberish_length = 0;
  double random_number = 0;

  // Generate a random sentence
  sentence_length = rand() % MAX_SENTENCE_LENGTH;
  for (int i = 0; i < sentence_length; i++) {
    sentence[i] = 'a' + (rand() % 26);
  }

  // Generate some gibberish
  gibberish_length = rand() % MAX_GIBBERISH_LENGTH;
  for (int i = 0; i < gibberish_length; i++) {
    gibberish[i] = 'a' + (rand() % 26);
  }

  // Mix the sentence and gibberish together
  for (int i = 0; i < sentence_length; i++) {
    sentence[i] = gibberish[i % gibberish_length];
  }

  // Print the mixed sentence
  printf("The sentence is: %s\n", sentence);

  // Generate a random number between 0 and 1
  random_number = drand48();

  // Check if the random number is less than 0.5
  if (random_number < 0.5) {
    // If the number is less than 0.5, print the sentence backwards
    printf("The sentence is: %s (backwards)\n", sentence);
  } else {
    // If the number is greater than or equal to 0.5, print the sentence forwards
    printf("The sentence is: %s (forwards)\n", sentence);
  }

  return 0;
}