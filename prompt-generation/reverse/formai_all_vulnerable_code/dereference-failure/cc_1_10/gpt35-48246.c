//FormAI DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length for words */
#define MAX_WORD_LENGTH 20

/* Define the dictionary size */
#define DICTIONARY_SIZE 100

/* Define the maximum number of suggestions */
#define MAX_SUGGESTIONS 3

/* Define the medieval style error messages */
const char *error_messages[] = {"Thy spelling is erroneous!", "Hark! Thy spelling is amiss!", "Verily, thy spelling is not correct!"};

/* Define the medieval style suggestion messages */
const char *suggestion_messages[] = {"Dost thou mean", "Might thou be trying to spell", "Perchance thou intended to spell"};

/* Define the dictionary as an array of strings */
const char *dictionary[DICTIONARY_SIZE] = {"bards", "castle", "dragon", "knight", "peasant", "princess", "sword"};

/* Helper function to check if a word is in the dictionary */
int is_word_in_dictionary(const char *word)
{
    for (int i = 0; i < DICTIONARY_SIZE; i++)
    {
        if (strcmp(word, dictionary[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

/* Helper function to suggest words */
void suggest_words(const char *word)
{
    /* Generate three random indices */
    int index_1 = rand() % DICTIONARY_SIZE;
    int index_2 = rand() % DICTIONARY_SIZE;
    int index_3 = rand() % DICTIONARY_SIZE;

    /* Get the three suggested words */
    const char *suggestion_1 = dictionary[index_1];
    const char *suggestion_2 = dictionary[index_2];
    const char *suggestion_3 = dictionary[index_3];

    /* Print the suggestion messages and the suggested words */
    printf("%s %s %s, %s %s %s, %s %s %s?\n", suggestion_messages[0], suggestion_1, "?", suggestion_messages[1], suggestion_2, "?", suggestion_messages[2], suggestion_3, "?");
}

/* The main spell checking function */
void spell_check(const char *text)
{
    char word[MAX_WORD_LENGTH];
    int word_index = 0;

    /* Loop through each character in the text */
    for (int i = 0; i <= strlen(text); i++)
    {
        char c = text[i];

        /* Check if the character is an alphabetic character */
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            /* Add the character to the current word */
            word[word_index] = c;
            word_index++;
        }
        /* Otherwise, we have reached the end of a word */
        else
        {
            /* Check if the word is in the dictionary */
            word[word_index] = '\0';
            if (!is_word_in_dictionary(word))
            {
                /* Print a random error message */
                int error_index = rand() % 3;
                printf("%s\n", error_messages[error_index]);

                /* Suggest some alternative words */
                suggest_words(word);
            }

            /* Reset the word index to start a new word */
            word_index = 0;
        }
    }
}

/* The main program */
int main()
{
    /* Seed the random number generator */
    srand(time(NULL));

    /* Get some text from the user */
    char text[100];
    printf("Enter some text for spell checking: ");
    fgets(text, 100, stdin);

    /* Call the spell checking function */
    spell_check(text);

    return 0;
}