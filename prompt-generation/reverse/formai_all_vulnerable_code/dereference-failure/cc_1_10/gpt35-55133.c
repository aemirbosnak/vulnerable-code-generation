//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
/*

In honor of Ada Lovelace, I present to you a C program that converts text to Morse code.
This program makes use of arrays, loops, and switch statements to achieve this functionality.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the function to convert to morse code
char* convertToMorseCode(char* inputText) {

    // initiating a few variables that'll make the code more readable
    int i, j, k;
    char morseCode[26][6] = { 
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, 
        {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, 
        {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, 
        {"-.--"}, {"--.."} 
    };

    // allocating memory for the converted code
    char* outputCode = malloc(strlen(inputText) * 6 * sizeof(char));
    k = 0;  // index of the next character of the output code 

    // iterating through each letter of the input text
    for (i = 0; i < strlen(inputText); i++) {

        // converting to lower case 
        inputText[i] = (char)tolower(inputText[i]);

        // handling spaces
        if (inputText[i] == ' ') {
            outputCode[k++] = ' ';
            continue;   // go to the next iteration
        }

        // handling special characters or numbers
        if (inputText[i] < 'a' || inputText[i] > 'z') {
            outputCode[k++] = '#';  // the Morse code for an error
            continue;   // go to the next iteration
        }

        // iterating through each letter of the alphabet
        for (j = 0; j < 26; j++) {
            if (inputText[i] == 'a' + j) {
                // converting to Morse code
                strcpy(outputCode + k, morseCode[j]);
                k += strlen(morseCode[j]);
                outputCode[k++] = ' ';
                break;  // go to the next iteration
            }
        }
    }

    // adding the null terminator to make sure the string is properly terminated
    outputCode[k] = '\0';

    // returning the converted code
    return outputCode;
}

int main() {

    // reading the input text from the user
    char inputText[100];
    printf("Enter the text you want to convert to Morse code: ");
    fgets(inputText, 100, stdin);

    // removing the trailing newline character
    inputText[strcspn(inputText, "\n")] = 0;

    // calling the function to convert to Morse code
    char* outputCode = convertToMorseCode(inputText);
    printf("The Morse code for \"%s\" is \"%s\"\n", inputText, outputCode);

    // freeing the allocated memory
    free(outputCode);
    
    return 0;
}