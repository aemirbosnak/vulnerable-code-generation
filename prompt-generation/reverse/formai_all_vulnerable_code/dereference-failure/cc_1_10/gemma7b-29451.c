//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    int frequency;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 1;
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        Word *currentWord = head;
        while (currentWord->next) {
            currentWord = currentWord->next;
        }
        currentWord->next = newWord;
    }

    return head;
}

int main() {
    Word *head = NULL;

    char *text = "I am a man, a lonely man. I have no wife, no children. I am sad, but I am trying to be happy. I am a poet, a writer. I love to read and write. I am a good person. I am a kind person. I am a caring person. I am a good friend. I am a loyal person. I am a strong person. I am a person of integrity.";

    char *words[] = {"I", "am", "a", "man", "a", "lonely", "man", "I", "have", "no", "wife", "no", "children", "I", "am", "sad", "but", "I", "am", "trying", "to", "be", "happy", "I", "am", "a", "poet", "a", "writer", "I", "love", "to", "read", "and", "write", "I", "am", "a", "good", "person", "I", "am", "a", "kind", "person", "I", "am", "a", "caring", "person", "I", "am", "a", "good", "friend", "I", "am", "a", "loyal", "person", "I", "am", "a", "strong", "person", "I", "am", "a", "person", "of", "integrity"};

    for (int i = 0; i < 28; i++) {
        insertWord(head, words[i]);
    }

    Word *currentWord = head;
    while (currentWord) {
        printf("%s: %d\n", currentWord->word, currentWord->frequency);
        currentWord = currentWord->next;
    }

    return 0;
}