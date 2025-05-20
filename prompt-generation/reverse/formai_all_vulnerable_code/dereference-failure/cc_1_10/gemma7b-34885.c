//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CHAR 25

typedef struct Word
{
    char word[MAX_CHAR];
    struct Word* next;
} Word;

Word* createWord(char* word)
{
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;
    return newWord;
}

void insertWord(Word* head, char* word)
{
    Word* newWord = createWord(word);
    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = newWord;
    }
}

void printWords(Word* head)
{
    Word* currentWord = head;
    while (currentWord)
    {
        printf("%s ", currentWord->word);
        currentWord = currentWord->next;
    }
    printf("\n");
}

int main()
{
    time_t start, end;
    char word[MAX_CHAR];
    Word* head = NULL;

    start = time(NULL);

    // Type your words here
    insertWord(head, "Hello");
    insertWord(head, "World");
    insertWord(head, "Welcome");
    insertWord(head, "To");
    insertWord(head, "The");
    insertWord(head, "Test");
    insertWord(head, "Program");

    end = time(NULL);

    printWords(head);

    printf("Time taken: %ld seconds\n", end - start);

    return 0;
}