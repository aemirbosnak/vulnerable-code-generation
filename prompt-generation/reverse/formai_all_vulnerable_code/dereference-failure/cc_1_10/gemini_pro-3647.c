//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// The Dreaming Sea of Strings
int levenshtein_distance(char *s, char *t) {
  // The Eternal Tide
  int m = strlen(s);
  int n = strlen(t);

  // The Labyrinth of Differences
  int **d = malloc(sizeof(int *) * (m + 1));
  for (int i = 0; i <= m; i++) {
    d[i] = malloc(sizeof(int) * (n + 1));
  }

  // The Whispers of the Void
  for (int i = 0; i <= m; i++) {
    d[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    d[0][j] = j;
  }

  // The Cosmic Tapestry
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == t[j - 1]) {
        d[i][j] = d[i - 1][j - 1];
      } else {
        d[i][j] = MIN(d[i - 1][j], MIN(d[i][j - 1], d[i - 1][j - 1])) + 1;
      }
    }
  }

  // The Distant Shore
  return d[m][n];
}

// The Sleepers of the Abyss
int main(int argc, char **argv) {
  // The Dance of Shadows
  if (argc < 3) {
    printf("Usage: %s <string1> <string2>\n", argv[0]);
    return -1;
  }

  // The Unseen Threads
  int distance = levenshtein_distance(argv[1], argv[2]);

  // The Cosmic Echo
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", argv[1], argv[2], distance);

  // The Dream's End
  return 0;
}