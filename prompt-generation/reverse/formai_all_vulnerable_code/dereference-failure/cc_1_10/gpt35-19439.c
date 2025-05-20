//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

struct Node {
    char character;
    char* morseCode;
    struct Node* next;
};

char* convertToMorseCode(char*);
void addNode(char, char*);
char* translateToMorseCode(char);
void printMorseCode(struct Node*);

struct Node* head = NULL;

int main() {
    char input[MAX_INPUT_LENGTH];
    char* morseCode;

    // Create morse code dictionary
    addNode('a', ".-");
    addNode('b', "-...");
    addNode('c', "-.-.");
    addNode('d', "-..");
    addNode('e', ".");
    addNode('f', "..-.");
    addNode('g', "--.");
    addNode('h', "....");
    addNode('i', "..");
    addNode('j', ".---");
    addNode('k', "-.-");
    addNode('l', ".-..");
    addNode('m', "--");
    addNode('n', "-.");
    addNode('o', "---");
    addNode('p', ".--.");
    addNode('q', "--.-");
    addNode('r', ".-.");
    addNode('s', "...");
    addNode('t', "-");
    addNode('u', "..-");
    addNode('v', "...-");
    addNode('w', ".--");
    addNode('x', "-..-");
    addNode('y', "-.--");
    addNode('z', "--..");

    // Get user input
    printf("Cyberpunk Text to Morse Code Converter\n");
    printf("Enter a text to convert to morse code:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Convert input to morse code
    morseCode = convertToMorseCode(input);

    // Print morse code
    printf("\nMorse Code:\n");
    printf("%s\n", morseCode);

    return 0;
}

char* convertToMorseCode(char* input) {
    int i, j, length;
    char* morseCode;
    char* newMorseCode;

    // Allocate memory for morseCode
    morseCode = (char*) malloc(strlen(input) * 10);
    morseCode[0] = '\0';

    // Convert each character to morse code
    length = strlen(input);
    for (i = 0; i < length; i++) {
        // Translate character to morse code
        newMorseCode = translateToMorseCode(tolower(input[i]));

        // Append the new morse code to morseCode
        strcat(morseCode, newMorseCode);

        // Add a space between each letter
        if (i < length - 1 && input[i + 1] != ' ') {
            strcat(morseCode, " ");
        }

        // Free memory allocated for newMorseCode
        free(newMorseCode);
    }

    return morseCode;
}

void addNode(char character, char* morseCode) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->character = character;
    newNode->morseCode = morseCode;
    newNode->next = head;
    head = newNode;
}

char* translateToMorseCode(char character) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->character == character) {
            return current->morseCode;
        }
        current = current->next;
    }

    return "";
}

void printMorseCode(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%c: %s\n", node->character, node->morseCode);
    printMorseCode(node->next);
}