//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <time.h>

int main()
{
    time_t start, end;
    int i, speed, words = 0, characters = 0;
    char text[1000];

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please paste the text you want to type below:\n");

    // Get the text from the user
    gets(text);

    // Start the timer
    start = time(NULL);

    // The user will type the text here
    printf("Start typing now...\n");
    scanf("%[^\n]%*c", text);

    // Stop the timer
    end = time(NULL);

    // Calculate the time taken
    int timeTaken = end - start;

    // Calculate the speed
    speed = (characters / timeTaken) * 60;

    // Calculate the number of words and characters
    words = wordsFromText(text);
    characters = charactersFromText(text);

    // Print the results
    printf("Your typing speed is: %d words per minute.\n", words);
    printf("Your typing speed is: %d characters per minute.\n", speed);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);

    return 0;
}

int wordsFromText(char *text)
{
    int i, words = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' && text[i-1] != ' ')
        {
            words++;
        }
    }

    return words;
}

int charactersFromText(char *text)
{
    int i, characters = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        characters++;
    }

    return characters;
}