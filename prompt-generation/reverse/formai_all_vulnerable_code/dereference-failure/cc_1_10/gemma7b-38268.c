//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

char **words = NULL;
char **sentences = NULL;

void analyze_sentence(char *sentence) {
  // Split the sentence into words
  char *word = strtok(sentence, " ");
  int i = 0;
  words = realloc(words, (i + 1) * sizeof(char *));
  words[i++] = word;

  // Remove punctuation from the words
  for (word = strtok(NULL, " "); word; word = strtok(NULL, " ")) {
    char *punc = strpbrk(word, "!.?:");
    if (punc) {
      *punc = '\0';
    }
  }

  // Analyze the word frequency
  int word_count = 0;
  for (int j = 0; words[j]; j++) {
    word_count++;
  }

  // Store the sentence and its word count
  sentences = realloc(sentences, (i + 1) * sizeof(char *));
  sentences[i++] = sentence;
  sentences[i - 1] = word_count;
}

int main() {
  // Analyze a bunch of sentences
  analyze_sentence("This is a sentence with a lot of words.");
  analyze_sentence("Another sentence, with even more words than the first one.");
  analyze_sentence("A sentence with a few short words.");

  // Print the results
  for (int i = 0; sentences[i]; i++) {
    printf("Sentence: %s\n", sentences[i]);
    printf("Word count: %d\n", sentences[i + 1]);
    printf("\n");
  }

  return 0;
}