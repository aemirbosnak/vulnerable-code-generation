//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Word is a sequence of non-whitespace characters.
typedef struct Word {
  char *str;
  size_t len;
} Word;

// A Sentence is a sequence of Words, terminated by a period.
typedef struct Sentence {
  Word *words;
  size_t num_words;
} Sentence;

// A Text is a sequence of Sentences.
typedef struct Text {
  Sentence *sentences;
  size_t num_sentences;
} Text;

// Read a Text from a file.
Text *read_text(FILE *fp) {
  Text *text = malloc(sizeof(Text));
  text->sentences = NULL;
  text->num_sentences = 0;

  char buf[1024];
  while (fgets(buf, sizeof(buf), fp)) {
    // Parse the sentence.
    Sentence sentence;
    sentence.words = NULL;
    sentence.num_words = 0;

    char *word_start = buf;
    char *word_end;
    while ((word_end = strchr(word_start, ' ')) != NULL) {
      // Add the word to the sentence.
      Word word;
      word.str = word_start;
      word.len = word_end - word_start;
      sentence.words = realloc(sentence.words, (sentence.num_words + 1) * sizeof(Word));
      sentence.words[sentence.num_words++] = word;

      // Advance to the next word.
      word_start = word_end + 1;
    }

    // Add the last word to the sentence.
    Word word;
    word.str = word_start;
    word.len = strlen(word_start);
    sentence.words = realloc(sentence.words, (sentence.num_words + 1) * sizeof(Word));
    sentence.words[sentence.num_words++] = word;

    // Add the sentence to the text.
    text->sentences = realloc(text->sentences, (text->num_sentences + 1) * sizeof(Sentence));
    text->sentences[text->num_sentences++] = sentence;
  }

  return text;
}

// Free a Text.
void free_text(Text *text) {
  for (size_t i = 0; i < text->num_sentences; i++) {
    for (size_t j = 0; j < text->sentences[i].num_words; j++) {
      free(text->sentences[i].words[j].str);
    }
    free(text->sentences[i].words);
  }
  free(text->sentences);
  free(text);
}

// Summarize a Text.
Text *summarize_text(Text *text) {
  Text *summary = malloc(sizeof(Text));
  summary->sentences = NULL;
  summary->num_sentences = 0;

  for (size_t i = 0; i < text->num_sentences; i++) {
    // Compute the sentence score.
    double score = 0.0;
    for (size_t j = 0; j < text->sentences[i].num_words; j++) {
      if (text->sentences[i].words[j].len > 3) {
        score += 1.0 / text->sentences[i].words[j].len;
      }
    }

    // Add the sentence to the summary if it has a high score.
    if (score > 0.5) {
      summary->sentences = realloc(summary->sentences, (summary->num_sentences + 1) * sizeof(Sentence));
      summary->sentences[summary->num_sentences++] = text->sentences[i];
    }
  }

  return summary;
}

// Print a Text.
void print_text(Text *text) {
  for (size_t i = 0; i < text->num_sentences; i++) {
    for (size_t j = 0; j < text->sentences[i].num_words; j++) {
      printf("%s ", text->sentences[i].words[j].str);
    }
    printf(".\n");
  }
}

int main() {
  FILE *fp = fopen("text.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  Text *text = read_text(fp);
  fclose(fp);

  Text *summary = summarize_text(text);
  free_text(text);

  print_text(summary);
  free_text(summary);

  return EXIT_SUCCESS;
}