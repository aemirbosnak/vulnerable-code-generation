//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert a string to alien language
char* alienize(char* input) {
    int i;
    char* output = (char*)malloc(sizeof(char) * (strlen(input) + 1));
    
    for (i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (char)toupper(input[i] + 2);
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (char)tolower(input[i] + 2);
        } else {
            output[i] = input[i];
        }
    }
    
    output[strlen(input)] = '\0';
    return output;
}

// Function to translate from alien language to human language
char* translate(char* input) {
    char* output = (char*)malloc(sizeof(char) * (strlen(input) + 1));
    
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (char)tolower(input[i] - 2);
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (char)toupper(input[i] - 2);
        } else {
            output[i] = input[i];
        }
    }
    
    output[strlen(input)] = '\0';
    return output;
}

int main() {
    char* input = "Hello, Earthlings!";
    char* translated = translate(alienize(input));
    printf("Alienized: %s\n", input);
    printf("Translated: %s\n", translated);
    
    free(input);
    free(translated);
    return 0;
}