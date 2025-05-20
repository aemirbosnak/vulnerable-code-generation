//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <text>\n", argv[0]);
    return 1;
  }

  char *text = argv[1];
  int len = strlen(text);
  int i, j, k;

  // Create a 2D array to store the sentiment scores for each word.
  int **scores = malloc(len * sizeof(int *));
  for (i = 0; i < len; i++) {
    scores[i] = malloc(len * sizeof(int));
  }

  // Initialize the sentiment scores to 0.
  for (i = 0; i < len; i++) {
    for (j = 0; j < len; j++) {
      scores[i][j] = 0;
    }
  }

  // Iterate over the text and calculate the sentiment scores for each word.
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      int score = 0;
      for (k = i; k <= j; k++) {
        if (text[k] == 'a' || text[k] == 'e' || text[k] == 'i' || text[k] == 'o' || text[k] == 'u') {
          score++;
        } else if (text[k] == 'b' || text[k] == 'c' || text[k] == 'd' || text[k] == 'f' || text[k] == 'g') {
          score--;
        }
      }
      scores[i][j] = score;
    }
  }

  // Print the sentiment scores for each word.
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      printf("%s-%s: %d\n", text + i, text + j, scores[i][j]);
    }
  }

  // Free the memory allocated for the sentiment scores.
  for (i = 0; i < len; i++) {
    free(scores[i]);
  }
  free(scores);

  return 0;
}