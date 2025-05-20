//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to convert a string to uppercase
void toUpper(char* str) {
    int i = 0;
    while(str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to convert a string to lowercase
void toLower(char* str) {
    int i = 0;
    while(str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to convert a string to Morse code
void toMorse(char* str) {
    char* morse = (char*)malloc(strlen(str) * 2 + 1);
    int i = 0;
    while(str[i]) {
        if(isalpha(str[i])) {
            if(isupper(str[i])) {
                strcpy(morse+i*2, "A");
                i++;
            } else {
                strcpy(morse+i*2, "a");
            }
        } else if(isdigit(str[i])) {
            strcpy(morse+i*2, "0");
        } else {
            strcpy(morse+i*2, " ");
        }
        i++;
    }
    printf("%s\n", morse);
    free(morse);
}

int main() {
    char input[100];
    printf("Enter a string to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);
    toUpper(input);
    toMorse(input);
    return 0;
}