//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// A custom compression algorithm that compresses strings by looking for repeated substrings and replacing them with a token.

#define MAX_STRING_LENGTH 1000
#define MAX_TOKENS 100

void compress_string(char input_string[], char output_string[]);
void decompress_string(char input_string[], char output_string[]);

int main() {
  char original_string[MAX_STRING_LENGTH];
  char compressed_string[MAX_STRING_LENGTH];
  char decompressed_string[MAX_STRING_LENGTH];
  
  printf("Enter a string to compress: ");
  fgets(original_string, MAX_STRING_LENGTH, stdin);
  
  compress_string(original_string, compressed_string);
  printf("Compressed string: %s\n", compressed_string);
  
  decompress_string(compressed_string, decompressed_string);
  printf("Decompressed string: %s\n", decompressed_string);
  
  return 0;
}

void compress_string(char input_string[], char output_string[]) {
  char tokens[MAX_TOKENS][MAX_STRING_LENGTH];
  int num_tokens = 0;
  int token_length = 0;
  
  int i = 0;
  while (input_string[i] != '\0') {
    int j = i;
    while (input_string[j] != ' ' && input_string[j] != '\n' && input_string[j] != '\0') {
      j++;
    }
    int word_length = j - i;
    
    if (word_length > 1) {
      int k;
      for (k = 0; k < num_tokens; k++) {
        if (strncmp(tokens[k], input_string + i, word_length) == 0) {
          break;
        }
      }
      
      if (k < num_tokens) {
        snprintf(output_string + token_length, MAX_STRING_LENGTH - token_length, "%d ", k);
      } else {
        strncpy(tokens[num_tokens], input_string + i, word_length);
        strncpy(output_string + token_length, input_string + i, word_length);
        output_string[token_length + word_length] = ' ';
        num_tokens++;
      }
      token_length += word_length + 1;
    } else {
      strncpy(output_string + token_length, input_string + i, word_length);
      output_string[token_length + word_length] = ' ';
      token_length += word_length + 1;
    }
    i = j + 1;
  }
  output_string[token_length] = '\0';
}

void decompress_string(char input_string[], char output_string[]) {
  char tokens[MAX_TOKENS][MAX_STRING_LENGTH];
  int num_tokens = 0;
  
  int i = 0;
  while (input_string[i] != '\0') {
    if (input_string[i] >= '0' && input_string[i] <= '9') {
      int j = i;
      while (input_string[j] != ' ') {
        j++;
      }
      int token_index = atoi(input_string + i);
      strncpy(output_string + strlen(output_string), tokens[token_index], strlen(tokens[token_index]));
      i = j + 1;
    } else {
      int j = i;
      while (input_string[j] != ' ' && input_string[j] != '\0') {
        j++;
      }
      strncpy(output_string + strlen(output_string), input_string + i, j - i);
      i = j + 1;
    }
  }
}