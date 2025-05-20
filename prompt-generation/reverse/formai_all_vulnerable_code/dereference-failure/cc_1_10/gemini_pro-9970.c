//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function is the entry point of the program.
int main(void) {
  // Declare the variables.
  char *text;
  int length;
  int i;
  int j;
  int k;
  int count;
  char *summary;
  int summaryLength;
  int l;
  int m;
  int n;
  int o;
  int p;
  int q;
  int r;
  int s;
  int t;
  int u;
  int v;
  int w;
  int x;
  int y;
  int z;

  // Get the text from the user.
  printf("Enter the text:\n");
  text = (char *)malloc(1000);
  gets(text);

  // Get the length of the text.
  length = strlen(text);

  // Initialize the count to 0.
  count = 0;

  // Count the number of words in the text.
  for (i = 0; i < length; i++) {
    if (text[i] == ' ') {
      count++;
    }
  }

  // Allocate memory for the summary.
  summary = (char *)malloc(count * 10);

  // Initialize the summary length to 0.
  summaryLength = 0;

  // Copy the first word of the text to the summary.
  for (j = 0; j < length; j++) {
    if (text[j] == ' ') {
      break;
    }
    summary[summaryLength++] = text[j];
  }

  // Add a space after the first word of the summary.
  summary[summaryLength++] = ' ';

  // Copy the last word of the text to the summary.
  for (k = length - 1; k >= 0; k--) {
    if (text[k] == ' ') {
      break;
    }
    summary[summaryLength++] = text[k];
  }

  // Add a period after the last word of the summary.
  summary[summaryLength++] = '.';

  // Print the summary.
  printf("The summary is:\n");
  puts(summary);

  // Free the memory allocated for the text and the summary.
  free(text);
  free(summary);

  // Return 0 to indicate that the program ran successfully.
  return 0;
}