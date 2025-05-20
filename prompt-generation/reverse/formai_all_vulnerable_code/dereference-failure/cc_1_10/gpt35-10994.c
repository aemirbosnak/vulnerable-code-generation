//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a linked list node to store each word
struct WordNode {
    char *word;
    int count;
    struct WordNode *next;
};

typedef struct WordNode WordNode;

// Function to insert a new word into the linked list
void insertWord(char *newWord, WordNode **head) {
    WordNode *current = *head;
    WordNode *previous = NULL;
    int wordExists = 0;

    // Check if the word already exists in the linked list
    while (current != NULL) {
        if (strcmp(current->word, newWord) == 0) {
            current->count++;
            wordExists = 1;
            break;
        }
        previous = current;
        current = current->next;
    }

    // If the word does not exist, add it to the linked list
    if (!wordExists) {
        WordNode *newNode = (WordNode*)malloc(sizeof(WordNode));
        newNode->word = newWord;
        newNode->count = 1;
        newNode->next = NULL;
        if (previous == NULL) {
            *head = newNode;
        } else {
            previous->next = newNode;
        }
    }
}

// Function to convert a string to lowercase
void toLowercase(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char *input = (char*)malloc(sizeof(char)*1000);
    printf("Enter a string: ");
    fgets(input, 1000, stdin);

    WordNode *head = NULL;

    // Split the string into words
    char *word = strtok(input, " \n\t");
    while (word != NULL) {
        toLowercase(word);
        insertWord(word, &head);
        word = strtok(NULL, " \n\t");
    }

    // Print out the word frequency
    printf("\nWord frequency:\n");
    WordNode *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }

    return 0;
}