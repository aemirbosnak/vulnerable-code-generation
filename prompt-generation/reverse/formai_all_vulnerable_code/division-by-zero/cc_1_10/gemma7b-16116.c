//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <time.h>

int main() {
  time_t tStart, tEnd;
  int i, words, characters, speed;
  char text[200];

  printf("Welcome to the Typing Speed Test!\n");
  printf("Please enter the text you want to type: ");

  fgets(text, 200, stdin);

  tStart = time(NULL);

  for (i = 0; text[i] != '\0'; i++) {
    printf("%c", text[i]);
  }

  tEnd = time(NULL);

  words = words_count(text);
  characters = characters_count(text);

  speed = (characters / (tEnd - tStart)) * 60;

  printf("\nYour typing speed is: %d words per minute.\n", speed);
  printf("You have typed a total of: %d words and %d characters.\n", words, characters);

  return 0;
}

int words_count(char *text) {
  int words = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] == ' ' || text[i] == '\n') {
      words++;
    }
  }

  return words;
}

int characters_count(char *text) {
  int characters = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    characters++;
  }

  return characters;
}