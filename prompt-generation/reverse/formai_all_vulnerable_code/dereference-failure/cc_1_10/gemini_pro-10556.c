//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEXT_LEN 256
#define WORDS_PER_MINUTE 60
#define TEST_DURATION 60  // seconds

// function to generate random text
char *generate_text(int len) {
  char *text = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    text[i] = 'a' + rand() % 26;
  }
  text[len] = '\0';
  return text;
}

// function to calculate typing speed
int calculate_speed(int keystrokes, double time) {
  return (int)((keystrokes / 5) / time * WORDS_PER_MINUTE);
}

int main() {
  // seed random number generator
  srand(time(NULL));

  // generate random text
  char *text = generate_text(TEXT_LEN);

  // print instructions
  printf("Type the following text as fast as you can:\n");
  printf("%s\n", text);
  printf("Press Enter when you are ready to start.\n");
  getchar();

  // start timer
  clock_t start = clock();

  // get user input
  char input[TEXT_LEN + 1];
  int keystrokes = 0;
  while (1) {
    char c = getchar();
    if (c == '\n') {
      break;
    } else {
      keystrokes++;
      input[keystrokes - 1] = c;
    }
  }

  // calculate time taken
  clock_t end = clock();
  double time = (double)(end - start) / CLOCKS_PER_SEC;

  // calculate typing speed
  int speed = calculate_speed(keystrokes, time);

  // print results
  printf("You typed %d keystrokes in %.2f seconds.\n", keystrokes, time);
  printf("Your typing speed is %d words per minute.\n", speed);

  // free allocated memory
  free(text);

  return 0;
}