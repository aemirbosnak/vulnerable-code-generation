//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: unmistakable
#include <stdio.h>
#include <string.h>

/*
This program is a C Cat Language Translator. It takes in any input string and converts it to Cat Language.
*/

// Function to convert input string to Cat Language
char* toCatLanguage(char* input)
{
    // Initialize variables
    int inputLength = strlen(input);
    char* catLanguage = malloc(inputLength * 2 + 1);
    int catIndex = 0;

    // Loop through each character of the input string
    for(int i = 0; i < inputLength; i++)
    {
        // Check if the character is a vowel
        if(input[i] == 'a' || input[i] == 'A' || input[i] == 'e' || input[i] == 'E' || input[i] == 'i' || input[i] == 'I' || input[i] == 'o' || input[i] == 'O' || input[i] == 'u' || input[i] == 'U')
        {
            strcat(catLanguage, "at");
            catIndex += 2;
        }
        // Check if the character is a consonant
        else if(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
        {
            catLanguage[catIndex] = input[i];
            catIndex++;
        }
    }

    // Add a meow to the end of the Cat Language string
    strcat(catLanguage, "meow");

    return catLanguage;
}

// Main function
int main()
{
    char input[100];
    char* catLanguage;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter any sentence you would like to translate to Cat Language:\n");
    fgets(input, 100, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Convert input to Cat Language
    catLanguage = toCatLanguage(input);

    // Print Cat Language translation
    printf("\nCat Language Translation: %s\n", catLanguage);

    // Free dynamically allocated memory
    free(catLanguage);

    return 0;
}