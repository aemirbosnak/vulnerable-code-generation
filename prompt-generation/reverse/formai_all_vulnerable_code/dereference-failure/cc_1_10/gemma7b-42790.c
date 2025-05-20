//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024

void text_summarizer(char *text)
{
  char *summary = NULL;
  int summary_size = 0;
  int i = 0;
  int word_count = 0;

  // Calculate the number of words in the text
  for (i = 0; text[i] != '\0'; i++)
  {
    if (text[i] == ' ')
    {
      word_count++;
    }
  }

  // Allocate memory for the summary
  summary = malloc(word_count * 20);

  // Create the summary
  for (i = 0; text[i] != '\0'; i++)
  {
    if (text[i] != ' ')
    {
      summary[summary_size] = text[i];
      summary_size++;
    }
  }

  // Print the summary
  printf("%s\n", summary);

  // Free the memory allocated for the summary
  free(summary);
}

int main()
{
  char text[MAX_TEXT_SIZE];

  // Get the text from the user
  printf("Enter text: ");
  fgets(text, MAX_TEXT_SIZE, stdin);

  // Summarize the text
  text_summarizer(text);

  return 0;
}