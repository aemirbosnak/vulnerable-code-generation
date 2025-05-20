//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        head->next = insertWord(head->next, word);
    }

    return head;
}

int wordCompare(char *word1, char *word2) {
    return strcmp(word1, word2);
}

int detectSpam(char *text) {
    Word *head = NULL;
    char *words[MAX_WORDS];
    char *p = text;

    // Tokenize the text into words
    words[0] = strtok(p, " ");
    int i = 1;
    while ((words[i] = strtok(NULL, " ")) != NULL) {
        i++;
    }

    // Insert each word into the linked list
    for (int i = 0; words[i] != NULL; i++) {
        insertWord(head, words[i]);
    }

    // Iterate over the list of words and check if any word is a spam word
    for (Word *word = head; word != NULL; word = word->next) {
        if (wordCompare(word->word, "free") == 0 || wordCompare(word->word, "lottery") == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char *text = "You have won $10,000! Free your mind, free your soul!";
    int isSpam = detectSpam(text);

    if (isSpam) {
        printf("Spam detected!");
    } else {
        printf("No spam detected.");
    }

    return 0;
}