//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct WordNode {
    char word[MAX_WORD_LENGTH];
    int frequency;
    struct WordNode* next;
} WordNode;

WordNode* createWordNode(char* word, int frequency) {
    WordNode* newNode = malloc(sizeof(WordNode));
    strcpy(newNode->word, word);
    newNode->frequency = frequency;
    newNode->next = NULL;
    return newNode;
}

void addWordToWordList(WordNode* head, char* word, int frequency) {
    WordNode* newNode = createWordNode(word, frequency);
    if (head == NULL) {
        head = newNode;
    } else {
        WordNode* current = head;
        WordNode* previous = NULL;
        while (current) {
            if (strcmp(current->word, word) == 0) {
                current->frequency++;
                previous = current;
            }
            previous = current;
            current = current->next;
        }
        if (previous) {
            previous->next = newNode;
        } else {
            head = newNode;
        }
    }
}

int main() {
    WordNode* head = NULL;
    char text[] = "This is a sample text with many words. Some words are repeated multiple times. The word 'the' is the most repeated word in this text.";
    char* words[MAX_WORDS];
    int wordIndex = 0;

    // Tokenize the text into words
    words[wordIndex++] = strtok(text, " ");
    while (words[wordIndex] = strtok(NULL, " "), wordIndex < MAX_WORDS) {
        addWordToWordList(head, words[wordIndex], 1);
    }

    // Print the words and their frequencies
    WordNode* current = head;
    while (current) {
        printf("%s: %d\n", current->word, current->frequency);
    }

    return 0;
}