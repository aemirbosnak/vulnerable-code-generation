//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *insertWord(WordNode *head, char *word) {
    WordNode *newNode = malloc(sizeof(WordNode));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = insertWord(head->next, word);
    }

    return head;
}

int wordFrequency(WordNode *head, char *word) {
    WordNode *current = head;

    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    WordNode *head = NULL;
    char *text = "This is a sample text. It contains many words. Some words are repeated. The frequency of a word can be counted. Isn't that amazing?";

    insertWord(head, "is");
    insertWord(head, "a");
    insertWord(head, "the");
    insertWord(head, "sample");
    insertWord(head, "text");
    insertWord(head, "many");
    insertWord(head, "words");
    insertWord(head, "some");
    insertWord(head, "repeated");
    insertWord(head, "The");
    insertWord(head, "frequency");
    insertWord(head, "of");
    insertWord(head, "word");
    insertWord(head, "can");
    insertWord(head, "be");
    insertWord(head, "counted");
    insertWord(head, "Isn't");
    insertWord(head, "that");
    insertWord(head, "amazing");

    int frequency = wordFrequency(head, "The");

    if (frequency) {
        printf("The word 'The' appears %d times in the text.\n", frequency);
    } else {
        printf("The word 'The' does not appear in the text.\n");
    }

    return 0;
}