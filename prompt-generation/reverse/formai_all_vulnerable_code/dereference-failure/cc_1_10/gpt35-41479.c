//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* c_cat_language_translator(char* input) {
    int length = strlen(input);
    char* output = calloc(length + 1, sizeof(char)); // allocate memory for output string
    
    // loop through each character in input string
    for(int i = 0; i < length; i++) {
        switch(input[i]) {
            case 'c': // if input character is 'c'
                if(i + 3 < length && input[i+1] == 'a' && input[i+2] == 't') { // check if the next 3 characters make up 'cat'
                    strcat(output, "meow"); // add 'meow' to output string
                    i += 2; // skip the next 2 characters ('a' and 't')
                } else {
                    strcat(output, "c"); // add 'c' to output string
                }
                break;
            case 'h':
                strcat(output, "purr");
                if(i+1 < length && (input[i+1] == 'h' || input[i+1] == 'H')) { // check if the next character is 'h' or 'H'
                    strcat(output, " purr"); // add 'purr' again
                    i++; // skip the next character ('h' or 'H')
                }
                break;
            case 't':
                strcat(output, "hiss");
                if(i+2 < length && input[i+1] == 'h' && input[i+2] == 'h') { // check if the next 2 characters are 'hh'
                    strcat(output, " hiss"); // add 'hiss' again
                    i += 2; // skip the next 2 characters ('h' and 'h')
                }
                break;
            default:
                strcat(output, " "); // add a space for all other characters
                break;
        }
    }
    
    return output; // return the translated string
}

// example usage of the translator function
int main() {
    char* input = "cathouse";
    char* output = c_cat_language_translator(input);
    printf("%s\n", output); // should print "meowpurrhissmeow"
    free(output); // free memory allocated for output string
    return 0;
}