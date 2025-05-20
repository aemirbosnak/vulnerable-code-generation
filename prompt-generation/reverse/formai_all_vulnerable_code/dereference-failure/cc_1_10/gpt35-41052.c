//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToMorse(char*);

int main() {
   char *text = (char*) malloc(100 * sizeof(char));
   printf("Enter text to convert to Morse code: ");
   scanf("%[^\n]%*c", text);

   char* morseCode = convertToMorse(text);
   printf("Morse Code: %s\n", morseCode);
   
   free(text);
   free(morseCode);
   return 0;
}

char* convertToMorse(char* text) {
   // Define a lookup table to convert characters to Morse code
   const char *morseTable[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                                 ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                                 "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----",
                                 ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
   
   char* morseCode = (char*) malloc(1000 * sizeof(char));
   int morseIndex = 0;

   // Iterate through each character in the input text
   for (int i = 0; i < strlen(text); i++) {
      char ch = tolower(text[i]);

      // Check if the character is alphanumeric
      if (isalnum(ch)) {
         // Convert character to Morse code using lookup table
         int codeIndex = (isdigit(ch)) ? ch - '0' + 26 : ch - 'a';
         strcpy(morseCode + morseIndex, morseTable[codeIndex]);
         morseIndex += strlen(morseTable[codeIndex]);
      } else if (ch == ' ') {
         // Add space to separate words
         strcpy(morseCode + morseIndex, " ");
         morseIndex += 1;
      } else {
         // Ignore non-alphanumeric characters
         continue;
      }
   }
   return morseCode;
}