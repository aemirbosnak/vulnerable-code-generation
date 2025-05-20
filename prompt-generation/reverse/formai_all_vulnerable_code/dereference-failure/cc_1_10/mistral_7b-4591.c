//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define MAX_WORD_SIZE 50
#define NUM_ALPHABETS 26
#define NUM_SYMBOLS 5

typedef struct {
    char symbol;
    int index;
} Alphabet;

Alphabet alphabets[NUM_ALPHABETS];
char input[MAX_INPUT_SIZE];
char output[MAX_INPUT_SIZE];
int inputIndex = 0;
int outputIndex = 0;

void initializeAlphabets() {
    int i, j;
    for (i = 0; i < NUM_ALPHABETS; i++) {
        alphabets[i].symbol = 'A' + i;
        alphabets[i].index = i;
    }
}

int findIndex(char symbol) {
    int i;
    for (i = 0; i < NUM_ALPHABETS; i++) {
        if (alphabets[i].symbol == symbol) {
            return alphabets[i].index;
        }
    }
    return -1;
}

void translate(char *input) {
    int i, j;
    while (*input != '\0') {
        i = findIndex(*input);
        if (i != -1) {
            output[outputIndex++] = alphabets[(inputIndex + NUM_SYMBOLS - i) % NUM_ALPHABETS].symbol;
        } else {
            if (isspace(*input)) {
                output[outputIndex++] = ' ';
            } else if (isdigit(*input)) {
                output[outputIndex++] = '0' + (*input - '0' + NUM_SYMBOLS) % NUM_SYMBOLS;
            } else {
                output[outputIndex++] = '#';
            }
        }
        input++;
        inputIndex++;
    }
    output[outputIndex] = '\0';
}

int main() {
    int i;
    char *inputString;

    initializeAlphabets();

    printf("Enter the Earth language string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    inputString = strtok(input, " \n");

    translate(inputString);

    printf("The Alien language translation is: %s\n", output);

    return 0;
}