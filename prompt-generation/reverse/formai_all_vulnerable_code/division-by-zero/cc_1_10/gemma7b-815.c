//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>

int main() {
  time_t start, end;
  int i, words, chars, speed;
  char text[1024];

  printf("Enter text: ");
  fgets(text, 1024, stdin);

  start = clock();
  words = count_words(text);
  chars = count_chars(text);
  end = clock();

  speed = (chars * 1000) / (end - start);

  printf("Words: %d\n", words);
  printf("Chars: %d\n", chars);
  printf("Speed: %d words/sec\n", speed);

  return 0;
}

int count_words(char *text) {
  int words = 0;
  char *ptr = text;

  while (*ptr) {
    if (*ptr == ' ' || *ptr == '\n' || *ptr == '\t') {
      words++;
    }
    ptr++;
  }

  return words;
}

int count_chars(char *text) {
  int chars = 0;
  char *ptr = text;

  while (*ptr) {
    chars++;
    ptr++;
  }

  return chars;
}