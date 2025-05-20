//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *createWord(char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;
    return newWord;
}

void translate(Word *wordList) {
    for (Word *word = wordList; word; word = word->next) {
        switch (word->word[0]) {
            case 'a':
                word->word[0] = 'b';
                break;
            case 'e':
                word->word[0] = 'f';
                break;
            case 'i':
                word->word[0] = 'j';
                break;
            default:
                break;
        }
    }
}

int main() {
    Word *wordList = createWord("apple");
    wordList = createWord("banana");
    wordList = createWord("orange");
    wordList = createWord("grape");

    translate(wordList);

    for (Word *word = wordList; word; word = word->next) {
        printf("%s ", word->word);
    }

    printf("\n");

    return 0;
}