//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words in a text
#define MAX_WORDS 1000

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the structure of a word
typedef struct Word {
    char *word;
    int length;
    struct Word *next;
} Word;

// Function to insert a word into a linked list
void insertWord(Word **head, char *word, int length) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = malloc(sizeof(char) * length);
    newWord->length = length;

    strcpy(newWord->word, word);

    if (*head == NULL) {
        *head = newWord;
    } else {
        (*head)->next = newWord;
        *head = newWord;
    }
}

// Function to count the number of words in a text
int countWords(Word *head) {
    int wordCount = 0;

    while (head) {
        wordCount++;
        head = head->next;
    }

    return wordCount;
}

int main() {
    Word *head = NULL;

    // Insert some words into the linked list
    insertWord(&head, "Hello", 5);
    insertWord(&head, "World", 6);
    insertWord(&head, "!", 1);

    // Count the number of words in the text
    int wordCount = countWords(head);

    // Print the number of words
    printf("The number of words in the text is: %d", wordCount);

    return 0;
}