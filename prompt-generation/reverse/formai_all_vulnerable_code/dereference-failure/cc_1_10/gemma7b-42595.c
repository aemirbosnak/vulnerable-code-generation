//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

char **word_list;

void scan_email(char *email) {
  char *message = email;
  char *word = NULL;
  int i = 0;

  // Allocate memory for the word list
  word_list = malloc(MAX_WORDS * sizeof(char *));

  // Extract words from the email message
  while ((word = strsep(message, " ")) != NULL) {
    word_list[i++] = strdup(word);
  }

  // Clean up memory
  free(word_list);
}

int analyze_words(char **words) {
  int i = 0;
  int spam_score = 0;

  // Check for known spam words
  for (i = 0; words[i] != NULL; i++) {
    if (strcmp(words[i], "spam") == 0) {
      spam_score++;
    } else if (strcmp(words[i], "free") == 0) {
      spam_score++;
    } else if (strcmp(words[i], "lottery") == 0) {
      spam_score++;
    }
  }

  // Return the spam score
  return spam_score;
}

int main() {
  char email[] = "Subject: Free Lottery Ticket! Click Here!";

  scan_email(email);
  int spam_score = analyze_words(word_list);

  if (spam_score > 0) {
    printf("Spam detected!\n");
  } else {
    printf("No spam detected.\n");
  }

  return 0;
}