//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in a sentence
#define MAX_SENTENCE_LENGTH 100

// Define the maximum number of sentences in a paragraph
#define MAX_PARAGRAPH_LENGTH 100

// Define the maximum number of paragraphs in a document
#define MAX_DOCUMENT_LENGTH 100

// Define the structure of a word
typedef struct {
  char *word;
  int length;
} Word;

// Define the structure of a sentence
typedef struct {
  Word words[MAX_SENTENCE_LENGTH];
  int length;
} Sentence;

// Define the structure of a paragraph
typedef struct {
  Sentence sentences[MAX_PARAGRAPH_LENGTH];
  int length;
} Paragraph;

// Define the structure of a document
typedef struct {
  Paragraph paragraphs[MAX_DOCUMENT_LENGTH];
  int length;
} Document;

// Create a new word
Word *new_word(char *word) {
  Word *new_word = malloc(sizeof(Word));
  new_word->word = malloc(strlen(word) + 1);
  strcpy(new_word->word, word);
  new_word->length = strlen(word);
  return new_word;
}

// Create a new sentence
Sentence *new_sentence(char *sentence) {
  Sentence *new_sentence = malloc(sizeof(Sentence));
  new_sentence->length = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    new_sentence->words[new_sentence->length++] = *new_word(word);
    word = strtok(NULL, " ");
  }
  return new_sentence;
}

// Create a new paragraph
Paragraph *new_paragraph(char *paragraph) {
  Paragraph *new_paragraph = malloc(sizeof(Paragraph));
  new_paragraph->length = 0;
  char *sentence = strtok(paragraph, ".");
  while (sentence != NULL) {
    new_paragraph->sentences[new_paragraph->length++] = *new_sentence(sentence);
    sentence = strtok(NULL, ".");
  }
  return new_paragraph;
}

// Create a new document
Document *new_document(char *document) {
  Document *new_document = malloc(sizeof(Document));
  new_document->length = 0;
  char *paragraph = strtok(document, "\n");
  while (paragraph != NULL) {
    new_document->paragraphs[new_document->length++] = *new_paragraph(paragraph);
    paragraph = strtok(NULL, "\n");
  }
  return new_document;
}

// Print a word
void print_word(Word *word) {
  printf("%s", word->word);
}

// Print a sentence
void print_sentence(Sentence *sentence) {
  for (int i = 0; i < sentence->length; i++) {
    print_word(&sentence->words[i]);
    printf(" ");
  }
}

// Print a paragraph
void print_paragraph(Paragraph *paragraph) {
  for (int i = 0; i < paragraph->length; i++) {
    print_sentence(&paragraph->sentences[i]);
    printf("\n");
  }
}

// Print a document
void print_document(Document *document) {
  for (int i = 0; i < document->length; i++) {
    print_paragraph(&document->paragraphs[i]);
    printf("\n");
  }
}

// Free a word
void free_word(Word *word) {
  free(word->word);
  free(word);
}

// Free a sentence
void free_sentence(Sentence *sentence) {
  for (int i = 0; i < sentence->length; i++) {
    free_word(&sentence->words[i]);
  }
  free(sentence);
}

// Free a paragraph
void free_paragraph(Paragraph *paragraph) {
  for (int i = 0; i < paragraph->length; i++) {
    free_sentence(&paragraph->sentences[i]);
  }
  free(paragraph);
}

// Free a document
void free_document(Document *document) {
  for (int i = 0; i < document->length; i++) {
    free_paragraph(&document->paragraphs[i]);
  }
  free(document);
}

// Main function
int main() {
  // Create a new document
  Document *document = new_document("Hello world! This is a test document.");

  // Print the document
  print_document(document);

  // Free the document
  free_document(document);

  return 0;
}