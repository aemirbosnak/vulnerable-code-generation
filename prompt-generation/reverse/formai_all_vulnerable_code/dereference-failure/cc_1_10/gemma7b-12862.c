//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096

void text_summarizer(char **buffer, int buffer_size, char **summary) {
  // Allocate summary buffer
  *summary = malloc(buffer_size);
  if (*summary == NULL) {
    return;
  }

  // Calculate summary length
  int summary_length = buffer_size / 2;

  // Summarize text
  for (int i = 0; i < summary_length; i++) {
    *summary = strcat(*summary, " ");
    *summary = strcat(*summary, buffer[i]);
  }

  // Null terminate summary
  *summary = strcat(*summary, "\0");
}

int main() {
  // Allocate text buffer
  char *text_buffer = malloc(MAX_BUFFER_SIZE);
  if (text_buffer == NULL) {
    return 1;
  }

  // Get text from user
  printf("Enter text: ");
  fgets(text_buffer, MAX_BUFFER_SIZE, stdin);

  // Summarize text
  char *summary = NULL;
  text_summarizer(&text_buffer, MAX_BUFFER_SIZE, &summary);

  // Print summary
  printf("Summary: \n");
  printf("%s\n", summary);

  // Free memory
  free(text_buffer);
  free(summary);

  return 0;
}