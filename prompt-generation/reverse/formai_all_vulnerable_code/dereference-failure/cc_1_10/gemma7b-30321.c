//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

int main()
{
  // Allocate memory for the spam detection system
  char **words = (char**)malloc(MAX_WORDS * sizeof(char*));

  // Create a list of words that are commonly found in spam
  words[0] = "free";
  words[1] = "lottery";
  words[2] = "miracle";
  words[3] = "prize";
  words[4] = "quick";
  words[5] = "easy";
  words[6] = "fast";
  words[7] = "miracle";

  // Get the email message
  char email[1000];
  printf("Enter the email message: ");
  fgets(email, 1000, stdin);

  // Split the email message into words
  char *word = strtok(email, " ");

  // Iterate over the words in the email message
  int i = 0;
  while (word)
  {
    // Check if the word is in the list of commonly found spam words
    for (int j = 0; j < MAX_WORDS; j++)
    {
      if (strcmp(word, words[j]) == 0)
      {
        // Increment the spam score
        i++;
      }
    }

    // Get the next word in the email message
    word = strtok(NULL, " ");
  }

  // Calculate the spam score
  int spam_score = i / MAX_WORDS * 100;

  // Print the spam score
  printf("The spam score is: %d%%", spam_score);

  // Free the memory allocated for the spam detection system
  free(words);

  return 0;
}