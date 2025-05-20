//FormAI DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program demonstrates a simple encryption technique known as
 * Caesar Cipher, which shifts each letter of the original text by a
 * fixed number of positions down the alphabet. 
 * The shift amount is specified by the user through the command line.
 * */

int main(int argc, char *argv[]) {
  
  // check if the command line argument is valid
  if(argc != 2) {
    printf("Usage: %s <shift>\n", argv[0]);
    return 1;
  }

  // parse the shift amount from the input and validate it
  int shift = atoi(argv[1]);
  if(shift <= 0) {
    printf("Error: shift amount must be a positive integer\n");
    return 1;
  }

  // read the input text from the user
  printf("Enter the text you want to encrypt:\n");
  char original_text[100];
  fgets(original_text, 100, stdin);

  // initialize the encrypted text buffer and loop variables
  char encrypted_text[100];
  int i = 0;
  int length = strlen(original_text);

  // iterate over each character in the original text
  while(i < length) {

    // if the character is a letter, shift it by the user-specified amount
    if(isalpha(original_text[i])) {

      // determine the character's case (upper or lower)
      char base = isupper(original_text[i]) ? 'A' : 'a';

      // shift the character down the alphabet
      char shifted = ((original_text[i] - base + shift) % 26) + base;

      // add the shifted character to the encrypted text buffer
      encrypted_text[i] = shifted;

    } else {

      // if the character is not a letter, add it to the encrypted text buffer unchanged
      encrypted_text[i] = original_text[i];

    }

    i++; // update the loop variable

  }

  // print the encrypted text to the user
  printf("Encrypted text: %s", encrypted_text);
  
  return 0; // indicate successful completion of the program
}