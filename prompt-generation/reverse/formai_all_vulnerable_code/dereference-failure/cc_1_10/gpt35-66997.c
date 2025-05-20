//FormAI DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char *summarize(char *text, int summary_length);

int main(void)
{
  char text[MAX_SIZE];
  int summary_length;

  printf("Welcome to the Text Summarizer!\n\n");
  printf("Please enter the text you'd like to summarize (max %d characters):\n", MAX_SIZE);
  fgets(text, MAX_SIZE, stdin);

  printf("\nHow long would you like the summary to be (in characters)?\n");
  scanf("%d", &summary_length);

  char *summary = summarize(text, summary_length);

  printf("\nHere's your summary!\n\n%s\n", summary);

  free(summary);

  return 0;
}

char *summarize(char *text, int summary_length)
{
  int original_length = strlen(text);

  // Count the number of sentences
  int num_sentences = 0;
  for (int i = 0; i < original_length; i++)
  {
    if (text[i] == '.' || text[i] == '?' || text[i] == '!')
    {
      num_sentences++;
    }
  }

  // Allocate memory for storing the sentences
  char **sentences = (char **)malloc(num_sentences * sizeof(char *));
  if (sentences == NULL)
  {
    printf("Error: Out of Memory");
    exit(1);
  }

  // Tokenize the text into sentences
  int sentence_index = 0;
  char *sentence = strtok(text, ".?!");
  while (sentence != NULL)
  {
    sentences[sentence_index] = sentence;
    sentence_index++;
    sentence = strtok(NULL, ".?!");
  }

  // Calculate the score of each sentence based on the frequency of important words
  int *score = (int *)calloc(num_sentences, sizeof(int));
  if (score == NULL)
  {
    printf("Error: Out of Memory");
    exit(1);
  }

  char *important_words[] = {"important", "crucial", "significant", "vital", "essential"};
  int num_important_words = sizeof(important_words) / sizeof(char *);

  for (int i = 0; i < num_sentences; i++)
  {
    for (int j = 0; j < num_important_words; j++)
    {
      char *word = strstr(sentences[i], important_words[j]);
      if (word != NULL)
      {
        score[i]++;
      }
    }
  }

  // Find the top scoring sentences and concatenate them to form the summary
  int summary_index = 0;
  char *summary = (char *)malloc(summary_length * sizeof(char));
  if (summary == NULL)
  {
    printf("Error: Out of Memory");
    exit(1);
  }

  while (strlen(summary) < summary_length && summary_index < num_sentences)
  {
    int max_score_index = -1;
    int max_score = -1;

    for (int i = 0; i < num_sentences; i++)
    {
      if (score[i] > max_score)
      {
        max_score = score[i];
        max_score_index = i;
      }
    }

    if (max_score_index != -1)
    {
      if (strlen(summary) + strlen(sentences[max_score_index]) <= summary_length)
      {
        strcat(summary, sentences[max_score_index]);
        strcat(summary, " ");
      }
      score[max_score_index] = -1; // set score to -1 to ignore the sentence in future iterations
    }

    summary_index++;
  }

  // Clean up
  free(sentences);
  free(score);

  return summary;
}