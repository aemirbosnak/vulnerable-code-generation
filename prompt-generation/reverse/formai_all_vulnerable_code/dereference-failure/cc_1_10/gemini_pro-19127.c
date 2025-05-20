//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo, Romeo! Wherefore art thou, Romeo?
#define ROMEO "Romeo"

// Deny thy father and refuse thy name;
#define FATHER "father"
#define NAME "name"

// Or, if thou wilt not, be but sworn my love,
#define LOVE "love"

// And I'll no longer be a Capulet.
#define CAPULET "Capulet"

// 'Tis but thy name that is my enemy;
#define ENEMY "enemy"

// Thou art thyself, though not a Montague.
#define MONTAGUE "Montague"

// What's Montague? it is nor hand, nor foot,
#define HAND "hand"
#define FOOT "foot"

// Nor arm, nor face, nor any other part
#define ARM "arm"
#define FACE "face"
#define PART "part"

// Belonging to a man. O, be some other name!
#define MAN "man"

int main(int argc, char *argv[]) {
  // What word do we seek in this tale of woe?
  if (argc < 2) {
    printf("Usage: %s <word>\n", argv[0]);
    return EXIT_FAILURE;
  }
  char *word = argv[1];

  // Open the file containing the tale of Romeo and Juliet
  FILE *fp = fopen("romeoandjuliet.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  // Declare our variables for counting words and lines
  int word_count = 0;
  int line_count = 0;

  // Read the file line by line
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Increment the line count
    line_count++;

    // Split the line into words
    char *words[1024];
    int word_count_in_line = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      words[word_count_in_line++] = token;
      token = strtok(NULL, " ");
    }

    // Count the occurrences of the word in the line
    for (int i = 0; i < word_count_in_line; i++) {
      if (strcmp(words[i], word) == 0) {
        word_count++;
      }
    }
  }

  // Close the file
  fclose(fp);

  // Now our task is done, and we can tell the user how oft the word appears
  printf("The word '%s' appears %d times in the tale of Romeo and Juliet.\n", word,
         word_count);

  return EXIT_SUCCESS;
}