//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* translate(char* input) {
    char* output = malloc(strlen(input) * 2); // allocate enough memory for the output
    char* outputPtr = output; // use a pointer to keep track of the output position
    char* currWord = strtok(input, " "); // use strtok to split input str into words
    
    while(currWord != NULL) { // loop until all the words are translated
        char* currPtr = currWord; // use a pointer to keep track of the current word position

        *outputPtr = toupper(*currPtr); // capitalize the first letter of the word
        outputPtr++;
        currPtr++;

        while(*currPtr != '\0') { // loop through the rest of the word
            if(*currPtr == 'c' || *currPtr == 'C') { // translate 'C' and 'c' to 'meow'
                *outputPtr = 'm';
                outputPtr++;
                *outputPtr = 'e';
                outputPtr++;
                *outputPtr = 'o';
                outputPtr++;
                *outputPtr = 'w';
                outputPtr++;
            } else {
                *outputPtr = *currPtr; // copy the letter to the output
                outputPtr++;
            }

            currPtr++;
        }

        *outputPtr = ' '; // put a space between the words
        outputPtr++;

        currWord = strtok(NULL, " "); // move on to the next word
    }

    *outputPtr = '\0'; // null terminate the output string

    return output;
}

int main() {
    char input[100];
    printf("Enter a sentence to translate:\n");
    fgets(input, sizeof(input), stdin); // get user input

    char* output = translate(input); // translate the input

    printf("\nTranslated sentence:\n%s", output); // print the output

    free(output); // free the memory allocated for the output

    return 0;
}