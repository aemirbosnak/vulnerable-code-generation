//FormAI DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 1000 // maximum length of input text
#define MAX_SUMMARY_LEN 500 // maximum length of summary

// function to remove punctuations and convert to lowercase
char *sanitize(char *text) {
  char *p = text;
  while (*p) {
    if (*p >= 'A' && *p <= 'Z') {
      *p = *p + ('a' - 'A'); // convert uppercase to lowercase
    } else if (*p == '.' || *p == ',' || *p == ';' || *p == ':' || *p == '?' || *p == '!') {
      *p = ' '; // replace punctuations with whitespace
    }
    p++;
  }
  return text;
}

// function to split text into sentences
char **split_sentences(char *text, int *num_sentences) {
  char **sentences = NULL;
  char *sentence = strtok(text, ".!?"); // split based on punctuations
  int i = 0;
  while (sentence != NULL) {
    sentences = (char **)realloc(sentences, (i + 1) * sizeof(char *));
    sentences[i] = sanitize(sentence); // remove punctuations and convert to lowercase
    i++;
    sentence = strtok(NULL, ".!?"); // continue splitting
  }
  *num_sentences = i;
  return sentences;
}

// function to calculate frequency of each word in the text
void calc_word_freq(char **sentences, int num_sentences, char **words, int *freq, int *num_words) {
  int i, j;
  for (i = 0; i < num_sentences; i++) {
    char sentence[MAX_INPUT_LEN];
    strcpy(sentence, sentences[i]);
    char *word = strtok(sentence, " "); // split based on whitespace
    while (word != NULL) {
      int found = 0;
      for (j = 0; j < *num_words; j++) {
        if (strcmp(words[j], word) == 0) {
          freq[j]++; // increment frequency if word is already present
          found = 1;
          break;
        }
      }
      if (!found) { // add word to list if it is not already present
        words = (char **)realloc(words, (*num_words + 1) * sizeof(char *));
        words[*num_words] = (char *)malloc((strlen(word) + 1) * sizeof(char));
        strcpy(words[*num_words], word);
        freq[*num_words] = 1;
        (*num_words)++;
      }
      word = strtok(NULL, " "); // continue splitting
    }
  }
}

// function to sort words in descending order of frequency
void sort_words(char **words, int *freq, int num_words) {
  int i, j;
  char *temp;
  int temp_freq;
  for (i = 0; i < num_words - 1; i++) {
    for (j = i + 1; j < num_words; j++) {
      if (freq[j] > freq[i]) {
        // swap words and frequencies
        temp = words[i];
        words[i] = words[j];
        words[j] = temp;
        temp_freq = freq[i];
        freq[i] = freq[j];
        freq[j] = temp_freq;
      }
    }
  }
}

// function to generate summary
char *generate_summary(char **sentences, int num_sentences) {
  char **words = NULL;
  int *freq = NULL;
  int num_words = 0;
  calc_word_freq(sentences, num_sentences, words, freq, &num_words); // calculate frequency of each word
  sort_words(words, freq, num_words); // sort words in descending order of frequency
  int i, j, k, summary_len = 0;
  char *summary = (char *)malloc(MAX_SUMMARY_LEN * sizeof(char));
  summary[0] = '\0';
  for (i = 0; i < num_words; i++) {
    int word_len = strlen(words[i]);
    if (summary_len + word_len + 3 <= MAX_SUMMARY_LEN) { // check if summary can accomodate next word
      strcat(summary, words[i]); // add word to summary
      strcat(summary, "..."); // add ellipsis
      strcat(summary, " "); // add whitespace
      summary_len += word_len + 3;
    } else {
      break;
    }
  }
  // capitalize first letter of summary and add ending punctuation
  summary[0] = summary[0] - ('a' - 'A');
  int last_index = strlen(summary) - 1;
  if (summary[last_index] != '.' && summary[last_index] != '?' && summary[last_index] != '!') {
    strcat(summary, ".");
    summary_len++;
  }
  return summary;
}

int main() {
  char input[MAX_INPUT_LEN];
  printf("Enter text to summarize:\n");
  fgets(input, MAX_INPUT_LEN, stdin); // read input text from user
  int num_sentences;
  char **sentences = split_sentences(input, &num_sentences); // split text into sentences
  char *summary = generate_summary(sentences, num_sentences); // generate summary
  printf("Summary:\n");
  printf("%s\n", summary); // print summary
  // free memory
  int i;
  for (i = 0; i < num_sentences; i++) {
    free(sentences[i]);
  }
  free(sentences);
  free(summary);
  return 0;
}