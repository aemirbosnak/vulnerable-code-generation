//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Spam detection system
int main() {
  // Get the text to be analyzed
  char text[200];
  printf("Enter text: ");
  fgets(text, 200, stdin);

  // Create a spam detection score
  int score = 0;

  // Check for common spam words
  char* spam_words[] = {"free", "lottery", "miracle", "miracle"};
  for (int i = 0; i < 4; i++) {
    if (strstr(text, spam_words[i]) != NULL) {
      score++;
    }
  }

  // Check for suspicious punctuation
  char* suspicious_punctuation = {"!", "@", "#"};
  for (int i = 0; i < 3; i++) {
    if (strstr(text, suspicious_punctuation[i]) != NULL) {
      score++;
    }
  }

  // Check for excessive caps
  if (text[0] >= 'A' && text[0] <= 'Z') {
    score++;
  }

  // Check for overly long words
  char* long_words = {"abracadabra", "pneumonoultramicroscopicsilicovolcanoconiosis"};
  for (int i = 0; i < 2; i++) {
    if (strstr(text, long_words[i]) != NULL) {
      score++;
    }
  }

  // Determine the spam detection threshold
  int threshold = 3;

  // Check if the score exceeds the threshold
  if (score > threshold) {
    printf("Spam detected!\n");
  } else {
    printf("No spam detected.\n");
  }

  return 0;
}