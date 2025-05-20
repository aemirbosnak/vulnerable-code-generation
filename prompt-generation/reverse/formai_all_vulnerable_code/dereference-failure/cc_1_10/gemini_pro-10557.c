//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 1024

typedef struct {
  char *str;
  int len;
  double entropy;
} String;

double calc_entropy(String *str) {
  int i;
  double entropy = 0.0;
  int freq[256] = {0};

  for (i = 0; i < str->len; i++) {
    freq[str->str[i]]++;
  }

  for (i = 0; i < 256; i++) {
    if (freq[i] > 0) {
      double prob = (double)freq[i] / str->len;
      entropy -= prob * log2(prob);
    }
  }

  return entropy;
}

int main() {
  String str;
  double threshold = 0.8;

  // Get the input string from the user.
  printf("Enter the string: ");
  str.str = (char *)malloc(MAX_STR_LEN * sizeof(char));
  fgets(str.str, MAX_STR_LEN, stdin);
  str.len = strlen(str.str) - 1;

  // Calculate the entropy of the string.
  str.entropy = calc_entropy(&str);

  // Check if the entropy is greater than the threshold.
  if (str.entropy > threshold) {
    printf("The string is spam.\n");
  } else {
    printf("The string is not spam.\n");
  }

  // Free the allocated memory.
  free(str.str);

  return 0;
}