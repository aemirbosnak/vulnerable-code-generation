//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: creative
// Sentiment analysis tool using statistical methods

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a few constants
#define MIN_WORD_LENGTH 3
#define MAX_DICTIONARY_SIZE 10000
#define MAX_SENTENCE_LENGTH 1000

// Define a structure to represent a word
typedef struct {
  char* word;
  int count;
  float sentiment;
} Word;

// Define a structure to represent a sentence
typedef struct {
  char* sentence;
  float sentiment;
} Sentence;

// Create a new word
Word* new_word(char* word) {
  Word* w = malloc(sizeof(Word));
  w->word = strdup(word);
  w->count = 1;
  w->sentiment = 0.0;
  return w;
}

// Create a new sentence
Sentence* new_sentence(char* sentence) {
  Sentence* s = malloc(sizeof(Sentence));
  s->sentence = strdup(sentence);
  s->sentiment = 0.0;
  return s;
}

// Add a word to the dictionary
void add_word_to_dictionary(Word* w, Word** dictionary, int* dictionary_size) {
  if (*dictionary_size == MAX_DICTIONARY_SIZE) {
    fprintf(stderr, "Error: dictionary is full\n");
    exit(1);
  }
  dictionary[*dictionary_size] = w;
  (*dictionary_size)++;
}

// Get a word from the dictionary
Word* get_word_from_dictionary(char* word, Word** dictionary, int* dictionary_size) {
  for (int i = 0; i < *dictionary_size; i++) {
    if (strcmp(dictionary[i]->word, word) == 0) {
      return dictionary[i];
    }
  }
  return NULL;
}

// Add a sentence to the list of sentences
void add_sentence_to_list(Sentence* s, Sentence** sentences, int* sentences_size) {
  if (*sentences_size == MAX_SENTENCE_LENGTH) {
    fprintf(stderr, "Error: list of sentences is full\n");
    exit(1);
  }
  sentences[*sentences_size] = s;
  (*sentences_size)++;
}

// Get a sentence from the list of sentences
Sentence* get_sentence_from_list(int index, Sentence** sentences, int* sentences_size) {
  if (index < 0 || index >= *sentences_size) {
    fprintf(stderr, "Error: index out of bounds\n");
    exit(1);
  }
  return sentences[index];
}

// Tokenize a sentence into a list of words
char** tokenize_sentence(char* sentence, int* words_size) {
  char** words = malloc(MAX_SENTENCE_LENGTH * sizeof(char*));
  char* word = strtok(sentence, " ");
  int i = 0;
  while (word != NULL) {
    if (strlen(word) >= MIN_WORD_LENGTH) {
      words[i] = strdup(word);
      i++;
    }
    word = strtok(NULL, " ");
  }
  *words_size = i;
  return words;
}

// Calculate the sentiment of a sentence
float calculate_sentence_sentiment(Sentence* s, Word** dictionary, int* dictionary_size) {
  float sentiment = 0.0;
  int words_size = 0;
  char** words = tokenize_sentence(s->sentence, &words_size);
  for (int i = 0; i < words_size; i++) {
    Word* w = get_word_from_dictionary(words[i], dictionary, dictionary_size);
    if (w != NULL) {
      sentiment += w->sentiment;
    }
  }
  free(words);
  return sentiment;
}

// Print the sentiment of a sentence
void print_sentence_sentiment(Sentence* s) {
  printf("Sentence: %s\n", s->sentence);
  printf("Sentiment: %f\n\n", s->sentiment);
}

// Main function
int main() {
  // Create a dictionary of words and their sentiments
  Word* dictionary[MAX_DICTIONARY_SIZE];
  int dictionary_size = 0;
  FILE* f = fopen("sentiment_dictionary.txt", "r");
  if (f == NULL) {
    fprintf(stderr, "Error: could not open sentiment dictionary file\n");
    exit(1);
  }
  char line[MAX_SENTENCE_LENGTH];
  while (fgets(line, MAX_SENTENCE_LENGTH, f) != NULL) {
    char* word = strtok(line, " ");
    char* sentiment = strtok(NULL, " ");
    float f_sentiment = atof(sentiment);
    Word* w = new_word(word);
    w->sentiment = f_sentiment;
    add_word_to_dictionary(w, dictionary, &dictionary_size);
  }
  fclose(f);

  // Create a list of sentences
  Sentence* sentences[MAX_SENTENCE_LENGTH];
  int sentences_size = 0;
  f = fopen("sentences.txt", "r");
  if (f == NULL) {
    fprintf(stderr, "Error: could not open sentences file\n");
    exit(1);
  }
  while (fgets(line, MAX_SENTENCE_LENGTH, f) != NULL) {
    Sentence* s = new_sentence(line);
    s->sentiment = calculate_sentence_sentiment(s, dictionary, &dictionary_size);
    add_sentence_to_list(s, sentences, &sentences_size);
  }
  fclose(f);

  // Print the sentiment of each sentence
  for (int i = 0; i < sentences_size; i++) {
    print_sentence_sentiment(get_sentence_from_list(i, sentences, &sentences_size));
  }

  return 0;
}