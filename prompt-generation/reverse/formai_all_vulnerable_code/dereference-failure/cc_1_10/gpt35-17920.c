//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function to generate random strings
char* generateRandomString(int length) {
  int i;
  char* str = malloc(sizeof(char) * length);
  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  srand(time(NULL));

  if (length) {
      for (i = 0; i < length; i++) {
          int key = rand() % (int)(sizeof(charset) - 1);
          str[i] = charset[key];
      }
  }

  str[length] = '\0';
  return str;
}

int main() {
  char* user_input = malloc(sizeof(char) * MAX_STRING_LENGTH);
  char* generated_string = generateRandomString(MAX_STRING_LENGTH);

  printf("Type the following string as fast as you can: \n\n%s\n\n", generated_string);

  clock_t start_time = clock();
  fgets(user_input, MAX_STRING_LENGTH, stdin);
  clock_t end_time = clock();

  double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

  int count = 0;
  for(int i = 0; i < MAX_STRING_LENGTH; i++) {
    if(generated_string[i] == '\n') {
      break;
    }
    count++;
  }

  user_input[strcspn(user_input, "\n")] = 0; // Remove the newline character from the user input

  if(strcmp(user_input, generated_string) == 0) {
    printf("\nCongratulations! You typed the correct string in %f seconds!\n", elapsed_time);
    double wpm = (count / elapsed_time) * 60 / 5;
    printf("Your typing speed is: %f words per minute.\n", wpm);
  } else {
    printf("\nSorry, you typed the wrong string.\n");
  }

  free(user_input);
  free(generated_string);

  return 0;
}