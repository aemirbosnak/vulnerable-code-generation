//FormAI DATASET v1.0 Category: Text Summarizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100000
#define MAX_SUMMARY_SIZE 500

// The Text Summarizer function
char* summarize_text(char *input_text, int max_summary_size) {
  int i, j, k, summary_length = 0, cur_sentence_length = 0;
  int num_sentences = 0, max_num_sentences = max_summary_size / 10;
  char *summary = (char*) malloc(sizeof(char) * max_summary_size);
  char *cur_sentence = (char*) malloc(sizeof(char) * 500);
  
  // Get input text length
  int input_text_len = strlen(input_text);

  // Initialize the summary and current sentence
  memset(summary, 0, max_summary_size * sizeof(char));
  memset(cur_sentence, 0, 500 * sizeof(char));

  // Loop through the input text
  for (i = 0; i < input_text_len; i++) {
    char c = input_text[i];
    cur_sentence[cur_sentence_length] = c;
    cur_sentence_length++;

    // Check if we've reached the end of a sentence
    if (c == '.' || c == '?' || c == '!') {
      num_sentences++;

      // Trim spaces from the current sentence
      while (cur_sentence[cur_sentence_length - 2] == ' ') {
        cur_sentence_length--;
      }

      // Add current sentence to the summary if we haven't exceeded the max sentence limit
      if (num_sentences <= max_num_sentences) {
        strncat(summary, cur_sentence, strlen(cur_sentence));
        summary_length += strlen(cur_sentence);
      }

      // Reset the current sentence
      memset(cur_sentence, 0, 500);
      cur_sentence_length = 0;

      // Stop summarizing if we've exceeded the max summary size
      if (summary_length >= max_summary_size) {
        break;
      }
    }
  }

  free(cur_sentence);

  // Return the summary
  return summary;
}

int main() {
  char *input_text = (char*) malloc(sizeof(char) * MAX_INPUT_SIZE);
  char *summary_text;

  printf("Enter the text to summarize:\n");
  fgets(input_text, MAX_INPUT_SIZE, stdin);

  printf("\n");

  // Summarize the text
  summary_text = summarize_text(input_text, MAX_SUMMARY_SIZE);

  printf("Summary:\n");
  printf("%s\n", summary_text);

  free(input_text);
  free(summary_text);

  return 0;
}