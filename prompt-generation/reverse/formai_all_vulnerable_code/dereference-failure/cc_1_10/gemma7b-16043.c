//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Word {
  char word[MAX_WORDS];
  int frequency;
} Word;

Word words[MAX_WORDS];

void analyze_text(char *text) {
  char *sentence = text;
  char word[MAX_WORDS];
  int i = 0;

  // Tokenize the text into sentences
  while (sentence) {
    // Extract the word
    word[0] = '\0';
    sentence = strsep(sentence, ".");
    if (sentence) {
      strcpy(word, sentence);
      word[MAX_WORDS - 1] = '\0';

      // Analyze the word
      for (i = 0; words[i].word && words[i].frequency; i++) {
        if (strcmp(word, words[i].word) == 0) {
          words[i].frequency++;
          break;
        }
      }

      // If the word is not found, add it to the dictionary
      if (i == MAX_WORDS - 1) {
        strcpy(words[MAX_WORDS - 1].word, word);
        words[MAX_WORDS - 1].frequency = 1;
      }
    }
  }
}

int main() {
  char text[] = "This is a sample text that contains many spam words, such as free, offer, and discount. It also contains some legitimate words, such as car, house, and book.";

  analyze_text(text);

  // Print the words and their frequencies
  for (int i = 0; words[i].word && words[i].frequency; i++) {
    printf("%s: %d\n", words[i].word, words[i].frequency);
  }

  return 0;
}