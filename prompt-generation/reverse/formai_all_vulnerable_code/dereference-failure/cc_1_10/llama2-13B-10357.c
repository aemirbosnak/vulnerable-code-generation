//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 1024

// Function to convert binary to text
void binary_to_text(char *binary, int length, char *text) {
  int i, j;
  for (i = 0; i < length; i++) {
    if (binary[i] == 1) {
      text[j] = '1';
      j++;
    } else {
      text[j] = '0';
      j++;
    }
  }
  text[j] = '\0';
}

// Function to convert text to binary
void text_to_binary(char *text, int length, char *binary) {
  int i, j;
  for (i = 0; i < length; i++) {
    if (text[i] == '1') {
      binary[j] = 1;
      j++;
    } else {
      binary[j] = 0;
      j++;
    }
  }
  binary[j] = '\0';
}

int main() {
  char binary[MAX_INPUT_LENGTH] = "11010110";
  char text[MAX_OUTPUT_LENGTH] = "";

  // Convert binary to text
  binary_to_text(binary, strlen(binary), text);
  printf("Text: %s\n", text);

  // Convert text to binary
  text_to_binary(text, strlen(text), binary);
  printf("Binary: %s\n", binary);

  return 0;
}