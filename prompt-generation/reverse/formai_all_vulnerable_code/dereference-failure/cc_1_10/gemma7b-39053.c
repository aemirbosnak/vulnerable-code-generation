//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define WORDS_PER_LINE 20

typedef struct Word {
    char **words;
    int index;
} Word;

void initializeWord(Word *word) {
    word->words = (char **)malloc(MAX_WORDS * sizeof(char *));
    word->index = 0;
}

void addWord(Word *word, char *wordStr) {
    word->words[word->index++] = strdup(wordStr);
}

int main() {
    time_t start, end;
    Word word;
    initializeWord(&word);

    start = time(NULL);

    // Type as fast as you can!
    addWord(&word, "Quick");
    addWord(&word, "Brown");
    addWord(&word, "Fox");
    addWord(&word, "Jumping");
    addWord(&word, "Frog");
    addWord(&word, "The");
    addWord(&word, "Quick");
    addWord(&word, "Brown");
    addWord(&word, "Fox");
    addWord(&word, "Jumping");
    addWord(&word, "Frog");
    addWord(&word, "The");
    addWord(&word, "Quick");
    addWord(&word, "Brown");
    addWord(&word, "Fox");
    addWord(&word, "Jumping");
    addWord(&word, "Frog");

    end = time(NULL);

    printf("Time taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Number of words typed: %d\n", word.index);

    return 0;
}