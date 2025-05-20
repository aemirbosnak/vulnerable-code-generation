//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include <stdio.h>
#include <time.h>

int main()
{
    int speedTestTime = 30; // In seconds
    int targetWords = 10; // Number of words to type
    char textToType[1000] = "This is the text you will need to type. It is a sample text that is designed to test your typing speed.";
    char userText[1000] = "";
    int wordsTyped = 0;
    clock_t start, end;

    // Start the timer
    start = clock();

    // Get the user to type the text
    printf("Please type the following text as quickly as possible:\n\n");
    printf("%s", textToType);
    printf("\n");

    // Get the user's text
    printf("Please paste your typed text below:\n\n");
    getline(userText, 1000, stdin);

    // Stop the timer
    end = clock();

    // Calculate the time taken
    int timeTaken = (end - start) / CLOCKS_PER_SEC;

    // Calculate the number of words typed
    wordsTyped = wordsTypedFromText(userText, textToType);

    // Print the results
    printf("Your typing speed is: %.2f words per second.\n", (wordsTyped / timeTaken) * 60);
    printf("You typed a total of %d words in %d seconds.\n", wordsTyped, timeTaken);

    return 0;
}

int wordsTypedFromText(char *text1, char *text2)
{
    int i = 0;
    int wordsTyped = 0;

    // Iterate over the text
    for (i = 0; text1[i] != '\0'; i++)
    {
        // Check if the character is a space
        if (text1[i] == ' ')
        {
            // Increment the number of words typed
            wordsTyped++;
        }
    }

    // Return the number of words typed
    return wordsTyped;
}