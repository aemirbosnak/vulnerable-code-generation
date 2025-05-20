//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove stop words from a string
char *remove_stop_words(char *str) {
  char *stop_words[] = {"a", "an", "the", "and", "or", "but", "to", "of", "in", "on", "for", "as", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "having", "do", "does", "did", "doing", "can", "could", "may", "might", "must", "should", "will", "would", "shall", "should", "who", "what", "when", "where", "why", "how", "he", "she", "it", "they", "we", "you", "me", "him", "her", "it", "them", "us", "you", "his", "hers", "its", "theirs", "ours", "yours", "mine", "myself", "himself", "herself", "itself", "themselves", "ourselves", "yourselves", "I", "me", "my", "mine", "you", "your", "yours", "he", "his", "him", "she", "her", "hers", "it", "its", "we", "us", "our", "ours", "they", "them", "their", "theirs"};
  int num_stop_words = sizeof(stop_words) / sizeof(char *);
  char *new_str = (char *)malloc(strlen(str) + 1);
  int i, j, k;
  k = 0;
  for (i = 0; str[i] != '\0'; i++) {
    for (j = 0; j < num_stop_words; j++) {
      if (strcmp(&str[i], stop_words[j]) == 0) {
        i += strlen(stop_words[j]) - 1;
        break;
      }
    }
    new_str[k++] = str[i];
  }
  new_str[k] = '\0';
  return new_str;
}

// Function to summarize a text
char *summarize_text(char *text) {
  // Remove stop words from the text
  char *new_text = remove_stop_words(text);

  // Tokenize the text
  char *tokens[1000];
  int num_tokens = 0;
  char *token = strtok(new_text, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Count the frequency of each token
  int token_counts[1000];
  for (int i = 0; i < num_tokens; i++) {
    token_counts[i] = 0;
    for (int j = 0; j < num_tokens; j++) {
      if (strcmp(tokens[i], tokens[j]) == 0) {
        token_counts[i]++;
      }
    }
  }

  // Sort the tokens by frequency
  for (int i = 0; i < num_tokens - 1; i++) {
    for (int j = i + 1; j < num_tokens; j++) {
      if (token_counts[i] < token_counts[j]) {
        char *temp = tokens[i];
        tokens[i] = tokens[j];
        tokens[j] = temp;
        int temp2 = token_counts[i];
        token_counts[i] = token_counts[j];
        token_counts[j] = temp2;
      }
    }
  }

  // Generate the summary
  char *summary = (char *)malloc(1000);
  int summary_length = 0;
  for (int i = 0; i < num_tokens; i++) {
    if (summary_length + strlen(tokens[i]) + 1 < 1000) {
      strcat(summary, tokens[i]);
      strcat(summary, " ");
      summary_length += strlen(tokens[i]) + 1;
    } else {
      break;
    }
  }

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char *text = (char *)malloc(1000);
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char *summary = summarize_text(text);

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the memory allocated for the text and the summary
  free(text);
  free(summary);

  return 0;
}