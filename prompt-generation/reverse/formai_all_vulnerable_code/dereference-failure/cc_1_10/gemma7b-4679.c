//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CHAR_PER_WORD 20

typedef struct Word {
    char **characters;
    int length;
} Word;

Word *createWord(int length) {
    Word *word = malloc(sizeof(Word));
    word->characters = malloc(sizeof(char *) * length);
    word->length = length;
    return word;
}

void addCharacter(Word *word, char character) {
    word->characters[word->length++] = malloc(sizeof(char));
    *word->characters[word->length - 1] = character;
}

int main() {
    time_t start, end;
    int words_per_minute;
    Word *words = NULL;
    char input[MAX_CHAR_PER_WORD];

    start = time(NULL);

    printf("Enter words, one per line: (Press Ctrl-D to quit)\n");

    while (1) {
        char *word = fgets(input, MAX_CHAR_PER_WORD, stdin);
        if (word == NULL) {
            break;
        }

        Word *newWord = createWord(strlen(word) + 1);
        addCharacter(newWord, '\0');

        words = words ? words : newWord;
    }

    end = time(NULL);

    words_per_minute = (words ? words->length : 0) * 60 / (end - start);

    printf("Total number of words entered: %d\n", words ? words->length : 0);
    printf("Words per minute: %d\n", words_per_minute);

    free(words);

    return 0;
}