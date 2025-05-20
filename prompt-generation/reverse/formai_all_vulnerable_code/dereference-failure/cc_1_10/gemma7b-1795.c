//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <string.h>

void alien_translator(char **alien_sentence)
{
    // Allocate memory for the translated sentence.
    char *translated_sentence = (char *)malloc(strlen(*alien_sentence) * sizeof(char));

    // Translate the alien sentence.
    for (int i = 0; i < strlen(*alien_sentence); i++)
    {
        switch ((*alien_sentence)[i])
        {
            case 'a':
                translated_sentence[i] = 'A';
                break;
            case 'e':
                translated_sentence[i] = 'E';
                break;
            case 'i':
                translated_sentence[i] = 'I';
                break;
            case 'o':
                translated_sentence[i] = 'O';
                break;
            case 'u':
                translated_sentence[i] = 'U';
                break;
            default:
                translated_sentence[i] = (*alien_sentence)[i];
                break;
        }
    }

    // Print the translated sentence.
    printf("%s", translated_sentence);

    // Free the memory allocated for the translated sentence.
    free(translated_sentence);
}

int main()
{
    // Get the alien sentence from the user.
    char *alien_sentence = NULL;
    printf("Enter an alien sentence: ");
    getline(stdin, alien_sentence, 1024);

    // Translate the alien sentence.
    alien_translator(&alien_sentence);

    // Free the memory allocated for the alien sentence.
    free(alien_sentence);

    return 0;
}