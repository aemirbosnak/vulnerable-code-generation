//FormAI DATASET v1.0 Category: String manipulation ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// The purpose of this program is to take a sentence input by the user,
// then scramble the words in the sentence but still keep the sentence readable.
// It achieves this by breaking down the sentence into individual words,
// then rearranging the order of the words while keeping the first and last letter in place.

// Function that scrambles the middle of each word, while keeping the first and last letter in place
void scramble(char *word)
{
  int len = strlen(word);

  if (len > 2) // scrambling only applies to words with more than two letters
  {
    for (int i = 1; i < len - 1; i++) // loop through the middle of the word
    {
      int j = rand() % (len - 2) + 1; // randomly choose a position in the middle

      // swap the current character with the randomly chosen character
      char temp = word[i];
      word[i] = word[j];
      word[j] = temp;
    }
  }
}

int main()
{
  // user inputs a sentence
  char sentence[100];
  printf("Enter a sentence: ");
  fgets(sentence, 100, stdin);

  // break apart the sentence into individual words
  char *word = strtok(sentence, " ,.-\n");
  char *words[100];
  int wordCount = 0;

  while (word != NULL)
  {
    words[wordCount] = word; // add the word to an array
    word = strtok(NULL, " ,.-\n");
    wordCount++; // keep track of the number of words
  }

  // scramble the middle of each word
  for (int i = 0; i < wordCount; i++)
  {
    scramble(words[i]);
  }

  // print out the scrambled sentence
  printf("Scrambled sentence: ");
  printf("%c", toupper(words[0][0])); // print out the first letter of the first word capitalized
  printf("%s", words[0]+1); // print out the rest of the first word
  for (int i = 1; i < wordCount; i++)
  {
    printf(" "); // print out a space between words
    printf("%c", words[i][0]); // print out the first letter of the word
    printf("%s", words[i]+1); // print out the rest of the word
  }
  printf("\n");

  return 0;
}