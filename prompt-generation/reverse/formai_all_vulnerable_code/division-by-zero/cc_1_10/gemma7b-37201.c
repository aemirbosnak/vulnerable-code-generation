//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    int speed, words, characters;
    char text[1000];

    printf("Please enter the text you want to type:");
    gets(text);

    start = time(NULL);
    printf("Please type the text as quickly as possible:");
    gets(text);
    end = time(NULL);

    words = words_count(text);
    characters = characters_count(text);

    speed = (characters / (end - start)) * 60;

    printf("Your typing speed is: %d words per minute.\n", speed);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);

    return 0;
}

int words_count(char *text)
{
    int words = 0;
    char *p = text;

    while (*p)
    {
        if (*p == ' ' || *p == '\n' || *p == '\t')
        {
            words++;
        }
        p++;
    }

    return words;
}

int characters_count(char *text)
{
    int characters = 0;
    char *p = text;

    while (*p)
    {
        characters++;
        p++;
    }

    return characters;
}