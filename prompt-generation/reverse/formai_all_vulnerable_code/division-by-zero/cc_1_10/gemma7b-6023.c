//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    int speed = 0, words = 0, characters = 0;
    char text[1000] = "";

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter the text you want to type: ");

    getline(text, 1000, stdin);

    start = time(NULL);
    printf("Start typing...\n");

    getline(text, 1000, stdin);

    end = time(NULL);

    words = words_count(text);
    characters = characters_count(text);

    speed = (characters * 60) / (end - start);

    printf("Your typing speed is: %d words per minute.\n", speed);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);

    return 0;
}

int words_count(char *text)
{
    int words = 0, i = 0;

    while (text[i] != '\0')
    {
        if (text[i] == ' ' || text[i] == '\n')
        {
            words++;
        }
        i++;
    }

    return words;
}

int characters_count(char *text)
{
    int characters = 0, i = 0;

    while (text[i] != '\0')
    {
        characters++;
        i++;
    }

    return characters;
}