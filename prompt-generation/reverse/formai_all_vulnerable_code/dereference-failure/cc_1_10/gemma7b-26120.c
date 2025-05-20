//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_GUESSES 3

typedef struct Word
{
    char **words;
    int current_word_index;
    int guesses;
} Word;

Word createWord()
{
    Word word;
    word.words = malloc(MAX_WORDS * sizeof(char *));
    word.current_word_index = 0;
    word.guesses = MAX_GUESSES;
    return word;
}

void playWordGame(Word *word)
{
    char guess;
    printf("Guess the word: ");
    scanf(" %c", &guess);

    if (guess == word->words[word->current_word_index])
    {
        printf("Correct! You win!\n");
        word->guesses--;
    }
    else
    {
        printf("Incorrect. Try again.\n");
    }

    if (word->guesses == 0)
    {
        printf("Sorry, you lose.\n");
    }
    else
    {
        word->current_word_index++;
        playWordGame(word);
    }
}

int main()
{
    Word word = createWord();
    word.words[0] = "apple";
    word.words[1] = "banana";
    word.words[2] = "orange";
    word.words[3] = "grape";
    word.words[4] = "mango";
    word.words[5] = "pineapple";
    word.words[6] = "watermelon";
    word.words[7] = "apricot";
    word.words[8] = "peach";
    word.words[9] = "mango";

    playWordGame(&word);

    return 0;
}