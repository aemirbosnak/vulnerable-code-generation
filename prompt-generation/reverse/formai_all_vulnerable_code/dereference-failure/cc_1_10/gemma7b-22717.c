//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct AlienWord
{
    char word[MAX_WORD_LENGTH];
    struct AlienWord* next;
} AlienWord;

AlienWord* alienWordCreate()
{
    AlienWord* newWord = malloc(sizeof(AlienWord));
    newWord->word[0] = '\0';
    newWord->next = NULL;
    return newWord;
}

void alienWordAdd(AlienWord* wordList, char* word)
{
    AlienWord* newNode = alienWordCreate();
    strcpy(newNode->word, word);
    if (wordList)
    {
        wordList->next = newNode;
    }
    else
    {
        wordList = newNode;
    }
}

int alienWordSearch(AlienWord* wordList, char* word)
{
    for (AlienWord* currentWord = wordList; currentWord; currentWord = currentWord->next)
    {
        if (strcmp(currentWord->word, word) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    AlienWord* alienWordList = alienWordCreate();

    // Multiplayer code starts here

    // Assume two players, Alice and Bob, are connected
    char* AliceWord = "Greetings, alien!";
    alienWordAdd(alienWordList, AliceWord);

    char* BobWord = "May the Force be with you!";
    alienWordAdd(alienWordList, BobWord);

    // Alice sends her word to Bob
    printf("Alice: %s\n", AliceWord);

    // Bob checks if his word is the same as Alice's
    if (alienWordSearch(alienWordList, BobWord) == 1)
    {
        printf("Bob: Your word is the same as Alice's!\n");
    }
    else
    {
        printf("Bob: Your word is not the same as Alice's.\n");
    }

    // Multiplayer code ends here

    return 0;
}