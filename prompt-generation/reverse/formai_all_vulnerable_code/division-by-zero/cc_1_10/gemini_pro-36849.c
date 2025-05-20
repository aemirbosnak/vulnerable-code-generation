//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct score_t {
  char name[255];
  long long int speed;
  long long int accuracy;
};

void display_test(char text[]) {
  printf("Type the following text:\n\n%s\n\n", text);
}

void get_input(char input[], size_t size) {
  printf("Your input:\n");
  fgets(input, size, stdin);
}

void calculate_score(struct score_t *score, char text[], char input[]) {
  int len_text = strlen(text);
  int len_input = strlen(input);
  int matches = 0;

  for (int i = 0; i < len_input; i++) {
    if (text[i] == input[i]) {
      matches++;
    }
  }

  score->speed = (long long int)(matches * 60) / len_text;
  score->accuracy = (long long int)(matches * 100) / len_input;
}

void display_score(struct score_t *score) {
  printf("\nYour speed: %lld WPM\n", score->speed);
  printf("Your accuracy: %lld%%\n", score->accuracy);
}

int main() {
  char text[] = "The quick brown fox jumps over the lazy dog";
  char input[255];
  struct score_t score;

  display_test(text);
  get_input(input, sizeof(input));
  calculate_score(&score, text, input);
  display_score(&score);

  return 0;
}