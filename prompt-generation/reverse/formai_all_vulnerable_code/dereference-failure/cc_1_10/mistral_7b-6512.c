//MISTRAL-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
 char letter;
 char *morse;
} morse_t;

morse_t morse_table[] = {
 {'A', ".-"},
 {'B', "-..."},
 {'C', "-.-."},
 {'D', "-.."},
 {'E', "."},
 {'F', "..-."},
 {'G', "--."},
 {'H', "...."},
 {'I', ".."},
 {'J', ".---"},
 {'K', "-.-"},
 {'L', ".-.."},
 {'M', "--"},
 {'N', "-."},
 {'O', "---"},
 {'P', ".--."},
 {'Q', "--.-"},
 {'R', ".-."},
 {'S', "..."},
 {'T', "-"},
 {'U', "..-"},
 {'V', "...-"},
 {'W', ".--"},
 {'X', "-..-"},
 {'Y', "-.--"},
 {'Z', "--.."},
 {'1', ".----"},
 {'2', "..---"},
 {'3', "...--"},
 {'4', "....-"},
 {'5', "....."},
 {'6', "-...."},
 {'7', "--..."},
 {'8', "---.."},
 {'9', "----."},
 {'0', "-----"},
 {' ', "/"},
 {'?', "..--.."},
 {'!', "-.-.--"},
 {'.' , ".-.-.-"},
 {'-', "-___-"},
 {'_', "____"},
 {'+', "----.----"}
};

int hash_func(char c) {
 int hash = 0;
 int i;

 for(i = 0; i < 26; i++) {
 if(morse_table[i].letter == toupper(c)) {
 hash = i;
 break;
 }
 }

 if(isdigit(c)) {
 hash += 26;
 hash += (c - '1');
 }

 return hash;
}

void to_morse(char *input, char *output) {
 int i, j;
 char c;
 int hash;

 strcpy(output, "");

 for(i = 0; i < strlen(input); i++) {
 c = input[i];
 hash = hash_func(c);

 if(isalnum(c)) {
 strcat(output, morse_table[hash].morse);
 strcat(output, " ");
 } else if(c == ' ') {
 strcat(output, morse_table[33].morse);
 strcat(output, " ");
 }
 }
}

int main(int argc, char *argv[]) {
 char input[100], output[500];

 if(argc < 2) {
 printf("Usage : %s <text to convert to morse code>\n", argv[0]);
 return 1;
 }

 strcpy(input, argv[1]);
 to_morse(input, output);
 printf("Morse code : %s\n", output);

 return 0;
}