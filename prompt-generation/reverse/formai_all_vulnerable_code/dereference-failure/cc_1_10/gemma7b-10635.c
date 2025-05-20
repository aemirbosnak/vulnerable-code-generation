//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
  char* name;
  char* value;
  struct Token* next;
} Token;

Token* extract_metadata(char* file_path) {
  FILE* file = fopen(file_path, "r");
  if (!file) {
    return NULL;
  }

  char line[MAX_TOKENS];
  Token* head = NULL;
  Token* current = NULL;

  while (fgets(line, MAX_TOKENS, file) != NULL) {
    char* token_start = line;
    char* token_end = strchr(line, ':');

    if (token_start && token_end) {
      char* token_name = strdup(token_start);
      char* token_value = strdup(token_end + 1);

      Token* new_token = malloc(sizeof(Token));
      new_token->name = token_name;
      new_token->value = token_value;
      new_token->next = NULL;

      if (head) {
        current->next = new_token;
      } else {
        head = new_token;
      }

      current = new_token;
    }
  }

  fclose(file);

  return head;
}

int main() {
  char* file_path = "my_file.txt";
  Token* metadata = extract_metadata(file_path);

  if (metadata) {
    for (Token* token = metadata; token; token = token->next) {
      printf("%s: %s\n", token->name, token->value);
    }
  } else {
    printf("Error extracting metadata.\n");
  }

  return 0;
}