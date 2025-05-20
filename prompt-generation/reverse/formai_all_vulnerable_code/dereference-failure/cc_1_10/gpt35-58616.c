//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SUMMARY_SIZE 100

char* text_summarizer(char* text) {
  char* summary = malloc(sizeof(char) * MAX_SUMMARY_SIZE);

  // Split sentences by period, exclamation mark or question mark
  char* sentence = strtok(text, ".!?");

  int summary_size = 0;
  int sentence_count = 0;

  // Continue summarizing sentences until character limit is reached 
  while (sentence != NULL && summary_size < MAX_SUMMARY_SIZE) {
    sentence_count++;

    // Check for important keywords in sentence
    if (strstr(sentence, "important") != NULL || strstr(sentence, "urgent") != NULL || strstr(sentence, "critical") != NULL) {
      strcat(summary, sentence);
      summary_size += strlen(sentence);
    }

    // Check if sentence contains numbers
    // If so, add to summary
    int contains_number = 0;
    for (int i = 0; i < strlen(sentence); i++) {
      if (isdigit(sentence[i])) {
        contains_number = 1;
        break;
      }
    }

    if (contains_number) {
      strcat(summary, sentence);
      summary_size += strlen(sentence);
    }

    // Get next sentence
    sentence = strtok(NULL, ".!?");
  }

  // If no important or numeric sentences were found,
  // add the first sentence to the summary
  if (strlen(summary) == 0 && sentence_count > 0) {
    sentence = strtok(text, ".");
    strcat(summary, sentence);
  }

  return summary;
}

int main() {
  char input_text[MAX_INPUT_SIZE];
  printf("Enter text to be summarized:\n");
  fgets(input_text, sizeof(input_text), stdin);
  input_text[strcspn(input_text, "\n")] = '\0';
  
  char* summary = text_summarizer(input_text);
  printf("Summary:\n%s\n", summary);

  free(summary);
  
  return 0;
}