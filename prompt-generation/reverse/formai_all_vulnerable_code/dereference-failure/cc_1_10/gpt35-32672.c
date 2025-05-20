//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

// declaration of functions
bool isWord(const char* str);
void processText(char* text);

int main()
{
    char text[MAX_LENGTH];

    printf("Please enter some text:\n");
    fgets(text, MAX_LENGTH, stdin);

    printf("\nProcessing the text...\n\n");
    processText(text);

    return 0;
}

bool isWord(const char* str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(!isalpha(str[i]) && str[i] != '\'' && str[i] != '-')
        {
            return false;
        }
    }

    return true;
}

void processText(char* text)
{
    char* word;
    char* savePtr;

    word = strtok_r(text, " \n\r\t", &savePtr);

    while(word != NULL)
    {
        if(isWord(word))
        {
            printf("%s ", word);
        }
        else
        {
            int len = strlen(word);

            if(ispunct(word[len - 1]))
            {
                printf("%c ", word[len - 1]);
                word[len - 1] = '\0';
            }

            if(isWord(word + 1))
            {
                printf("%c%s ", word[0], word + 1);
            }
            else
            {
                printf("%s ", word);
            }
        }

        word = strtok_r(NULL, " \n\r\t", &savePtr);
    }
}