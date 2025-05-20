//FormAI DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100 // Maximum input size for the text to be checked
#define MAX_WORD_SIZE 50 // Maximum size of a single word

// A linked list node to store the dictionary
typedef struct DictNode {
    char* word;
    struct DictNode* next;
} DictNode;

// A function to add a word to the dictionary
void addToDictionary(DictNode** dict, char* word) {
    DictNode* node = (DictNode*) malloc(sizeof(DictNode));
    node->word = (char*) malloc(strlen(word) + 1);
    strcpy(node->word, word);
    node->next = *dict;
    *dict = node;
}

// A function to free the memory used by the dictionary
void freeDictionary(DictNode* dict) {
    while (dict) {
        DictNode* next = dict->next;
        free(dict->word);
        free(dict);
        dict = next;
    }
}

// A function to check if a word is in the dictionary
int checkDictionary(DictNode* dict, char* word) {
    while (dict) {
        if (strcmp(dict->word, word) == 0) {
            return 1;
        }
        dict = dict->next;
    }
    return 0;
}

// A function to read and convert a text to a list of words
char** readText(char* text, int* length) {
    char** words = (char**) malloc(MAX_INPUT_SIZE * sizeof(char*));
    char* word;
    int i = 0;
    word = strtok(text, " "); // get the first word
    while (word != NULL) { // loop through all the words
        words[i++] = word;
        word = strtok(NULL, " "); // get the next word
    }
    *length = i; // set the length of the array
    return words;
}

// A function to check and correct the spelling of a text
char* spellCheck(char* text, DictNode* dict) {
    int length;
    char** words = readText(text, &length);
    char* correctedText = (char*) malloc(MAX_INPUT_SIZE * sizeof(char));
    char* buffer = (char*) malloc(MAX_WORD_SIZE * sizeof(char));
    int i, j, k, l, m, n, o, p, q; // variables for looping
    for (i = 0; i < length; i++) {
        // Check if the word is in the dictionary
        if (checkDictionary(dict, words[i])) {
            strcat(correctedText, words[i]);
        } else {
            // Try to correct the word
            for (j = 0; words[i][j] != 0; j++) {
                // Case 1: Delete one letter
                for (k = 0; k < j; k++) {
                    buffer[k] = words[i][k];
                }
                for (l = j + 1; words[i][l] != 0; l++) {
                    buffer[k++] = words[i][l];
                }
                buffer[k] = 0;
                if (checkDictionary(dict, buffer)) {
                    strcat(correctedText, buffer);
                    strcat(correctedText, " ");
                    break;
                }
                // Case 2: Replace one letter
                for (m = 'a'; m <= 'z'; m++) {
                    buffer[j] = m;
                    buffer[j + 1] = 0;
                    if (checkDictionary(dict, buffer)) {
                        strcat(correctedText, buffer);
                        strcat(correctedText, " ");
                        break;
                    }
                }
                if (m <= 'z') {
                    break;
                }
                // Case 3: Insert one letter
                for (n = 0, o = 0; words[i][n] != 0; n++) {
                    if (n == j) {
                        buffer[o++] = 'a';
                        buffer[o++] = 0;
                    }
                    buffer[o++] = words[i][n];
                }
                buffer[o++] = 'a';
                buffer[o] = 0;
                if (checkDictionary(dict, buffer)) {
                    strcat(correctedText, buffer);
                    strcat(correctedText, " ");
                    break;
                }
                // Case 4: Swap two adjacent letters
                for (p = 0, q = 0; words[i][p] != 0; p++) {
                    if (p == j) {
                        buffer[q++] = words[i][p + 1];
                    } else if (p == j + 1) {
                        buffer[q++] = words[i][p - 1];
                    } else {
                        buffer[q++] = words[i][p];
                    }
                }
                buffer[q] = 0;
                if (checkDictionary(dict, buffer)) {
                    strcat(correctedText, buffer);
                    strcat(correctedText, " ");
                    break;
                }
            }
            if (words[i][j] == 0) {
                // No correction found, add the original word
                strcat(correctedText, words[i]);
                strcat(correctedText, " ");
            }
        }
    }
    // Free the memory used by the word list
    for (i = 0; i < length; i++) {
        free(words[i]);
    }
    free(words);
    free(buffer);
    return correctedText;
}

int main() {
    // Create the dictionary
    DictNode* dict = NULL;
    addToDictionary(&dict, "apple");
    addToDictionary(&dict, "banana");
    addToDictionary(&dict, "cherry");
    addToDictionary(&dict, "date");
    addToDictionary(&dict, "elderberry");

    // Ask for input text
    printf("Enter text to be spell checked: ");
    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = 0;
    }

    // Check and correct the spelling
    char* correctedText = spellCheck(input, dict);

    // Print the corrected text
    printf("Corrected text: %s\n", correctedText);

    // Free the memory used by the dictionary and corrected text
    freeDictionary(dict);
    free(correctedText);

    return 0;
}