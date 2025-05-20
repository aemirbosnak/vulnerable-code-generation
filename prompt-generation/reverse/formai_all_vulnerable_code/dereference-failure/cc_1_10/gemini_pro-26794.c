//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
// A Morse code tree node
typedef struct TreeNode {
    char letter;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// A utility function to create a new TreeNode
TreeNode* newNode(char letter) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->letter = letter;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// A utility function to traverse the Morse code tree and print the Morse code of the input text
void printMorseCode(TreeNode* root, char* text) {
    if (text == NULL || *text == '\0') {
        return;
    }
    // Traverse the Morse code tree
    if (*text == root->letter) {
        printf(" %s ", root->letter);
        printMorseCode(root->left, text + 1);
        printMorseCode(root->right, text + 1);
    } else {
        printMorseCode(root->left, text);
        printMorseCode(root->right, text);
    }
}

// The main function that converts a text string to Morse code
char* textToMorseCode(char* text) {
    // Create a Morse code tree
    TreeNode* root = newNode('.');
    root->left = newNode('-');
    root->right = newNode('o');
    root->left->left = newNode('a');
    root->left->right = newNode('e');
    root->right->left = newNode('i');
    root->right->right = newNode('u');
    root->left->left->left = newNode('r');
    root->left->left->right = newNode('w');
    root->left->right->left = newNode('t');
    root->left->right->right = newNode('y');
    root->right->left->left = newNode('d');
    root->right->left->right = newNode('f');
    root->right->right->left = newNode('g');
    root->right->right->right = newNode('h');
    root->left->left->left->left = newNode('c');
    root->left->left->left->right = newNode('x');
    root->left->left->right->left = newNode('q');
    root->left->left->right->right = newNode('z');
    root->left->right->left->left = newNode('l');
    root->left->right->left->right = newNode('p');
    root->left->right->right->left = newNode('j');
    root->left->right->right->right = newNode('k');
    root->right->left->left->left = newNode('m');
    root->right->left->left->right = newNode('n');
    root->right->left->right->left = newNode('b');
    root->right->left->right->right = newNode('v');
    root->right->right->left->left = newNode('s');

    // Convert the text to Morse code
    char* morseCode = (char*)malloc(sizeof(char) * 100);
    printMorseCode(root, text);
    morseCode[strlen(morseCode) - 1] = '\0';

    // Return the Morse code
    return morseCode;
}

// The main function that takes input from the user and prints the Morse code of the input text
int main() {
    // Get the input text from the user
    char text[100];
    printf("Enter the text to be converted to Morse code: ");
    gets(text);

    // Convert the text to Morse code
    char* morseCode = textToMorseCode(text);

    // Print the Morse code
    printf("The Morse code of the input text is: %s\n", morseCode);

    return 0;
}