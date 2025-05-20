//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in a sentence
#define MAX_SENTENCE_LENGTH 1000

// Define the maximum number of sentences in a paragraph
#define MAX_PARAGRAPH_LENGTH 10000

// Define the maximum number of paragraphs in a text
#define MAX_TEXT_LENGTH 100000

// Define the structure of a word
typedef struct word {
  char *string;
  int length;
} word_t;

// Define the structure of a sentence
typedef struct sentence {
  word_t *words;
  int num_words;
} sentence_t;

// Define the structure of a paragraph
typedef struct paragraph {
  sentence_t *sentences;
  int num_sentences;
} paragraph_t;

// Define the structure of a text
typedef struct text {
  paragraph_t *paragraphs;
  int num_paragraphs;
} text_t;

// Define the function to create a new word
word_t *new_word(char *string) {
  word_t *word = malloc(sizeof(word_t));
  word->string = strdup(string);
  word->length = strlen(string);
  return word;
}

// Define the function to create a new sentence
sentence_t *new_sentence(char *string) {
  sentence_t *sentence = malloc(sizeof(sentence_t));
  sentence->words = malloc(MAX_SENTENCE_LENGTH * sizeof(word_t));
  sentence->num_words = 0;

  // Tokenize the string into words
  char *token = strtok(string, " ");
  while (token != NULL) {
    word_t *word = new_word(token);
    sentence->words[sentence->num_words++] = *word;
    token = strtok(NULL, " ");
  }

  return sentence;
}

// Define the function to create a new paragraph
paragraph_t *new_paragraph(char *string) {
  paragraph_t *paragraph = malloc(sizeof(paragraph_t));
  paragraph->sentences = malloc(MAX_PARAGRAPH_LENGTH * sizeof(sentence_t));
  paragraph->num_sentences = 0;

  // Tokenize the string into sentences
  char *token = strtok(string, ".");
  while (token != NULL) {
    sentence_t *sentence = new_sentence(token);
    paragraph->sentences[paragraph->num_sentences++] = *sentence;
    token = strtok(NULL, ".");
  }

  return paragraph;
}

// Define the function to create a new text
text_t *new_text(char *string) {
  text_t *text = malloc(sizeof(text_t));
  text->paragraphs = malloc(MAX_TEXT_LENGTH * sizeof(paragraph_t));
  text->num_paragraphs = 0;

  // Tokenize the string into paragraphs
  char *token = strtok(string, "\n");
  while (token != NULL) {
    paragraph_t *paragraph = new_paragraph(token);
    text->paragraphs[text->num_paragraphs++] = *paragraph;
    token = strtok(NULL, "\n");
  }

  return text;
}

// Define the function to print a word
void print_word(word_t *word) {
  printf("%s", word->string);
}

// Define the function to print a sentence
void print_sentence(sentence_t *sentence) {
  for (int i = 0; i < sentence->num_words; i++) {
    print_word(&sentence->words[i]);
    printf(" ");
  }
}

// Define the function to print a paragraph
void print_paragraph(paragraph_t *paragraph) {
  for (int i = 0; i < paragraph->num_sentences; i++) {
    print_sentence(&paragraph->sentences[i]);
    printf(". ");
  }
}

// Define the function to print a text
void print_text(text_t *text) {
  for (int i = 0; i < text->num_paragraphs; i++) {
    print_paragraph(&text->paragraphs[i]);
    printf("\n");
  }
}

// Define the function to free a word
void free_word(word_t *word) {
  free(word->string);
  free(word);
}

// Define the function to free a sentence
void free_sentence(sentence_t *sentence) {
  for (int i = 0; i < sentence->num_words; i++) {
    free_word(&sentence->words[i]);
  }
  free(sentence->words);
  free(sentence);
}

// Define the function to free a paragraph
void free_paragraph(paragraph_t *paragraph) {
  for (int i = 0; i < paragraph->num_sentences; i++) {
    free_sentence(&paragraph->sentences[i]);
  }
  free(paragraph->sentences);
  free(paragraph);
}

// Define the function to free a text
void free_text(text_t *text) {
  for (int i = 0; i < text->num_paragraphs; i++) {
    free_paragraph(&text->paragraphs[i]);
  }
  free(text->paragraphs);
  free(text);
}

// Define the main function
int main() {
  // Create a new text
  text_t *text = new_text("This is a sample text.\nThis is another paragraph.\nThis is the third paragraph.");

  // Print the text
  print_text(text);

  // Free the text
  free_text(text);

  return 0;
}