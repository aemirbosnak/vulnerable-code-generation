//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the mapping of Morse code to characters
const char *morse_code[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                            ".---","-.-",".-..","--","-.","---",".--.","--.-",
                            ".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

//Define the corresponding characters
const char *alphabets = "abcdefghijklmnopqrstuvwxyz";

//Function to convert a single character to Morse code
void charToMorse(char character, char *morse) {
  int index;
  if (character >= 'a' && character <= 'z') {
    index = character - 'a';
    strcpy(morse, morse_code[index]);
  } else if (character >= 'A' && character <= 'Z') {
    index = character - 'A';
    strcpy(morse, morse_code[index]);
  } else if (character >= '0' && character <= '9') {
    index = character - '0' + 22;
    strcpy(morse, morse_code[index]);
  } else if (character == '.') {
    strcpy(morse, ".-.-.-");
  } else if (character == ',') {
    strcpy(morse, "--..--");
  } else if (character == '?') {
    strcpy(morse, "..--..");
  } else if (character == '/') {
    strcpy(morse, "-..-.");
  } else {
    *morse = '\0';
  }
}

//Function to convert the entire text to Morse code
void textToMorse(char *text, char *morse) {
  char morseChar[20];
  int i, j, len;
  len = strlen(text);
  morse[0] = '\0';
  for (i = 0; i < len; i++) {
    if (text[i] == ' ') {
      strcat(morse, "/");
    } else {
      charToMorse(text[i], morseChar);
      strcat(morse, morseChar);
      strcat(morse, " ");
    }
  }
}

//Function to handle input and output in an asynchronous manner
void handleIO(char *input, char *output) {
    int len;
    printf("Enter the text: ");
    scanf("%[^\n]%*c", input);
    len = strlen(input);
    if(input[len-1] == '\r'){
        input[len-1] = '\0';
    }
    textToMorse(input, output);
    printf("The Morse code translation is: %s\n", output);
}

//Main function
int main() {
  char input[1024];
  char output[1024];
  handleIO(input, output);
  return 0;
}