//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char *alien_dict[] = {
    "ab", "ba", "cc", "dc", "ed", "fe", "gh", "hi", "ij", "jk",
    "kl", "lm", "mn", "no", "op", "pq", "qr", "rs", "st", "tu",
    "uv", "vw", "wx", "xy", "yz"
};

// Define the maximum length of an Alien word
#define MAX_WORD_LEN 20

// Function to translate an Alien word to English
char *alien_to_english(char *alien_word)
{
    int i, j;
    char *english_word = malloc(MAX_WORD_LEN + 1);
    english_word[0] = '\0';

    for (i = 0; i < strlen(alien_word); i += 2)
    {
        for (j = 0; j < 25; j++)
        {
            if (strcmp(alien_dict[j], alien_word + i) == 0)
            {
                strcat(english_word, "abcdefghijklmnopqrstuvwxyz"[j]);
                break;
            }
        }
    }

    return english_word;
}

// Function to translate an English word to Alien
char *english_to_alien(char *english_word)
{
    int i, j;
    char *alien_word = malloc(MAX_WORD_LEN + 1);
    alien_word[0] = '\0';

    for (i = 0; i < strlen(english_word); i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (english_word[i] == "abcdefghijklmnopqrstuvwxyz"[j])
            {
                strcat(alien_word, alien_dict[j]);
                break;
            }
        }
    }

    return alien_word;
}

// Main function
int main()
{
    char alien_word[MAX_WORD_LEN + 1];
    char english_word[MAX_WORD_LEN + 1];

    printf("Enter an Alien word: ");
    scanf("%s", alien_word);
    printf("The English translation is: %s\n", alien_to_english(alien_word));

    printf("Enter an English word: ");
    scanf("%s", english_word);
    printf("The Alien translation is: %s\n", english_to_alien(english_word));

    return 0;
}