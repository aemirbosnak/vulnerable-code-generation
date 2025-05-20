//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STRING_LENGTH 100

// Define the maximum number of characters in a word
#define MAX_WORD_LENGTH 20

// Define the maximum number of words in a sentence
#define MAX_SENTENCE_LENGTH 100

// Define the maximum number of sentences in a paragraph
#define MAX_PARAGRAPH_LENGTH 10

// Define the maximum number of paragraphs in a document
#define MAX_DOCUMENT_LENGTH 10

// Define the data structure for a word
typedef struct {
  char *word;
  int length;
} Word;

// Define the data structure for a sentence
typedef struct {
  Word *words[MAX_WORD_LENGTH];
  int length;
} Sentence;

// Define the data structure for a paragraph
typedef struct {
  Sentence *sentences[MAX_SENTENCE_LENGTH];
  int length;
} Paragraph;

// Define the data structure for a document
typedef struct {
  Paragraph *paragraphs[MAX_PARAGRAPH_LENGTH];
  int length;
} Document;

// Create a new word
Word *create_word(char *word) {
  Word *new_word = malloc(sizeof(Word));
  new_word->word = malloc(strlen(word) + 1);
  strcpy(new_word->word, word);
  new_word->length = strlen(word);
  return new_word;
}

// Create a new sentence
Sentence *create_sentence(char *sentence) {
  Sentence *new_sentence = malloc(sizeof(Sentence));
  new_sentence->length = 0;
  char *token = strtok(sentence, " ");
  while (token != NULL) {
    Word *new_word = create_word(token);
    new_sentence->words[new_sentence->length++] = new_word;
    token = strtok(NULL, " ");
  }
  return new_sentence;
}

// Create a new paragraph
Paragraph *create_paragraph(char *paragraph) {
  Paragraph *new_paragraph = malloc(sizeof(Paragraph));
  new_paragraph->length = 0;
  char *token = strtok(paragraph, ".");
  while (token != NULL) {
    Sentence *new_sentence = create_sentence(token);
    new_paragraph->sentences[new_paragraph->length++] = new_sentence;
    token = strtok(NULL, ".");
  }
  return new_paragraph;
}

// Create a new document
Document *create_document(char *document) {
  Document *new_document = malloc(sizeof(Document));
  new_document->length = 0;
  char *token = strtok(document, "\n");
  while (token != NULL) {
    Paragraph *new_paragraph = create_paragraph(token);
    new_document->paragraphs[new_document->length++] = new_paragraph;
    token = strtok(NULL, "\n");
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
    if (i > 0) {
      printf(" ");
    }
    print_word(sentence->words[i]);
  }
  printf(".");
}

// Print a paragraph
void print_paragraph(Paragraph *paragraph) {
  for (int i = 0; i < paragraph->length; i++) {
    if (i > 0) {
      printf("\n");
    }
    print_sentence(paragraph->sentences[i]);
  }
}

// Print a document
void print_document(Document *document) {
  for (int i = 0; i < document->length; i++) {
    if (i > 0) {
      printf("\n");
    }
    print_paragraph(document->paragraphs[i]);
  }
}

// Free the memory allocated for a word
void free_word(Word *word) {
  free(word->word);
  free(word);
}

// Free the memory allocated for a sentence
void free_sentence(Sentence *sentence) {
  for (int i = 0; i < sentence->length; i++) {
    free_word(sentence->words[i]);
  }
  free(sentence);
}

// Free the memory allocated for a paragraph
void free_paragraph(Paragraph *paragraph) {
  for (int i = 0; i < paragraph->length; i++) {
    free_sentence(paragraph->sentences[i]);
  }
  free(paragraph);
}

// Free the memory allocated for a document
void free_document(Document *document) {
  for (int i = 0; i < document->length; i++) {
    free_paragraph(document->paragraphs[i]);
  }
  free(document);
}

int main() {
  // Create a test document
  char *document = "This is a test document. It contains multiple paragraphs. Each paragraph contains multiple sentences. Each sentence contains multiple words. The document is about the future of performance-critical components.";
  Document *test_document = create_document(document);

  // Print the test document
  print_document(test_document);

  // Free the memory allocated for the test document
  free_document(test_document);

  return 0;
}