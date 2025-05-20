//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100

typedef struct Word {
    char word[MAX_WORDS];
    int frequency;
} Word;

Word words[MAX_WORDS];

void initializeWords() {
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].word[0] = '\0';
        words[i].frequency = 0;
    }
}

void addWord(char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }

    Word newWord;
    strcpy(newWord.word, word);
    newWord.frequency = 1;

    for (int i = MAX_WORDS - 1; i >= 0; i--) {
        if (words[i].word[0] == '\0') {
            strcpy(words[i].word, newWord.word);
            return;
        }
    }

    // Should not reach here
    printf("Error: Word list full.\n");
}

int main() {
    initializeWords();

    char word[20];

    printf("Enter a word: ");
    scanf("%s", word);

    addWord(word);

    printf("Word added: %s, frequency: %d\n", words[0].word, words[0].frequency);

    return 0;
}