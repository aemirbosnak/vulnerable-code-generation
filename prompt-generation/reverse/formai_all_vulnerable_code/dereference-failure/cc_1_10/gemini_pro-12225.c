//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TEXT_LENGTH 100
#define MAX_WORDS 10
#define MAX_CHARACTERS_PER_WORD 20

// Array of words to be typed
char *words[MAX_WORDS] = {
  "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "is"
};

// Function to generate a random word
char *generate_random_word() {
  return words[rand() % MAX_WORDS];
}

// Function to generate a random sentence
char *generate_random_sentence() {
  char *sentence = malloc(sizeof(char) * TEXT_LENGTH);
  int num_words = rand() % MAX_WORDS;
  for (int i = 0; i < num_words; i++) {
    strcat(sentence, generate_random_word());
    strcat(sentence, " ");
  }
  sentence[strlen(sentence) - 1] = '\0';
  return sentence;
}

// Function to test typing speed
void test_typing_speed() {
  char *sentence = generate_random_sentence();
  printf("Type the following sentence as quickly as possible:\n\n%s\n", sentence);
  time_t start_time = time(NULL);
  char typed_sentence[TEXT_LENGTH];
  scanf("%s", typed_sentence);
  time_t end_time = time(NULL);
  int num_characters = strlen(sentence);
  int time_taken = end_time - start_time;
  float speed = (float)num_characters / time_taken;
  printf("\nYour typing speed is: %.2f characters per second\n", speed);
}

// Main function
int main() {
  srand(time(NULL));
  test_typing_speed();
  return 0;
}