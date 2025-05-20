//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SENTENCES 50
#define MAX_SUMMARY_SIZE 100

char* read_input(){
  char* input_text = malloc(MAX_INPUT_SIZE * sizeof(char));
  printf("Enter the text to be summarized: \n");
  fgets(input_text, MAX_INPUT_SIZE, stdin);
  return input_text;
}

void remove_punctuation(char* sentence) {
  int len = strlen(sentence);
  for(int i=0;i<len;i++) {
    char ch = sentence[i];
    if ((ch == '.') || (ch == ',') || (ch == ':') || (ch == ';') 
        || (ch == '!') || (ch == '?')) {
      sentence[i] = ' ';
    }
  }
}

int count_sentences(char* input_text) {
  int count = 0;
  int len = strlen(input_text);
  for(int i=0;i<len;i++) {
    if (input_text[i] == '.') {
      count++;
    }
  }
  return count;
}

char** split_sentences(char* input_text, int sentence_count) {
  char** sentences = malloc(sentence_count * sizeof(char*));
  char* sentence = strtok(input_text, ".");
  int i = 0;
  while (sentence != NULL) {
    sentences[i] = malloc((strlen(sentence)+1) * sizeof(char));
    strcpy(sentences[i], sentence);
    i++;
    sentence = strtok(NULL, ".");
  }
  return sentences;
}

int* score_sentences(char** sentences, int sentence_count) {
  int* scores = malloc(sentence_count * sizeof(int));
  for(int i=0;i<sentence_count;i++) {
    char* sentence = sentences[i];
    remove_punctuation(sentence);
    int word_count = 0;
    for(int j=0;j<strlen(sentence);j++) {
      if (sentence[j] == ' ') {
        word_count++;
      }
    }
    scores[i] = word_count;
  }
  return scores;
}

int* get_summary_indices(int* scores, int sentence_count) {
  int* summary_indices = malloc(MAX_SUMMARY_SIZE * sizeof(int));
  int summary_size = 0;
  for(int i=0;i<MAX_SUMMARY_SIZE;i++) {
    int max_index = -1;
    int max_score = -1;
    for(int j=0;j<sentence_count;j++) {
      if ((scores[j] > max_score) && (summary_indices[j] == 0)) {
        max_score = scores[j];
        max_index = j;
      }
    }
    if (max_index != -1) {
      summary_indices[max_index] = 1;
      summary_size++;
    }
    if (summary_size >= MAX_SUMMARY_SIZE) {
      break;
    }
  }
  return summary_indices;
}

void print_summary(char** sentences, int* summary_indices, int sentence_count) {
  printf("\nSummary: \n");
  for(int i=0;i<sentence_count;i++) {
    if (summary_indices[i] == 1) {
      printf("%s.", sentences[i]);
    }
  }
}

int main() {
  char* input_text = read_input();
  int sentence_count = count_sentences(input_text);
  char** sentences = split_sentences(input_text, sentence_count);
  int* scores = score_sentences(sentences, sentence_count);
  int* summary_indices = get_summary_indices(scores, sentence_count);
  print_summary(sentences, summary_indices, sentence_count);
  return 0;
}