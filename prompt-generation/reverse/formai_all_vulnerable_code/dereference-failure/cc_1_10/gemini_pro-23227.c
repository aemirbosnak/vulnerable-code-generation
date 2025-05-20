//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
#define TOK_START 0
#define TOK_END 1
#define TOK_WORD 2
#define TOK_PUNCT 3

// Token structure
typedef struct {
  int type;
  char *text;
} Token;

// Tokenizer function
Token *tokenize(char *text) {
  // Allocate memory for the tokens
  Token *tokens = malloc(sizeof(Token) * (strlen(text) + 1));

  // Initialize the first token
  tokens[0].type = TOK_START;
  tokens[0].text = text;

  // Tokenize the text
  int i = 0;
  int j = 0;
  while (text[i] != '\0') {
    // Check if the current character is a letter
    if (isalpha(text[i])) {
      // If it is, start a new word token
      tokens[j].type = TOK_WORD;
      tokens[j].text = &text[i];

      // Increment the token index
      j++;

      // Increment the character index
      i++;

      // Continue until the next non-letter character
      while (isalpha(text[i])) {
        i++;
      }
    } else {
      // If the current character is not a letter, start a new punctuation token
      tokens[j].type = TOK_PUNCT;
      tokens[j].text = &text[i];

      // Increment the token index
      j++;

      // Increment the character index
      i++;

      // Continue until the next letter character
      while (!isalpha(text[i])) {
        i++;
      }
    }
  }

  // Add the end token
  tokens[j].type = TOK_END;
  tokens[j].text = NULL;

  // Return the tokens
  return tokens;
}

// Summarizer function
char *summarize(char *text) {
  // Tokenize the text
  Token *tokens = tokenize(text);

  // Allocate memory for the summary
  char *summary = malloc(sizeof(char) * (strlen(text) + 1));

  // Summarize the text
  int i = 0;
  int j = 0;
  while (tokens[i].type != TOK_END) {
    // If the current token is a word token, add it to the summary
    if (tokens[i].type == TOK_WORD) {
      strcat(summary, tokens[i].text);
      strcat(summary, " ");

      // Increment the summary index
      j++;
    }

    // Increment the token index
    i++;
  }

  // Remove the last space from the summary
  summary[j - 1] = '\0';

  // Return the summary
  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char *text = malloc(sizeof(char) * 1024);
  printf("Enter the text to be summarized: ");
  scanf("%s", text);

  // Summarize the text
  char *summary = summarize(text);

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the memory
  free(text);
  free(summary);

  return 0;
}