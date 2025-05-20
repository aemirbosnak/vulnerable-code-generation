//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 1

// Function to count the number of vowels in a given string
int count_vowels(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
      count++;
    }
  }
  return count;
}

// Function to replace all vowels with their corresponding numbers
char *replace_vowels(char *str) {
  int i = 0;
  char *new_str = malloc(strlen(str) * sizeof(char));
  for (int j = 0; str[j] != '\0'; j++) {
    if (str[j] == 'a') {
      new_str[i] = '2';
      i++;
    } else if (str[j] == 'e') {
      new_str[i] = '3';
      i++;
    } else if (str[j] == 'i') {
      new_str[i] = '4';
      i++;
    } else if (str[j] == 'o') {
      new_str[i] = '5';
      i++;
    } else if (str[j] == 'u') {
      new_str[i] = '6';
      i++;
    } else {
      new_str[i] = str[j];
    }
  }
  new_str[i] = '\0';
  return new_str;
}

int main() {
  char str[] = "Hello, how are you?";
  int vowel_count = count_vowels(str);
  char *new_str = replace_vowels(str);
  printf("The number of vowels in the original string is: %d\n", vowel_count);
  printf("The replaced string is: %s\n", new_str);
  free(new_str);
  return 0;
}