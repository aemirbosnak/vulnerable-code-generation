//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10
#define MAX_CHAR 20

typedef struct AlienWord
{
    char **word;
    int length;
    struct AlienWord *next;
} AlienWord;

AlienWord *head = NULL;

void alienWordInsert(char **word, int length)
{
    AlienWord *newNode = (AlienWord *)malloc(sizeof(AlienWord));
    newNode->word = (char **)malloc(sizeof(char *) * MAX_WORDS);
    newNode->length = length;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        AlienWord *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

char **alienWordTranslate(char **word, int length)
{
    char **newWord = (char **)malloc(sizeof(char *) * MAX_WORDS);
    newWord[0] = malloc(sizeof(char) * MAX_CHAR);
    newWord[1] = NULL;

    AlienWord *temp = head;
    int i = 0;
    while (temp)
    {
        for (int j = 0; j < temp->length; j++)
        {
            if (strcmp(word[j], temp->word[j]) == 0)
            {
                newWord[i] = temp->word[j];
                i++;
            }
        }
        temp = temp->next;
    }

    return newWord;
}

int main()
{
    alienWordInsert("aba", 3);
    alienWordInsert("abc", 3);
    alienWordInsert("bcd", 3);

    char **word = ("xyz" );
    char **translatedWord = alienWordTranslate(word, 3);

    printf("%s", translatedWord[0]);

    return 0;
}